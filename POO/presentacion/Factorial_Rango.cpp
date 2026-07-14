#include<iostream>
using namespace std;

class FactorialRango{
	private:
		int m;
		int n;
		int factorial;
		
	public:
		FactorialRango();
		~FactorialRango();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
};

FactorialRango::FactorialRango(){
	cout<<"Creando datos....."<<endl;
	m = 0;
	n = 0;
	factorial = 0;
}

void FactorialRango::EntrarDatos(){
	cout<<"Por favor digite el primer numero del rango: ";
	cin>>m;
	cout<<"Por favor digite el ultimo numero del rango: ";
	cin>>n;
}

void FactorialRango::ProcesarDatos(){
	factorial = 1;
	for(int i=m; i<=n; i++){
		factorial *= i;
	}
}

void FactorialRango::MostrarDatos(){
	cout<<"El factorial calculado desde "<<m<<" hasta "<<n<<" es: "<<factorial<<endl;
}

FactorialRango::~FactorialRango(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	FactorialRango calculo;
	calculo.EntrarDatos();
	calculo.ProcesarDatos();
	calculo.MostrarDatos();
	return 0;