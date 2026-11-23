#include "caja.h"

caja::caja() {
    base=0;
    lado=0;
}
vector<particula> caja::getparticula(){
    return particla;
}
void caja::setdimensiones(float b,float l){
    base=b;
    lado=l;
}
void caja::tiempo(float dt,float tActual,ofstream &archivo){
    for(int i=0;i<particla.size();i++){
        particla[i].movimiento(dt, 9.81);
        float px=particla[i].getposicionx();
        float py=particla[i].getposiciony();
        float r=particla[i].getr();
        float vx=particla[i].getvx();
        float vy=particla[i].getvy();
        if(px+r>=base){
            px=base-r;
            particla[i].setposicion(px,py);
            if(vx>0){
                vx=-vx;
                particla[i].setvelocidad(vx,vy);
                archivo<<tActual<<"\tCOLISION_PARED_DER\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
            }
        }
        if(px-r<=0){
            px=r;
            particla[i].setposicion(px,py);
            if(vx<0){
                vx=-vx;
                particla[i].setvelocidad(vx,vy);
                archivo<<tActual<<"\tCOLISION_PARED_IZQ\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
            }
        }
        if(py+r>=lado){
            py=lado-r;
            particla[i].setposicion(px,py);
            if(vy>0){
                vy=-vy;
                particla[i].setvelocidad(vx,vy);
                archivo<<tActual<<"\tCOLISION_TECHO\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
            }
        }
        if(py-r<=0){
            py=r;
            particla[i].setposicion(px,py);
            if(vy<0){
                vy=-vy;
                particla[i].setvelocidad(vx,vy);
                archivo<<tActual<<"\tCOLISION_PISO\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
            }
        }
        for(int j=0;j<obstaclo.size();j++){
            float obs_izq=obstaclo[j].getposicionx();
            float obs_der=obstaclo[j].getposicionx()+obstaclo[j].getlado();
            float obs_abajo=obstaclo[j].getposiciony();
            float obs_arriba=obstaclo[j].getposiciony()+obstaclo[j].getlado();
            float e=obstaclo[j].gete();

            if(py>=obs_abajo&&py<=obs_arriba){
                if(px+r>=obs_izq&&px<obs_izq&&vx>0){
                    px=obs_izq-r;
                    vx=vx*-e;
                    particla[i].setposicion(px,py);
                    particla[i].setvelocidad(vx,vy);
                    archivo<<tActual<<"\tCOLISION_OBS_"<<j<<"_IZQ\t"<<i<<"\t"<<px<<"\t"<< py<<"\n";
                }
                else if(px-r<=obs_der&&px>obs_der&&vx<0){
                    px=obs_der+r;
                    vx=vx*-e;
                    particla[i].setposicion(px,py);
                    particla[i].setvelocidad(vx,vy);
                    archivo<<tActual<<"\tCOLISION_OBS_"<<j<<"_DER\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
                }
            }
            if(px>=obs_izq&&px<=obs_der){
                if(py+r>=obs_abajo&&py<obs_abajo&&vy>0){
                    py=obs_abajo-r;
                    vy=vy*-e;
                    particla[i].setposicion(px,py);
                    particla[i].setvelocidad(vx,vy);
                    archivo<<tActual<<"\tCOLISION_OBS_"<<j<<"_ABAJO\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
                }
                else if(py-r<=obs_arriba&&py>obs_arriba&&vy<0){
                    py=obs_arriba+r;
                    vy=vy*-e;
                    particla[i].setposicion(px,py);
                    particla[i].setvelocidad(vx,vy);
                    archivo<<tActual<<"\tCOLISION_OBS_"<<j<<"_ARRIBA\t"<<i<<"\t"<<px<<"\t"<<py<<"\n";
                }
            }
        }
    }
    for(int i=0;i<particla.size();i++){
        for(int k=i+1;k<particla.size();k++){
            float dx=particla[k].getposicionx()-particla[i].getposicionx();
            float dy=particla[k].getposiciony()-particla[i].getposiciony();
            float distanciaCuadrada=(dx * dx)+(dy * dy);
            float sumaRadios=particla[i].getr()+particla[k].getr();
            float sumaRadiosCuadrada=sumaRadios*sumaRadios;
            if(distanciaCuadrada<=sumaRadiosCuadrada){
                float m1=particla[i].getm();
                float m2=particla[k].getm();
                float masaFinal=m1+m2;
                float nuevaVx=((m1*particla[i].getvx())+(m2*particla[k].getvx()))/masaFinal;
                float nuevaVy=((m1*particla[i].getvy())+(m2*particla[k].getvy()))/masaFinal;
                float xcm=((m1*particla[i].getposicionx())+(m2*particla[k].getposicionx()))/masaFinal;
                float ycm=((m1*particla[i].getposiciony())+(m2*particla[k].getposiciony()))/masaFinal;
                particla[i].setmasa(masaFinal);
                particla[i].setvelocidad(nuevaVx,nuevaVy);
                particla[i].setposicion(xcm,ycm);
                particla[i].setradio(particla[i].getr()+particla[k].getr());
                archivo<<tActual<<"\tCOLISION_PARTICULAS\t"<<i<<"+"<<k<<"\t"<<xcm<<"\t"<<ycm<<"\n";
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