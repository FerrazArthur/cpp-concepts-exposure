#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Construtor é chamado." << std::endl; }
    ~MyClass() { std::cout << "Destrutor é chamado." << std::endl; }
};

/*
Esse código objetiva exemplificar como o shared_ptr funciona. O objeto destruido em duas ocasiões:
    Quando o utimo share_ptr que aponta pra ele for apagado ou atribuido a outro objeto.
*/

int main() {
    //Cria um shared_ptr vazio
    std::shared_ptr<MyClass> ptr1;
    
    auto func = [](std::shared_ptr<MyClass> &ptr1){
        //define um novo shared_ptr e atribui uma instância de MyClass
        std::shared_ptr<MyClass> ptr2(new MyClass());
        //realiza uma copia pro shared ptr definido na main
        ptr1 = ptr2;

        std::cout << "Dentro do contexto interno: " << "pointerCount = " <<ptr1.use_count()<< std::endl;
        //Ambos os ponteiros compartilham propriedade sobre o objeto, então o contador de referência é 2
    };
    //chama a função func
    func(ptr1);

    std::cout << "Fora do contexto interno: "<< "pointerCount = " <<ptr1.use_count() << std::endl;
    //Sair do contexto de func destroi ptr2, decrementando o contador de referência para 1
    //Aqui o objeto ainda existe, pois ptr1 ainda aponta pra ele

    //A função main finaliza, oque acarreta da destruição de ptr1 pois decrementa o contador de referência 
    //para 0
    //isso faz com que o destrutor de MyClass seja chamado
    return 0;
}