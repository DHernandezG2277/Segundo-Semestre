//Asignacion dinamica de matrices

#include<iostream>
using namespace std;

class Memoria{
	private:
	
	int **mat;
	double pr;
	int i,j,f,c,s;
	
	public:
	Memoria();
	~Memoria();
	void EntraDatos(void);
	void ProcesaDatos(void);
	void MuestraDatos(void);
};

Memoria::Memoria(){
	cout<<" Matriz..... "<<endl;
	i=j=f=c=s=0;
	pr= 0.0;
	cout<<" Digite el numero de filas: ";
	cin>>f;
	cout<<" Digite el numero de columnas: ";
	cin>>c;
	mat= new int *[f];
	if(mat == NULL){
		cout<<" Error 1 en memoria "<<endl;
		}
	for(i=0; i<f; i++){
		mat[i]= new int [c];
		}
	if(mat[i] == NULL){
		cout<<" Error 2 en memoria "<<endl;
		}
	for(i=0; i<f; i++){
		for(j=0; j<f; j++){
			mat[i][j]=0;
			}
		}
	}
	
Memoria::~Memoria(){
	cout<<" No matriz..... "<<endl;
	for(i=0; i<f; i++){
		delete mat[i];
		delete mat;
		}
	}
	
void Memoria::EntraDatos()
{
		for(i=0; i<f; i++){
			for(j=0; j<c; j++){
				cout<<"Digite el dato "<<endl;
				cin>>mat[i][j];
			}
		}
		
}
	
void Memoria::ProcesaDatos(){
		for(i=0; i<f; i++)
		{
			for(j=0; j<c; j++)
			{
				s= s+mat[i][j];
			}
		}
		pr= s/(f*c);
	}
	

void Memoria::MuestraDatos()
{
	cout<<"Datos en constructor"<<endl;
	for(i=0; i<f; i++)
	{
		for(j=0; j<c; j++)
			cout<<mat[i][j]<<" ";
			cout<<endl;		
			
	}
	cout<<"La sumatoria de la matriz es: "<<s<<endl;
	cout<<"El promedio de la matriz es: "<<pr<<endl;
}
	
	
int main(){
	Memoria obj;
	obj.EntraDatos();
	obj.ProcesaDatos();
	obj.MuestraDatos();
	return -1;
	
}
	
