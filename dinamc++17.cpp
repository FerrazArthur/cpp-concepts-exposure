#include<iostream>
#include<vector>
#include<math.h>
#include<any>

using namespace std;
/*
O objetivo desse código é mostrar como o typecast any_cast funciona
    e como utilizar o any_cast para evitar erros de compilação
    e de execução, diferente do void* que não tem essa capacidade.
*/
int anycExe(any valorQualquer)
{
    try
    {   
        //ao tentar fazer o typecast de um valor que não é double, 
        //é lançada uma exceção
        cout<<"módulo de "<<any_cast<double>(valorQualquer)
        <<" é "
        << sqrt(any_cast<double>(valorQualquer)*any_cast<double>(valorQualquer))
        <<endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
int main()
{
    anycExe("abc"); //string não é double
    anycExe(13); //int não é double
    anycExe(13.9); //double é double
    return 0;
}
