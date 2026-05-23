#include <iostream>
#include <string>

using namespace std;

struct Espada {
string nombre; // public por defecto
int dano;
}; // <-- quita este ';' y mira el error del compilador

int main() {
Espada e;
e.nombre = "Hacha";
e.dano = 42;
cout << e.nombre << " -- dano: " << e.dano << endl;
return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Personaje {
public:
    // Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
      vida_(vida),
      nivel_(nivel) {}

void mostrar() const { // const: este metodo no modifica el objeto
    cout<< "[" << nivel_ << "] " << nombre_
        << " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }
// Destructor -- lo convertiremos en virtual en el Bloque 4
~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
    string nombre_;
    int vida_;
    int nivel_;
}; // <-- punto y coma obligatorio

int main() {
    Personaje heroe("Elara", 85, 3);
    heroe.mostrar();
    return 0;
}


#include <iostream>
#include <string>
using namespace std;
class Personaje {
public:
    // Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
      vida_(vida),
      nivel_(nivel) {}

void mostrar() const { // const: este metodo no modifica el objeto
    cout<< "[" << nivel_ << "] " << nombre_
        << " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }
// Destructor -- lo convertiremos en virtual en el Bloque 4
~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
    string nombre_;
    int vida_;
    int nivel_;
}; // <-- punto y coma obligatorio


#include <iostream>
#include <string>

using namespace std;

class Personaje {
public:
    // Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
      vida_(vida),
      nivel_(nivel) {}

void mostrar() const { // const: este metodo no modifica el objeto
    cout<< "[" << nivel_ << "] " << nombre_
        << " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }
// Destructor -- lo convertiremos en virtual en el Bloque 4
~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
    string nombre_;
    int vida_;
    int nivel_;
}; // <-- punto y coma obligatorio

class Guerrero : public Personaje { // hereda de Personaje
public:
    Guerrero(string nombre, int vida, int nivel,string arma, int fuerza)
    : Personaje(nombre, vida, nivel), // inicializa la parte Personaje primero
        arma_(arma),
        fuerza_(fuerza) {}

    void info_guerrero() const {
        cout << " Arma : " <<arma_ << endl;
        cout << " Fuerza: " << fuerza_ << endl;
    }
private:
    string arma_;
    int fuerza_;
};

class Mago : public Personaje { // hereda de Personaje
    public:
        Mago(string  nombre, int vida, int nivel,
            string escuela,int mana)
            
            :Personaje(nombre,vida,nivel), // inicializa la parte Personaje primero
            escuela_(escuela),
            mana_(mana) {}

    void info_mago() const {
        cout << " Escuela: " << escuela_ << endl;
        cout << " Mana: " << mana_ << endl;
    }

    private:
        string escuela_;
        int mana_;
};  


int main () {
    Guerrero g("Thorin", 100, 5, "Hacha de Guerra", 42);
    g.mostrar(); // HEREDADO de Personaje -- no lo escribiste en Guerrero
    g.info_guerrero(); // PROPIO de Guerrero
    cout << endl;

    Mago m("Elara", 75, 7, "Fuego", 120);
    m.mostrar(); // HEREDADO de Personaje
    m.info_mago(); // PROPIO de Mago
    return 0;

    Guerrero Ragnar ("Ragnar", 120, 8, "Espada Runa", 85);
    Ragnar.mostrar();
    Ragnar.info_guerrero();
    cout << endl;

    Mago Seraphina("Seraphina", 60, 9, "Hielo", 200);
    Seraphina.mostrar();
    Seraphina.info_mago();
}
#include <iostream>
#include <string>

using namespace std;

class Personaje {
public:
    // Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
      vida_(vida),
      nivel_(nivel) {}

virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;
}

void mostrar() const { // const: este metodo no modifica el objeto
    cout<< "[" << nivel_ << "] " << nombre_
        << " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }
// Destructor -- lo convertiremos en virtual en el Bloque 4
~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
    string nombre_;
    int vida_;
    int nivel_;
}; // <-- punto y coma obligatorio

class Guerrero : public Personaje { // hereda de Personaje
public:
    Guerrero(string nombre, int vida, int nivel,string arma, int fuerza)
    : Personaje(nombre, vida, nivel), // inicializa la parte Personaje primero
        arma_(arma),
        fuerza_(fuerza) {}

    void info_guerrero() const {
        cout << " Arma : " <<arma_ << endl;
        cout << " Fuerza: " << fuerza_ << endl;
    }
    void atacar() const override {
    cout << nombre_ << " golpea con " << arma_ << endl;
    cout << " Dano fisico: " << fuerza_ * 2 << endl;
    }

private:
    string arma_;
    int fuerza_;
};

class Mago : public Personaje { // hereda de Personaje
    public:
        Mago(string  nombre, int vida, int nivel,
            string escuela,int mana)
            
            :Personaje(nombre,vida,nivel), // inicializa la parte Personaje primero
            escuela_(escuela),
            mana_(mana) {}

    void info_mago() const {
        cout << " Escuela: " << escuela_ << endl;
        cout << " Mana: " << mana_ << endl;
    }
    void atacar() const override {
    cout << nombre_ << " lanza un hechizo de " << escuela_ << endl;
    cout << " Dano mágico: " << mana_ / 2 << endl;
    }

    private:
        string escuela_;
        int mana_;
};  


int main () {

    Personaje p ("aldeano",30,1);
    Guerrero g("Thorin", 100, 5, "Hacha de Guerra", 42);
    Mago m("Elara", 75, 7, "Fuego", 120);
    
    p.atacar(); // ataca de forma basica
    g.atacar(); // Sobrescribe el metodo atacar de Personaje
    m.atacar();
    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Personaje {
public:
    // Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
      vida_(vida),
      nivel_(nivel) {}

virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;
}

void mostrar() const { // const: este metodo no modifica el objeto
    cout<< "[" << nivel_ << "] " << nombre_
        << " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }
// Destructor -- lo convertiremos en virtual en el Bloque 4
virtual ~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
    string nombre_;
    int vida_;
    int nivel_;
}; // <-- punto y coma obligatorio

class Guerrero : public Personaje { // hereda de Personaje
public:
    Guerrero(string nombre, int vida, int nivel,string arma, int fuerza)
    : Personaje(nombre, vida, nivel), // inicializa la parte Personaje primero
        arma_(arma),
        fuerza_(fuerza) {}

    void info_guerrero() const {
        cout << " Arma : " <<arma_ << endl;
        cout << " Fuerza: " << fuerza_ << endl;
    }
    void atacar() const override {
    cout << nombre_ << " golpea con " << arma_ << endl;
    cout << " Dano fisico: " << fuerza_ * 2 << endl;
    }

private:
    string arma_;
    int fuerza_;
};

class Mago : public Personaje { // hereda de Personaje
    public:
        Mago(string  nombre, int vida, int nivel,
            string escuela,int mana)
            
            :Personaje(nombre,vida,nivel), // inicializa la parte Personaje primero
            escuela_(escuela),
            mana_(mana) {}

    void info_mago() const {
        cout << " Escuela: " << escuela_ << endl;
        cout << " Mana: " << mana_ << endl;
    }
    void atacar() const override {
    cout << nombre_ << " lanza un hechizo de " << escuela_ << endl;
    cout << " Dano mágico: " << mana_ / 2 << endl;
    }

    private:
        string escuela_;
        int mana_;
};  


int main() {
vector<Personaje*> partida;
partida.push_back(new Personaje("Aldeano", 30, 1));
partida.push_back(new Guerrero("Thorin", 100, 5, "Hacha de Guerra", 42));
partida.push_back(new Mago("Elara", 75, 7, "Fuego", 120));
partida.push_back(new Guerrero("Ragnar", 120, 8, "Espada Runa", 58));
cout << "=== RONDA DE COMBATE ===" << endl;
for (Personaje* p : partida) {
p->mostrar(); // dispatch virtual -- ejecuta mostrar() de Personaje
p->atacar(); // dispatch virtual -- cada objeto responde a su manera
cout << endl;
}
// Liberar memoria: delete activa el destructor virtual correcto
for (Personaje* p : partida) delete p;
return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Personaje {
public:
    Personaje(string nombre, int vida, int nivel)
        : nombre_(nombre), vida_(vida), nivel_(nivel) {}

    virtual void atacar() const {
        cout << nombre_ << " ataca de forma basica." << endl;
    }

    void mostrar() const {
        cout << "[" << nivel_ << "] " << nombre_
             << " HP: " << vida_ << endl;
    }

    string getNombre() const { return nombre_; }
    int getVida() const { return vida_; }
    int getNivel() const { return nivel_; }

    virtual ~Personaje() {}

protected:
    string nombre_;
    int vida_;
    int nivel_;
};

class Arquero : public Personaje {
public:
    Arquero(string nombre, int vida, int nivel,
            string arco, int precision)
        : Personaje(nombre, vida, nivel),
          arco_(arco), precision_(precision) {}

    void atacar() const override {
        cout << nombre_ << " dispara con " << arco_ << endl;
        cout << "Precision: " << precision_
             << "% Dano: " << precision_ * 3 << endl;
    }

private:
    string arco_;
    int precision_;
};

int main() {
    vector<Personaje*> partida;

    partida.push_back(new Arquero("Legolas", 100, 5, "Arco largo", 90));
    partida.push_back(new Arquero("Robin", 80, 4, "Arco corto", 75));

    for (auto p : partida) {
        p->atacar();
    }
    for (auto p : partida) {
        delete p;
    }

    return 0;
}
