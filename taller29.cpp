 #include <iostream>
 #include <string>
 using namespace std;

 class JugadorRanked {
        private :
            string nickname ;
            int elo ;
            char historial [10]; // Guarda ’V’ o ’D’
            int partidas ; // Cuantas partidas hay en historial ( max 10)

        public :
            // CONSTRUCTOR (ya esta hecho )
            JugadorRanked ( string nick ) {
            nickname = nick ;
            elo = 1000;
            partidas = 0;
            }   

        // Registra una victoria
        void victoria ( int & victoriasTotales ) {
        if ( partidas < 10) {  // Solo si hay espacio en el array
            // TODO 1: Sumar 25 a elo
                elo = elo + 25;

            // TODO 2: Guardar ’V’ en historial [ partidas ]
                for(int i =0; i < 10;i++){
                    if ((historial[i]== 'V')or (historial[i]=='D') )
                    {        }else {historial[i]= 'V';}
                }

            // TODO 3: Incrementar partidas en 1 ( partidas ++)
                partidas = partidas + 1;

            // TODO 4: Incrementar victoriasTotales en 1
                victoriasTotales = victoriasTotales + 1;
            cout << " Victoria ! +25 ELO . Total : " << elo << endl ;
            } else {
            cout << " Historial lleno !" << endl ;
            }

        }
        // Registra una derrota
        void derrota () {
            if ( partidas < 10) {
            // TODO 5: Restar 20 a elo
                elo = elo - 25;

            // TODO 6: Si elo < 0 , ponerlo en 0 ( usa un if)
                if (elo < 0 ){ elo = 0; }
                
            // TODO 7: Guardar ’D’ en historial [ partidas ]
                for(int i =0; i < 10;i++){
                    if ((historial[i]== 'V')or (historial[i]=='D') )
                    {        }else {historial[i]= 'D';}
                }

            // TODO 8: Incrementar partidas en 1
                partidas = partidas + 1; 
            cout << " Derrota . -20 ELO . Total : " << elo << endl ;
            } else {
            cout << " Historial lleno !" << endl ;
            }

        }

        // Muestra el perfil
        void mostrar () {
            cout << " === PERFIL ===" << endl ;
            // TODO 9: Imprimir " Nickname : " seguido de nickname
            cout<<"Nickname: " << nickname;

            // TODO 10: Imprimir " ELO : " seguido de elo
            cout<<"ELO: "<<elo;
            cout << " Historial : ";
            for (int i = 0; i < partidas ; i ++) {
            cout << "[" << historial [ i] << "]";
            }
            cout << endl ;

        }

        // Retorna puntero al elo
        int * getEloPtr () {
        // TODO 11: Escribir return & elo ;
            return & elo;
        }
    };

// FUNCION EXTERNA CON PUNTERO
 void aplicarDecay ( int * ptrElo , int cantidad ) {
    // TODO 12: Restar cantidad a * ptrElo ( escribir : * ptrElo = * ptrElo - cantidad ;)
        * ptrElo = * ptrElo - cantidad;
    //programacion en C++ Taller Integrador Pag. 4
        if (* ptrElo < 0) {
        * ptrElo = 0;
        }
    cout << " Decay aplicado : -" << cantidad << " ELO " << endl ;
 }

 int main () {
    
    int victoriasTotales = 0;
    int opcion ;
    string nombre ;
    
    cout << " Ingresa tu nickname : ";
    cin >> nombre ;

    JugadorRanked jugador ( nombre );

    
    while ( true ) {
        cout << "\n === RANKED SIMULATOR === " << endl ;
        cout << "1. Registrar Victoria " << endl ;
        cout << "2. Registrar Derrota " << endl ;
        cout << "3. Ver Perfil " << endl ;
        cout << "4. Aplicar Decay ( -50 ELO )" << endl ;
        cout << "5. Salir " << endl ;
        cout << " Opcion : ";
        cin >> opcion ;

        if ( opcion == 1) {
        jugador . victoria ( victoriasTotales );
        } else if ( opcion == 2) {
        jugador . derrota () ;
        } else if ( opcion == 3) {
        jugador . mostrar () ;
        cout << " Victorias totales : " << victoriasTotales << endl ;
        } else if ( opcion == 4) {
        aplicarDecay ( jugador . getEloPtr () , 50) ;
        } else if ( opcion == 5) {
        break ;
        }
    }

    cout << " Gracias por jugar !" << endl ;

}
#include <iostream>
#include <string>

using namespace std;

class Playlist {
    private:
        string nombre;
        int duraciones[10]; // Duracion de cada cancion en segundos
        int numCanciones;   // Cuantas canciones hay ( max 10)

    public:
        // CONSTRUCTOR
        Playlist(string nom) {
            nombre = nom;
            numCanciones = 0;
        }

    // Calcula duracion total
        int duracionTotal() {
            int suma = 0;
            for (int i = 0; i < numCanciones; i++) {
                suma = suma + duraciones[i];
            }
            return suma;
        }

    // Agrega una cancion
    void agregar(int segundos) {
        if (numCanciones < 10) {
            // TODO 1
            duraciones[numCanciones] = segundos;
            // TODO 2
            numCanciones = numCanciones + 1;

        cout << "Cancion agregada (" << segundos << " seg)" << endl;
        } else {    cout << "Playlist llena!" << endl;  }
    }

    // Reproduce la playlist
    void reproducir(int &minutosEscuchados) {
        int minutos = duracionTotal() / 60;
        // TODO 3
        minutosEscuchados = minutosEscuchados + minutos;
        cout << "Reproduciendo... +" << minutos << " minutos" << endl;
    }

    // Muestra info
    void mostrar() {
        cout << "=== PLAYLIST ===" << endl;

        cout << "Nombre: " << nombre << endl;
        cout << "Canciones: " << numCanciones << endl;
        cout << "Duracion total: " << duracionTotal() << " seg" << endl;

        cout << "Detalle:" << endl;
        for (int i = 0; i < numCanciones; i++) {
            cout << "Cancion " << (i + 1) << ": " << duraciones[i] << " seg" << endl;
        }
    }

    // Retorna puntero a numCanciones
    int* getNumCancionesPtr() {
        // TODO 7
        return &numCanciones;
    }
};

// FUNCION EXTERNA CON PUNTERO
void resetear(int *ptrCanciones) {
    // TODO 8
    *ptrCanciones = 0;

    cout << "Playlist reseteada" << endl;
}

int main() {
    int minutosEscuchados = 0;

    string nombre;
    cout << "Nombre de tu playlist: ";
    cin >> nombre;

    Playlist miPlaylist(nombre);

    int opcion;
    int duracion;

    while (true) {
        cout << "\n=== PLAYLIST MANAGER ===" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Reproducir playlist" << endl;
        cout << "3. Ver info" << endl;
        cout << "4. Resetear playlist" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Duracion en segundos: ";
            cin >> duracion;

            miPlaylist.agregar(duracion);

        } else if (opcion == 2) {
            miPlaylist.reproducir(minutosEscuchados);

        } else if (opcion == 3) {
            miPlaylist.mostrar();
            cout << "Minutos escuchados: " << minutosEscuchados << endl;

        } else if (opcion == 4) {
            resetear(miPlaylist.getNumCancionesPtr());

        } else if (opcion == 5) {
            break;
        }
    }

    cout << "Hasta luego!" << endl;
    return 0;
}


#include <iostream>
#include <string>

using namespace std ;

class Perfil {
private :
    string username ;
    int seguidores ;
    int likes [10]; // Likes de cada post
    int posts ; // Cuantos posts hay ( max 10)

    public :
    // CONSTRUCTOR (ya esta hecho )
    Perfil ( string user , int segs ) {
    username = user ;
    seguidores = segs ;
    posts = 0;
    }

    // Calcula total de likes (ya esta hecho )
    int totalLikes () {
    int suma = 0;
    for (int i = 0; i < posts ; i ++) {
    suma = suma + likes [ i ];
    }
    return suma ;
    }

    // Publica un post
    void publicar ( int numLikes ) {
    if ( posts < 10) {
    // TODO 1: Guardar numLikes en likes [ posts ]
        likes[posts] = numLikes;
    // TODO 2: Incrementar posts en 1
        posts += 1;
    cout << " Post publicado con " << numLikes << " likes " << endl ;
    } else {    cout << " Maximo de posts alcanzado !" << endl ;    }
    }

    // Gana seguidores
    void ganarSeguidores ( int & segsGanados , int cantidad ) {
        // TODO 3: Sumar cantidad a seguidores
            seguidores += cantidad;
        // TODO 4: Sumar cantidad a segsGanados
            segsGanados += cantidad;
        cout << "+" << cantidad << " seguidores !" << endl ;
    }

    // Pierde seguidores
    void perderSeguidores ( int cantidad ) {
    // TODO 5: Restar cantidad a seguidores
    seguidores = seguidores - cantidad;
    // TODO 6: Si seguidores < 0, ponerlo en 0
    if(seguidores<0) seguidores = 0; 
    cout << "-" << cantidad << " seguidores " << endl ;
    
    }
    
    // Muestra perfil
    void mostrar () {
        cout << " === PERFIL ===" << endl ;
        // TODO 7: Imprimir "@" seguido de username
        cout<<"@"<<username;
        // TODO 8: Imprimir " Seguidores : " seguido de seguidores
        cout<<"Seguidores: "<<seguidores;
        // TODO 9: Imprimir " Posts : " seguido de posts
        cout<<"Posts: "<<posts;
        cout << " Total likes : " << totalLikes () << endl ;
        cout << " Likes por post :" << endl ;
        for (int i = 0; i < posts ; i ++) {
        cout << " Post " << (i +1) << ": " << likes [i] << " likes " << endl ;
        }
    }

    // Retorna puntero a seguidores
    int * getSeguidoresPtr () {
    // TODO 10: Escribir return & seguidores ;
        return &seguidores;
    }
 };
// FUNCION EXTERNA CON PUNTERO
 void comprarSeguidores ( int * ptrSeg , int cantidad ) {
// TODO 11: Sumar cantidad a * ptrSeg
    *ptrSeg += cantidad;
cout << " Advertencia : seguidores falsos no dan likes !" << endl ;
cout << "+" << cantidad << " seguidores comprados " << endl ;
}

int main () {
int segsGanados = 0;
string user ;
int segsIniciales ;
cout << "Tu username : ";
cin >> user ;
cout << " Seguidores iniciales : ";
cin >> segsIniciales ;

Perfil miPerfil ( user , segsIniciales );

int opcion ;
int cantidad ;
while ( true ) {
cout << "\n === INSTAGRAM ANALYTICS === " << endl ;
cout << "1. Publicar post " << endl ;
cout << "2. Ganar seguidores " << endl ;
cout << "3. Perder seguidores " << endl ;
cout << "4. Ver perfil " << endl ;
cout << "5. Comprar seguidores " << endl ;
cout << "6. Salir " << endl ;
cout << " Opcion : ";
cin >> opcion ;
if ( opcion == 1) {
 cout << " Cuantos likes tuvo el post : ";
 cin >> cantidad ;
 miPerfil . publicar ( cantidad );
} else if ( opcion == 2) {
 cout << " Cuantos seguidores ganaste : ";
 cin >> cantidad ;
 miPerfil . ganarSeguidores ( segsGanados , cantidad );
 } else if ( opcion == 3) {
 cout << " Cuantos seguidores perdiste : ";
 cin >> cantidad ;
 miPerfil . perderSeguidores ( cantidad );
 } else if ( opcion == 4) {
 miPerfil . mostrar () ;
 cout << " Seguidores ganados organicamente : " << segsGanados << endl ;
 } else if ( opcion == 5) {
 cout << " Cuantos seguidores comprar : ";
 cin >> cantidad ;
 comprarSeguidores ( miPerfil . getSeguidoresPtr () , cantidad );
 } else if ( opcion == 6) {
 break ;
 }
 }

cout << " Hasta luego !" << endl ;
return 0;
}
