#include <iostream>
#include <malloc.h>

using namespace std;

struct no {
  int codigo;
  struct no *prox;
};
void inserir(no**inicio)
{
  no *aux;
  aux = (no*)malloc(sizeof(no));
  if(aux!=NULL)
  {
    cout<< "Digite um valor:";
    cin >> aux ->codigo;
    aux->prox=(*inicio);
    (*inicio)=aux;
  }
}
void impressao(no*inicio)
{
  no *aux;
  aux=inicio;
  while(aux!=NULL){
    cout<< aux ->codigo;
    aux=aux->prox;
  }
}

int main() 
{
int lista,i;
no *inicio=NULL;
no *aux;

cout << " Digite o tamanho da lista ligada:" ;
cin >> lista;
for(i=0;i<lista; i++)
{
  inserir(&inicio);
  }
  impressao(inicio);
  return 0;
}