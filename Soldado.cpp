#include "Soldado.h"

Soldado::Soldado(string psexo):Tropa(psexo,90,25,10,20,15,5,1,"Soldado"){

}

void Soldado::Ataque(Tropa& enemigo){
    enemigo.setVida(enemigo.getVida()-ataque);
}