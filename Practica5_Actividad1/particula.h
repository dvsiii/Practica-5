#ifndef PARTICULA_H
#define PARTICULA_H
#include <string>
using namespace std;
class particula
{
    float posicion[2];
    float velocidad[2];
    float masa;
    float radio;
public:
    particula();
    float geometria(float radio);
    void movimiento(float tiempo, float gravedad);
    void agregarparticula(float px, float py, float vx, float vy, float m, float r);
    void setposicion(float x, float y);
    void setvelocidad(float x, float y);
    void setmasa(float masa);
    void setradio(float radio);
    float getposicionx();
    float getposiciony();
    float getvx();
    float getvy();
    float getm();
    float getr();
};

#endif // PARTICULA_H
