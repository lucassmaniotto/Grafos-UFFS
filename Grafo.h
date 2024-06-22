#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Grafo {
public:
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
    void imprime_graus();
    bool caminho_restrito(int x, int y, int w, int z, int marcado[]);
    bool eh_clique(std::vector<int> vertices);
    Grafo inverterArestas();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;

    void valida_vertice(int v);
    void valida_peso(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
