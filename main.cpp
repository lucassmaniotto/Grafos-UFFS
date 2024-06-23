#include "Aresta.h"
#include "Grafo.h"
#include "Filapri_min.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <limits.h>

using namespace std;

int main() {
    int v, a;
    cin >> v >> a;
    Grafo grafo(v);

    cin.ignore();

    for (int i = 0; i < a; i++) {
        string linha;
        getline(cin, linha);
        stringstream ss(linha);

        int v1, v2, peso;
        ss >> v1 >> v2 >> peso;

        Aresta aresta(v1, v2, peso);
        grafo.insere_aresta(aresta);
    }
    
    Grafo grafoInverido = grafo.inverterArestas();

    int vezes, X, M;

    cin >> vezes;

    for (int i = 0; i < vezes; i++) {
        cin >> X >> M;
        grafoInverido.encontraCaminhoViavel(X, M);
    }

    return 0;
}
