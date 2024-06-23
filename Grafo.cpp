#include "Grafo.h"
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

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (const Destino &destino : lista_adj_[v]) {
            cout << " " << destino.v;
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_peso(int peso) {
    if (peso < 0) {
        throw out_of_range("Peso invalido: " + to_string(peso));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
    valida_peso(e.peso);
}

Grafo Grafo::inverterArestas() {
    Grafo grafo_invertido(num_vertices_);

    for (int v = 0; v < num_vertices_; ++v) {
        for (const Destino &destino : lista_adj_[v]) {
            grafo_invertido.insere_aresta(Aresta(destino.v, v, destino.peso));
        }
    }

    return grafo_invertido;
}

void Grafo::Dijkstra(int s, vector<int> &pai, vector<int> &dp){
    pai.resize(num_vertices_, -1);
    dp.resize(num_vertices_, INT_MAX);
    dp[s] = 0;
    Filapri_min<int> fila_prim(num_vertices_);
    for (int i = 0 ; i < num_vertices_; i++){
        fila_prim.insere(i, dp[i]);
    }
    while (!fila_prim.vazia())
    {
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