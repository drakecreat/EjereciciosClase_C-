#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class pasajero{

    private:
    string nombre;
    double saldo;
    double costos = 0;
    vector<double> historial_km;
    public:
    pasajero(string nombre, double saldo){
        nombre = nombre;
        saldo = saldo;
    }   
    void recargar(double monto){ //1
        saldo += monto;
    }
    void viaje(double km){  //2
        double costo = km * 0.50;
        double tc= 0;
        if(km <= 0){
            cout<<"Distancia no valida para el viaje. #hoy no viajamos en el tiempo#"<<endl;
            tc += costo;
            double &reftc = tc;
            return;
        }else   if (saldo >= costo){
            saldo -= costo;
            if(historial_km.size() < 15){
                historial_km.push_back(km);
            }   
        } else {
            cout << "Saldo insuficiente para realizar el viaje." << endl;
        }
    }
    void historial(){ //3
        cout << "Historial de viajes:" << endl;
        for (size_t i = 0; i < historial_km.size(); ++i){
            double costo = historial_km[i] * 0.50;
            cout << "Viaje " << i + 1 << " : " << historial_km[i] << " km -> Costo: $" << fixed << setprecision(2) << costo << endl;
        }
    }
    void perfil(){ //4
        cout<<"| Nombre: "<<nombre<<" | Saldo: "<<saldo<<"Viajes: "<<historial_km.size()<<endl;
    }
    void tcostos(){//5
        cout<<"El total gastado es: "<<costos;
    }
    void promocion(double* monto){ //6
        *monto += 10;
    }
    void salir(vector<double>& hitorial_km){ //7
        
        cout <<"Se hicieron : "<<hitorial_km.size()<<" viajes"; 
    }


};

int main (){
    double monto;
    int op = 1;
    string nombre;
    vector<double>hitorial_km;
    do{
    cout<<"ingresa tu nombre: ";
    cin>>nombre;
    cout<<"ingresa el monto a recargar: ";  cin>>monto;
    pasajero p(nombre, monto);
    cout<<"=== MENU ==="<<endl;
    cout<< "1. Recargar saldo"<<endl;
    cout<< "2. Realizar un viaje"<<endl;
    cout<< "3. Ver historial"<<endl;
    cout<< "4. Ver perfil"<<endl;
    cout<< "5. Ver costo total gastado"<<endl;
    cout<< "6. Aplicar promocion"<<endl;
    cout<< "7. Salir"<<endl;
    
    if(op ==1){
        cout<<"ingresa el monto a recargar: ";  cin>>monto;
        p.recargar(monto);
    } else if(op == 2){
        double km;
        cout<<"ingresa los km del viaje: "; cin>>km;
        p.viaje(km);
    } else if(op == 3){
        p.historial();
    } else if(op== 4){
        p.perfil();
    }else if(op== 5){
        p.tcostos();
    }else if(op== 6){
        p.promocion(&monto);
    }else if(op== 7){
        p.salir(hitorial_km);
    }

    }while (op != 7);
    

    return 0;
}
