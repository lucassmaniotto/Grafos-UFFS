#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include "Destino.h"
#include <vector>
#include <list>

class Digrafo {
public:
    Digrafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    void insere_aresta(Aresta e);
    Digrafo inverterArestas();
    void Dijkstra(int s, std::vector<int> &pai, std::vector<int> &dp);
    void encontraCaminhoViavel(int X, int M);
private:
    int num_vertices_;
    int num_arestas_;

    std::vector<std::list<Destino>> lista_adj_;

    void valida_vertice(int v);
    void valida_peso(int peso);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
