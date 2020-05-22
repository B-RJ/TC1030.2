// Bruno Ramos Jimenez A01701464

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Clase Padre
// ===========================================

class Sesion{
	public:
		void set_usuario(string u);
		virtual void set_contrasena();
		
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


// Clase hijo Administrador
// ===========================================

class Administrador : public Sesion{
	private:
		string palabra_secreta;
	public:
		int get_contrasena(string u);
		void permitir_imprimir_cuenta(string u);
		void eliminar_cuenta(string u);
		void set_contrasena(int c, int ps); //metodo sobreescrito
		
		Administrador(){}
		Administrador(string u, int c, string ps): Sesion(u,c){
			palabra_secreta = ps;
		}
};

int Administrador :: get_contrasena(string u){
	cout << 1;
}

void Administrador :: permitir_imprimir_cuenta(string u){
	cout << 2;
}

void Administrador :: eliminar_cuenta(string n){
	cout << 3;
}
void Administrador :: set_contrasena(int c, int ps){
	contrasena = c;
	palabra_secreta = ps;
}

// Clase hijo Mesero
// ===========================================

class Mesero : public Sesion{
	protected:
		bool permiso_imprimir_cuenta = true;
	
	public:
		string imprimir_cuenta(int nmesa);
		void imprimir_cuenta();
		void set_contrasena(int c);
		
		Mesero(){}
};

string Mesero :: imprimir_cuenta(int mesa){
	return "cuenta";
}

void Mesero :: imprimir_cuenta(){
	permiso_imprimir_cuenta = !permiso_imprimir_cuenta; 
}

void Mesero :: set_contrasena(int c){
	contrasena = c;
}

// Clase principal
// ===========================================

class Restaurante{
	private:
		string nombre;
		int capacidad_max;
		Administrador administradores[100];
		Mesero meseros[100];
		int contador_admins = 1;
		int contador_meseros = 0;
	public:
		void set_nombre(string n);
		void set_capacidad_max(int cm);
		string get_nombre();
		int get_capacidad_max();
		void actualizar_sesiones(Sesion s);
		
		Restaurante(){}
		Restaurante(string n, int cm, string no, int c, string ps){
			nombre = n;
			capacidad_max = cm;
			Administrador admin1(no,c,ps);
			
		}			
};

void Restaurante :: set_nombre(string n){
	nombre = n;
}

void Restaurante :: set_capacidad_max(int cm){
	capacidad_max = cm;
}

void Restaurante :: actualizar_sesiones(Sesion s){
	
}

int main(){
	return 0;
};
