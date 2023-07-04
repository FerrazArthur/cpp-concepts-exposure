#include <iostream>
#include <memory>

class MyClass {
public:
    int a = 0;
    MyClass(int val) { this->a = val;std::cout << "Constructor is called." << std::endl; }
    ~MyClass() { std::cout << "Destructor is called." << std::endl; }
};

int main() {
    // declara Ponteiro weak
    std::weak_ptr<MyClass> ptr1;
    
    std::cout << "Outside the inner scope: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
    auto func = [](std::weak_ptr<MyClass> &ptr1){
        //define shared pointer e a atribui uma istância de MyClass 
        std::shared_ptr<MyClass> ptr2(new MyClass(10));
        // atribui ao ponteiro weak o conteúdo do ponteiro compartilhado
        ptr1 = ptr2;
        
        std::cout << "Inside the inner scope, before usage: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        
        if (std::shared_ptr<MyClass> aux = ptr1.lock())
        {
            std::cout<<"valor dentro da classe: "<<aux->a<<std::endl;
            std::cout << "Inside the inner scope, during usage: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        }

        std::cout << "Inside the inner scope, after usage: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        //ambos ponteiros compartilham o mesmo objeto mas o contador de referência só mostra 1
    };
    func(ptr1);
    std::cout << "Outside the inner scope." << "pointerCount = " <<ptr1.use_count() << std::endl;
    // Ao terminar o escopo de func, ptr2 é destruído e o contador de referência é decrementado de volta pra 0
    return 0;
}