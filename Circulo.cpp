#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {

    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int num_vertices): o numero de vertices " +
            to_string(num_vertices) + " eh invalido!"));
    }

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0 );
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas(){
    return num_arestas_;
}