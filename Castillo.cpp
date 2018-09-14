#include "Castillo.h"
#include <string>
using std::string;

Castillo::Castillo(int oro,int madera,int piedra):Edificio(oro,madera,piedra){

}
string Castillo::toString(){
    return "Castillo";
}