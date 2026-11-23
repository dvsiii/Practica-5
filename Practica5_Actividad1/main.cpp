#include <iostream>
#include <fstream>
#include "caja.h"
using namespace std;
int main() {
    caja miCaja;
    miCaja.setdimensiones(100, 100);
    obstaculo o1, o2, o3, o4;
    o1.setposicion(20, 20); o1.setlado(10); o1.sete(0.8);
    o2.setposicion(60, 20); o2.setlado(10); o2.sete(0.8);
    o3.setposicion(20, 60); o3.setlado(10); o3.sete(0.8);
    o4.setposicion(60, 60); o4.setlado(10); o4.sete(0.8);
    particula p1, p2, p3, p4;
    p1.agregarparticula(10, 80,  15,  5, 2, 2);
    p2.agregarparticula(90, 80, -18,  2, 3, 2.5);
    p3.agregarparticula(45, 90,   8, -5, 1.5, 2);
    p4.agregarparticula(50, 45, -12, 14, 2.5, 2);
    miCaja.agregarparticula(p1);
    miCaja.agregarparticula(p2);
    miCaja.agregarparticula(p3);
    miCaja.agregarparticula(p4);
    miCaja.agregarovstaculo(o1, 0);
    miCaja.agregarovstaculo(o2, 1);
    miCaja.agregarovstaculo(o3, 2);
    miCaja.agregarovstaculo(o4, 3);
    ofstream archivo("simulacion.txt");
    if (!archivo.is_open()) {
        cout << "Error al crear el archivo." << endl;
        return 1;
    }
    archivo<< "Tiempo\tEvento\tID\tX\tY\n";
    float dt=0.01;
    float tiempoTotal=10;
    for (float t=0;t<=tiempoTotal;t+=dt) {
        miCaja.tiempo(dt,t,archivo);
        vector<particula> lista=miCaja.getparticula();
        for (int i=0;i<lista.size();i++){
            archivo<<t<<"\tPOS\t"<<i<<"\t"<<lista[i].getposicionx()<<"\t"<<lista[i].getposiciony()<<"\n";
        }
    }
    cout<<"Simulacion terminada. Datos guardados en simulacion.txt"<<endl;
    return 0;
}