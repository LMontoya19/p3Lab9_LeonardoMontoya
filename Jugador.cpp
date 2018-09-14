#include "Jugador.h"

Jugador::Jugador(){
    nombre = "Jugador";
}
Jugador::Jugador(string pnombre,Civilizacion* pcivil){
    nombre = pnombre;
    civilizacion = pcivil;
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
