#include<iostream>
using namespace std;

class Arreglos
{
 public:
 	void Entrada(int *&, int &, int *&);
 	void Proceso(int *&, int &);
 	void Salida(int *&, int &, int *&);
};

void Arreglos::Entrada(int *&entero, int &grande, int *&copia)
 {
   cout<<"Ingrese la dimension del arreglo entero: ";
   cin>>grande;
   entero=new int[grande];
   copia=new int[grande];
   for(int i=0; i<grande; i++)
   {
     int n=0;
     cout<<"Ingrese un numero entero: ";
     cin>>n;
     entero[i]=n;
     copia[i]=entero[i];
   }
 }

void Arreglos::Proceso(int *&entero, int &grande)
 {
     
   int aux=0; 
   for(int i=0; i<grande*2; i++)
   {
     int j=0;
     while(j < grande  && entero[j] < entero[j+1])
     {
       j++;
     }
     if(j<grande-1)
		{
			aux=entero[j];
     		entero[j] = entero[j+1];
     		entero[j+1] = aux;
		}
   }
 }
 
 void Arreglos::Salida(int *&entero, int &grande, int *&copia)
{
	cout<<"Los numeros enteros ingresados son: "<<endl;
	for(int i=0; i<grande; i++)
  		{
    		cout<<copia[i]<<", ";
 		}
 	cout<<endl;
  	cout<<"Los numeros enteros organizados son: "<<endl;
 	 for(int i=0; i<grande; i++)
  		{
    		cout<<entero[i]<<", ";
 		}
 	cout<<endl;
}   


int main()
{
  Arreglos arr;
  int *entero;
  int *copia;
  int tama=0;
  arr.Entrada(entero, tama, copia);
  arr.Proceso(entero, tama);
  arr.Salida(entero, tama, copia);
  return 0;
}