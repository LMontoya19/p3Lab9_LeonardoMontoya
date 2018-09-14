#include "Civilizacion.h"

Civilizacion::Civilizacion(){
    oro=0;
    madera = 0;
    piedra = 0;
    alimento = 0;
    maxpoblacion = 0;
    poblacionactual = 0;
}

Civilizacion::Civilizacion(int poro,int pmadera,int ppiedra,int palimento,int pmaxpoblacion,int ppoblacionactual,string pnombre){
    oro = poro;
    madera = pmadera;
    piedra = ppiedra;
    alimento = palimento;
    maxpoblacion = pmaxpoblacion;
    poblacionactual = ppoblacionactual;
    nombre = pnombre;
}
int Civilizacion::getAlimento(){
    return alimento;
}
int Civilizacion::getMadera(){
    return madera;
}
int Civilizacion::getMaxpoblacion(){
    return maxpoblacion;
}
int Civilizacion::getOro(){
    return oro;
}
int Civilizacion::getPiedra(){
    return piedra;
}
int Civilizacion::getPoblacionactual(){
    return poblacionactual;
}
void Civilizacion::setMaxpoblacion(int pmax){
    maxpoblacion = pmax;
}
void Civilizacion::setPoblacion(int x){
    if(poblacionactual+x<=maxpoblacion){
        poblacionactual+=x;
    }else{
        poblacionactual=maxpoblacion;
    }
}

Civilizacion::~Civilizacion(){
    for(int i = 0;i<tropas.size();i++){
        if(tropas[i]!=NULL){
        delete tropas[i];
        }
        
    }
    /*for(int i =0;i<edificios.size();i++){
        if(edificios[i]!=NULL){
        delete edificios[i];
        }
        
    }*/
    for(int i =0;i<aldeanos.size();i++){
        if(aldeanos[i]!=NULL){
        delete aldeanos[i];}
       
    }
    
}
string Civilizacion::getNombre(){
    return nombre;
}
vector<Aldeano*>& Civilizacion::getAldeanos(){
    return aldeanos;
}
vector<Tropa*>& Civilizacion::getTropas(){
    return tropas;
}
vector<Edificio*>& Civilizacion::getEdificios(){
    return edificios;
}
void Civilizacion::setAlimentos(int x){
    alimento+= x;
}
void Civilizacion::setMadera(int x){
    madera+=x;
}
void Civilizacion::setOro(int x){
    oro+=x;
}
void Civilizacion::setPiedra(int x){
    piedra+=x;
}
