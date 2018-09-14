#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <vector>
#include<string>
using std::string;
using std::vector;
#include "Tropa.h"
#include "Edificio.h"
#include "Aldeano.h"

    class Civilizacion{
        private:
            string nombre;
            int oro,madera,piedra,alimento,maxpoblacion,poblacionactual;
            vector<Tropa*> tropas;
            vector<Edificio*>edificios;
            vector<Aldeano*>aldeanos;
        public:
        
            Civilizacion();
            Civilizacion(int,int,int,int,int,int,string);
            int getOro();
            int getMadera();
            int getPiedra();
            int getAlimento();
            int getMaxpoblacion();
            int getPoblacionactual();
            void setMaxpoblacion(int);
            void setPoblacion(int);
            void setMadera(int);
            void setPiedra(int);
            void setOro(int);
            string getNombre();
            vector<Aldeano*>& getAldeanos();
            vector<Tropa*>& getTropas();
            vector<Edificio*>& getEdificios();
            ~Civilizacion();
            void setAlimentos(int);
            
    };
#endif