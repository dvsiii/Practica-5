#ifndef CAJA_H
#define CAJA_H
#include "particula.h"
#include "obstaculo.h"
#include <vector>
using namespace std;
class caja
{
    float lado;
    float base;
    obstaculo obstaculo[4];
    vector<particula> particula;
public:
    caja();
};

#endif // CAJA_H
