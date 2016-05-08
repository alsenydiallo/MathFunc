#include<stdio.h>
#define _USE_MATH_DEFINES 
#include<math.h>

int fact(int n)
{
	int result = 0;

	if (n == 0)
	    return 1;
	else
	    return n *= fact(n-1);
}

int main()
{
	double x = 5.15274E-8;
	double y = 1.19209E-7;

	double result =100;
	int n = 1;
	
	for(; result >=  y ; n++)
	  {
		result =(2.0/(fact((n + 1))) * pow((M_LN2/2), (n + 1)));
	  }

	printf("Result = %.10E \n", result);
	printf("expected to be less than : %.10E\n", y);
	printf("n : %i\n", n);

	return 0;
}
