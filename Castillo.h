#ifndef CASTILLO_H
#define CASTILLO_H
#include "Edificio.h"
#include <string>
using std::string;
    class Castillo:public Edificio{
        public:
            Castillo(int,int,int);
            virtual string toString();
    };
#endif