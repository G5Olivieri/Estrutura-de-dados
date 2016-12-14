#include "list.h"

list::list()
{
	value = position = size = 0;
	next = ant = NULL;
}

void list::setValue(int n)
{
	this->value = n;
}

void list::setNext(list* l)
{
	this->next = l;
}

void list::setAnt(list* l)
{
	this->ant = l;
}

void list::setSize(int n)
{
	this->size = n;
}

void list::setPosition(int n)
{
	this->position = n;
}

int list::getValue()
{
	return this->value;
}

int list::getSize()
{
	return this->size;
}

int list::getPosition()
{
	return this->position;
}

list* list::getNext()
{
	return this->next;
}

list* list::getAnt()
{
	return this->ant;
}

bool list::testEmpty(list* l)
{
	if(!l->getNext()) return true;
	else return false;
}

list* list::pusher()
{
	int v;
	list* tempNode = new list();
	if(!tempNode)
	{
		std::cout << "Sem memoria: ";
		return NULL;
	}
	else
	{
		std::cout << "Digite o valor do elemento: ";
		std::cin >> v;
		tempNode->setValue(v);
		return tempNode;
	}
}

void list::atualiza(list* l)
{
	list* tempNode = l->getNext();
	for(int i = 1; i <= l->getSize(); i++)
	{
		tempNode->setPosition(i);
		tempNode = tempNode->getNext();
	}
}

list* list::lastElement(list* l)
{
	if(!l->getNext()) return l;
	else return lastElement(l->getNext());
}

void list::pushFirst(list* l, list* newNode)
{
	newNode->setPosition(1);
	newNode->setAnt(l);
	l->setNext(newNode);
	l->setSize(l->getSize()+1);
}

void list::pushBegin(list* l)
{
	list* newNode = pusher();
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		newNode->setAnt(l);
		newNode->setNext(l->getNext());
		l->getNext()->setAnt(newNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void list::pushEnd(list* l)
{
	list* newNode = pusher();
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		list* lastNode = lastElement(l);
		lastNode->setNext(newNode);
		newNode->setAnt(lastNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void list::pushPosition(list* l, int p)
{
	list* newNode = pusher();
	if(testEmpty(l))
	{
		pushFirst(l, newNode);
		std::cout << "Lista vazia, elemento colocado na primeira posicao: ";
	}
	else
	{
		list* atualNode = l->getNext();

		while(atualNode->getPosition() != p)
			atualNode = atualNode->getNext();

		newNode->setNext(atualNode);
		newNode->setAnt(atualNode->getAnt());
		atualNode->getAnt()->setNext(newNode);
		atualNode->setAnt(newNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void list::popFirst(list* l)
{
		delete l->getNext();
		l->setNext(NULL);
        l->setSize(l->getSize()-1);
     	l->atualiza(l);
}

void list::popBegin(list* l)
{
	list* atualNode = l->getNext();
	if(testEmpty(l))
		popFirst(l);
	else
	{
                atualNode = l->getNext();
                atualNode->getNext()->setAnt(l);
                l->setNext(atualNode->getNext());
                l->setSize(l->getSize()-1);
		l->atualiza(l);
		delete atualNode;
	}
}

void list::popEnd(list* l)
{
	if(testEmpty(l))
		popFirst(l);
	else
	{
		list* antLastNode = lastElement(l);
		antLastNode = antLastNode->getAnt();
		delete antLastNode->getNext();
		antLastNode->setNext(NULL);
		l->setSize(l->getSize()-1);
	}
}

void list::popPosition(list* l, int p)
{
	list* atualNode = l->getNext();
	if(testEmpty(l))
		popFirst(l);
	else
	{
		while(atualNode->getPosition() != p)
			atualNode = atualNode->getNext();
		atualNode->getAnt()->setNext(atualNode->getNext());
		atualNode->getNext()->setAnt(atualNode->getAnt());
		delete atualNode;
		l->setSize(l->getSize()-1);
		l->atualiza(l);
	}
}

list* list::show(list* l)
{
	if(!l->getNext()) return NULL;
	else
	{
		std::cout << "Element " << l->getNext()->getPosition() << " - Value: "
			  << l->getNext()->getValue() << ": ";
		return show(l->getNext());
	}
}

void list::free(list* l)
{
	if(testEmpty(l))
	{
		delete l->getNext();
		std::cout << "Lista vazia: ";
	}
	else
	{
		list* tempNode = lastElement(l);
		while(tempNode != l)
		{
			tempNode = tempNode->getAnt();
			delete tempNode->getNext();
		}
		delete l->getNext();
		std::cout << "Lista vazia: ";
	}
}
