#include "particula.h"

particula::particula() {
    posicion[0]=0;
    posicion[1]=0;
    velocidad[0]=0;
    velocidad[1]=0;
    masa=0;
    radio=0;
}
float particula::getposicionx(){
    return posicion[0];
}
float particula::getposiciony(){
    return posicion[1];
}
float particula::getvx(){
    return velocidad[0];
}
float particula::getvy(){
    return velocidad[1];
}
float particula::getm(){
    return masa;
}
float particula::getr(){
    return radio;
}
void particula::movimiento(float tiempo, float gravedad){
    float x =posicion[0]+velocidad[0]*tiempo;
    float y =posicion[1]+velocidad[1]*tiempo-0.5*gravedad*(tiempo*tiempo);
    posicion[0]=x;
    posicion[1]=y;
}
void particula::setposicion(float x, float y){
    posicion[0]=x;
    posicion[1]=y;
}
void particula::setvelocidad(float x, float y){
    velocidad[0]=x;
    velocidad[1]=y;
}
void particula::setmasa(float masas){
    masa=masas;
}
void particula::setradio(float r){
    radio=r;
}
void particula::agregarparticula(float px, float py, float vx, float vy, float m, float r){
    setposicion(px,py);
    setvelocidad(vx,vy);
    setmasa(m);
    setradio(r);
}