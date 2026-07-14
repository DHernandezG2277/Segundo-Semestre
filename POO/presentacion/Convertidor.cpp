#include<iostream>
using namespace std;

class ConversionSistemas{
	private:
		int numero_decimal;
		char binario[50];
		char octal[50];
		char hexadecimal[50];
		
	public:
		ConversionSistemas();
		~ConversionSistemas();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
		void DecimalABinario(void);
		void DecimalAOctal(void);
		void DecimalAHexadecimal(void);
};

ConversionSistemas::ConversionSistemas(){
	cout<<"Creando datos....."<<endl;
	numero_decimal = 0;
	for(int i=0; i<50; i++){
		binario[i] = '\0';
		octal[i] = '\0';
		hexadecimal[i] = '\0';
	}
}

void ConversionSistemas::EntrarDatos(){
	cout<<"Por favor ingrese un numero decimal: ";
	cin>>numero_decimal;
}

void ConversionSistemas::DecimalABinario(){
	if(numero_decimal == 0){
		binario[0] = '0';
		binario[1] = '\0';
		return;
	}
	
	int temp[50];
	int indice = 0;
	int n = numero_decimal;
	
	while(n > 0){
		temp[indice] = n % 2;
		n = n / 2;
		indice++;
	}
	
	for(int i=0; i<indice; i++){
		binario[i] = temp[indice - 1 - i] + '0';
	}
	binario[indice] = '\0';
}

void ConversionSistemas::DecimalAOctal(){
	if(numero_decimal == 0){
		octal[0] = '0';
		octal[1] = '\0';
		return;
	}
	
	int temp[50];
	int indice = 0;
	int n = numero_decimal;
	
	while(n > 0){
		temp[indice] = n % 8;
		n = n / 8;
		indice++;
	}
	
	for(int i=0; i<indice; i++){
		octal[i] = temp[indice - 1 - i] + '0';
	}
	octal[indice] = '\0';
}

void ConversionSistemas::DecimalAHexadecimal(){
	if(numero_decimal == 0){
		hexadecimal[0] = '0';
		hexadecimal[1] = '\0';
		return;
	}
	
	char digitos_hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int temp[50];
	int indice = 0;
	int n = numero_decimal;
	
	while(n > 0){
		temp[indice] = n % 16;
		n = n / 16;
		indice++;
	}
	
	for(int i=0; i<indice; i++){
		hexadecimal[i] = digitos_hex[temp[indice - 1 - i]];
	}
	hexadecimal[indice] = '\0';
}

void ConversionSistemas::ProcesarDatos(){
	DecimalABinario();
	DecimalAOctal();
	DecimalAHexadecimal();
}

void ConversionSistemas::MostrarDatos(){
	cout<<endl;
	cout<<"Numero decimal: "<<numero_decimal<<endl<<endl;
	cout<<"En binario: "<<binario<<endl<<endl;
	cout<<"En octal: "<<octal<<endl<<endl;
	cout<<"En hexadecimal: "<<hexadecimal<<endl<<endl;
}

ConversionSistemas::~ConversionSistemas(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	ConversionSistemas conversion;
	conversion.EntrarDatos();
	conversion.ProcesarDatos();
	conversion.MostrarDatos();
	return 0;
}