#include "Aresta.h"
#include "Grafo.h"
#include "Filapri_min.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <limits.h>


using namespace std;

int main() {
    Grafo grafo(4);

    // teste.insere(0, 4);

    //insere, remove, vazia e dimini_prio

    Aresta e1(0, 3, 4);
    Aresta e2(1, 0, 6);
    Aresta e3(1, 3, 2);
    Aresta e4(2, 0, 2);
    Aresta e5(3, 2, 3);

    grafo.insere_aresta(e1);
    grafo.insere_aresta(e2);
    grafo.insere_aresta(e3);
    grafo.insere_aresta(e4);
    grafo.insere_aresta(e5);

    grafo.imprime();

    vector<int> dp, pai;

    Grafo g = grafo.inverterArestas();

    g.Dijkstra(0, pai, dp);

    cout << "Vetor pai:" << endl;
    for (int i = 0; i < pai.size(); ++i) {
        cout << pai[i] << " ";
    }
    cout << endl;

    cout << "Vetor dp:" << endl;
    for (int i = 0; i < dp.size(); ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;


    cout << endl;

    return 0;
}
