#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int lambdaCapture()
{
    int a = -4;
    int b = 0;
    void * ptr = NULL;
    ptr = &a;
    auto func = [ptr]() -> double
    {
        //b = 2; //copilador não identifica pois não pertence
        // ao contexto de func [capture-list]
        
        //como feito em c:
        return sqrt((double) *(int*)ptr * (double) *(int*)ptr) ;

        //return sqrt(static_cast<double>( *(static_cast<int*>(ptr)) ) * static_cast<double>( *(static_cast<int*>(ptr)) ) );
    };
    cout<<"módulo de "<<a<<" é "<< func()<<endl;
    return 0;
}

int main()
{
    lambdaCapture();
    return 0;
}
