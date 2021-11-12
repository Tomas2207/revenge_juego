#include <iostream>
#include <cstdlib>

using namespace std;

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
    for(int i = 0; i < cant; i++){
        cout << "DADO " << i+1 << "----> "<<v[i] << endl;
    }
}
