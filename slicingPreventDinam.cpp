#include<iostream>
#include<memory>

using namespace std;

/*
Esse código objetiva demonstrar como impedir o compilador de 
    aceitar atribuições que ocasionariam em slicing.
*/

class B { //classe base suprime operações de cópia
public:
    virtual void funcao1() { cout<<"classse base\n"; }
    B() = default;
    // //removemos as operações de cópia
     //B(const B&) = delete;
     //B &operator=(const B&) = delete;
};

class D : public B {
public:
    // sobrescreve a função virtual
    void funcao1() override {  cout<<"classse filha\n"; }
    // ...
};

// exemplo do documento
void f(B& b)
{
    b.funcao1();//Retorna "classe filha"
    
    //auto b2 = static_cast<D&>(b); //O compilador não permite
    auto b2 = dynamic_cast<D&>(b); //Safe downcast
    auto b3(b); //também aqui não permite

    b2.funcao1(); 
    b3.funcao1();
}

int main()
{
    // exemplo do documento
    D d;
    f(d);//slicing ocorreria aqui

    return 0;
}