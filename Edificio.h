#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>
using std::string;
    class Edificio{
        private:
            int coro,costoMadera,costoPiedra;
        public:
            Edificio();
            Edificio(int,int,int);
            int getCostoMadera();
            int getCostoPiedra();
            int getOro();
            virtual string toString()=0;
    };
#endif