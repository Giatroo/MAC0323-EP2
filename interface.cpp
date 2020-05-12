#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define debug(a) std::cout << #a << " = " << (a) << std::endl;

class Node {
  public:
	std::vector<Node *> adj; // A lista de adjacentes ao nó
	std::string palavra;     // A palavra do nó
	int index;               // O índice do nó no grafo
	Node() : palavra(""){};
	Node(std::string palavra) : palavra(palavra){};
	Node(std::string palavra, int index) : palavra(palavra), index(index){};
};

// k definido como no enunciado será passado como argumento de linha de comando
class Grafo {
  public:
	long unsigned int k;       // k referente ao enunciado
	long unsigned int V, E;    // Número de vértices e número de arestas
	std::vector<Node *> nodes; // A lista de nós do grafo

  public:
	Grafo() {
		this->k = 10;
		V = E = 0;
	}
	Grafo(int k) { /* Inicializa um grafo com parâmetro k */
		this->k = k;
		V = E = 0;
	}
	~Grafo() {
		for (long unsigned int i = 0; i < V; i++) delete nodes[i];
		nodes.clear();
		V = E = 0;
	}

	void imprime() {
		std::cout << "Grafo com " << V << " vértices e " << E << " arestas: " << std::endl;
		for (long unsigned int i = 0; i < V; i++) {
			std::cout << "Nó " << nodes[i]->index << " \"" << nodes[i]->palavra
			          << "\" de adjacentes: " << std::endl;
			for (long unsigned int j = 0; j < nodes[i]->adj.size(); j++)
				std::cout << "\t" << nodes[i]->adj[j]->palavra << std::endl;
		}
	}

	int insere(std::string palavra) {
		/* Insere a palavra e retorna o número de arestas adicionados ao grafo,
		retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
		if (palavra.size() < k) return -1;
		bool exists = false;
		for (long unsigned int i = 0; i < V && !exists; i++) {
			exists = nodes[i]->palavra == palavra;
		}
		if (exists) return -1;

		// Se não existe, inserimos
		nodes.push_back(new Node(palavra, V));
		V++;

		// Agora vamos criar as novas arestas com todos os nós que seguem as regras estabelecidas no
		// enunciado do projeto
		int new_edges = 0;
		for (long unsigned int i = 0; i < V - 1; i++) {
			// para cada outro nó, vamos verificar cada uma das propriedades:
			std::string s1, s2;
			s1 = palavra;
			s2 = nodes[i]->palavra;
			// 1) remoção/inserção de uma letra

			bool item1 = true;
			if (s1.size() < s2.size()) swap(s1, s2);

			if (s1.size() - s2.size() == 1) {
				bool dif = false;
				for (long unsigned int i = 0; i < s2.size() && item1; i++) {
					if (!dif) {
						if (s1[i] != s2[i]) {
							dif = true;
							i--;
						}
					} else {
						if (s1[i + 1] != s2[i]) { item1 = false; }
					}
				}
			} else
				item1 = false;

			if (item1) {
				new_edges++;
				nodes[i]->adj.push_back(nodes[V - 1]);
				nodes[V - 1]->adj.push_back(nodes[i]);
				continue; // Vai para o próximo nó, não precisamos olhar os outros itens
			}

			// 2) troca de letras de uma mesma palavra
			bool item2 = false;
			if (s1.size() == s2.size()) {
				int num_dif = 0;
				int ind[2];
				for (long unsigned int i = 0; i < s1.size(); i++) {
					if (s1[i] != s2[i]) {
						num_dif++;
						if (num_dif == 3) break;
						ind[num_dif - 1] = i;
					}
				}
				if (num_dif == 2) item2 = (s1[ind[0]] == s2[ind[1]] && s1[ind[1]] == s2[ind[0]]);
			} else
				item2 = false;

			if (item2) {
				new_edges++;
				nodes[i]->adj.push_back(nodes[V - 1]);
				nodes[V - 1]->adj.push_back(nodes[i]);
				continue; // Vai para o próximo nó, não precisamos olhar os outros itens
			}

			// 3) substituição de uma letra
			bool item3 = false;
			if (s1.size() == s2.size()) {
				int num_dif = 0;
				for (long unsigned int i = 0; i < s1.size() && num_dif <= 1; i++)
					if (s1[i] != s2[i]) num_dif++;
				item3 = num_dif <= 1;
			} else
				item3 = false;
			if (item3) {
				new_edges++;
				nodes[i]->adj.push_back(nodes[V - 1]);
				nodes[V - 1]->adj.push_back(nodes[i]);
				continue; // Vai para o próximo nó, não precisamos olhar os outros itens
			}
		}

		E += new_edges;
		return new_edges;
	}

	int vertices() { /* Retorna o número de vértices do grafo*/
		return V;
	}

	int arestas() { /* Retorna o número de vértices do grafo*/
		return E;
	}

	int componentes() { /* Retorna o número de componentes do grafo */
		if (E > (V - 1) * (V - 2) / 2) return 1;

		int num_comp = 0;

		std::vector<bool> listed = std::vector<bool>(V, false);

		for (long unsigned int i = 0; i < V; i++) {
			if (!listed[i]) {
				num_comp++;
				listed[i] = true;
				std::queue<int> q;
				q.push(i);

				int cur;
				while (!q.empty()) {
					cur = q.front();
					q.pop();
					for (Node *u : nodes[cur]->adj) {
						if (!listed[u->index]) {
							listed[u->index] = true;
							q.push(u->index);
						}
					}
				}
			}
		}

		return num_comp;
	}

	bool conexo() { /* Retorna se o grafo é ou não conexo */
		return componentes() == 1;
	}

	int tamComp(std::string palavra) {
		/* Retorna o tamanha da componente conexa onde está a palavra
		ou -1 caso ela não se encontre no grafo */

		int index = -1;
		for (long unsigned int i = 0; i < V && index == -1; i++)
			if (nodes[i]->palavra == palavra) index = i;

		if (index == -1) return -1;

		int tam_comp = 0;
		std::vector<bool> listed = std::vector<bool>(V, false);
		listed[index] = true;
		std::queue<int> q;
		q.push(index);

		int cur;
		while (!q.empty()) {
			tam_comp++;
			cur = q.front();
			q.pop();
			for (Node *u : nodes[cur]->adj) {
				if (!listed[u->index]) {
					listed[u->index] = true;
					q.push(u->index);
				}
			}
		}

		return tam_comp;
	}

	int dist(std::string a, std::string b) {
		/* Retorna a menor distância entre as palavras a e b ou -1
		caso elas estejam desconexas ou não estejam no grafo */

		int indA, indB;
		indA = indB = -1;
		for (long unsigned int i = 0; i < V && (indA == -1 || indB == -1); i++) {
			if (nodes[i]->palavra == a) indA = i;
			if (nodes[i]->palavra == b) indB = i;
		}

		if (indA == -1 || indB == -1) return -1;

		std::vector<bool> listed = std::vector<bool>(V, false);
		std::vector<int> dist = std::vector<int>(V, -1);
		listed[indA] = true;
		dist[indA] = 0;
		std::queue<int> q;
		q.push(indA);

		int cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (nodes[cur]->palavra == b) return dist[cur];
			for (Node *u : nodes[cur]->adj) {
				if (!listed[u->index]) {
					listed[u->index] = true;
					dist[u->index] = dist[cur] + 1;
					q.push(u->index);
				}
			}
		}

		return -1;
	}

	bool bfs1(std::vector<int> &dist, int pai, int cur) {
		dist[cur] = dist[pai] + 1;
		for (Node *u : nodes[cur]->adj) {
			if (dist[u->index] == 0 && dist[cur] > 1) return false;
			if (dist[u->index] == -1 && bfs1(dist, cur, u->index) == false) return false;
		}

		return true;
	}
	bool emCiclo(std::string a) {
		/* Retorna verdadeiro caso a palavra esteja em algum ciclo,
		falso caso contrário */

		int index = -1;
		for (long unsigned int i = 0; i < V && index == -1; i++)
			if (nodes[i]->palavra == a) index = i;

		if (index == -1) return false;

		std::vector<int> dist = std::vector<int>(V, -1);
		dist[index] = 0;
		for (Node *u : nodes[index]->adj)
			if (bfs1(dist, index, u->index) == false) return true;

		return false;
	}

	bool bfs2(std::vector<bool> &listed, int pai, int cur, int iA, int iB, bool &found) {
		// debug(cur);
		bool ans = false;
		listed[cur] = true;
		if (cur == iB) found = true;
		for (Node *u : nodes[cur]->adj) {
			if (pai != iA && u->index == iA && found) {
				// std::cout << "true para: " << std::endl;
				// std::cout << "\t";
				// debug(cur);
				return true;
			}
			if (!listed[u->index] && bfs2(listed, cur, u->index, iA, iB, found)) ans = true;
      if (cur == iB) found = false;
		}

		return ans;
	}

	bool emCiclo(std::string a, std::string b) {
		/* Retorna verdadeiro caso exista um ciclo que contenha ambas as palavras,
		falso caso contrário */

		int iA, iB;
		iA = iB = -1;
		for (long unsigned int i = 0; i < V && (iA == -1 || iB == -1); i++) {
			if (nodes[i]->palavra == a) iA = i;
			if (nodes[i]->palavra == b) iB = i;
		}

		if (iA == -1 || iB == -1) return false;

		std::vector<bool> listed = std::vector<bool>(V, false);
		// debug(iA);
		// debug(iB);
		listed[iA] = true;
		bool found;
		for (Node *n : nodes[iA]->adj) {
			found = false;
			if (bfs2(listed, iA, n->index, iA, iB, found)) return true;
			// std::cout << "voltando" << std::endl;
		}

		return false;
	}
};
