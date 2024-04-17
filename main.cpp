#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>

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
        Grafo g(5);

        g.insere_aresta(Aresta(0,1));
        g.insere_aresta(Aresta(1,2));
        g.insere_aresta(Aresta(3,4));

        g.eh_conexo();

        Grafo g2(4);

        g2.insere_aresta(Aresta(0,1));
        g2.insere_aresta(Aresta(1,2));
        g2.insere_aresta(Aresta(2,3));

        g2.eh_conexo();
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
