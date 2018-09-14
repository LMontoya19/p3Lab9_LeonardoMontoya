#ifndef TROPA_H
#define TROPA_H
#include <string>
using std::string;
    class Tropa{
        protected:
            string tipo;
            string sexo;
            int costoalimentacion;
            int costoOro;
            int ataque;
            int defensa;
            int vida;
            int velocidad;
            int tiempoentrenamineto;
            bool listo;
        public:
            virtual void Ataque(Tropa&)=0;
            Tropa(string,int,int,int,int,int,int,int,string);
            int getAtaque();
            int getVida();
            int getTiempo();
            int getCosto();
            int getAlimentacion();
            int getDefensa();
            void setVida(int);
            void Entrenar();
            string getTipo();
            bool getListo();

    };
#endif