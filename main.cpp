#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo g(4);
        g.imprime();

        g.insere_aresta(Aresta (0,1));
        g.insere_aresta(Aresta (0,2));

        g.imprime();

        cout << "Arestas: " << g.num_arestas() << "\n\n";

        g.remove_aresta(Aresta(0,1));

        g.imprime();

        cout << "Arestas: " << g.num_arestas() << "\n\n";
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
