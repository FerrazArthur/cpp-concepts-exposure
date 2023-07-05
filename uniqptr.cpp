#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> p1(new int(5));

    //transfere objeto pra new
    unique_ptr<int> newp1 = move(p1);
    //shared_ptr<int> ptr = newp1; //compilador não permite
    //unique_ptr<int> ptr = &newp1; //também nao permite

    unique_ptr<int> p2(new int(10));
    
    if (p1) {
        cout << "p1 owns the object "<< *p1 << endl;
    }
    else{
        cout << "newp1 owns the object "<< *newp1 << endl;
    }
    
    if (p2) {
        cout << "p2 owns the object " << *p2 <<endl;
    }

    return 0;
}
