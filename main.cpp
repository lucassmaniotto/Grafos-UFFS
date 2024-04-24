#include "Aresta.h"
#include "Grafo.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void entrada(Grafo& grafo, char operacao, vector<int>& param) {
    switch(operacao) {
        case 'I': {
            int x = param[0];
            int y = param[1];
            Aresta aresta(x, y);
            grafo.insere_aresta(aresta);
            break;
        }
        case 'R': {
            int x = param[0];
            int y = param[1];
            Aresta aresta(x, y);
            grafo.remove_aresta(aresta);
            break;
        }
        case 'E': {
            cout << grafo.num_arestas() << endl;
            break;
        }
        case 'Q': {
            vector<int> vertices(param.begin() + 1, param.end());
            bool eh_clique = grafo.eh_clique(vertices);
            cout << (eh_clique ? "SIM" : "NAO") << endl;
            break;
        }
        case 'C': {
            int x = param[0];
            int y = param[1];
            int w = param[2];
            int z = param[3];
            vector<int> marcado(grafo.num_vertices(), 0);
            bool caminho = grafo.caminho_restrito(x, y, w, z, marcado.data());
            cout << (caminho ? "SIM" : "NAO") << endl;
            break;
        }
        case 'P': {
            grafo.imprime_graus();
            break;
        }
        case 'G': {
            grafo.imprime_graus();
            break;
        }
        default:
            break;
    }
}

int main() {
    int V, O;
    cin >> V >> O;
    Grafo grafo(V);

    cin.ignore();

    for(int i = 0; i < O; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        char operacao;
        ss >> operacao;

        vector<int> params;
        int param;
        while(ss >> param) {
            params.push_back(param);
        }

        entrada(grafo, operacao, params);
    }

    return 0;
}
