/* Esse arquivo contém a função main
 */

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

	cout << "Dist ato rolar " << g.dist("ato", "rolar") << endl;
	cout << "Dist ato olhar " << g.dist("ato", "olhar") << endl;
	for (long unsigned int i = 0; i < g.vertices(); i++) {
		cout << "ciclo " << g.nodes[i]->palavra << " " << g.emCiclo(g.nodes[i]->palavra) << endl;
	}
}

int main(int argc, char *argv[]) { return 0; }
