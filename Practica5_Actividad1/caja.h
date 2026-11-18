#ifndef CAJA_H
#define CAJA_H
#include "particula.h"
#include "obstaculo.h"
#include <vector>
#include <array>
using namespace std;
class caja
{
    float lado;
    float base;
    array<obstaculo,4> obstaclo;
    vector<particula> particla;
public:
    caja();
    void agregarparticula(particula p);
    void tiempo(float dt);
    void agregarovstaculo(obstaculo o, int indice);
};

#endif // CAJA_H
