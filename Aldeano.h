#ifndef ALDEANO_H
#define ALDEANO_H
#include <string>
using std::string;
    class Aldeano{
        private:
            string sexo;
            int costo;
        public:
            Aldeano();
            Aldeano(string,int);
            void setSexo(string);
            void setCosto(int);
            string getSexo();
            int getCosto();

    };
#endif