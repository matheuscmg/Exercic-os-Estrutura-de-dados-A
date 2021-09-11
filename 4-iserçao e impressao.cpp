#include <iostream>
#include <malloc.h>
using namespace std;
struct no
{
    int codigo;
    struct no *prox;
};
void insereInicio(no **lista)
{
    no *aux;
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " \n Digite um numero para ser alocado : ";
        cin >> aux->codigo;
        aux->prox = (*lista);
        (*lista) = aux;
    }
}
void insereFIM(no **lista)
{
    no *aux, *aux2;
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " \n Digite o numero para ser alocado no final : ";
        cin >> aux->codigo;
        aux->prox = NULL;
    }
    if ((*lista) == NULL)
    {
        (*lista) = aux;
    }
    else
    {
        aux2 = (*lista);
        while (aux2->prox != NULL)
        {
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
    }
}
void imprime(no *lista)
{
    while (lista != NULL)
    {
        cout << lista->codigo;
        lista = lista->prox;
    }
}
int main()
{
    no *lista = NULL;
    int opcao;

    do
    {
        cout << " \n 1 Para inserir um No no inicio da lista! ";
        cout << " \n 2 para inserir um No no final da lista ! ";
        cout << " \n 3 para imprimir a lista ligada ! ";
        cout << " \n Informe sua opcao : ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insereInicio(&lista);
            break;
        case 2:
            insereFIM(&lista);
            break;
        case 3:
            imprime(lista);
            break;
        }

    } while (opcao != 0);
    return 0;
}