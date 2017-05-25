#include "Fila.h"
#include <cstddef>
#include <iostream>
bool Fila::vazia()
{
    return getInicio() == NULL;
}

void Fila::push(int valor)
{
    if(vazia())
    {
        setInicio(new No(valor));
        setFim(getInicio());
    }
    else
    {
        this->getFim()->setProx(new No(valor));
        setFim(this->getFim()->getProx());
    }
}

int Fila::pop()
{
    int valor = getInicio()->getValor();
    if(vazia())
    {
        return VAZIA;
    }
    else
    {
        No *temp = getInicio();
        setInicio(getInicio()->getProx());
        delete temp;
    }
    return valor;

}

std::ostream& operator<<(std::ostream& out, Fila *f)
{
    No *temp = f->getInicio();
    while(temp)
    {
        out << temp->getValor() << " ";
        temp = temp->getProx();
    }
    return out;
}
