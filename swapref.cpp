#include<iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
   int x = 5, y = 10;
   cout << "Antes do Swap: x = " << x << " y = " << y << endl; // Outputs 5 10
   
   swap(x, y);
   cout << "Depois do Swap: x = " << x << " y = " << y << endl;  // Outputs 10 5
   return 0
}
