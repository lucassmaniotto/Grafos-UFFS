#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {

    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int num_vertices): o numero de vertices " +
            to_string(num_vertices) + " eh invalido!"));
    }

    listas_adj_.resize(num_vertices);

    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas(){
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if(e.v1 < num_vertices_ && e.v2 < num_vertices_) {
        if(listas_adj_ [e.v1][e.v2])
            return true;
        return false;
    }
}

void Grafo::insere_aresta(Aresta e) {
    if(!tem_aresta(e)) {
        listas_adj_ [e.v1][e.v2] = 1;
        listas_adj_ [e.v2][e.v1] = 1;

        num_arestas_ ++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if(tem_aresta(e)) {
        listas_adj_ [e.v1][e.v2] = 0;
        listas_adj_ [e.v2][e.v1] = 0;

        num_arestas_ --;
    }
}

void Grafo::imprime() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (int j = 0; j < num_vertices_; j++) {
            if(listas_adj_ [i][j] != 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
    cout << "\n";
}