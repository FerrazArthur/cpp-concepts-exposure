#include <iostream>
#include <memory>

class MyClass {
public:
    int a = 0;
    MyClass(int val) { this->a = val;std::cout << "Construtor é chamado." << std::endl; }
    ~MyClass() { std::cout << "Destrutor é chamado." << std::endl; }
};

/*
Essa função objetiva demonstrar o uso valores referenciados por ponteiros weak
*/

int main() {
    // declara Ponteiro weak
    std::weak_ptr<MyClass> ptr1;
    
    std::cout << "Fora do contexto interno: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
    auto func = [](std::weak_ptr<MyClass> &ptr1){
        //define shared pointer e a atribui uma instância de MyClass 
        std::shared_ptr<MyClass> ptr2(new MyClass(10));
        // atribui ao ponteiro weak o conteúdo do ponteiro compartilhado
        ptr1 = ptr2;
        
        std::cout << "Dentro do contexto interno, antes de utilizar o weak: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        
        if (std::shared_ptr<MyClass> aux = ptr1.lock())
        {
            std::cout<<"valor dentro da classe: "<<aux->a<<std::endl;
            std::cout << "Dentro do contexto interno, durante o uso do weak: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        }

        std::cout << "Dentro do contexto interno, após utilizar o weak: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        //ambos ponteiros compartilham o mesmo objeto mas o contador de referência só mostra 1
    };
    func(ptr1);
    std::cout << "Fora do contexto interno: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
    // Ao terminar o escopo de func, ptr2 é destruído e o contador de referência é decrementado de volta pra 0
    return 0;
}