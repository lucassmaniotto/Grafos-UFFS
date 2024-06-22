#ifndef ARESTA_H

#define ARESTA_H

#include <string>

class Aresta {
public:
    const int u;
    const int v;
    const int peso;

    Aresta(int u, int v, int peso);

    std::string to_string();
};

#endif /* ARESTA_H */
