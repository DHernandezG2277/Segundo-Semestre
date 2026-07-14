//organizador de arreglos entero, flotante y char

#include<iostream>
using namespace std;

class Arreglos
{
 public:
 	void Entrada(int *);
 	void Entrada(float *);
 	void Entrada(char *);
 	void Proceso(int *, int);
 	void Proceso(float *, int);
 	void Proceso(char *, int);
 	void Salida(int *, int);
 	void Salida(float *, int);
 	void Salida(char *, int);
};


void Arreglos::Entrada(int *entero)
 {
 	int grande=0;
   cout<<"Ingrese la dimension del arreglo entero: ";
   cin>>grande;
   entero=new int[grande];
   for(int i=0; i<grande; i++)
   {
     int n=0;
     cout<<"Ingrese un numero entero: ";
     cin>>n;
     entero[i]=n;
   }
   Proceso(entero, grande);
 }
  
void Arreglos::Entrada(float *flotante)
 {
 	int grande=0;
   cout<<"Ingrese la dimension del arreglo flotante: ";
   cin>>grande;
   flotante=new float[grande];
   for(int i=0; i<grande; i++)
   {
     float n=0.0;
     cout<<"Ingrese un numero decimal: ";
     cin>>n;
     flotante[i]=n;
   }
   Proceso(flotante, grande);
 } 

void Arreglos::Entrada(char *cadena)
 {
 	int grande=0;
   cout<<"Ingrese la dimension de la cadena: ";
   cin>>grande;
   cadena=new char[grande];
   for(int i=0; i<grande; i++)
   {
     char n= '\0' ;
     cout<<"Ingrese un caracter: ";
     cin>>n;
     cadena[i]=n;
   }
   Proceso(cadena, grande);
 }
 
void Arreglos::Proceso(int *entero, int grande)
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
   Salida(entero, grande);
 }

void Arreglos::Proceso(char *cadena, int grande)
 {
     
   int aux=0; 
   for(int i=0; i<grande*2; i++)
   {
     int j=0;
     while(j < grande  && cadena[j] <= cadena[j+1])
     {
       j++;
     }
     if(j<grande-1)
		{
			aux=cadena[j];
     		cadena[j] = cadena[j+1];
     		cadena[j+1] = aux;
		}
   }
   Salida(cadena, grande);
 }
 
void Arreglos::Proceso(float *flotante, int grande)
 {
     
   int aux=0; 
   for(int i=0; i<grande*2; i++)
   {
     int j=0;
     while(j < grande  && flotante[j] < flotante[j+1])
     {
       j++;
     }
     if(j<grande-1)
		{
			aux=flotante[j];
     		flotante[j] = flotante[j+1];
     		flotante[j+1] = aux;
		}
   }
   Salida(flotante, grande);
 }

void Arreglos::Salida(int *entero, int grande)
{
  cout<<"Los numeros enteros organizados son: "<<endl;
  for(int i=0; i<grande; i++)
  {
    cout<<entero[i]<<", ";
  }
  
  cout<<endl;
}   
  
void Arreglos::Salida(float *flotante, int grande)
{
  cout<<"Los numeros decimales organizados son: "<<endl;
  for(int i=0; i<grande; i++)
  {
    cout<<flotante[i]<<", ";
  }
  
  cout<<endl;
}    

void Arreglos::Salida(char *cadena, int grande)
{
  cout<<"Los caracteres organizados son: "<<endl;
  for(int i=0; i<grande; i++)
  {
    cout<<cadena[i]<<", ";
  }
  
  cout<<endl;
} 



int main()
{
  Arreglos arr;
  int *entero;
  float *flotante;
  char *cadena;
  arr.Entrada(entero);
  arr.Entrada(flotante);
  arr.Entrada(cadena);
  return 0;
}

     
     
     
     
     
     
