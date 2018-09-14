#include "Jugador.h"

Jugador::Jugador(){
    nombre = "Jugador";
}
Jugador::Jugador(string pnombre,Civilizacion* pcivil){
    nombre = pnombre;
    civilizacion = new Civilizacion(pcivil->getOro(),pcivil->getMadera(),pcivil->getPiedra(),200,pcivil->getMaxpoblacion(),5,pcivil->getNombre());

}

void Jugador::setNombre(string pnombre){
    nombre = pnombre;
}
string Jugador::getNombre(){
    return nombre;
}
void Jugador::setCivilizacion(Civilizacion* pcivil){
    civilizacion = pcivil;
}
Civilizacion* Jugador::getCivilizacion(){
    return civilizacion;
}
Jugador::~Jugador(){
    
}
