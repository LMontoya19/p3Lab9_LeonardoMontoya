#include "Aldeano.h"
#include <string>
using std::string;
Aldeano::Aldeano(){
    sexo = "asaber";
    costo = 0;
}
Aldeano::Aldeano(string psexo,int pcosto){
    sexo = psexo;
    costo = pcosto;
}
void Aldeano::setCosto(int pcosto){
    costo = pcosto;
}
void Aldeano::setSexo(string psexo){
    sexo = psexo;
}
int Aldeano::getCosto(){
    return costo;
}
string Aldeano::getSexo(){
    return sexo;
}
