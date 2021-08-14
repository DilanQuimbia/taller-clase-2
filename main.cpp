#include <iostream>
#include <fstream>
using namespace std;
ofstream binario;
void Burbuja (int a[],int n);
void Busqueda(int a[],int n,int dato);
int main()
{
  
  int n,a[n];
  binario.open("BDD/binario.txt",ios::app);
  cout<<"Cuantos datos vas a ingresar: ";
  cin>>n;
  binario<<"Los datos ingresados son: ";
    for (int i=0;i<n;i++){
      cout<<"Ingresa el dato "<<i+1<<" : ";
      cin>>a[i];
      binario<<"["<<a[i]<<"]";
    }
   Burbuja (a,n);
    cout << " Los datos ordenados son: ";
    binario << " Los datos ordenados son: ";

    for(int i=0 ; i<n ; i++){
      cout << a[i];
      binario << a[i] << " : " ;
    }
    int b;
    cout << endl;
    cout <<" Cual de los datos que ingresados deseas buscar? ";
    cin>>b;
    binario<<endl;
    binario<<"El elemento a buscar es: "<<b<<endl;
    int i,j,k;
    i=0;
    j=n-1;
  
    do
    {
        k=(i+j)/2;
        if(a[k]<=b)
          {
            i=k+1;
          }
        if (a[k]>=b)
          {
            j=k-1;
          }
    }while (i<=j);

    if(a[k]==b)
    {
      cout <<"\nElemento encontrado en la posición:"<<k+1<<endl;
      binario <<"\nElemento encontrado en la posición:"<<k<<endl;
    }
    else 
    {
      cout <<"\nElemento no encontrado"<<endl;
      binario <<"\nElemento no encontrado"<<endl;
    }
      binario.close();
   return 0;
}

void Burbuja (int a[],int n)
{
  int aux;
  for (int i=0 ; i<n ; i++)
  {
    for(int j=i+1 ; j<n ; j++)
    {
      if(a[j]<a[i])
      {
        aux=a[i];

        a[i]=a[j];

        a[j]=aux;

      }
    }
  }
}