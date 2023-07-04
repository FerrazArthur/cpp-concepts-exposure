#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double absolut(int a);
int conventional()
{
    int a = -4;
    double b = absolut(a);
 /*
    double absolut(int a)
    {   
        // não funciona definição 
        //de funções tradicionais 
        //dentro do escopo de outras funções
        return math.sqrt(double(a)*double(a));
    }
*/
    cout<<"módulo de "<<a<<" é "<< absolut(a) <<endl;
    return 0;
}
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

double absolut(int a)
{
    return sqrt((double)a*(double)a);
}