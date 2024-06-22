#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>
#include <tuple>

class Grafo {
public:
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    void insere_aresta(Aresta e);
    //void imprime();
    //Grafo inverterArestas();
private:
    int num_vertices_;
    int num_arestas_;

    std::vector<std::list<std::tuple<int, int>>> lista_adj_;

    void valida_vertice(int v);
    void valida_peso(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
