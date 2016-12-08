#include <cstdio>
#include <cstdlib>
#include "stack.h"

int main(int argc, char* argv[])
{
	stack s;
	s.push(&s);
	s.push(&s);
	s.showStack(&s);
	getchar();
	return 0;
}
