#include "rlutil.h"
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "funciones.h"
#include <ctime>

using namespace std;

void Burbujeo(int v[],string v2[]){
    for(int c = 0; c < 10; c++){
        for(int x = 0; x<9;x++){
            if (v[x] < v[x+1]) {
                int aux = v[x+1];
                v[x+1] = v[x];
                v[x] = aux;

                string aux2 = v2[x+1];
                v2[x+1] = v2[x];
                v2[x] = aux2;

            }
        }
    }
}

void RandomDados(int v[],int cant){ //numeros aleatorios.
    for (int x = 0; x< cant; x++) {
        v[x] = 1 + rand() % 6;
    }
}

void RandomDados12(int v[], int cant){
    for (int x = 0; x< cant; x++) {
        v[x] = 1 + rand() % 12;
    }
}
void MostrarDados (int v[],int cant){ //muestra los dados que se formaron.
    int i;
    for(i=0;i<cant;i++){
    dibujarDado(i+1, v[i]);
}
}
int Jugador_Actual (bool J1){
    int num;
    if(J1 == true){
        num = 1;
        J1 = false;
    }
    else {
        num = 2;
        J1 = true;
    }
    return num;
}

void recuadro(int x, int y, int ancho, int alto){
const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    rlutil::setColor(rlutil::WHITE);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
}

void recuadro1(int x, int y, int ancho, int alto){

const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    rlutil::setColor(rlutil::WHITE);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i,4);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}

void dibujarDado(int nroDado, int valor){
    const int Y = 6;
    const int ALTO = 4;
    const int INI = -4;
    const int X = INI + (nroDado * 10);
    const int ANCHO = 8;

    /// Ubicaciones del punto
    const int CENTRO_X = X + ANCHO/2;
    const int CENTRO_Y = Y + ALTO/2;
    const int IZQUIERDA = CENTRO_X - 2;
    const int ARRIBA = CENTRO_Y - 1;
    const int DERECHA= CENTRO_X + 2;
    const int ABAJO= CENTRO_Y + 1;


    recuadro(X, Y, ANCHO, ALTO);

    /// Dibujar los puntos


    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    rlutil::setColor(rlutil::WHITE);
    switch(valor){
        case 1:
            rlutil::locate(CENTRO_X, CENTRO_Y);
            cout <<"*";
        break;
        case 2:
            if (nroDado%2 == 0){
                rlutil::locate(IZQUIERDA, ARRIBA);
                cout << "*";
                rlutil::locate(DERECHA, ABAJO);
                cout << "*";
            }
            else{
                rlutil::locate(DERECHA, ARRIBA);
                cout << "*";
                rlutil::locate(IZQUIERDA, ABAJO);
                cout << "*";
            }
        break;
        case 3:
            if (nroDado%2 == 0){
                rlutil::locate(IZQUIERDA, ARRIBA);
                cout << "*";
                rlutil::locate(DERECHA, ABAJO);
                cout << "*";
            }
            else{
                rlutil::locate(DERECHA, ARRIBA);
                cout << "*";
                rlutil::locate(IZQUIERDA, ABAJO);
                cout << "*";
            }
            rlutil::locate(CENTRO_X, CENTRO_Y);
            cout << "*";
        break;
        case 4:
            rlutil::locate(IZQUIERDA, ARRIBA);
            cout << "*";
            rlutil::locate(DERECHA, ABAJO);
            cout << "*";
            rlutil::locate(DERECHA, ARRIBA);
            cout << "*";
            rlutil::locate(IZQUIERDA, ABAJO);
            cout << "*";
        break;
        case 5:
            rlutil::locate(IZQUIERDA, ARRIBA);
            cout << "*";
            rlutil::locate(DERECHA, ABAJO);
            cout << "*";
            rlutil::locate(DERECHA, ARRIBA);
            cout << "*";
            rlutil::locate(IZQUIERDA, ABAJO);
            cout << "*";
            rlutil::locate(CENTRO_X, CENTRO_Y);
            cout << "*";
        break;
        case 6:
            rlutil::locate(IZQUIERDA, ARRIBA);
            cout << "*";
            rlutil::locate(DERECHA, ABAJO);
            cout << "*";
            rlutil::locate(DERECHA, ARRIBA);
            cout << "*";
            rlutil::locate(IZQUIERDA, ABAJO);
            cout << "*";
            rlutil::locate(DERECHA, CENTRO_Y);
            cout << "*";
            rlutil::locate(IZQUIERDA, CENTRO_Y);
            cout << "*";
        break;
    }
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
}

void MostrarDados12 (int v[],int cant){ //muestra los dados que se formaron.
    for(int i = 0; i < cant; i++){
        cout << "DADO DOCE CARAS: " <<v[i] << endl;
    }
}

int EmpezarGame(){
    srand(time(NULL));
    int J1 = 6, J2 = 6, Compartidos = 2, Numero_Objetivo = 0, seleccionar, suma = 0, DadosResta = 0;
    int vDados1[J1], vDados2[J2], vDados12[2], PuntajeJ1 = 0, PuntajeJ2 = 0, totalJ1 = 0, totalJ2 = 0, act, act2;
    bool otra = false, J = false;
    string nombre1, nombre2, actn1, actn2, ganador;


    recuadro(1,1,60,20);
    rlutil::locate(3,3);
    cin.ignore();
    cout << "Ingrese el nombre jugador 1: ";
    cin >> nombre1;
    rlutil::locate(3,4);
    cout << "Ingrese el nombre jugador 2: ";
    cin >> nombre2;

   do{  //PRIMERA RONDA PARA VER QUIEN EMPIEZA
            otra = false;
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(23,3);
            cout << "|   "<< nombre1 <<"   |" <<endl;
            rlutil::locate(3,8);
            RandomDados(vDados1, 1);
            MostrarDados(vDados1, 1);
            rlutil::locate(10,20);
            system("pause");


            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(23,3);
            cout << "|   "<< nombre2 <<"   |" <<endl;
            rlutil::locate(3,8);
            RandomDados(vDados2, 1);
            MostrarDados(vDados2, 1);
            rlutil::locate(10,20);
            system("pause");

            // UTILIZO UN IF PARA SABER QUIEN TIENE EL DADO MAYOR Y QUE JUGADOR EMPIEZA TIRANDO.
            recuadro1(1,1,60,20);
            if(vDados1[0] > vDados2[0]){
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(20,10);
            cout << "Comienza "<< nombre1 <<endl;
            J = true;
            }
            else if (vDados1[0] == vDados2[0]){
            otra = true;
            system("cls");
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(20,10);
            cout << "EMPATE" << endl;
          }
            else{
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(20,10);
            cout << "Comienza  "<< nombre2 <<endl;
        }
            rlutil::anykey();
            rlutil::cls();
            }while(otra == true);

    cout << "-------Comienza la partida---------" << endl;

    for(int c = 0; c<1;c++){
        int ronda = c+1;
        act = Jugador_Actual(J);
        act2;

            if (act == 1){
            act2 = 2;
            actn1 = nombre1;
            actn2 = nombre2;
            }
            else{
            act2 = 1;
            actn1 = nombre2;
            actn2 = nombre1;
            }
            recuadro1(1,1,60,20);

            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn1 << endl;
             rlutil::locate(50,19);
             cout<<"Ronda N: "<<ronda;
            rlutil::locate(10,20);
            system("pause");

                    //EMPIEZA EL JUGADOR 1

            RandomDados12(vDados12,Compartidos); //SE TIRAN LOS DADOS DE 12 PARA SABER EL NUMERO OBJETIVO
            rlutil::locate(3,8);
            MostrarDados12(vDados12, Compartidos);
            rlutil::locate(10,20);
            system("pause");
            system("cls");


            recuadro1(1,1,60,20);

            rlutil::locate(50,19);
            cout<<"Ronda N: "<<ronda;
            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn1 << endl;
            rlutil::locate(10,20);
            Numero_Objetivo = vDados12[0] + vDados12[1];
            rlutil::locate(40,3);
            cout << "Numero Objetivo: " << Numero_Objetivo << endl;
            rlutil::locate(10,20);
            system("pause");
            RandomDados(vDados1, J1);
            rlutil::locate(4,3);
            MostrarDados(vDados1,J1);
            rlutil::locate(2,16);
            cout << "Que dados desea seleccionar?" << endl;
            rlutil::locate(2,17);
            cout << "Para finalizar indique 0 " <<endl;
            rlutil::locate(2,18);
            cout << "Dado: ";
            cin>>seleccionar;
            rlutil::locate(10,20);
            system("pause");
            system("cls");

            recuadro1(1,1,60,20);
            rlutil::locate(50,19);
            cout<<"Ronda N: "<<ronda;
            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn1 << endl;
            rlutil::locate(40,3);
            cout << "Numero Objetivo: " << Numero_Objetivo << endl;

            while(seleccionar!=0){

                while(seleccionar>J1){
                rlutil::locate(2,18);
                cout<< "Invalido, seleccione otra vez" << endl;
                rlutil::locate(2,19);
                cout<< "Dado: " ;
                cin>> seleccionar;
                }                                              //Se eligen los dados para descartar.

                if (seleccionar ==0){
                    break;
                }
                suma += vDados1[seleccionar-1];

                rlutil::locate(2,3);
                MostrarDados(vDados1,J1);
                rlutil::locate(2,16);
                cout << "Suma hasta ahora: " << suma << endl;
                DadosResta++;
                rlutil::locate(2,17);
                cout << "Dado: ";
                cin>>seleccionar;

            }


            rlutil::cls();
            if (suma == Numero_Objetivo){       //si la suma de igual al objetivo se suman los dados al contrincante.
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(20,10);
            cout << "Tirada exitosa!" << endl;
            J1 = J1 - DadosResta;
            J2 += DadosResta;
            rlutil::locate(2,11);
            cout << "Dados del jugador "<< actn1 << " : " <<J1 << endl;
            rlutil::locate(2,12);
            cout << "Dados del jugador "<< actn2 << " : " << J2 << endl;
            PuntajeJ1 = suma * DadosResta;
            totalJ1+= PuntajeJ1;
            rlutil::locate(2,13);
            cout << "Puntaje del Jugador "<< actn1 << ": "<<PuntajeJ1;
            suma = 0;
            DadosResta = 0;
            }
            else{
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(20,10);
            cout<<"Tirada no exitosa" << endl;
            if (J2>1){
            J1+=1;
            J2 = J2-1;
            }
            suma = 0;
            DadosResta = 0;
            }
            if(J1==0){
            ganador = act;
            totalJ1+=10000;
            break;
            }
            else if(J2 ==0){
            ganador = act2;
            totalJ2+=10000;
            break;
            }
            rlutil::anykey();
            rlutil::cls();

            //EMPIEZA EL JUGADOR 2
            recuadro1(1,1,60,20);
            rlutil::locate(50,19);
            cout<<"Ronda N: "<<ronda;

            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn2 << endl;
            rlutil::locate(10,20);
            system("pause");

            RandomDados12(vDados12,Compartidos); //SE TIRAN LOS DADOS DE 12 PARA SABER EL NUMERO OBJETIVO
            rlutil::locate(3,8);
            MostrarDados12(vDados12, Compartidos);
            rlutil::locate(10,20);
            system("pause");
            system("cls");


            recuadro1(1,1,60,20);
            rlutil::locate(50,19);
            cout<<"Ronda N: "<<ronda;

            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn2 << endl;
            rlutil::locate(10,20);
            Numero_Objetivo = vDados12[0] + vDados12[1];
            rlutil::locate(40,3);
            cout << "Numero Objetivo: " << Numero_Objetivo << endl;
            rlutil::locate(10,20);
            system("pause");
            RandomDados(vDados2, J2);
            rlutil::locate(4,3);
            MostrarDados(vDados2,J2);
            rlutil::locate(2,16);
            cout << "Que dados desea seleccionar?" << endl;
            rlutil::locate(2,17);
            cout << "Para finalizar indique 0 " <<endl;
            rlutil::locate(2,18);
            cout << "Dado: ";
            cin>>seleccionar;
            rlutil::locate(10,20);
            system("pause");
            system("cls");

            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "| REVENGE |";
            rlutil::locate(5,3);
            cout << "JUGADOR " << actn2 << endl;
            rlutil::locate(40,3);
            cout << "Numero Objetivo: " << Numero_Objetivo << endl;

            while(seleccionar!=0){
                while(seleccionar>J2){
                rlutil::locate(2,18);
                cout<< "Invalido, seleccione otra vez" << endl;
                rlutil::locate(2,19);
                cout<< "Dado: " ;
                cin>> seleccionar;
                }                                              //Se eligen los dados para descartar.
                if (seleccionar ==0){
                    break;
                }
                suma += vDados2[seleccionar-1];

                rlutil::locate(2,3);
                MostrarDados(vDados2,J2);
                rlutil::locate(2,16);
                cout << "Suma hasta ahora: " << suma << endl;
                DadosResta++;
                rlutil::locate(2,17);
                cout << "Dado: ";
                cin>>seleccionar;

            }
            rlutil::cls();
            if (suma == Numero_Objetivo){       //si la suma de igual al objetivo se suman los dados al contrincante.
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(22,13);
            cout << "Tirada exitosa!" << endl;
            J2 = J2 - DadosResta;
            J1 += DadosResta;
            cout<< "Dados del jugador "<< actn1 << " : " <<J1 << "\nDados del jugador "<< actn2 << " : " << J2 << endl;
            PuntajeJ2 = suma * DadosResta;
            totalJ2+= PuntajeJ2;
            cout << "Puntaje del Jugador "<< actn2 << ": "<<PuntajeJ2;
            suma = 0;
            DadosResta = 0;
            }
            else{
            recuadro1(1,1,60,20);
            rlutil::locate(25,3);
            cout << "REVENGE";
            rlutil::locate(22,13);
            cout<<"Tirada no exitosa" << endl;
            if (J1>1){
            J2+=1;
            J1 = J1-1;
            }
            suma = 0;
            DadosResta = 0;
            }
            if(J1==0){
            ganador = act;
            totalJ1+=10000;
            break;
            }
            else if(J2 ==0){
            ganador = act2;
            totalJ2+=10000;
            break;
            }
            rlutil::anykey();
            rlutil::cls();
        }
    rlutil::cls();
    if (totalJ1>totalJ2){
    ganador = actn1;
    }
    else{
    ganador = actn2;
    }
    recuadro1(1,1,60,20);
    rlutil::locate(25,3);
    cout << "REVENGE";
    rlutil::locate(20,10);
    cout << "GANA EL JUGADOR " << ganador << "!!" <<endl;
    rlutil::locate(2,15);
    cout << "Puntaje total jugador " << actn1 << ": "<<totalJ1 << endl;
    rlutil::locate(2,16);
    cout << "Puntaje total jugador " << actn2 << ": "<<totalJ2 << endl;
    rlutil::anykey();
    if(ganador == actn1){
        return totalJ1;
    }
    else{
        return totalJ2;
    }


}
