#ifndef FILA_H_
#define FILA_H_
#include <iostream>

class fila {
	int value;
	int size;
	fila* next
public:
	fila();
	void setValue(int);
	int getValue();
	void setSize(int);
	int getSize();
	void setNext(fila*);
	fila* getNext();
	bool testEmpty(fila*);
	fila* pusher();
	void push(fila*);
	void pop(fila*);
	void free(fila*);
	void show(fila*);
};

#endif /* FILA_H_ */
