#include "Edificio.h"

Edificio::Edificio(){
    coro = 0;
    costoMadera = 0;
    costoPiedra = 0;
}
Edificio::Edificio(int poro,int pmadera,int ppiedra){
    coro = poro;
    costoMadera = pmadera;
    costoPiedra = ppiedra;
}
int Edificio::getOro(){
    return coro;
}
int Edificio::getCostoPiedra(){
    return costoPiedra;
}
int Edificio::getCostoMadera(){
    return costoMadera;
}
