#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "funciones.h"
using namespace std;


int main() {

    srand(time(NULL));
    int J1 = 6, J2 = 6, Compartidos = 2, Numero_Objetivo = 0, seleccionar, suma = 0, DadosResta = 0;
    int vDados1[J1], vDados2[J2], vDados12[2];
    bool otra = false;
    cout << "Para empezar la partida se tiran los dados" << endl;
    do{                                                             ///primera ronda para ver quien empieza.
        otra = false;
        cout << "Jugador 1" << endl;
        RandomDados(vDados1, 1);
        MostrarDados(vDados1, 1);
        cout << "Jugador 2" << endl;
        RandomDados(vDados2, 1);
        MostrarDados(vDados2, 1);
        if(vDados1[0] > vDados2[0]){
            cout << "Comienza el JUGADOR 1"<< endl;
        }
        else if (vDados1[0] == vDados2[0]){
            otra = true;
            cout << "EMPATE" << endl;
        }
        else{
            cout << "Comienza el JUGADOR 2" << endl;
        }

    }while(otra == true);

    cout << "-------Comienza la partida---------" << endl;

    while(J1!=0 || J2 !=0){

            ///Empieza el jugador 1
        RandomDados12(vDados12,Compartidos); /// Se tiran los dados de 12 para saber el numero objetivo
        MostrarDados(vDados12, Compartidos);
        Numero_Objetivo = vDados12[0] + vDados12[1];
        cout << "El numero objetivo es: " << Numero_Objetivo << endl;

        cout << "Tire los dados de 6 caras: " << endl; ///Se tiran los dados de 6 caras del J1.
        RandomDados(vDados1, J1);
        MostrarDados(vDados1,J1);
        cout<< "Que dados desea seleccionar? (Para finalizar seleccion ----->0)\nDados: ";

        do{                                     ///se eligen los dados para descartar.
            cin>>seleccionar;
            suma += vDados1[seleccionar-1];
            DadosResta++;

        }while(seleccionar!=0);

        if (suma == Numero_Objetivo){           ///si la suma de igual al objetivo se suman los dados al contrincante.
            cout << "Tirada exitosa!" << endl;
            J1 = J1 - DadosResta + 1;
            J2 += DadosResta - 1;
            cout<< "Dados del jugador 1: " <<J1 << "\nDados del jugador 2: "<< J2 << endl;
            suma = 0;
            DadosResta = 0;
        }
        else{
            cout<<"Tirada no exitosa" << endl;
        }

        cout << "Proximo Jugador" << endl; ///Empieza el jugador 2, el resto es una copia.
        RandomDados12(vDados12,Compartidos);
        MostrarDados(vDados12, Compartidos);
        Numero_Objetivo = vDados12[0] + vDados12[1];
        cout << "El numero objetivo es: " << Numero_Objetivo << endl;
        cout << "Tire los dados de 6 caras: " << endl;
        RandomDados(vDados2, J2);
        MostrarDados(vDados2,J2);
        cout<< "Que dados desea seleccionar? (Para finalizar seleccion ----->0)\nDados: ";

        do{
            cin>>seleccionar;
            suma += vDados2[seleccionar-1];
            DadosResta++;

        }while(seleccionar!=0);

        if (suma == Numero_Objetivo){
            cout << "Tirada exitosa!" << endl;
            J2 = J2 - DadosResta + 1;
            J1 += DadosResta - 1;
            cout<< "Dados del jugador 1: " <<J1 << "\nDados del jugador 2: "<< J2 << endl;
            suma = 0;
            DadosResta = 0;
        }
        else{
            cout<<"Tirada no exitosa" << endl;
        }
    }
    return 0;
}
