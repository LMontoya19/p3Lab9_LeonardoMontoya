#include "Aldeano.h"
#include "Caballeria.h"
#include "Casa.h"
#include "Castillo.h"
#include "Civilizacion.h"
#include "Edificio.h"
#include "GuerreroE.h"
#include "Jugador.h"
#include "Soldado.h"
#include "Tropa.h"
#include "Cuartel.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
vector<Aldeano*> nuevosaldeanos;
vector<Edificio*> nuevosedificios;
vector<Civilizacion*>civilizaciones;
vector<Jugador*> jugadores;
int main(){
    char resp = 's';
    while(resp=='s'){
        char opcion;
        cout<<endl;
        cout<<endl;
        cout<<"1)Crear Civilizacion"<<endl;
        cout<<"2)Crear Jugador"<<endl;
        cout<<"3)Guardar Informacion"<<endl;
        cout<<"4)Ingresar"<<endl;
        cout<<"5)Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case '1': {
                        string nombre;
                        cout<<"Ingrese nombre de civilizacion"<<endl;  
                        cin>>nombre;
                        cout<<"Ingrese cantidad de oro"<<endl;
                        int oro;
                        cin>>oro;
                        cout<<"Ingrese cantidad de madera"<<endl;
                        int madera;
                        cin>>madera;
                        cout<<"Ingrese cantidada de piedra"<<endl;
                        int piedra;
                        cin>>piedra;
                        cout<<"Ingrese poblacion maxima"<<endl;
                        int maxpob;
                        cin>>maxpob;
            
                     
                        civilizaciones.push_back(new Civilizacion(oro,madera,piedra,200,maxpob,5,nombre));
                        break;
                      }//Fin case 1 Crear Civilizacion
            case '2':{
                        if(!civilizaciones.empty()){
                            cout<<"Ingrese nombre"<<endl;
                            string nombre;
                            cin>>nombre;
                            for(int i = 0;i<civilizaciones.size();i++){
                                cout<<i<<")"<<civilizaciones[i]->getNombre()<<endl;
                            }
                            int opcion;
                            cout<<"Elija una civilizacion para administrar"<<endl;
                            cin>>opcion;
                            while(opcion>=civilizaciones.size()||opcion<0){
                                cout<<"Opcion no valida"<<endl;
                                for(int i = 0;i<civilizaciones.size();i++){
                                    cout<<i<<")"<<civilizaciones[i]->getNombre()<<endl;
                                }
                                int opcion;
                                cout<<"Elija una civilizacion para administrar"<<endl;
                                cin>>opcion;
                            }
                            jugadores.push_back(new Jugador(nombre,civilizaciones[opcion]));
                        }else{
                            cout<<"No hay civilizaciones"<<endl;
                        }
                        break;
                     }//Fin Case 2  Crear Jugador
            case '3':{
                        break;
                     }//Fin Case 3 Guardar Info
            case '4':{
                        for(int i = 0;i<jugadores.size();i++){
                            cout<<i<<")"<<jugadores[i]->getNombre()<<endl;
                        }
                        int jugadoractual;
                        cout<<"Elija un un jugador";
                        cin>>jugadoractual;
                        if(jugadoractual<jugadores.size()&&jugadoractual>=0){
                            char opcion2='s';
                            int recolecataAlimentos=0;
                            int recolectaOro=0;
                            int recoletaMadera=0;
                            int recolectaPiedra=0;
                            bool desterrado =false;
                            bool cuartel=false;
                            bool castillo = false;
                            int c=0;
                            while(opcion2=='s'){
                                char opingresar = '9';
                                cout<<endl;
                                cout<<endl;
                                cout<<"1)Nuevo Aldeano"<<endl;
                                cout<<"2)Buscar Recursos"<<endl;
                                cout<<"3)Nuevo Edificio"<<endl;
                                cout<<"4)Nueva Tropa"<<endl;
                                cout<<"5)Desterrar Poblacion"<<endl;
                                cout<<"6)Batalla"<<endl;
                                cout<<"7)Finalizar turno"<<endl;
                                cout<<"8)Volver a menu principal"<<endl;
                                cin>>opingresar;

                                switch(opingresar){
                                    case '1':
                                               { 
                                                
                                                if(jugadores[jugadoractual]->getCivilizacion()->getAldeanos().size()+
                                                jugadores[jugadoractual]->getCivilizacion()->getTropas().size()+c<
                                                jugadores[jugadoractual]->getCivilizacion()->getPoblacionactual()){
                                                    string sexo;
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getAlimento()>=55){
                                                        cout<<"Ingrese sexo de aldeano"<<endl;
                                                        cin>>sexo;
                                                        nuevosaldeanos.push_back(new Aldeano(sexo,55));
                                                        cout<<nuevosaldeanos.size()<<endl;
                                                        jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-55);
                                                        c++;
                                                    }else{
                                                        cout<<"No tiene suficientes alimentos para crear aldeano"<<endl;
                                                }}else{
                                                    cout<<"No hay espacio para mas habitantes"<<endl;
                                                }
                                                break;}
                                             //Fin case 1 nuevo aldeano
                                    case '2':{
                                                for(int i = 0;i<jugadores[jugadoractual]->getCivilizacion()->getAldeanos().size();i++){
                                                    recolecataAlimentos+=50;
                                                    recolectaOro+=30;
                                                    recolectaPiedra+=20;
                                                    recoletaMadera+=40;
                                                }
                                                break;
                                             }//Fin Case 2 Buscar Recursos
                                    case '3':{
                                                char opcionedificio ='4';
                                                cout<<"1)Casa"<<endl;
                                                cout<<"2)Cuartel"<<endl;
                                                cout<<"3)Castillo"<<endl;
                                                cin>>opcionedificio;
                                                if(opcionedificio=='1'){
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getMadera()>=50){
                                                        nuevosedificios.push_back(new Casa());
                                                        /*jugadores[jugadoractual]->getCivilizacion()->getEdificios().push_back(new Casa());
                                                        jugadores[jugadoractual]->getCivilizacion()->setPoblacion();
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-50);*/
                                                    }else{
                                                        cout<<"No hay suficientes materiales"<<endl;
                                                    }
                                                }else if(opcionedificio=='2'){
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getMadera()>=120&&
                                                        jugadores[jugadoractual]->getCivilizacion()->getPiedra()>=80){
                                                        nuevosedificios.push_back(new Cuartel());
                                                        /*jugadores[jugadoractual]->getCivilizacion()->getEdificios().push_back(new Cuartel());
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-120);
                                                        jugadores[jugadoractual]->getCivilizacion()->setPiedra(-80);
                                                        cuartel = true;*/
                                                    }else{
                                                        cout<<"No hay suficientes materiales"<<endl;
                                                    }
                                                }else if(opcionedificio=='3'){
                                                        if(jugadores[jugadoractual]->getCivilizacion()->getMadera()>=275&&
                                                        jugadores[jugadoractual]->getCivilizacion()->getPiedra()>=200){
                                                            nuevosedificios.push_back(new Castillo(0,275,200));
                                                            /*jugadores[jugadoractual]->getCivilizacion()->getEdificios().push_back(new Castillo(0,275,200));
                                                            jugadores[jugadoractual]->getCivilizacion()->setMadera(-275);
                                                            jugadores[jugadoractual]->getCivilizacion()->setOro(-200);
                                                            castillo=true;*/
                                                        }else{
                                                            cout<<"No hay suficientes materiales"<<endl;
                                                        }
                                                }else{

                                                    cout<<"Opcion no valida"<<endl;
                                                }
                                                break;
                                             }//Fin Case Nuevo edificio
                                    case '4':
                                                if(jugadores[jugadoractual]->getCivilizacion()->getAldeanos().size()+
                                                jugadores[jugadoractual]->getCivilizacion()->getTropas().size()<
                                                jugadores[jugadoractual]->getCivilizacion()->getPoblacionactual()){   
                                                    cout<<"1)Soldado"<<endl;
                                                    cout<<"2)Caballeria"<<endl;
                                                    cout<<"3)Guerrero Especial"<<endl;
                                                    char opciontropas='4';
                                                    cin>>opciontropas;
                                                    if(opciontropas=='1'){
                                                        if(cuartel==true){
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().push_back(new Soldado("s"));
                                                        }else{
                                                            cout<<"No tiene cuartel"<<endl;
                                                        }
                                                    }else if(opciontropas=='2'){
                                                        if(cuartel==true){
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().push_back(new Caballeria("s"));
                                                            cout<<jugadores[jugadoractual]->getCivilizacion()->getTropas().size();
                                                        }else{
                                                            cout<<"No tiene cuartel"<<endl;
                                                        }
                                                    }else if(opciontropas=='3'){
                                                        if(castillo==true){
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().push_back(new GuerreroE("s"));
                                                            
                                                        }else{
                                                            cout<<"No tiene Castillo"<<endl;
                                                        }
                                                    }else{
                                                        cout<<"Opcion no valida"<<endl;
                                                    }
                                                
                                                }else{
                                                    cout<<"No hay esapcion para mas poblacion"<<endl;
                                                }
                                                break;
                                             //Fin Case 4 Nueva tropa
                                    case '5':{
                                                /*for(int i = 0;i<jugadores[jugadoractual]->getCivilizacion()->getAldeanos().size();i++){
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getAldeanos()[i]!=NULL){
                                                    delete jugadores[jugadoractual]->getCivilizacion()->getAldeanos()[i];
                                                    }
                                                }
                                                for(int i = 0;i<jugadores[jugadoractual]->getCivilizacion()->getTropas().size();i++){
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getTropas()[i]!=NULL){
                                                    delete jugadores[jugadoractual]->getCivilizacion()->getTropas()[i];}
                                                }
                                                jugadores[jugadoractual]->getCivilizacion()->setMadera(-jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                jugadores[jugadoractual]->getCivilizacion()->setOro(-jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(-jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-jugadores[jugadoractual]->getCivilizacion()->getAlimento());
                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(100);*/
                                                desterrado = true;
                                                break;
                                             }//Fin case 5 Desterrar Poblacion
                                    case '6':{
                                                for(int i = 0;i<jugadores.size();i++){
                                                    if(i!=jugadoractual){
                                                        cout<<i<<")"<<jugadores[i]->getNombre()<<endl;
                                                    }
                                                }
                                                int batallar =-1;
                                                int tamiga,tenemiga;
                                                cout<<"Ingrese contra quien quiere batallar"<<endl;
                                                cin>>batallar;
                                                if(batallar<jugadores.size()&&batallar>=0&&batallar!=jugadoractual){
                                                    while(!jugadores[jugadoractual]->getCivilizacion()->getTropas().empty()&&!jugadores[batallar]->getCivilizacion()->getTropas().empty()){
                                                        cout<<"**Turno de "<<jugadores[jugadoractual]->getNombre()<<"**"<<endl;
                                                        for(int i = 0;i<jugadores[jugadoractual]->getCivilizacion()->getTropas().size();i++){
                                                            
                                                            cout<<i<<")"<<jugadores[jugadoractual]->getCivilizacion()->getTropas()[i]->getTipo()<<endl;}
                                                                   
                                                        cout<<"Eliga una tropa"<<endl;
                                                        
                                                        cin>>tamiga;
                                                        while(tamiga<0||tamiga>=jugadores[jugadoractual]->getCivilizacion()->getTropas().size()){
                                                            cout<<"Opcion no valida"<<endl;
                                                            cout<<"Eliga una tropa"<<endl;
                                                            cin>>tamiga;
                                                        }
                                                        cout<<"**Turno de "<<jugadores[batallar]->getNombre()<<"**"<<endl;
                                                        for(int i = 0;i<jugadores[batallar]->getCivilizacion()->getTropas().size();i++){
                                                            
                                                            cout<<i<<")"<<jugadores[batallar]->getCivilizacion()->getTropas()[i]->getTipo()<<endl;
                                                            
                                                        }
                                                        cout<<"Eliga una tropa"<<endl;
                                                        cin>>tenemiga;
                                                        while(tenemiga<0||tamiga>=jugadores[batallar]->getCivilizacion()->getTropas().size()){
                                                            cout<<"Opcion no valida"<<endl;
                                                            cout<<"Eliga una tropa"<<endl;
                                                            cin>>tenemiga;
                                                        }
                                                        while(jugadores[batallar]->getCivilizacion()->getTropas()[tenemiga]->getVida()>0&&jugadores[jugadoractual]->getCivilizacion()->getTropas()[tamiga]->getVida()>0){
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas()[tamiga]->Ataque(jugadores[batallar]->getCivilizacion()->getTropas()[tenemiga]);
                                                            if(jugadores[batallar]->getCivilizacion()->getTropas()[tenemiga]->getVida()>0){
                                                                jugadores[batallar]->getCivilizacion()->getTropas()[tenemiga]->Ataque(jugadores[jugadoractual]->getCivilizacion()->getTropas()[tamiga]);
                                                            }else{
                                                                 //cout<<"Gano tropa de: "<<jugadores[jugadoractual]->getNombre()<<endl;
                                                                 //jugadores[batallar]->getCivilizacion()->getTropas().erase(jugadores[batallar]->getCivilizacion()->getTropas().begin()+tenemiga);
                                                                 //jugadores[batallar]->getCivilizacion()->getTropas().shrink_to_fit();
                                                                //cout<<"Gano"<<jugadores[jugadoractual]->getNombre()<<endl;
                                                                /*jugadores[jugadoractual]->getCivilizacion()->setMadera(jugadores[batallar]->getCivilizacion()->getMadera());
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(-jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setOro(-jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setMadera(-jugadores[batallar]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(-jugadores[batallar]->getCivilizacion()->getAlimento());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(100);
                                                                jugadores[batallar]->getCivilizacion()->getTropas().erase(jugadores[batallar]->getCivilizacion()->getTropas().begin()+tenemiga);*/
                                                            }
                                                        
                                                        if(jugadores[jugadoractual]->getCivilizacion()->getTropas()[tamiga]->getVida()<0){
                                                             //cout<<"Gano tropa de: "<<jugadores[batallar]->getNombre()<<endl;
                                                            //jugadores[jugadoractual]->getCivilizacion()->getTropas().erase(jugadores[jugadoractual]->getCivilizacion()->getTropas().begin()+tamiga);
                                                             //jugadores[jugadoractual]->getCivilizacion()->getTropas().shrink_to_fit();
                                                             /*cout<<"Gano"<<jugadores[batallar]->getNombre()<<endl;
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().erase(jugadores[jugadoractual]->getCivilizacion()->getTropas().begin()+tamiga);
                                                            jugadores[batallar]->getCivilizacion()->setMadera(jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setOro(jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(-jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(-jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setMadera(-jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-jugadores[jugadoractual]->getCivilizacion()->getAlimento());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(100);*/
                                                        } 
                                                    }
                                                    if(jugadores[batallar]->getCivilizacion()->getTropas()[tenemiga]->getVida()<0){
                                                                 cout<<"Gano tropa de: "<<jugadores[jugadoractual]->getNombre()<<endl;
                                                                 jugadores[batallar]->getCivilizacion()->getTropas().erase(jugadores[batallar]->getCivilizacion()->getTropas().begin()+tenemiga);
                                                                 jugadores[batallar]->getCivilizacion()->getTropas().shrink_to_fit();
                                                                //cout<<"Gano"<<jugadores[jugadoractual]->getNombre()<<endl;
                                                                /*jugadores[jugadoractual]->getCivilizacion()->setMadera(jugadores[batallar]->getCivilizacion()->getMadera());
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(-jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setOro(-jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setMadera(-jugadores[batallar]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(-jugadores[batallar]->getCivilizacion()->getAlimento());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(100);
                                                                jugadores[batallar]->getCivilizacion()->getTropas().erase(jugadores[batallar]->getCivilizacion()->getTropas().begin()+tenemiga);*/
                                                            }
                                                        
                                                        if(jugadores[jugadoractual]->getCivilizacion()->getTropas()[tamiga]->getVida()<0){
                                                             cout<<"Gano tropa de: "<<jugadores[batallar]->getNombre()<<endl;
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().erase(jugadores[jugadoractual]->getCivilizacion()->getTropas().begin()+tamiga);
                                                             jugadores[jugadoractual]->getCivilizacion()->getTropas().shrink_to_fit();
                                                             /*cout<<"Gano"<<jugadores[batallar]->getNombre()<<endl;
                                                            jugadores[jugadoractual]->getCivilizacion()->getTropas().erase(jugadores[jugadoractual]->getCivilizacion()->getTropas().begin()+tamiga);
                                                            jugadores[batallar]->getCivilizacion()->setMadera(jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setOro(jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(-jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(-jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setMadera(-jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-jugadores[jugadoractual]->getCivilizacion()->getAlimento());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(100);*/
                                                        } 
                                                    }
                                                    if(jugadores[jugadoractual]->getCivilizacion()->getTropas().empty()){
                                                        cout<<"Gano: "<<jugadores[batallar]->getNombre()<<endl;
                                                       
                                                            
                                                            jugadores[batallar]->getCivilizacion()->setMadera(jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setOro(jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(-jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(-jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setMadera(-jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-jugadores[jugadoractual]->getCivilizacion()->getAlimento());
                                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(100);
                                                    }
                                                    if(jugadores[batallar]->getCivilizacion()->getTropas().empty() ){
                                                        cout<<"Gano: "<<jugadores[jugadoractual]->getNombre()<<endl;
                                                        
                                                                jugadores[jugadoractual]->getCivilizacion()->setOro(jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setPiedra(-jugadores[batallar]->getCivilizacion()->getPiedra());
                                                                jugadores[batallar]->getCivilizacion()->setOro(-jugadores[batallar]->getCivilizacion()->getOro());
                                                                jugadores[batallar]->getCivilizacion()->setMadera(-jugadores[batallar]->getCivilizacion()->getMadera());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(-jugadores[batallar]->getCivilizacion()->getAlimento());
                                                                jugadores[batallar]->getCivilizacion()->setAlimentos(100);
                                                                

                                                    }
                                                }
                                                break;
                                             }//Fin case 6 Batalla
                                    case '7':{
                                        c=0;
                                                for(int i = 0;i<nuevosaldeanos.size();i++){
                                                    cout<<"*Aldeano Creado"<<endl;
                                                    jugadores[jugadoractual]->getCivilizacion()->getAldeanos().push_back(nuevosaldeanos[i]);
                                                    delete nuevosaldeanos[i];
                                                    
                                                }
                                                nuevosaldeanos.clear();
                                                
                                                for(int i =0;i<jugadores[jugadoractual]->getCivilizacion()->getTropas().size();i++ ){
                                                    jugadores[jugadoractual]->getCivilizacion()->getTropas()[i]->Entrenar();
                                                }
                                                if(recolecataAlimentos>0||recolectaOro>0||recolectaPiedra>0||recoletaMadera>0){
                                                    cout<<"***Recolecta de Recuros***"<<endl;
                                                    cout<<"Alimentos: "<<recolecataAlimentos<<endl;
                                                    cout<<"Oro: "<<recolectaOro<<endl;
                                                    cout<<"Piedra: "<<recolectaPiedra<<endl;
                                                    cout<<"Madera: "<<recoletaMadera<<endl;
                                                    jugadores[jugadoractual]->getCivilizacion()->setMadera(recoletaMadera);
                                                    jugadores[jugadoractual]->getCivilizacion()->setAlimentos(recolecataAlimentos);
                                                    jugadores[jugadoractual]->getCivilizacion()->setOro(recolectaOro);
                                                    jugadores[jugadoractual]->getCivilizacion()->setPiedra(recolectaPiedra);
                                                     recolecataAlimentos=0;
                                                     recolectaOro=0;
                                                     recoletaMadera=0;
                                                     recolectaPiedra=0;
                                                }
                                                 for(int i = 0;i<nuevosedificios.size();i++){
                                                    cout<<nuevosedificios[i]->toString()<<"creado"<<endl;
                                                    if(nuevosedificios[i]->toString().compare("Cuartel")==0){
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-120);
                                                        jugadores[jugadoractual]->getCivilizacion()->setPiedra(-80);
                                                        cuartel=true;
                                                    }else if(nuevosedificios[i]->toString().compare("Castillo")==0){
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-275);
                                                        jugadores[jugadoractual]->getCivilizacion()->setOro(-200);
                                                        castillo=true;
                                                    }else{
                                                        cout<<"Hola"<<endl;
                                                        jugadores[jugadoractual]->getCivilizacion()->setPoblacion(5);
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-50);
                                                    }
                                                    jugadores[jugadoractual]->getCivilizacion()->getEdificios().push_back(nuevosedificios[i]);
                                                    delete nuevosedificios[i];
                                                }
                                                nuevosedificios.clear();
                                                if(desterrado==true){
                                                jugadores[jugadoractual]->getCivilizacion()->getAldeanos().clear();
                                                jugadores[jugadoractual]->getCivilizacion()->getTropas().clear();
                                                jugadores[jugadoractual]->getCivilizacion()->setMadera(-jugadores[jugadoractual]->getCivilizacion()->getMadera());
                                                jugadores[jugadoractual]->getCivilizacion()->setOro(-jugadores[jugadoractual]->getCivilizacion()->getOro());
                                                jugadores[jugadoractual]->getCivilizacion()->setPiedra(-jugadores[jugadoractual]->getCivilizacion()->getPiedra());
                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(-jugadores[jugadoractual]->getCivilizacion()->getAlimento());
                                                jugadores[jugadoractual]->getCivilizacion()->setAlimentos(100);
                                                cout<<"Se desterro el pueblo"<<endl;
                                                desterrado=false;
                                                }
                                                
                                                break;
                                            }//Fin Case 7 Finalizar Turno
                                    case '8':{
                                        c=0;
                                            for(int i = 0;i<nuevosaldeanos.size();i++){
                                                    cout<<"*Aldeano Creado"<<endl;
                                                    jugadores[jugadoractual]->getCivilizacion()->getAldeanos().push_back(nuevosaldeanos[i]);
                                                };
                                                for(int i = 0;i<nuevosaldeanos.size();i++){
                                                    delete nuevosaldeanos[i];
                                                };
                                                    nuevosaldeanos.clear();
                                                    
                                                for(int i =0;i<jugadores[jugadoractual]->getCivilizacion()->getTropas().size();i++ ){
                                                    jugadores[jugadoractual]->getCivilizacion()->getTropas()[i]->Entrenar();
                                                }
                                                 if(recolecataAlimentos>0||recolectaOro>0||recolectaPiedra>0||recoletaMadera>0){
                                                    cout<<"***Recolecta de Recuros***"<<endl;
                                                    cout<<"Alimentos: "<<recolecataAlimentos<<endl;
                                                    cout<<"Oro: "<<recolectaOro<<endl;
                                                    cout<<"Piedra: "<<recolectaPiedra<<endl;
                                                    cout<<"Madera: "<<recoletaMadera<<endl;
                                                    jugadores[jugadoractual]->getCivilizacion()->setMadera(recoletaMadera);
                                                    jugadores[jugadoractual]->getCivilizacion()->setAlimentos(recolecataAlimentos);
                                                    jugadores[jugadoractual]->getCivilizacion()->setOro(recolectaOro);
                                                    jugadores[jugadoractual]->getCivilizacion()->setPiedra(recolectaPiedra);
                                                     recolecataAlimentos=0;
                                                     recolectaOro=0;
                                                     recoletaMadera=0;
                                                     recolectaPiedra=0;
                                                }
                                                for(int i = 0;i<nuevosedificios.size();i++){
                                                    cout<<nuevosedificios[i]->toString()<<" creado"<<endl;
                                                    if(nuevosedificios[i]->toString().compare("Cuartel")==0){
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-120);
                                                        jugadores[jugadoractual]->getCivilizacion()->setPiedra(-80);
                                                        cuartel=true;
                                                    }else if(nuevosedificios[i]->toString().compare("Castillo")==0){
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-275);
                                                        jugadores[jugadoractual]->getCivilizacion()->setOro(-200);
                                                        castillo=true;
                                                    }else{
                                                        cout<<"hola"<<endl;
                                                        jugadores[jugadoractual]->getCivilizacion()->setPoblacion(5);
                                                        jugadores[jugadoractual]->getCivilizacion()->setMadera(-50);
                                                    }
                                                    jugadores[jugadoractual]->getCivilizacion()->getEdificios().push_back(nuevosedificios[i]);
                                                    delete nuevosedificios[i];
                                                }
                                                nuevosedificios.clear();
                                                if(desterrado==true){
                                                jugadores[jugadoractual]->getCivilizacion()->getAldeanos().clear();
                                                jugadores[jugadoractual]->getCivilizacion()->getTropas().clear();
                                                cout<<"Se desterro el pueblo"<<endl;
                                                desterrado=false;
                                                }
                                                
                                                       
                                            opcion2 = 'n';
                                                break;
                                             }//Fin case 8 volver menu principal
                                }//Fin switch ingresar
                            }
                        }else{
                            cout<<"Opcion no valida"<<endl;
                        }
                        break;
                     }//Fin case 4 Ingresar
            case '5':{
                        resp='n';
                        break;
                     }//Fin case 5 Salir
        }//Fin Switch Menu Principal
    }//Fin while menu principal
    for(int i = 0;i<civilizaciones.size();i++){
        delete civilizaciones[i];
    };
    for(int i = 0;i<jugadores.size();i++){
        delete jugadores[i];
        
    }
    return 0;
}
