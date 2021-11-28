#include "rlutil.h"
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "funciones.h"
#include <ctime>
using namespace std;



int main()
{
   int opcion,juego, est, stats[10]={0}, a=0;
   char salir;
   bool incorrecto = true;

   string nombre, n[10];
   for(int e = 0; e<10;e++){
    n[e] = "VACIO";
   }


    while(incorrecto == true){
    incorrecto = false;
    recuadro(1,1,60,20);
    recuadro(8,4,46,15);
    rlutil::locate(23,3);
    cout << "BIENVENIDOS A REVENGE " << endl;
    rlutil::locate(11,7);
    cout<<"1- JUGAR ";
    rlutil::locate(11,9);
    cout<<"2- ESTADISTICAS ";
    rlutil::locate(11,11);
    cout<<"3- CREDITOS";
    rlutil::locate(11,13);
    cout<<"0- SALIR";
    rlutil::locate(11,15);
    cout<<"ELIJA UNA OPCION: ";
    cin>>opcion;
    rlutil::locate(10,20);
    system("pause");
    system("cls");

        switch(opcion) {
            case 1:
            juego=EmpezarGame();
            incorrecto = true;
            rlutil::locate(2,19);
            cout << "Ingrese nombre para las estadisticas" << endl;
            rlutil::locate(2,20);
            cin >> nombre;
            stats[a] = juego;
            n[a] = nombre;
            a+=1;
            Burbujeo(stats, n);
            rlutil::anykey();

            break;

            case 2:
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
              cout << "Estadisticas" << endl;
              for(int z=0; z<10;z++){
                rlutil::locate(15,z+5);
                cout<< n[z] << " " <<stats[z] << endl;
              }
              rlutil::anykey();
              incorrecto = true;
            break;


            case 3:
              recuadro(1,1,60,20);
              recuadro(8,4,46,15);
              rlutil::locate(25,3);
              cout << "CREDITOS" << endl;;
              rlutil::locate(17,5);
              cout << "Equipo: Los Revengers " << endl;
              rlutil::locate(19,9);
              cout << "Luka Gallo - 25189" << endl;
              rlutil::locate(15,10);
              cout << "Tomas Abraham Legajo - 25687" << endl;
              rlutil::locate(10,20);
              system("pause");
              system("cls");
              incorrecto=true;
              break;


            case 0:
               recuadro(1,1,60,20);
               recuadro(8,4,46,15);
               rlutil::locate(25,3);
               cout << "Opcion de salida";
               rlutil::locate(18,5);
               cout << "Realmente desea salir?" << endl;
               rlutil::locate(18,6);
               cout << "S/N: ";
               cin >> salir;
               if(salir=='s'|| salir=='S'){
               rlutil::locate(18,10);
               cout << "Gracias por jugar REVENGE!" << endl;
               rlutil::locate(1,22);
               return 0;

              }
              else if(salir=='n'|| salir=='N'){
               incorrecto=true;
              }
                break;

            default:

                recuadro(1,1,60,20);
                rlutil::locate(15,10);
                rlutil::setColor(rlutil::BLACK);
                cout << "Comando incorrecto!" << endl;
                rlutil::setColor(rlutil::BLACK);
                rlutil::locate(10,20);
                system("pause");
                system("cls");
                incorrecto=true;
                break;
        }


    }





    return 0;
}

