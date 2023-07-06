#include <iostream>
#include <memory>

using namespace std;

/*
Esse código objetiva demonstrar o uso de unique_ptr, que é um ponteiro
    inteligente que não permite cópias, apenas permite movimentação.
    O ponteiro quando é destruído, destrói o objeto que aponta também.
*/

int main() {
    unique_ptr<int> p1(new int(5));

    //transfere objeto pra new
    unique_ptr<int> newp1 = move(p1);

    //shared_ptr<int> ptr = newp1; //compilador não permite
    //unique_ptr<int> ptr = newp1; //compilador não permite
    unique_ptr<int> p2(new int(10));

    if (p1) {
        cout << "p1 é proprietário do objeto: "<< *p1 << endl;
    }
    else{
        cout << "newp1 é proprietário do objeto: "<< *newp1 << endl;
    }
    
    if (p2) {
        cout << "p2 é proprietário do objeto: " << *p2 <<endl;
    }

    return 0;
}
