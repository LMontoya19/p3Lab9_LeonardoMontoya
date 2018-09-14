#include "Casa.h"
#include <string>
using std::string;

Casa::Casa(int poro,int pmadera,int ppiedra):Edificio(poro,pmadera,ppiedra){
}
Casa::Casa():Edificio(0,55,0){

}
string Casa::toString(){
    return "Casa";
}