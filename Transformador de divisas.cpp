tarea_io_datatypes_dereckrivera
Dereck Steve Rivera Mena cmp 1101

Breve descripción de lo que hace el programa:

Este programa en C++ implementa un motor de conversión de divisas con dos modos de funcionamiento: modo continuo y modo sesión con estadísticas. Permite ingresar una divisa base y una cotizada (validando que tengan exactamente 3 letras), una tasa de cambio y un monto a convertir. El sistema calcula el valor convertido y ofrece la opción de aplicar una comisión personalizada o predefinida (casa de cambio o banco). En el modo continuo, cada conversión se almacena en un vector mediante la estructura Conversion, permitiendo mostrar un historial completo al finalizar. En el modo sesión, el programa permite ingresar múltiples montos hasta que el usuario decida salir, utilizando try-catch para validar entradas numéricas. Además, calcula estadísticas en tiempo real como: Total acumulado convertido Promedio por conversión Monto mínimo y máximo Número total de conversiones Estas estadísticas se almacenan en un vector usando la estructura sesion. El programa también incluye: Validación de texto con isalpha Formateo de números con dos decimales y separador de miles Inicialización segura del mínimo usando numeric_limits Manejo de errores para evitar que el programa se detenga ante entradas inválidas En resumen, es un sistema estructurado que combina validación de datos, almacenamiento dinámico, control de errores y análisis estadístico en tiempo real.

Instrucciones para compilar y ejecutar el programa (por ejemplo: g++ deber1.cpp -o deber1 y luego ./deber1) g++ deber1.cpp -o programa ./programa


  
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;


//analisa las letras una a una si son o no letras
bool soloLetras(string texto) {
	for(char c : texto) {if (!isalpha(c))return false/*si no son letras false*/;}return true;
}

string decimales(long double valor){
	
	stringstream ss;
	ss << fixed << setprecision(2)<< valor;
	string s= ss.str();
	int pos = s.find('.');
	
	for(int i = pos -3;i>0;i-= 3){
	s.insert(i,",");}
return s;
}

//AI START 
struct Conversion{
	string base;
	string cotizada;
	string tasa;
	string montobase;
	string montoConvertido;
};
struct sesion{
	int monto;
	int Contador;
	int montoc;
	float base_acumulado;
	float convertido_acumulado;
	float pconversion;
	double Montomin;
	double Montomax;
		};
//AI FINISH

int main() {
	/* modo continua de transformacion de divisas*/
	int modo;
	cout<<"Seleccione modo: (1) Continua (2) Sesion (3) Salir"<<endl;
	cin>>modo;
	long double tasavisual, tasacompleta=0, bmonto=0, cmonto, montoc; // definicion continua de variables
	string base, cotizada;
	
	//AI START
	vector<Conversion>historial;
	vector<sesion>segunda;
	//AI FINISH
	
	if (modo == 1){
	
	char repetir = 'y';
	
	for(;repetir=='y'|| repetir== 'Y';){
		
	char confirmacion= 'n';
	
			
				bool lon= false ;
				while(base.length()!=3 /*largo de la palabra diferente de 3*/ || lon==false) {
					cout<<"Divisa base: "; cin>> base ;
					lon= soloLetras(base);//guardo si es true o false de la variable base en lon para luego evaluarla
					if (base.length()!=3) cout<<"Error: Mas 3 letras"<<endl;
					if (lon==false)cout<<"Error: caracter no valido"<<endl;
				}
			
				bool ln= false ;
				while(cotizada.length()!=3 || ln==false) {
					cout<<"Divisa Cotizada: ";cin>> cotizada;
					ln= soloLetras(cotizada);
					if (cotizada.length()!=3) cout<<"Error: Mas 3 letras"<<endl;
					if (ln==false)cout<<"Error: caracter no valido"<<endl;
				}
			
			do{
				cout<<"Tasa: ";
				cin>> tasacompleta;
				if (tasacompleta <0)	cout<<"su tasa "<< tasacompleta <<" da perdida";
					else if (tasacompleta== 0)cout<<"su tasa "<<tasacompleta<<" la division es invalida";
				}while(repetir == 'y'&& tasacompleta <= 0);
			
			//evaluar y guardar el valor del monto base
			do{
				cout<<"Monto a convertir: ";cin>>bmonto;
				if (bmonto <0)	cout<<"su tasa "<< bmonto <<" da perdida"<<endl;
				else if (bmonto== 0)cout<<"su monto "<<bmonto<<" es nulo"<<endl;
			}while(bmonto<=0&&repetir == 'y');
			
			montoc =bmonto * tasacompleta ;
			
						// === COMISION ===
			char cobraComision;
			double porcentaje = 0;
			double montoFinal = montoc;
			
			cout<<"¿Cobrar comision por transaccion? (y/n): ";
			cin>>cobraComision;
			
			if(cobraComision == 'y' || cobraComision == 'Y'){
			
			    cout<<"¿Tiene el porcentaje exacto? (y/n): ";
			    char tieneValor;
			    cin>>tieneValor;
			
			    if(tieneValor == 'y' || tieneValor == 'Y'){
			        cout<<"Ingrese porcentaje de comision (%): ";
			        cin>>porcentaje;
			    } else {
			        cout<<"Opciones disponibles:"<<endl;
			        cout<<"1) Casa de cambio (2%)"<<endl;
			        cout<<"2) Banco (5%)"<<endl;
			        cout<<"Seleccione opcion: ";
			        int opcion;
			        cin>>opcion;
			
			        if(opcion == 1) porcentaje = 2;
			        else if(opcion == 2) porcentaje = 5;
			        else porcentaje = 0;
			    }

    montoFinal = montoc - (montoc * porcentaje / 100.0);
}
			
			string tasastr = decimales(tasacompleta);
			string montocstr = decimales(montoFinal);
			string bmontostr = decimales(bmonto);
			//AI START
			Conversion nueva;
			
			nueva.base = base ;
			nueva.cotizada =cotizada;
			nueva.tasa = tasastr;
			nueva.montobase= bmontostr;
			nueva.montoConvertido = montocstr;
			
			historial.push_back(nueva);
			//AI FINISH
			
			cout<<"quiere tranformar otra divisa (y/n):  ";
			cin>>repetir;
 			}
	for(const Conversion & c: historial){
		
		cout<<"=== CONVERSION DE DIVISAS ===" <<endl;
		cout<<"Par: "<< c.base <<"/" <<c.cotizada<<endl;
		cout<<"Tasa: " <<c.tasa<< endl;
		cout<<"Monto base: "<<c.montobase <<" "<<c.base<<endl;
		cout<<"Monto convertido: "<< c.montoConvertido<<" "<<c.cotizada<<endl;
		
	}
		
			
	} else if ( modo ==2){
		/* Sesión donde doy promedio paso a paso */
	int contador = 0;
	double total_base = 0, total_convertido = 0, max = 0, promedio =0;
	double min = numeric_limits<double>::infinity();
	
	
					bool lon= false ;
				while(base.length()!=3 /*largo de la palabra diferente de 3*/ || lon==false) {
					cout<<"Divisa base: "; cin>> base ;
					lon= soloLetras(base);//guardo si es true o false de la variable base en lon para luego evaluarla
					if (base.length()!=3) cout<<"Error: Mas 3 letras"<<endl;
					if (lon==false)cout<<"Error: caracter no valido"<<endl;
				}
			
				bool ln= false ;
				while(cotizada.length()!=3 || ln==false) {
					cout<<"Divisa Cotizada: ";cin>> cotizada;
					ln= soloLetras(cotizada);
					if (cotizada.length()!=3) cout<<"Error: Mas 3 letras"<<endl;
					if (ln==false)cout<<"Error: caracter no valido"<<endl;
				}
				
				cout<<"Tasa: ";
				cin>> tasacompleta;
				if (tasacompleta <0)	cout<<"su tasa "<< tasacompleta <<" da perdida";
					else if (tasacompleta== 0)cout<<"su tasa "<<tasacompleta<<" la division es invalida";	
		
	
string repetir;

	    while (true){
	
	        cout<<"Ingrese un monto a convertir (o 'q' para salir): ";
	        cin>>repetir;
	
	        if (repetir == "q" || repetir == "Q")
	            break;
	
	        try{
	            double monto = stod(repetir);
	            double convertido = monto * tasacompleta;
				
				montoc =monto * tasacompleta ;
								// === COMISION ===
				char cobraComision;
				double porcentaje = 0;
				double montoFinal = convertido;
				
				cout<<"¿Cobrar comision por transaccion? (y/n): ";
				cin>>cobraComision;
				
				if(cobraComision == 'y' || cobraComision == 'Y'){
				
				    cout<<"¿Tiene el porcentaje exacto? (y/n): ";
				    char tieneValor;
				    cin>>tieneValor;
				
				    if(tieneValor == 'y' || tieneValor == 'Y'){
				        cout<<"Ingrese porcentaje de comision (%): ";
				        cin>>porcentaje;
				    } else {
				        cout<<"Opciones disponibles:"<<endl;
				        cout<<"1) Casa de cambio (2%)"<<endl;
				        cout<<"2) Banco (5%)"<<endl;
				        cout<<"Seleccione opcion: ";
				        int opcion;
				        cin>>opcion;
				
				        if(opcion == 1) porcentaje = 2;
				        else if(opcion == 2) porcentaje = 5;
				        else porcentaje = 0;
				    }
				
				    montoFinal = convertido - (convertido * porcentaje / 100.0);
}
	            contador++;
	            total_base += monto;
	            total_convertido += convertido;
	
	            if(monto < min) min = monto;
	            if(monto > max) max = monto;
	
	            promedio = total_base / contador;
	
	            // Guardar snapshot en vector
	            sesion nueva;
	            
	            nueva.monto = monto;
	            nueva.montoc = montoFinal;
	            nueva.Contador = contador;
	            nueva.base_acumulado = total_base;
	            nueva.convertido_acumulado = total_convertido;
	            nueva.pconversion = promedio;
	            nueva.Montomin = min;
	            nueva.Montomax = max;
	
	            segunda.push_back(nueva);
	
	
	        }
	        catch(invalid_argument&){
	            cout<<"Error: Ingrese un numero valido";
	        }
	    }
		cout<<"=== SESION DE CONVERSION ==="<<endl;
		cout<<"Par: "<<base<<"/"<<cotizada<<endl;
		cout<<"Tasa: "<<tasacompleta<<endl;
		
	    // Mostrar todas las estadísticas acumuladas
	    for(const sesion & c : segunda){
	    	cout<<endl;
			cout<<"Conversion #"<<c.Contador<<":"<<endl;
			cout<<"  Monto base: "<<c.monto<<" "<<base<<endl;
			cout<<"  Monto convertido: "<<c.montoc <<" "<<cotizada<<endl<<endl;
	        cout<<"--- Estadisticas de la sesion ---"<<endl;
	        cout<<"Total de conversiones: "<<c.Contador<<endl;
	        cout<<"Total base acumulado: "<<decimales(c.base_acumulado)<<" "<<base<<endl;
	        cout<<"Total convertido acumulado: "<<decimales(c.convertido_acumulado)<<" "<<cotizada<<endl;
	        cout<<"Promedio por conversion: "<<decimales(c.pconversion)<<" "<<base<<endl;
	        cout<<"Monto minimo: "<<decimales(c.Montomin)<<" "<<base<<endl;
	        cout<<"Monto maximo: "<<decimales(c.Montomax)<<" "<<base<<endl;
	        cout<<endl;
	    }  
    
	}	else	
	return 0;
}
