#include "Caballeria.h"

Caballeria::Caballeria(string psexo):Tropa(psexo,110,60,17,30,30,5,2,"Caballeria"){
    
}

void Caballeria::Ataque(Tropa* enemigo){
    int dano;
    dano = (ataque+velocidad)/2;
    enemigo->setVida(enemigo->getVida()-dano);
}