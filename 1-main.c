#include "main.h"
#include <limits.h>
#include <stdio.h>
int
main ()
{
	int n, m, len;



	_printf ("Negative:[%i]\n", NULL);
	printf ("Negative:[%i]\n", 34342);

	n = _printf ("abds kk %c %s %i", 'c', "some", -77);
	printf ("\nelement numbers: %d ", n);

	 m = _printf ("ttrtrtr grhrthtrh");
	printf ("\nelement numbers: %d ", m);

	len = _printf ("Let's try to printf a simple sentence.\n");
	printf ("\nelement numbers: %d ", len);

	return 0;
}
