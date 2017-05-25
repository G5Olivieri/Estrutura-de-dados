#include <iostream>
#include <Fila.h>
using namespace std;

int main()
{
    Fila *fila = new Fila(59);
    fila->push(30);
    fila->push(10);
    fila->push(-10);
    cout << fila;
    cout << fila->pop();
    cout << fila;
    return 0;
}
