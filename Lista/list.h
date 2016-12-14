#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

class list
{
	int value, position, size;
	list* next, *ant;
	public:
		list();
		void setValue(int n);
		void setNext(list* l);
		void setAnt(list* l);
		void setSize(int n);
		void setPosition(int n);
		int getValue();
		int getSize();
		int getPosition();
		list* getNext();
		list* getAnt();
		bool testEmpty(list* l);
		list* pusher();
		void atualiza(list* l);
		list* lastElement(list* l);
		void pushFirst(list* l, list* newNode);
		void pushBegin(list* l);
		void pushEnd(list* l);
		void pushPosition(list* l, int p);
		void popFirst(list* l);
		void popBegin(list* l);
		void popEnd(list* l);
		void popPosition(list* l, int p);
		list* show(list* l);
		void free(list* l);
};

#endif // _LIST_H_
