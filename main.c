#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	long double	d = 0.12312312312312312323;
	//ft_printf("%+u  fhfh%-5d   %+.3f\n, %20o, %10X, %15x\n", -21, 50, d, 156, 200, 250);
	//printf("%+u  fhfh%-5.60d   %+.3f\n, %20.60o, %10X, %.15x\n", -21, 50, d, 156, 200, 250);
	//printf("%u  fhh%-5d   %+.3f", 21, 50, d);
	//printf("%u        %d                 %f\n", 21, 50, d);
	char *str = "World\n";
	char *join;
	join = ft_strjoin(PF_RESET, str);

	write(1, PF_RESET, ft_strlen(PF_RESET));
	ft_printf("%d\n", ft_strlen(PF_RESET));
	write(1, join, ft_strlen(join));
    printf("%030Le\n", d);
	return 0;
}