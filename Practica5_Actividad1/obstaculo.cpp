#include "obstaculo.h"

obstaculo::obstaculo() {
    lado=0;
    posicion[0]=0;
    posicion[1]=0;
}
float obstaculo::getposicionx(){
    return posicion[0];
}
float obstaculo::getposiciony(){
    return posicion[1];
}
float obstaculo::getlado(){
    return lado;
}
void obstaculo::setlado(float l){
    lado=l;
}
void obstaculo::setposicion(float x, float y){
    posicion[0]=x;
    posicion[1]=y;
}