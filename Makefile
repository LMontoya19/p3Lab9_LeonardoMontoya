main:	Aldeano.o Caballeria.o Casa.o Castillo.o Civilizacion.o Edificio.o GuerreroE.o Jugador.o Soldado.o Tropa.o main.o Cuartel.o
	g++ Aldeano.o Caballeria.o Casa.o Castillo.o Civilizacion.o Edificio.o GuerreroE.o Jugador.o Soldado.o Tropa.o main.o Cuartel.o -o main
	rm *.o
main.o:	Aldeano.cpp Caballeria.cpp Casa.cpp Castillo.cpp Civilizacion.cpp Edificio.cpp GuerreroE.h Jugador.cpp Soldado.cpp Tropa.cpp main.cpp Cuartel.cpp
	g++ -c main.cpp
Caballeria.o:	Caballeria.cpp Tropa.cpp
	g++ -c Caballeria.cpp
Casa.o:	Casa.cpp Edificio.cpp
	g++ -c Casa.cpp
Castillo.o:	Castillo.cpp Edificio.cpp
	g++ -c Castillo.cpp
Civilizacion.o:	Civilizacion.cpp Tropa.cpp Edificio.cpp
	g++ -c Civilizacion.cpp
Edificio.o:	Edificio.cpp
	g++ -c Edificio.cpp
Jugador.o:	Jugador.cpp
	g++ -c Jugador.cpp
Soldado.o:	Soldado.cpp Tropa.cpp
	g++ -c Soldado.cpp
Tropa.o:	Tropa.cpp
	g++ -c Tropa.cpp
Aldeano.o:	Aldeano.cpp
	g++ -c Aldeano.cpp
GuerreroE.o:	GuerreroE.cpp Tropa.cpp
	g++ -c GuerreroE.cpp
Cuartel.o:	Cuartel.cpp
	g++ -c Cuartel.cpp