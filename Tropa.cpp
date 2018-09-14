#include "Tropa.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
Tropa::Tropa(string psexo,int pcostoalimentacion,int pcostooro,int pataque,int pdefensa,int pvida,int pvelociad,int ptiempoentrenamiento,string ptipo){
    sexo = psexo;
    costoalimentacion = pcostoalimentacion;
    costoOro = pcostooro;
    ataque = pataque;
    defensa = pdefensa;
    vida = pvida;
    tiempoentrenamineto = ptiempoentrenamiento;
    tipo=ptipo;
    listo = false;
}

int Tropa::getAtaque(){
    return ataque;
}
int Tropa::getAlimentacion(){
    return costoalimentacion;
}
int Tropa::getCosto(){
    return costoOro;
}
int Tropa::getDefensa(){
    return defensa;
}
int Tropa::getTiempo(){
    return tiempoentrenamineto;
}
int Tropa::getVida(){
    return vida;
}
void Tropa::setVida(int pvida){
    vida = pvida;
}
void Tropa::Entrenar(){
    tiempoentrenamineto--;
    if(tiempoentrenamineto==0){
        cout<<tipo<<" ha sido entrenado"<<endl;
        listo=true;
    }
}
string Tropa::getTipo(){
    return tipo;
}
bool Tropa::getListo(){
    return listo;
}