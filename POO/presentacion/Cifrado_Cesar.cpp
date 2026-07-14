#include<iostream>
using namespace std;

class CifradoCesar{
	private:
		char Alfabeto[27];
		char Frase[30];
		char Frase_codificada[30];
		
	public:
		CifradoCesar();
		~CifradoCesar();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
};

CifradoCesar::CifradoCesar(){
	cout<<"Creando datos....."<<endl;
	for(int i=0; i<27; i++){
		Alfabeto[i] = '\0';
	}
	for(int i=0; i<30; i++){
		Frase[i] = '\0';
		Frase_codificada[i] = '\0';
	}
}

void CifradoCesar::EntrarDatos(){
	cout<<"Rellenar alfabeto..."<<endl;
	for(int i=0; i<27; i++){
		cout<<"Por favor ingrese la "<<i+1<<" letra del alfabeto: ";
		cin>>Alfabeto[i];
	}
	cout<<"Ingresar frase: "<<endl;
	for(int i=0; i<30; i++){
		cin.getline(Frase, 30);
	}
}

void CifradoCesar::ProcesarDatos(){
	for(int i=0; i<30; i++){
		int j=0;
		while(Frase[i] != Alfabeto[j]){
			j++;
		}
		Frase_codificada[i] = Alfabeto[j+3];
	}
}

void CifradoCesar::MostrarDatos(){
	cout<<"La frase digitada es: ";
	for(int i=0; i<30; i++){
		cout<<Frase[i];
	}
	cout<<endl;
	cout<<"La frase codificada queda: ";
	for(int i=0; i<30; i++){
		cout<<Frase_codificada[i];
	}
	cout<<endl;
}

CifradoCesar::~CifradoCesar(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	CifradoCesar cifrador;
	cifrador.EntrarDatos();
	cifrador.ProcesarDatos();
	cifrador.MostrarDatos();
	return 0;
}