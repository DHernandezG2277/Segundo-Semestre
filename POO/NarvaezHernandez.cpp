#include<iostream>
#include<fstream>
using namespace std;

class Archivo{
	private:
	char Frase[100];
	int contador=0;
	char Letra;
	int Vocales, Longitud, Palabras,Mayuscula, Minuscula, Letras_t,       Espacios_blanco;
	public:
	Archivo();
	~Archivo();
	void CrearArchivo(void);
	void Contador(void);
	void AbrirArchivo(void);
};

Archivo::Archivo(){
	cout<<"Iniciando...."<<endl;
	Vocales=0, Longitud=0, Palabras=0, Mayuscula=0, Minusculas=0, Letras_t=0, Espacios_blanco=0;
}

void Archivo::CrearArchivo(){
	ofstream Salida("texto303.txt");
	Salida<<"Tanto si piensas que puedes como si crees que no puedes, estas en lo cierto. ¡Programo luego existo!$"<<endl;
}

void Archivo::AbrirArchivo(){
	ifstream Entrada("texto303.txt");
	while (Entrada.get(Letra) && contador<99){
		Frase[contador++] = Letra;
	}
	Frase[contador] = '\0';
}

void Archivo::Contador(){
	for(int i=0; Frase[i]!= '\0'; i++){
		if(Frase[i] == 'a' || Frase[i] == 'e' || Frase[i] == 'i'|| Frase[i] == 'o' || Frase[i] == 'u'){
			Vocales++;
		}
		Longitud++;
		if(Frase[i]== NULL){
			Palabras++;
			Espacios_blanco++;
		}
		if(Frase[i]>='A'&& Frase[i]<='Z'){
		Mayuscula++;
		}if(Frase[i]>='a'&& Frase[i]<='z'){
		Minuscula++;
	      } 
	      Letras_t= Longitud-Espacios_blanco;
               }
}
	      
		
	
	
	
