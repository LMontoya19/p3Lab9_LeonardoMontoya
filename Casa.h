#ifndef CASA_H
#define CASA_H
#include "Edificio.h"
    class Casa:public Edificio{
        public:
            Casa();
            Casa(int,int,int);
            virtual string toString();
    };
#endif