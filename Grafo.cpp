#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    lista_adj_.resize(num_vertices);
}


int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (find(lista_adj_[e.v1].begin(), lista_adj_[e.v1].end(), e.v2) != lista_adj_[e.v1].end() ||
        find(lista_adj_[e.v2].begin(), lista_adj_[e.v2].end(), e.v1) != lista_adj_[e.v2].end() ||
        e.v1 == e.v2) 
    {
        return;
    }
    
    lista_adj_[e.v1].push_back(e.v2);
    lista_adj_[e.v2].push_back(e.v1);

    num_arestas_++;
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (find(lista_adj_[e.v1].begin(), lista_adj_[e.v1].end(), e.v2) != lista_adj_[e.v1].end() ||
        find(lista_adj_[e.v2].begin(), lista_adj_[e.v2].end(), e.v1) != lista_adj_[e.v2].end())
    {
        lista_adj_[e.v1].remove(e.v2);
        lista_adj_[e.v2].remove(e.v1);

        num_arestas_--;  
    }
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int i : lista_adj_[v]) {
            cout << " " << i;
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}

void Grafo::imprime_graus(){
    for(int i = 0; i < num_vertices_; i++){
        cout << i <<": " << lista_adj_[i].size() << endl;
    }
}

bool Grafo::caminho_restrito(int v, int w, int x, int z, int marcado[]) {
    if (v == w) {
        return true;
    }
    marcado[v] = 1;
    for (int u : lista_adj_[v]) {
        if ((v != x || u != z) && (v != z || u != x))
            if (marcado[u] == 0) {
                if (caminho_restrito(u, w, x, z, marcado)) {
                    return true;
                }
            }
    }
    return false;
}

bool Grafo::eh_clique(vector<int> vertices) {
    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = i + 1; j < vertices.size(); j++) {
            if (find(lista_adj_[vertices[i]].begin(), lista_adj_[vertices[i]].end(), vertices[j]) == lista_adj_[vertices[i]].end()) {
                return false;
            }
        }
    }
    return true;
}