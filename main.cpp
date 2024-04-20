#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {
        Grafo grafo(6);

        //cout << grafo.num_arestas() << endl;
        grafo.insere_aresta(Aresta(0,1));
        //grafo.insere_aresta(Aresta(1,0));
        grafo.insere_aresta(Aresta(0,2));
        grafo.insere_aresta(Aresta(0,4));
        grafo.insere_aresta(Aresta(1,3));
        grafo.insere_aresta(Aresta(1,4));
        grafo.insere_aresta(Aresta(2,4));
        grafo.insere_aresta(Aresta(3,4));
        grafo.insere_aresta(Aresta(3,5));
        //cout << grafo.num_arestas() << endl;
        grafo.imprime();
        //grafo.imprime_graus();

        int marcado[grafo.num_vertices()] = {0};
        grafo.caminho_restrito(0,4,0, marcado);

    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
