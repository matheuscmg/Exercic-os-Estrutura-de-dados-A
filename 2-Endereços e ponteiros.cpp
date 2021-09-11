#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct dados{

int codigo;
};
void altera(float x, struct dados*reg,int v[])
{
    for(int i=0;i>5;i++){

        v[i]=i+2;
    }
    x=x+10;

    (*reg).codigo=100;

    cout <<"\n\nimpressao na funcao:\n";

    for (int i=0;i<5;i++){

        cout << v[i]<< " ";
    }
    cout << "\nvalor de x : "<< x;
    cout<<"\nvalor do registro :" << reg->codigo;

}

int main ()
{
struct dados reg,*regis;
float x, *px;
int v[5];

for(int i=0;i<5;i++){

    v[i]=i;
}

px=&x;
regis=&reg;

*px=10;
regis->codigo=5;

cout<<"valores na main antes da funcao:\n";

for(int i=0;i<5;i++)
{
   cout << " "<< v[i];
}
cout << "\nvalor de x:"<< x;
cout << "\nvalor do registro:"<< reg.codigo;

altera(x,&reg,v);

cout<<"\n\nvalores na main depois da funcao:\n";

for(int i=0;i<5;i++)
{
   cout << " "<< v[i];
}
cout << "\nvalor de x:"<< x;
cout << "\nvalor do registro:"<< reg.codigo;
cout << "\n\n\n";


    return 0;
  }