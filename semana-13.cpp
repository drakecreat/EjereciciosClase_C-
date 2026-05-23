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
#include <iostream>
#include <array>
#include<cmath>
using namespace std;

int main (){
    float max= - INFINITY,  min= INFINITY;
    int ifmax,ifmin, jfmax,jfmin;
    //0 vacia, valores altos =mas peligrosa
    /*empieza paso 1*/
    array <array<int, 4>, 3> mapa ={{{2, 0, 5, 0}, {3, 8, 0, 4},{1, 6, 7, 0}}};//paso 1
    /*termina paso 1*/
    /*empieza paso 2*/
    for (int i =0 ;i <mapa.size();i++){

        for(int j =0 ;j<mapa[i].size();j++){

            cout<<mapa[i][j]<<" ";
        }
        cout<<endl;
    }
    /*termina paso 2*/
    /*empieza paso 3*/
    mapa[0][2]= 9;
    cout<<"Se modifica el valor del mapa[0][2] es: "<<mapa[0][2]<<endl;
    mapa[2][3]= 3;
    cout<<"Se modifica el valor del mapa[2][3] es: "<<mapa[2][3]<<endl;
    /*termina paso 3*/
    /*empieza paso 4 y 5*/
    for (int i =0 ;i <mapa.size();i++){
        float suma_= 0;
        for(int j =0 ;j<mapa[i].size();j++){

           suma_ += mapa[i][j];//paso 4
            if(mapa[i][j] > max){max = mapa[i][j];  ifmax = i; jfmax= j;}//Paso 5
            if(mapa[i][j] < min){min = mapa[i][j]; ifmin = i ; jfmin= j ;}//Paso 5
        }
        
        float promedio = suma_/mapa[i].size();//paso 4
        cout<<"El promedio de la fila "<<i<<" es: "<<promedio<<endl;//paso 4
    }

    cout<<"El valor máximo es: "<<max<<"en la fila "<<ifmax<<" y columna "<<jfmax<<endl;//paso 5
    cout<<"El valor mínimo es: "<<min<<"en la fila "<<ifmin<<" y columna "<<jfmin<<endl;//paso 5
    /*termina paso 4 y 5*/
    /*empieza paso 6*/
    for (int i =0 ;i <mapa.size();i++){

        for(int j =0 ;j<mapa[i].size();j++){

            cout<<mapa[i][j]<<" ";
        }
        cout<<endl;
    }
    /*termina paso 6*/   
    return 0;
}


