// Bruno Ramos Jimenez A01701464

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Clase Padre
// ===========================================

class Sesion{
	public:
		void set_usuario(string u);
		virtual void set_contrasena(int contra);
		string get_usuario() const;
		int get_contrasena() const;
		
		Sesion(){}
		Sesion(string u, int c){
			usuario = u;
			contrasena = c;
	}
	
	protected:
		string usuario;
		int contrasena;
};

void Sesion :: set_usuario(string u){
	usuario = u;
};

string Sesion :: get_usuario() const{
	return usuario;
}

void Sesion :: set_contrasena(int contra){
	contrasena = contra;
}

int Sesion :: get_contrasena() const{
	return contrasena;
}


// Clase hijo Administrador
// ===========================================

class Administrador : public Sesion{
	private:
		string palabra_secreta;
	public:
		void permitir_imprimir_cuenta(string u);
		void eliminar_cuenta(string u);
		void set_contrasena(int c, string ps); //metodo sobreescrito
		
		Administrador(){}
		Administrador(string u, int c, string ps): Sesion(u,c){
			palabra_secreta = ps;
		}
};


void Administrador :: permitir_imprimir_cuenta(string u){
	cout << 2;
}

void Administrador :: eliminar_cuenta(string n){
	cout << 3;
}
void Administrador :: set_contrasena(int c, string ps){
	if(ps == palabra_secreta){
		contrasena = c;
	}
	else{
		cout << "Palabra secreta incorrecta";
	}
	
}

// Clase hijo Mesero
// ===========================================

class Mesero : public Sesion{
	protected:
		bool permiso_imprimir_cuenta = true;
	
	public:
		string imprimir_cuenta(int nmesa);
		void imprimir_cuenta();
		
		
		Mesero(){}
		Mesero(string u, int c): Sesion(u,c){}
};

string Mesero :: imprimir_cuenta(int mesa){
	return "cuenta";
}

void Mesero :: imprimir_cuenta(){
	permiso_imprimir_cuenta = !permiso_imprimir_cuenta; 
}

//class Bar_tender : public Sesion{
//	protected:
		
//}


// Clase principal
// ===========================================

class Restaurante{
	private:
		string nombre;
		int capacidad_max = 10;
	public:
		void set_nombre(string n);
		void set_capacidad_max(int cm);
		string get_nombre();
		virtual void get_capacidad_max();
		void actualizar_sesiones(vector<Administrador>&);
		void actualizar_sesiones(vector<Mesero>&);
		void mostrar_sesiones(const vector<Administrador>&);
		void mostrar_sesiones(const vector<Mesero>&);
		void cambio_contrasena(vector<Administrador>&,string n, int c, string ps);
		void cambio_contrasena(vector<Mesero>&,string n, int c);
		
		
		Restaurante(){}
		//Restaurante(string n, int cm, string no, int c, string ps){
		//	nombre = n;
		//	capacidad_max = cm;
		//	Administrador *admin1 = new Administrador(no,c,ps);
			
		//}			
};

void Restaurante :: set_nombre(string n){
	nombre = n;
}

void Restaurante :: set_capacidad_max(int cm){
	capacidad_max = cm;
}
void Restaurante :: get_capacidad_max(){
	cout << capacidad_max << endl;
}

void Restaurante :: actualizar_sesiones(vector<Administrador>& nmi_clase){
	cout << "Numero de cuentas administrador";
	int tamano_clase;
	string nombre_cuenta_ad;
	int contrasena_ad;
	string palabra_s;
	cin >> tamano_clase;
	
	for (int i = 0; i < tamano_clase; i++){
		cout << "Nombre cuenta ";
		cin >> nombre_cuenta_ad;
		cout << "Contrasena ";
		cin >> contrasena_ad;
		cout << "Palabra secreta ";
		cin >> palabra_s;
		
		Administrador nuevoadmin(nombre_cuenta_ad,contrasena_ad,palabra_s);
		
		nmi_clase.push_back(nuevoadmin);
		cout << endl;
		
	}
	cout << endl;
}

void Restaurante :: actualizar_sesiones(vector<Mesero>& nmi_clase){
	cout << "Numero de cuentas mesero";
	int tamano_clase;
	string nombre_cuenta_ad;
	int contrasena_ad;
	cin >> tamano_clase;
	
	for (int i = 0; i < tamano_clase; i++){
		cout << "Nombre cuenta ";
		cin >> nombre_cuenta_ad;
		cout << "Contrasena ";
		cin >> contrasena_ad;
		
		Mesero nuevomese(nombre_cuenta_ad,contrasena_ad);
		
		nmi_clase.push_back(nuevomese);
		cout << endl;
		
	}
	cout << endl;
}

void Restaurante :: mostrar_sesiones(const vector<Administrador>& nmi_clase){
	unsigned int tamano = nmi_clase.size();
	for (unsigned int i = 0; i < tamano; i++){
		cout << "Nombre: " << nmi_clase[i].get_usuario() << endl;
		cout << "Contrasena: " << nmi_clase[i].get_contrasena() << endl;
		cout << endl;
	}
}

void Restaurante :: mostrar_sesiones(const vector<Mesero>& nmi_clase){
	unsigned int tamano = nmi_clase.size();
	for (unsigned int i = 0; i < tamano; i++){
		cout << "Nombre: " << nmi_clase[i].get_usuario() << endl;
		cout << "Contrasena: " << nmi_clase[i].get_contrasena() << endl;
		cout << endl;
	}
}

void Restaurante :: cambio_contrasena(vector<Administrador>& nmi_clase,string n, int c, string ps){
	unsigned int tamano = nmi_clase.size();
	for (unsigned int i = 0; i < tamano; i++){
		if(n == nmi_clase[i].get_usuario()){
			
			nmi_clase[i].set_contrasena(c,ps);
		}
		cout << endl;
	}
}


void Restaurante :: cambio_contrasena(vector<Mesero>& nmi_clase,string n, int c){
	unsigned int tamano = nmi_clase.size();
	for (unsigned int i = 0; i < tamano; i++){
		if(n == nmi_clase[i].get_usuario()){
			
			nmi_clase[i].set_contrasena(c);
		}
		cout << endl;
	}
}

class Restaurante_con_antro : public Restaurante{
	protected:
		int capacidad_max_rest = 10;
		int capacidad_max_antro = 50;
	public:
		void set_capacidad_max_rest();
		void set_capacidad_max_antro();
		void get_capacidad_max();
		Restaurante_con_antro(){}
		
};

void Restaurante_con_antro :: get_capacidad_max(){
	cout << capacidad_max_rest + capacidad_max_antro << endl;
}
int main(){
	vector<Administrador> mi_clase;
	vector<Mesero> mi_clase2;
	vector<Administrador> mi_clase_bar;
	vector<Mesero> mi_clase2_bar;
	Restaurante *rest1 = new Restaurante();
	Restaurante *rest2 = new Restaurante_con_antro();
	rest1->get_capacidad_max();
	rest2->get_capacidad_max();
	
	//rest1->actualizar_sesiones(mi_clase);
	//rest1->mostrar_sesiones(mi_clase);
	
	rest1->actualizar_sesiones(mi_clase2);
	rest1->mostrar_sesiones(mi_clase2);
	string nom_cue;
	int contra;
	cout << "Nombre de cuenta a la cual cambiar contrasena";
	cin >> nom_cue;
	cout << "Nueva contrasena ";
	cin >> contra;
	rest1->cambio_contrasena(mi_clase2, nom_cue, contra);
	rest1->mostrar_sesiones(mi_clase2);
	
	//Cambio contra
	return 0;
};