#ifndef OBSTACULO_H
#define OBSTACULO_H

class obstaculo
{
    float lado;
    float posicion[2];
    float e;
public:
    obstaculo();
    void setlado(float l);
    void setposicion(float x, float y);
    void sete(float k);
    float gete();
    float getlado();
    float getposicionx();
    float getposiciony();
};

#endif // OBSTACULO_H
