#include <iostream>

using namespace std;

struct diag {
    char nome[30];
    float peso,altura;
    float imc;
};
int main() {
    struct diag pessoa[5];


    for(int i=0; i<3; i++) {
        cout << "\nQual e o seu nome : ";
        cin >> pessoa[i].nome;
        cout << "\nQual e a sua altura : ";
        cin >> pessoa[i].altura;
        cout << "\nQual e o seu peso :";
        cin >> pessoa[i].peso;
        pessoa[i].imc = pessoa[i].peso/ (pessoa[i].altura* pessoa[i].altura);
    }
    for(int i=0; i<3; i++) {
        if(pessoa[i].imc < 18.5) {
            cout << "o paciente "<< pessoa[i].nome << " esta abaixo do peso.";
        }
        else if(pessoa[i].imc > 18.5 && pessoa[i].imc <=25) {
            cout << "o paciente " << pessoa[i].nome << " esta com o peso ideal";
        }
        else if (pessoa[i].imc > 25 && pessoa[i].imc <=30) {
            cout << "o paciente "<< pessoa[i].nome << " esta com sobreoesi";
        }
        else if (pessoa[i].imc > 25 && pessoa[i].imc <=30) {
            cout << "o paciente "<< pessoa[i].nome << " esta com obesidade 1 ";
        }else if (pessoa[i].imc >30 && pessoa[i].imc  <= 35){
            cout << "o paciente "<< pessoa[i].nome << " esta com obesidade 3 ";
        }
        else cout << "o paciente "<< pessoa[i].nome << " esta com obesidade 2 ";
    }

    return 0;
}