#include <iostream>
#include <malloc.h>

using namespace std;

struct NO
{
    int num;
    struct NO *prox;
};


void push(NO **pilha)
{

    NO *aux;
    aux = (NO *)malloc(sizeof(NO)); 
   
    if (aux != NULL)
    {
        cout << "\n Digite o numero para inserir na pilha:";
        cin >> aux->num;
        aux->prox = (*pilha);
        *pilha = aux;
    }
}

void imprimepilha(NO *pilha)
{

    while (pilha != NULL)
    {
        cout << pilha->num;
        pilha = pilha->prox;
    }
}

void pop(NO **pilha)
{

    if (*pilha == NULL)
       cout << "\n Nao ha elementos na fila\n";

    else
    {
        NO *lixo = *pilha;
        *pilha = (*pilha)->prox;
        free(lixo);
    }
}



int main()
{

    int res;
    NO *pilha = NULL;

    do
    {
      cout<<"\n\nO que deseja fazer ?";
      cout<<"\n1 - Iserir elementos na pilha.";
      cout<<"\n2 - Imprimir elementos na pilha.";
      cout<<"\n3 - Remover elemento da pilha";
      cout<<"\nDigite a sua opção:";
       cin >> res;

        switch (res)
        {

        case 1:
            push(&pilha);
            break;

        case 2:
            pop(&pilha);
            break;

        case 3:
            imprimepilha(pilha);
            break;
        }

    } while (res != 0);

    return 0;
}