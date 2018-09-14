#ifndef CABALLERIA_H
#define CABALLERIA_H
#include "Tropa.h"
#include <string>
using std::string;
    class Caballeria:public Tropa{
        public:
            Caballeria(string);
            virtual void Ataque(Tropa*);
    };
#endif