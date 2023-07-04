#include<iostream>
#include<vector>
#include<math.h>
#include<any>

using namespace std;

int anycExe(any valorQualquer)
{
    try
    {
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
    anycExe("abc");
    anycExe(13);
    anycExe(13.9);
    return 0;
}
