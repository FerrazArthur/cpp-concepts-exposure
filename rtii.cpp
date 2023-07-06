#include <iostream>

class Base { virtual void dummy() {} };
class Derived1 : public Base { /* ... */ };
class Derived2 : public Base { /* ... */ };

using namespace std;

/*
Codigo adaptado de https://roadmap.sh/cpp
Objetiva ilustrar o uso do RunTime Type Identification -RTTI- e como o
    dynamic_cast pode ser usado para evitar o slicing que poderia resultar 
    de um down/upcasting de ponteiros, quando os objetos não são do mesmo tipo.
*/
int main() {
    //Cria um objeto Derived1 e atribui seu endereço a um ponteiro Base
    Base* base_ptr = new Derived1;
    
    //imprime objeto que base_ptr aponta, pra ilustar melhor no output.
    //O typeid também é RTTI
    cout<<"O ponteiro base_ptr aponta para um objeto do tipo: "
        <<typeid(*base_ptr).name()<<endl;


    //Utilizamos dynamic_cast para converter o ponteiro base_ptr para
    //  um ponteiro Derived1
    cout<<"Exemplo de dynamic_cast: \n";
    Derived1* derived1_ptr = dynamic_cast<Derived1*>(base_ptr);
    if (derived1_ptr) {
        //funcionará pois o ponteiro base_ptr aponta para um objeto do tipo
        //  Derived1
        cout << "Downcast do ponteiro Base pra Derived1 bem sucedido\n";
    }
    else {
        cout << "Downcast do ponteiro Base para Derived1 não permitido\n";
    }
    
    //o cast estático permite o downcast do ponteiro para estruturas irmãs
    cout<<"Exemplo de static_cast: \n";
    Derived2* derived2_ptr = static_cast<Derived2*>(base_ptr);
    if (derived2_ptr) {
        //funcionará, isso pode implicar em slicing.
        cout << "Downcast do ponteiro Base pra Derived2 bem sucedido\n";
    }
    else {
        cout << "Downcast do ponteiro Base pra Derived2 não permitido\n";
    }
    
    //Já o cast dinamico não permitirá, pois como base_ptr aponta para um 
    //  objeto Derived1, não é permitido o cast.
    cout<<"Exemplo de dynamic_cast: \n";
    Derived2* derived3_ptr = dynamic_cast<Derived2*>(base_ptr);
    if (derived3_ptr) {
        cout << "Downcast do ponteiro Base pra Derived2 bem sucedido\n";
    }
    else {
        //não funcionará
        cout << "Downcast do ponteiro Base pra Derived2 não permitido\n";
    }

    delete base_ptr;
    return 0;
}
