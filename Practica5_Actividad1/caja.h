#ifndef CAJA_H
#define CAJA_H
#include "particula.h"
#include "obstaculo.h"
#include <vector>
#include <array>
#include <fstream>
using namespace std;
class caja
{
    float lado;
    float base;
    array<obstaculo,4> obstaclo;
    vector<particula> particla;
public:
    caja();
    void setdimensiones(float b, float l);
    vector<particula> getparticula();
    void agregarparticula(particula p);
    void tiempo(float dt,float tActual,ofstream &archivo);
    void agregarovstaculo(obstaculo o, int indice);
};

#endif // CAJA_H
