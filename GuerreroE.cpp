#include "GuerreroE.h"

GuerreroE::GuerreroE(string psexo):Tropa(psexo,150,90,22,40,35,5,3,"Guerrero Especial"){

}
void GuerreroE::Ataque(Tropa* enemigo){
    int dano = ataque*(1+velocidad/5)+ enemigo->getVida()*0.15;
    enemigo->setVida(enemigo->getVida()-dano);
}