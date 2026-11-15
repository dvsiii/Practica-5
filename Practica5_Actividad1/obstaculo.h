#ifndef OBSTACULO_H
#define OBSTACULO_H

class obstaculo
{
    float lado;
    float posicion[2];
public:
    obstaculo();
    void setlado(float l);
    void setposicion(float x, float y);
    float getlado();
    float getposicionx();
    float getposiciony();
};

#endif // OBSTACULO_H
