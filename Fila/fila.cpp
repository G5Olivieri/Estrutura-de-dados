#include "fila.h"

fila::fila()
{
	this->value = 0;
	this->size = 0;
	this->next = NULL;
}

void fila::setValue(int n)
{
	this->value = n;
}

int fila::getValue()
{
	return this->value;
}

void fila::setSize(int n)
{
	this->size = n;
}

int fila::getSize()
{
	return this->size;
}

void fila::setNext(fila* f)
{
	this->next = f;
}

fila* fila::getNext()
{
	return this->next;
}

bool fila::testEmpty(fila* f)
{
	if(!(f->getNext())) return true;
	else return false;
}

fila* fila::pusher()
{
	fila* ptr = new fila();
	int n;
	if(!ptr)
	{
		std::cout << "Sem memoria: ";
		return NULL;
	}
	else
	{
		std::cout << "Digite o valor: ";
		std::cin >> n;
		ptr->setValue(n);
		ptr->setNext(NULL);
		return ptr;
	}
}

fila* fila::lastElement(fila* f)
{
	if(!f->getNext()) return f;
	else return lastElement(f->getNext());
}

void fila::push(fila* f)
{
	fila* ptr = pusher();
	if(testEmpty(f))
	{
		f->setNext(ptr);
		setSize(getSize()+1);
	}
	else
	{
		fila* temp = lastElement(f);
		temp->setNext(ptr);
		setSize(getSize()+1);
	}
}

void fila::pop(fila* f)
{
	fila* ptr = f->getNext();
	if(testEmpty(f)) std::cout << "Fila vazia: ";
	else
	{
		f->setNext(f->getNext()->getNext());
		std::cout << "Elemento removido: " << ptr->getValue() << std::endl;
		delete ptr;
	}
}

void fila::free(fila* f)
{
	if(testEmpty(f)) std::cout << "Fila vazia: ";
	else
	{
		fila* current = f->getNext();
		fila* next;
		while(current)
		{
			next = current->getNext();
			delete current;
			current = next;
		}
		std::cout << "Fila vazia: ";
	}
}

fila* fila::show(fila* f)
{
	if(!(f->getNext())) return NULL;
	else
	{
		std::cout << f->getNext()->getValue() << std::endl;
		return show(f->getNext());
	}
}

void fila::order(fila* f)
{
	int temp;
	fila* ptr = f->getNext();
	fila* cpr;
	while(ptr)
	{
		cpr = ptr->getNext();
		for(int i = 0; cpr; i++)
		{
			if(ptr->getValue() > cpr->getValue())
			{
				temp = ptr->getValue();
				ptr->setValue(cpr->getValue());
				cpr->setValue(temp);
			}
			cpr = cpr->getNext();
		}
		ptr = ptr->getNext();
	}
}
