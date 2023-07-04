#include<iostream>
#include<vector>
#include<math.h>

/*
Esse código tem objetivo de demonstrar a prototipagem de funções,
 A definição de funções lambda e sua utilização, em contraste com 
 as funções tradicionais.
*/
using namespace std;

//aqui a função absolut é prototipada
double absolut(int a);

//função tradicional
int conventional()
{
    int a = -4;
    double b = absolut(a);
    //Utilizando a função prototipada absolut
    cout<<"módulo de "<<a<<" é "<< absolut(a) <<endl;
    return 0;
}

//utiliza função lambda 
int lambdaCapture()
{
    int a = -4;
    int b = 0;
    auto func = [a]() -> double
    {
        //b = 2; //copilador não identifica pois não pertence
        // ao contexto de func [capture-list]
        return sqrt((double)a*(double)a);
    };
    cout<<"módulo de "<<a<<" é "<< func()<<endl;
    return 0;
}

int main()
{
    conventional();
    lambdaCapture();
    return 0;
}

//aqui a função absolut é definida
double absolut(int a)
{
    return sqrt((double)a*(double)a);
}