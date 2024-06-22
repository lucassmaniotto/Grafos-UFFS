#include "Aresta.h"
#include "Grafo.h"
#include "Filapri_min.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void Dijkstra(Grafo grafo, int s, vector<int> pai, vector<int> dp){

}



int main() {
    Grafo grafo(5);

    Filapri_min<int> teste(5);

    teste.insere(0, 4);

    //insere, remove, vazia e dimini_prio

    Aresta e1(0, 1, 5);
    Aresta e2(0, 2, 6);
    Aresta e3(0, 3, 7);
    Aresta e4(1, 0, 5);
    Aresta e5(2, 0, 5);

    grafo.insere_aresta(e1);
    grafo.insere_aresta(e2);
    grafo.insere_aresta(e3);
    grafo.insere_aresta(e4);
    grafo.insere_aresta(e5);

    grafo.imprime();

    Grafo g = grafo.inverterArestas();
    g.imprime();
    return 0;
}
