#include<iostream>
using namespace std;

class Factorial{
	private:
		int n;
		int n_factorial;
		
	public:
		Factorial();
		~Factorial();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
};

Factorial::Factorial(){
	cout<<"Creando datos....."<<endl;
	n = 0;
	n_factorial = 0;
}

void Factorial::EntrarDatos(){
	cout<<"Por favor ingrese un numero a operar: ";
	cin>>n;
}

void Factorial::ProcesarDatos(){
	n_factorial = 1;
	for(int i=1; i<=n; i++){
		n_factorial *= i;
	}
}

void Factorial::MostrarDatos(){
	cout<<"El factorial del numero "<<n<<" es: "<<n_factorial<<endl;
}

Factorial::~Factorial(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	Factorial calculo;
	calculo.EntrarDatos();
	calculo.ProcesarDatos();
	calculo.MostrarDatos();
	return 0;
}