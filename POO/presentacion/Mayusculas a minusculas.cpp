#include<iostream>
using namespace std;

class ConversionTexto{
	private:
		char cadena_original[100];
		char cadena_convertida[100];
		int longitud;
		
	public:
		ConversionTexto();
		~ConversionTexto();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
		void ObtenerLongitud(void);
};

ConversionTexto::ConversionTexto(){
	cout<<"Creando datos....."<<endl;
	for(int i=0; i<100; i++){
		cadena_original[i] = '\0';
		cadena_convertida[i] = '\0';
	}
	longitud = 0;
}

void ConversionTexto::EntrarDatos(){
	cout<<"Por favor ingrese una cadena de texto: ";
	cin.ignore();
	cin.getline(cadena_original, 100);
}

void ConversionTexto::ObtenerLongitud(){
	longitud = 0;
	while(cadena_original[longitud] != '\0'){
		longitud++;
	}
}

void ConversionTexto::ProcesarDatos(){
	ObtenerLongitud();
	
	for(int i=0; i<longitud; i++)
	{
		if(cadena_original[i] >= 'A' && cadena_original[i] <= 'Z')
		{
			cadena_convertida[i] = cadena_original[i] + 32;
		}
		else if(cadena_original[i] >= 'a' && cadena_original[i] <= 'z')
		{
			cadena_convertida[i] = cadena_original[i] - 32;
		}
		else
		{
			cadena_convertida[i] = cadena_original[i];
		}
	}
	cadena_convertida[longitud] = '\0';
}

void ConversionTexto::MostrarDatos(){
	cout<<endl;
	cout<<"Cadena original: "<<cadena_original<<endl<<endl;
	cout<<"Cadena convertida: "<<cadena_convertida<<endl<<endl;
}

ConversionTexto::~ConversionTexto(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	ConversionTexto conversion;
	conversion.EntrarDatos();
	conversion.ProcesarDatos();
	conversion.MostrarDatos();
	return 0;
}