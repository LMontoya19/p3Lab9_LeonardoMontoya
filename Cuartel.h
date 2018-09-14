#ifndef CUARTEL_H
#define CUARTEL_H
#include "Edificio.h"
#include <string>
using std::string;
    class Cuartel:public Edificio{
            public:
                Cuartel();
                virtual string toString();
    };
#endif