#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int main(void)
{
	/*double d1023 = 89884656743115795386465259539451236680898848947115328636715040578866337902750481566354238661203768010560056939935696678829394884407208311246423715319737062188883946712432742638151109800623047059726541476042502884419075341171231440736956555270413618581675255342293149119973622969239858152417678164812112068608.0;
	double dminus2047 = 1.0 / 16777216.0 / d1023;
	//%5.0f", 0.0) */
	char *s = "%f";
	double value = 0.000001;
	ft_printf("  my:");
	int my = ft_printf(s, value);
	ft_printf("\nreal:");
	int real = printf(s, value);
	printf("\nfull:");
	printf("%.1000f\n", value);
	ft_printf("\nmy:%d -- real:%d\n", my, real);
	return (0);
}
