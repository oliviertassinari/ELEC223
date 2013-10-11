#include <stdio.h>
#include "count.h"

int main() 
{
	yylex();
	printf("tic = %d, tac = %d, toc = %d\n", 
	       nb_tic, nb_tac, nb_toc);
	return (0);
}
