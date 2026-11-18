#include "caja.h"

caja::caja() {}
void caja::tiempo(float dt){
    for(int i=0;i<particla.size();i++){
        particla[i].movimiento(dt,9.81);
        if(particla[i].getposicionx()+particla[i].getr()>= base){
            particla[i].setvelocidad(particla[i].getvx()*-1,particla[i].getvy());
        }
        if(particla[i].getposicionx()-particla[i].getr()<= 0){
            particla[i].setvelocidad(particla[i].getvx()*-1,particla[i].getvy());
        }
        if(particla[i].getposiciony()+particla[i].getr()>=lado) {
            particla[i].setvelocidad(particla[i].getvx(),particla[i].getvy()*-1);
        }
        if(particla[i].getposiciony()-particla[i].getr()<= 0) {
            particla[i].setvelocidad(particla[i].getvx(),particla[i].getvy()*-1);
        }
        float px=particla[i].getposicionx();
        float py=particla[i].getposiciony();
        float r=particla[i].getr();
        float vx=particla[i].getvx();
        float vy=particla[i].getvy();
        for(int j=0;j<obstaclo.size(); j++){
            float obs_izq=obstaclo[j].getposicionx();
            float obs_der=obstaclo[j].getposicionx()+obstaclo[j].getlado();
            float obs_abajo=obstaclo[j].getposiciony();
            float obs_arriba=obstaclo[j].getposiciony()+obstaclo[j].getlado();
            float e=obstaclo[j].gete();
            if(py>=obs_abajo&&py<=obs_arriba){
                if(px+r>=obs_izq&&px<obs_izq){
                    particla[i].setvelocidad(vx*-e,vy);
                }
                else if(px-r<=obs_der&&px>obs_der){
                    particla[i].setvelocidad(vx*-e,vy);
                }
            }
            if(px>=obs_izq&&px<=obs_der){
                if(py+r>=obs_abajo&&py<obs_abajo){
                    particla[i].setvelocidad(vx,vy*-e);
                }
                else if(py-r<=obs_arriba&&py>obs_arriba){
                    particla[i].setvelocidad(vx,vy*-e);
                }
            }
        }
        for (int k=i+1;k<particla.size();k++){
            float dx=particla[k].getposicionx()-particla[i].getposicionx();
            float dy=particla[k].getposiciony()-particla[i].getposiciony();
            float distanciaCuadrada=(dx*dx)+(dy*dy);
            float sumaRadios=particla[i].getr()+particla[k].getr();
            float sumaRadiosCuadrada=sumaRadios*sumaRadios;
            if(distanciaCuadrada<=sumaRadiosCuadrada){
                float m1=particla[i].getm();
                float m2=particla[k].getm();
                float v1x=particla[i].getvx();
                float v1y=particla[i].getvy();
                float v2x=particla[k].getvx();
                float v2y=particla[k].getvy();
                float masaFinal=m1+m2;
                float nuevaVx=((m1*v1x)+(m2 * v2x))/masaFinal;
                float nuevaVy=((m1*v1y)+(m2*v2y))/masaFinal;
                particla[i].setmasa(masaFinal);
                particla[i].setvelocidad(nuevaVx,nuevaVy);
                particla[i].setradio(particla[i].getr()+particla[k].getr());
                particla.erase(particla.begin()+k);
                k--;
            }
        }
    }
}
void caja::agregarparticula(particula p){
    particla.push_back(p);
}
void caja::agregarovstaculo(obstaculo o, int indice){
    obstaclo[indice]=o;
}