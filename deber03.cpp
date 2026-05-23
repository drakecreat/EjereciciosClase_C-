#include <iostream>
#include <array>
using namespace std;

bool verificacion(array<array<char,3>,3> tablero){

    // filas
    for(int i=0;i<3;i++){
        if(tablero[i][0] != '0' &&
           tablero[i][0] == tablero[i][1] &&
           tablero[i][1] == tablero[i][2]){
            return true;
        }
    }

    // columnas
    for(int j=0;j<3;j++){
        if(tablero[0][j] != '0' &&
           tablero[0][j] == tablero[1][j] &&
           tablero[1][j] == tablero[2][j]){
            return true;
        }
    }

    // diagonal principal
    if(tablero[0][0] != '0' &&
       tablero[0][0] == tablero[1][1] &&
       tablero[1][1] == tablero[2][2]){
        return true;
    }

    // diagonal secundaria
    if(tablero[0][2] != '0' &&
       tablero[0][2] == tablero[1][1] &&
       tablero[1][1] == tablero[2][0]){
        return true;
    }

    return false;
}

bool rango(int x){
    return x>=0 && x<3;
}

void imprimir(array<array<char,3>,3> tablero){

    cout << endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main(){

    array<array<char,3>,3> tablero =
    {{
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    }};

    cout<<"Bienvenido al juego de 3 en raya!"<<endl;

    imprimir(tablero);

    int jugadorganador = 0;
    int movimientos = 0;

    while(verificacion(tablero)==false && movimientos<9){

        for(int i=0;i<2;i++){

            jugadorganador = i+1;

            int fila,columna;

            cout<<"Turno del jugador "<<jugadorganador<<endl;

            do{
                cout<<"ingresa fila (0-2): ";
                cin>>fila;
            }while(rango(fila)==false);

            do{
                cout<<"ingresa columna (0-2): ";
                cin>>columna;
            }while(rango(columna)==false);

            if(tablero[fila][columna] != '0'){
                cout<<"Esa casilla ya esta ocupada"<<endl;
                i--;
                continue;
            }

            if(i==0)
                tablero[fila][columna]='X';
            else
                tablero[fila][columna]='O';

            movimientos++;

            imprimir(tablero);

            if(verificacion(tablero)==true)
                break;

            if(movimientos==9)
                break;
        }
    }

    if(verificacion(tablero)==true){
        cout<<"El jugador "<<jugadorganador<<" ha ganado!"<<endl;
    }
    else{
        cout<<"El juego termino en empate"<<endl;
    }

    return 0;
}
