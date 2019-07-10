#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	double	d = 105.222123;
	//ft_printf("%+u  fhfh%-5d   %+.3f\n, %20o, %10X, %15x\n", -21, 50, d, 156, 200, 250);
	//printf("%+u  fhfh%-5.60d   %+.3f\n, %20.60o, %10X, %.15x\n", -21, 50, d, 156, 200, 250);
	//printf("%u  fhh%-5d   %+.3f", 21, 50, d);
	//printf("%u        %d                 %f\n", 21, 50, d);
	ft_printf("%d", 10);
	printf("%d", 10);
	return 0;
}