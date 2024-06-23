#include "Digrafo.h"
#include "Destino.h"
#include "Filapri_min.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

Digrafo::Digrafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    lista_adj_.resize(num_vertices);
}

int Digrafo::num_vertices() {
    return num_vertices_;
}

int Digrafo::num_arestas() {
    return num_arestas_;
}

void Digrafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (find_if(lista_adj_[e.v1].begin(), lista_adj_[e.v1].end(),
                     [&](const Destino &d) { return d.v == e.v2; }) != lista_adj_[e.v1].end() ||
        e.v1 == e.v2) {
        return;
    }

    Destino destino;

    destino.v = e.v2;
    destino.peso = e.peso;

    lista_adj_[e.v1].push_back(destino);

    num_arestas_++;
}

void Digrafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Digrafo::valida_peso(int peso) {
    if (peso < 0) {
        throw out_of_range("Peso invalido: " + to_string(peso));
    }
}

void Digrafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
    valida_peso(e.peso);
}

Digrafo Digrafo::inverterArestas() {
    Digrafo grafo_invertido(num_vertices_);

    for (int v = 0; v < num_vertices_; ++v) {
        for (const Destino &destino : lista_adj_[v]) {
            grafo_invertido.insere_aresta(Aresta(destino.v, v, destino.peso));
        }
    }

    return grafo_invertido;
}

void Digrafo::Dijkstra(int s, vector<int> &pai, vector<int> &dp) {
    pai.resize(num_vertices_, -1);
    dp.resize(num_vertices_, INT_MAX);
    dp[s] = 0;
    Filapri_min<int> fila_prim(num_vertices_);
    for (int i = 0 ; i < num_vertices_; i++) {
        fila_prim.insere(i, dp[i]);
    }
    while (!fila_prim.vazia()) {
        pair<int,int> u = fila_prim.remove();
        if (dp[u.first] != INT_MAX){
            for (const Destino& vizinho : lista_adj_[u.first]){
                if (dp[vizinho.v] > dp[u.first] + vizinho.peso){
                    dp[vizinho.v] = dp[u.first] + vizinho.peso;
                    pai[vizinho.v] = u.first;
                    fila_prim.diminui_prio(vizinho.v, dp[vizinho.v]);
                }
            }
        }
    }
}

void Digrafo::encontraCaminhoViavel(int X, int M) {
    vector<int> dp, pai;
    Dijkstra(X, pai, dp);
    for (int i = 0; i < num_vertices_; i++) {
        if (i != X) {
            if (dp[i] <= M) {
                cout << i << ": " << dp[i] << ", ";
                int j = i;
                while (pai[j] != -1) {
                    cout << j << " ";
                    j = pai[j];
                }
                cout << j << endl;
            } else {
                cout << i << ": economicamente inviavel ate " << X << endl;
            }
        }
    }
}