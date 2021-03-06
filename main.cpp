/* Esse arquivo contém a função main
 */

#include <fstream>
#include <iostream>

#include "interface.cpp"

using namespace std;

#define TAM_STRINGS 4

string randomWord() {
	string a = "";
	int len = (rand() % TAM_STRINGS) + 1;
	a.resize(len);
	for (int i = 0; i < len; i++) a[i] = (rand() % ('z' - 'a' + 1)) + 'a';
	return a;
}

void test1() {
	Grafo g(3);
	g.insere("alta");
	cout << g.conexo() << endl;
	g.insere("nota");
	g.insere("ata");
	cout << g.conexo() << endl;
	g.insere("ata");
	g.insere("nato");
	g.insere("gato");
	g.insere("rato");
	cout << g.componentes() << endl;
	g.insere("a");
	g.insere("bbb");
	cout << g.componentes() << endl;
	g.imprime();
	cout << endl;
	cout << "Tamanho rato " << g.tamComp("rato") << endl;
	cout << "Tamanho ata " << g.tamComp("ata") << endl;
	cout << "Tamanho alta " << g.tamComp("alta") << endl;
	cout << "Tamanho bbb " << g.tamComp("bbb") << endl;
	cout << "dist alta ata " << g.dist("alta", "ata") << endl;
	cout << "dist nota rato " << g.dist("nota", "rato") << endl;
	cout << "dist alta alta " << g.dist("alta", "alta") << endl;
}

void teste2() {
	Grafo g(3);
	g.insere("rolar");
	g.insere("olhar");
	g.insere("rota");
	g.insere("rolo");
	g.insere("olho");
	g.insere("olha");
	g.insere("rota");
	g.insere("rola");
	g.insere("ola");
	g.insere("rato");
	g.insere("gato");
	g.insere("gata");
	g.insere("ata");
	g.insere("ato");
	g.insere("lato");
	g.insere("lata");
	cout << g.conexo() << endl;
	cout << g.componentes() << endl;
	cout << g.tamComp("lata") << endl;
	g.imprime();

	for (int i = 0; i < g.vertices(); i++)
		cout << "ciclo " << g.nodes[i]->palavra << " " << g.emCiclo(g.nodes[i]->palavra) << endl;

	cout << "ciclo rato lato " << g.emCiclo("rato", "lato") << endl;
	cout << "ciclo lata olhar " << g.emCiclo("lata", "olhar") << endl;
	cout << "ciclo bbb lata " << g.emCiclo("bbb", "lata") << endl;
	cout << "ciclo rato ato " << g.emCiclo("rato", "ato") << endl;

	g.insere("abobora");
	g.insere("aboborar");
	cout << "ciclo abobora aboborar " << g.emCiclo("abobora", "aboborar") << endl;

	cout << "ciclo lato rato " << g.emCiclo("lato", "rato") << endl;
	cout << "ciclo olhar lata " << g.emCiclo("olhar", "lata") << endl;
	cout << "ciclo lata bbb " << g.emCiclo("lata", "bbb") << endl;
	cout << "ciclo ato rato " << g.emCiclo("ato", "rato") << endl;
	cout << "ciclo bbb bbb " << g.emCiclo("bbb", "bbb") << endl;
	cout << "ciclo lata lata " << g.emCiclo("lata", "lata") << endl;
	cout << "ciclo olha rolar " << g.emCiclo("olha", "rolar") << endl;
}

void mostreUso(string prog) {
	cout << "Modo de usar: " << endl;
	cout << prog << " k arquivo" << endl;
	cout << "\nOnde <k> é o tamanho mínimo das palavras e\n<arquivo> é o caminho de um"
	        " arquivo de texto para o programa carregar."
	     << endl;
	cout << "Se <arquivo> nao for informado, entao um grafo vazio sera criado." << endl;
}

void testeIterativo(Grafo &grafo) {
	string cmd, s1, s2;
	cout << "\nPossiveis operacoes do teste interativo:\n";
	cout << "(I)NSERT <palavra>\n(V)ERTICES\n(A)RESTAS\n(G)RAU "
	        "<palavra>\nGRAUMEDIO\nDENSIDADE\nNUMCOMPS\nINFOCOMPS\nTAMCOMP <palavra>\n(C)AMINHO "
	        "<palavra1> <palavra2>\n(D)IST <palavra1> <palavra2>\nCICLO1 "
	        "<palavra>\nCICLO2 <palavra1> <palavra2>\nINFOGERAL\n(P)RINT\n(H)ELP\n";
	cout << "EXIT para encerrar." << endl;
	cout << ">>> ";

	while (cin >> cmd) {
		// to lower
		for (string::iterator it = cmd.begin(); it < cmd.end(); it++)
			if ('A' <= *it && *it <= 'Z') *it = *it - 'A' + 'a';
		if (cmd == "exit") {
			system("clear");
			cout << "Obrigado pela preferência." << endl;
			break;
		} else if (cmd == "insert" || cmd == "i") {
			cin >> s1;
			grafo.insere(s1);
			cout << "Inserido " << s1 << endl;
		} else if (cmd == "vertices" || cmd == "v") {
			cout << "Vertices = " << grafo.vertices() << endl;
		} else if (cmd == "arestas" || cmd == "a") {
			cout << "Arestas = " << grafo.arestas() << endl;
		} else if (cmd == "grau" || cmd == "g") {
			cin >> s1;
			int g = grafo.grau(s1);
			if (g == -1)
				cout << s1 << " nao existe no grafo." << endl;
			else
				cout << "O grau de " << s1 << " é " << grafo.grau(s1) << endl;
		} else if (cmd == "graumedio") {
			cout << "O grau médio do grafo é " << grafo.graumedio() << endl;
		} else if (cmd == "densidade") {
			cout << "A densidade do grafo é " << grafo.densidade() << endl;
		} else if (cmd == "numcomps") {
			cout << "O grafo tem " << grafo.componentes() << " componentes." << endl;
		} else if (cmd == "tamcomp") {
			cin >> s1;
			cout << "A componentes da palavra " << s1 << " tem " << grafo.tamComp(s1)
			     << " vertices." << endl;
		} else if (cmd == "infocomps") {
			int numcomps, tammenor, tammaior;
			double tammedio;
			grafo.infoComps(numcomps, tammenor, tammaior, tammedio);
			cout << "Numero de componentes: " << numcomps << endl;
			cout << "Tamanho da menor componente: " << tammenor << endl;
			cout << "Tamanho da maior componente: " << tammaior << endl;
			cout << "Tamanho medio das componentes: " << tammedio << endl;
		} else if (cmd == "caminho" || cmd == "c") {
			cin >> s1 >> s2;
			if (grafo.dist(s1, s2) == -1)
				cout << "Não existe caminho entre " << s1 << " e " << s2 << endl;
			else
				cout << "Existe caminho entre " << s1 << " e " << s2 << endl;
		} else if (cmd == "dist" || cmd == "d") {
			cin >> s1 >> s2;
			int dist = grafo.dist(s1, s2);
			if (dist == -1)
				cout << "Não existe caminho entre " << s1 << " e " << s2 << endl;
			else
				cout << "A distância entre " << s1 << " e " << s2 << " é " << dist << endl;
		} else if (cmd == "ciclo1") {
			cin >> s1;
			if (grafo.emCiclo(s1))
				cout << s1 << " está em algum ciclo." << endl;
			else
				cout << s1 << " não está em nenhum ciclo." << endl;
		} else if (cmd == "ciclo2") {
			cin >> s1 >> s2;
			if (grafo.emCiclo(s1, s2))
				cout << "Existe ciclo contendo " << s1 << " e " << s2 << endl;
			else
				cout << "Não existe ciclo contendo " << s1 << " e " << s2 << endl;
		} else if (cmd == "infogeral" || cmd == "info") {
			int numcomps, tammenor, tammaior;
			double tammedio;
			cout << "Vertices = " << grafo.vertices() << endl;
			cout << "Arestas = " << grafo.arestas() << endl;
			grafo.infoComps(numcomps, tammenor, tammaior, tammedio);
			cout << "Numero de componentes: " << numcomps << endl;
			cout << "Tamanho da menor componente: " << tammenor << endl;
			cout << "Tamanho da maior componente: " << tammaior << endl;
			cout << "Tamanho medio das componentes: " << tammedio << endl;
			cout << "O grau médio do grafo é " << grafo.graumedio() << endl;
			cout << "A densidade do grafo é " << grafo.densidade() << endl;
		} else if (cmd == "print" || cmd == "p") {
			grafo.imprime();
		} else if (cmd == "help" || cmd == "h") {
			cout << "\nPossiveis operacoes do teste interativo:\n";
			cout << "(I)NSERT <palavra>\n(V)ERTICES\n(A)RESTAS\n(G)RAU "
			        "<palavra>\nGRAUMEDIO\nDENSIDADE\nNUMCOMPS\nINFOCOMPS\nTAMCOMP "
			        "<palavra>\n(C)AMINHO "
			        "<palavra1> <palavra2>\n(D)IST <palavra1> <palavra2>\nCICLO1 "
			        "<palavra>\nCICLO2 <palavra1> "
			        "<palavra2>\nINFOGERAL\n(P)RINT\n(H)ELP\n";
			cout << "EXIT para encerrar." << endl;
		} else
			cout << "Esse comando não existe!" << endl;
		cout << ">>> ";
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3 && argc != 2) {
		mostreUso(argv[0]);
		return 0;
	}

	Grafo grafo(atoi(argv[1]));
	if (argc == 3) {
		fstream arqTexto;
		arqTexto.open(argv[2]);
		if (arqTexto.fail()) {
			cout << "ERRO: arquivo" << argv[1] << "nao pode ser aberto." << endl;
			exit(EXIT_FAILURE);
		}

		clock_t start, end;
		string s;
		string especiais = ".\"!-:,_'’—?)(;*#1234567890$@%&*[]+/ ";
		int i = 1;
		start = clock();
		while (arqTexto >> s) {
			// Tratando a palavra (deixando ela minúscula e retirando caracteres especiais)
			// Infelizmente, não achei forma de tornar caracteres acentuados em minúsculos
			for (string::iterator it = s.begin(); it < s.end(); it++) {
				if ('A' <= *it && *it <= 'Z') *it = *it - 'A' + 'a';
				for (long unsigned int j = 0; j < especiais.size(); j++)
					if (*it == especiais[j] || !isascii(*it)) s.erase(it);
			}
			if (s.size() == 0) continue;

			cout << "Carregando palavras para o grafo...\t" << i++ << '\n';
			grafo.insere(s);
		}
		end = clock();
		cout << "Grafo criado com sucesso em " << (((double)(end - start)) / CLOCKS_PER_SEC)
		     << " segundos" << endl;
	} else {
		cout << "Grafo vazio criado com sucesso." << endl;
	}

	testeIterativo(grafo);

	return 0;
}
