#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int lambdaCapture()
{
    int a = -4;
    int b = -4;
    int* ptra = NULL;
    int& refb = b;
    ptra = &a;
    
    auto funcptr = [](int* ptra) -> double
    {
        return sqrt(*ptra * *ptra);
    };
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