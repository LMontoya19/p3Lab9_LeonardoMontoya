#ifndef GUERREROE_H
#define GUERREROE_H
#include "Tropa.h"
    class GuerreroE:public Tropa{
        public:
            GuerreroE(string);
            virtual void Ataque(Tropa&);
    };
#endif