#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

/*
O objetivo desse código é mostrar como utilizar ponteiros dinâmicos
    e como fazer typecast de ponteiros, contrastando os estilos de 
    c e c++
*/

int lambdaCapture(string estilo)
{
    int a = 0;
    void * ptr = NULL;
    //Aloca memória para um inteiro e atribui o endereço para ptr
    ptr = new int (-4);

    //passa ptr para o contexto local de lambda
    auto func = [ptr, estilo]() -> double
    {
        //a = 2; //copilador não identifica pois não pertence
        // ao contexto de func [capture-list]
        
        if (estilo == "c")
        {
            //typecast estilo c
            return sqrt((double) *(int*)ptr * (double) *(int*)ptr) ;
        }
        else
        {
            //typecast estilo c++
            return sqrt(static_cast<double>( *(static_cast<int*>(ptr)) ) 
                * static_cast<double>( *(static_cast<int*>(ptr)) ) );
        }
    };

    //typecast estilo c
    if (estilo == "c")
    {
        cout<<"módulo de "<<*(int*)ptr<<" é "<<func()<<endl;

        //importante desalocar a memória alocada para ptr, para evitar
        //vazamento de memória
        delete (int*)ptr;
    }

    //typecast estilo c++
    else if(estilo == "c++")
    {
        cout<<"módulo de "<<*static_cast<int*>(ptr)<<" é "<<func()<<endl;

        //importante desalocar a memória alocada para ptr, para evitar
        //vazamento de memória
        delete static_cast<int*>(ptr);
    }
    else
    {
        cout<<"estilo de cast inválido"<<endl;
        return 1;
    }

    return 0;
}

/*
Essa função identifica o estilo de cast a ser utilizado
    baseado nos argumentos passados para o programa. 
O estilo de cast pode ser c ou c++, sendo c++ o padrão.
*/
const char* getStyle(int argc, char const *argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "c") || strcmp(argv[1], "c++"))
        {
            return argv[1];
        }
    }
    return "c++";
}

int main(int argc, char const *argv[])
{
    //identifica estilo de cast a ser utilizado
    string estilo = getStyle(argc, argv);
    cout<<"Estilo de cast: "<<estilo<<endl;

    lambdaCapture(estilo);
    return 0;
}
