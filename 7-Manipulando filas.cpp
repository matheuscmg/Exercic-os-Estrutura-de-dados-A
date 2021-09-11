#include <iostream>
#include <malloc.h>
#include <time.h>
using namespace std;

struct no
{
    int num;
    time_t horario, atual;
    struct no *prox;
};

void inserirfila(no **fila, no **fim)
{
    no *aux; = (no*)malloc(sizeof(no));
    struct tm fuso;


    time_t currentTime;
    struct tm *timeinfo;
    currentTime = time(NULL);
    timeinfo = localtime(&aux->horario);
    

    if (aux != NULL)
    {
        cout << "\nDigite um numero :";
        cin >> aux->num;
        aux->prox = NULL;
        aux->horario = time(NULL);
        fuso = *localtime(&aux->horario);
        cout << " \nData de isercao: " << fuso.tm_mday << "/" <<fuso.tm_mon + 1 << "/" << fuso.tm_year + 1900 << endl;
       cout << "\nHorario de Cadastro: " << timeinfo->tm_hour;
       cout << ":" << timeinfo->tm_min<< ":" << timeinfo->tm_sec <<"\n";

    
    }

    if (*fila != NULL)
    {
        (*fim)->prox = aux;
        (*fim) = aux;

        
    }
    else
    {
        (*fila) = aux;
        (*fim) = aux;
    }
}

void removefila(no **fila)
{ no *lixo;
    struct tm fuso;


    time_t currentTime;
    struct tm *timeinfo;
    currentTime = time(NULL);
    

    if (*fila == NULL)
        cout << "\n Nao ha elementos na fila\n";

    else
    {
        lixo = (*fila);
        lixo->atual = time(NULL);
        (*fila) = (*fila)->prox;
        fuso = *localtime(&lixo->horario);
        cout << " \nData de insercao: " << fuso.tm_mday << "/" << fuso.tm_mon + 1 << "/" << fuso.tm_year + 1900 << endl;
        cout << "\nHorario de Cadastro: " << timeinfo->tm_hour;
        cout << ":" << timeinfo->tm_min<< ":" << timeinfo->tm_sec <<"\n";
        fuso = *localtime(&lixo->atual);
        cout << " \nData de remocao: " << fuso.tm_mday << "/" << fuso.tm_mon + 1 << "/" << fuso.tm_year + 1900 << endl;
        cout << "Horario de de remocao:  " << fuso.tm_hour << ":" << fuso.tm_min << ":" << fuso.tm_sec << endl;
        cout << "\nTempo esperado na fila : " << (difftime(lixo->atual, lixo->horario)) << " seg.";
        cout<<"\n-------------------------------";
            free(lixo);
    }
}

void imprimefila(no *fila)
{
   cout <<"\nnumeros na fila :";
    while (fila != NULL)
    {
        cout << fila->num<<",";
        fila = fila->prox;
    }
}

int main()
{
    no *fila = NULL;
    no *fim = NULL;

    int res;

    do
    {
      cout<<"\n\nO que deseja fazer ?";
      cout<<"\n1 - Iserir elementos na fila.";
      cout<<"\n2 - Imprimir elementos na fila.";
      cout<<"\n3 - Remover elemento da fila";
      cout<<"\nDigite a sua opção:";
       cin >> res;

        switch (res)
        {
        case 1:
            inserirfila(&fila, &fim);
            break;
        case 2:
        imprimefila(fila);
            break;
            
        case 3:
        removefila(&fila);
            break;
            
        }

    } while (res != 0);

    return 0;
}