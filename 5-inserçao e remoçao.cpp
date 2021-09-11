#include <malloc.h>
#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
};

void insereInicio(no **inicio)
{
    no *aux;
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " Digite um numero: ";
        cin >> aux->codigo;
        aux->prox = (*inicio);
        (*inicio) = aux;
    }
};

void inserirFim(no **inicio)
{
    no *aux2, *aux;
    aux2 = (no *)malloc(sizeof(no));
    cout << " Digite um numero para iserir no final da lista: ";
    cin >> aux2->codigo;
    aux2->prox = NULL;

    if (*inicio == NULL)
    {
        (*inicio) = aux2;
    }
    else
    {
        aux = (*inicio);
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux2->prox = NULL;
        aux->prox = aux2;
    }
};

void removeInicio(no **inicio)
{
    no *aux;

    if (*inicio == NULL)
    {
        cout << " \nA lista vazia!" << endl;
    }
    else if (*inicio != NULL)
    {
        aux = (*inicio);
        (*inicio) = (*inicio)->prox;
        free(aux);
    }
};

void removeFim(no **inicio)
{
    no *aux, *aux2 = (*inicio);

    if (*inicio == NULL)
    {
        cout << "A lista nao possue valores. " << endl;
    }
    else
    {
        while (aux2->prox != NULL)
        {
            aux = aux2;
            aux2 = aux2->prox;
        }
        if (aux2 == (*inicio))
        {
            (*inicio) = aux2->prox;
        }
        else
        {
            aux->prox = aux2->prox;
            free(aux2);
        }
    }
};

void busca(no *inicio)
{
    no *aux = inicio;
    int n, quant = 0;
    cout << " \n Informe o valor a ser buscado :";
    cin >> n;

    while (inicio != NULL)
    {
        if (inicio->codigo == n)
        {
            quant++;
        }
        inicio = inicio->prox;
    }

    if (quant == 0)
    {
        cout << " \nValor nao encontrado! " << endl;
    }
    else
        cout << " \nValor presente na lista! " << endl;
};

void tamanho(no *inicio)
{
    int cont = 0;

    if (inicio == NULL)
    {
        cout << " \n lista nao contem elementos! " << endl;
    }
    while (inicio != NULL)
    {
        cont++;
        inicio = inicio->prox;
    }
    cout << " \nA lista ligada contem : " << cont << " elementos ! " << endl;
};



void imprimir(no *inicio)
{
    no *aux;
    aux = inicio;
    while (aux != NULL)
    {
        cout << aux->codigo <<" ";
        aux = aux->prox;
    }
};

int main()
{
    no *inicio = NULL;
    int opcao;
    do
    {
        cout << "\n  1 Para inserir um No no inicio : ";
        cout << "\n  2 Para inserir um No no final! :";
        cout << "\n  3 Impressao dos valores da lista :";
        cout << "\n  4 remover No no inicio da lista :";
        cout << "\n  5 remover No no final da lista :";
        cout << "\n  6 Para busca um elemnto na lista: ";
        cout << "\n  7 para saber o tamanho da lista : ";
        cout << "\n  0 para sair do programa :";
        cout << "\n Digite uma opcao : ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insereInicio(&inicio);
            break;
        case 2:
            inserirFim(&inicio);
            break;
        case 3:
            imprimir(inicio);
            break;
        case 4:
            removeInicio(&inicio);
            break;
        case 5:
            removeFim(&inicio);
            break;
        case 6:
            busca(inicio);
            break;
        case 7:
            tamanho(inicio);
            break;
        }
    } while (opcao != 0);

    return 0;
}