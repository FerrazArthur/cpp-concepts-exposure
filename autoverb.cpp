#include <iostream>
#include <vector>
using namespace std;

/*
Código objetiva ilustrar algumas das usabilidades do auto em C++.
*/

int main()
{
    // forma tradicional de declarar una variavel
    int myInt = 5;

    // Utilizando auto para declarar una variavel
    auto myAutoInt = 5; //Deduz o tipo de myAutoInt como sendo int, em tempo de compilação

    // Reduzindo 'verbosidade' de trabalhar com tipos complexos
    vector<int> myVector = {1, 2, 3, 4, 5};

    //Sem utilizar auto, o tipo do iterador é muito longo
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    {
        cout << *it << endl;
    }

    // Com auto, o tipo do iterador é deduzido em tempo de compilação
    for (auto it = myVector.begin(); it != myVector.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}