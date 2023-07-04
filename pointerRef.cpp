#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
/*
Esse código tem objetivo de demonstrar a definição de funções lambda 
 com valores de retorno e utilizando parâmetros.
Também ilustra o uso de ponteiros vs referências quando parâmetros
 de funções.
*/
int lambdaCapture()
{
    int a = -4;
    int b = -4;
    //declarando ponteiro vazio
    int* ptra = NULL;
    //definindo referência para ponteiro b
    int& refb = b;
    //atribuindo endereço de a ao ponteiro
    ptra = &a;
    
    //função lambda que retorna o módulo de um número, 
    //recebendo um ponteiro como parâmetro
    auto funcptr = [](int* ptra) -> double
    {
        return sqrt(*ptra * *ptra);
    };
    //função lambda que retorna o módulo de um número
    //recebendo uma referência como parâmetro
    auto funcref = [](int& refb) -> double
    {
        return sqrt(refb * refb);
    };
    
    cout<<"módulo de "<<a<<" é "<< funcptr(ptra)<<endl;
    cout<<"módulo de "<<b<<" é "<< funcref(refb)<<endl;
    return 0;
}

int main()
{
    lambdaCapture();
    return 0;
}