#include "Aresta.h"
#include <string>

Aresta::Aresta(int u, int v, int peso) : u(u), v(v), peso(peso) {
}

std::string Aresta::to_string() {
    return std::to_string(u) + " " + std::to_string(v);
}
