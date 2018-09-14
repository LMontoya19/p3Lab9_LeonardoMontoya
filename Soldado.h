#ifndef SOLDADO_H
#define SOLDADO_H
#include "Tropa.h"
#include <string>
using std::string;
    class Soldado:public Tropa{
        public:
            Soldado(string);
            virtual void Ataque(Tropa&);
    };
#endif