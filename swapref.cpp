#include<iostream>

using namespace std;

/*
Objetiva demonstrar o uso de referências em C++.
*/

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
   int x = 5, y = 10;
   cout << "Antes do Swap: x = " << x << " y = " << y << endl; // Outputs 5 10
   
   swap(x, y);//não fosse a referência, x e y não seriam alterados
   cout << "Depois do Swap: x = " << x << " y = " << y << endl;  // Outputs 10 5
   return 0;
}
