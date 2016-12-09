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

	bool testEmpty(fila* f)
	{
		if(f->getNext()) return true;
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

	void fila::push(fila* f)
	{
		fila* ptr = pusher();
		if(testEmpty(f))
		{

		}
	}

	void fila::pop(fila* f)
	{

	}

	void fila::free(fila* f)
	{

	}

	void fila::show(fila* f)
	{

	}
