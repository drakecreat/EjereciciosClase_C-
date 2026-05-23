#include <iostream>
#include <string>
using namespace std;

void mostrarestado(string nombre, int hp, int maxHP);
void recibirdaño(int& hp, int danio);
void curar(int& hp, int cantidad, int maxHP);

int main (){

string nombreH = "Arthas";
int hp = 100, maxhp = 100;
mostrarestado(nombreH,hp,maxhp);
cout<<"Arthas recibe daño... -30"<<endl;
recibirdaño(hp,30);
mostrarestado(nombreH,hp,maxhp);
cout<<"Arthas recibe daño... -50"<<endl;
recibirdaño(hp,50);
mostrarestado(nombreH,hp,maxhp);
cout<<"Arthas recibe cura... +40"<<endl;
curar(hp,40,maxhp);
mostrarestado(nombreH,hp,maxhp);
cout<<"Arthas recibe daño... -80"<<endl;
recibirdaño(hp,80);
mostrarestado(nombreH,hp,maxhp);

return 0;
}

void mostrarestado(string nombre, int hp, int maxHP){
    cout <<"Estado de : "<<nombre<<" - "<<"HP: "<<hp<<" / "<<maxHP<<endl;
}
void recibirdaño(int& hp, int danio){
    hp = hp-danio;
    if (hp < 0){
        hp = 0;
    }
}
void curar(int& hp, int cantidad, int maxHP){
    hp = hp + cantidad;
    if (hp > maxHP){
        hp = maxHP;
    }
}
#include <iostream>
#include <string>
using namespace std;
void mostrarinventario(int oro, int popciones);
bool comprarpcion(int* oro,int* popciones, int precio);
void venderpociones(int* oro,int* pociones, int preccioventa);

int main (){
    int oro= 100,pociones = 2 , preicoCompra = 30, precioVenta = 15;
    string pudo= "false";
    mostrarinventario(oro,pociones);
     if(comprarpcion(&oro,&pociones,preicoCompra)== true)
    {pudo= "Exito!";}
    else{pudo = "Oro insuficiente!";} 
    cout<<"Comprando pocion..."<<pudo<<endl;
    mostrarinventario(oro,pociones);
     if(comprarpcion(&oro,&pociones,preicoCompra)== true)
    {pudo= "Exito!";}
    else{pudo = "Oro insuficiente!";}
    cout<<"Comprando pocion..."<<pudo<<endl;
    mostrarinventario(oro,pociones);
    if(comprarpcion(&oro,&pociones,preicoCompra)== true)
    {pudo= "Exito!";}
    else{pudo = "Oro insuficiente!";}
    cout<<"Comprando pocion..."<<pudo<<endl;
    mostrarinventario(oro,pociones);
    
    venderpociones(&oro,&pociones,precioVenta);
    cout<<"Vendiendo pocion..."<<endl;
    mostrarinventario(oro,pociones);
   
    if(comprarpcion(&oro,&pociones,preicoCompra)== true)
    {pudo= "Exito!";}else{pudo = "Oro insuficiente!";}
   
    cout<<"comprando pocion..."<<pudo<<endl;
    mostrarinventario(oro,pociones);


    return 0 ;
}

void mostrarinventario(int oro, int popciones){
    cout<<"Oro: "<<oro<<" | Pociones: "<<popciones<<endl;
}
bool comprarpcion(int* oro,int* pociones, int precio){
    if (*oro >= precio){
    *oro = *oro - precio;
    *pociones += 1;
    return true;
    }else{
        return false;
    }
}
void venderpociones(int* oro,int* pociones, int preccioventa){
    if(*pociones > 0){
        *oro = *oro + preccioventa;
        *pociones = *pociones - 1;
    }else{
        cout<<"no tienes pociones para vender";
    }

}



