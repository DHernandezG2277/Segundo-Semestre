#include<iostream>
#include<iomanip>
using namespace std;

class Maleta{
	private:
		int Enteros[6];
		//1. cantidad maletas
		//2. valor de produccion de las maletas (unidad)
		//3. valor de maletas a la venta (unidad)
		//4. valor total por las ventas
		//5. valor del IVA
		//6. total de las maletas
		double Decimas[6];
		//1. materia prima
		//2. mano de obra
		//3. servicios
		//4. accesorios
		//5. imprevistos
		//6. costo total de la produccion
		Maleta *sig;
		
	public:
		Maleta();
		~Maleta();
		void EntrarDatos(void);
		void ProcesarDatos(void);
		void MostrarDatos(void);
};

Maleta::Maleta(){
		cout<<"Creando datos....."<<endl;
		for(int i=0; i<6; i++){
			Enteros[i]= 0;
			Decimas[i]= 0.0;
		}
}

void Maleta::EntrarDatos(){
	 cout<<"Ingrese la cantidad de morrales: ";
	 cin>>Enteros[1];
	 cout<<"Ingrese el costo de produccion de los morrales: $";
	 cin>>Enteros[2];
	 cout<<"Ingrese el costo de venta de los morrales: $";
	 cin>>Enteros[3];
}

void Maleta::ProcesarDatos(){
	cout<<fixed<<setprecision(2);
	Decimas[6]= Enteros[1] * Enteros[2];
	Decimas[1]= Decimas[6] * 0.45;
	Decimas[2]= Decimas[6] * 0.33;
	Decimas[3]= Decimas[6] * 0.10;
	Decimas[4]= Decimas[6] * 0.05;
	Decimas[5]= Decimas[6] * 0.07;
	Enteros[4]= Enteros[3] * Enteros[1];
	Enteros[5]= Enteros[4] * 0.19;
	Enteros[6]= Enteros[4] + Enteros[5];
}

void Maleta::MostrarDatos(){
	cout<<fixed<<setprecision(2);
	cout<<"Cantidad de morrales: "<<Enteros[1]<<endl<<endl;
	cout<<"Costo de produccion por morral: $"<<Enteros[2]<<endl<<endl;
	cout<<"Valor de la materia prima de todos los morrales: $"<<Decimas[1]<<endl<<endl;
	cout<<"Costo total de mano de obra por todos los morrales: $"<<Decimas[2]<<endl<<endl;
	cout<<"Costo total por los servicios en la produccion de los morrales: $"<<Decimas[3]<<endl<<endl;
	cout<<"Valor de los accesorios para los morrales: $"<<Decimas[4]<<endl<<endl;
	cout<<"Costo de imprevistos en la produccion de los morrales: $"<<Decimas[5]<<endl<<endl;
	cout<<"Costo total por la produccion de los morrales: $"<<Decimas[6]<<endl<<endl;
	cout<<"Costo de venta por morral: $"<<Enteros[3]<<endl<<endl;
	cout<<"Valor subtotal por la venta de los morrales: $"<<Enteros[4]<<endl<<endl;
	cout<<"Valor del IVA por la venta de los morrales: $"<<Enteros[5]<<endl<<endl;
	cout<<"Valor total por la venta de los morrales: $"<<Enteros[6]<<endl<<endl;
}

Maleta::~Maleta(){
	cout<<"Eliminando datos....."<<endl;
}

int main(){
	Maleta morral;
	morral.EntrarDatos();
	morral.ProcesarDatos();
	morral.MostrarDatos();
	return 0;
}