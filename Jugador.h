#ifndef JUGADOR_H
#define JUGADOR_H
#include "Civilizacion.h"
#include <string>
using std::string;
    class Jugador{
        private:
            string nombre;
            Civilizacion* civilizacion;
        public:
            Jugador();
            Jugador(string,Civilizacion*);
            string getNombre();
            void setNombre(string);
            void setCivilizacion(Civilizacion*);
            Civilizacion* getCivilizacion();
            ~Jugador();
    };
#endif