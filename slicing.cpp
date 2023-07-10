#include<iostream>
#include<memory>

using namespace std;

/*
Esse código objetiva exemplificar o slicing em atribuição, que ocorre 
    quando um objeto de uma classe filha é atribuído a um ponteiro
    de uma classe pai.
*/

class B { //classe base não suprime operações de cópia
public:
    virtual void funcao1() { cout<<"classse base\n"; }
    // ... nada sobre as operações, então usará a default
};

class D : public B {
public:
    // sobrescreve a função virtual
    void funcao1() override {  cout<<"classse filha\n"; }
    // ...
};

// exemplo do documento
void f(auto b)
{
    b.funcao1();//Retorna "classe filha"
    
    auto b2 = b; //O slicing ocorre aqui
    auto b3(b); //também ocorre aqui
    //os métodos abaixo retornarão "classe base"
    b2.funcao1();
    b3.funcao1();
}

int main()
{
    // exemplo do documento
    D d;
    f(d);//slicing ocorre aqui

    return 0;
}