#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

#define	M_LOG2E		_Mldbl(1.4426950408889634074)	/* log 2e */
#define	M_LN2		_Mldbl(0.69314718055994530942)	/* log e2 */

float myexp(float x)
{
	int sign = +1;

	if (x < 0)
		sign = -1;

	x = abs(x);

	const float z = x * M_LOG2E;
	const int m = floorf(z);
	const float w = z - m;
	float r = 0.0;
	const float u = w * M_LN2;

	float r1 = ldexpf(1, m);

	float r2 = 1.0/5040;;

	//r2 = fmaf(r2, x, 1.0/5040);
	r2 = fmaf(r2, x, 1.0/720);
	r2 = fmaf(r2, x, 1.0/120);
	r2 = fmaf(r2, x, 1.0/24);
	r2 = fmaf(r2, x, 1.0/6);
	r2 = fmaf(r2, x, 0.5);
	r2 = fmaf(r2, x, 1);
	r2 = fmaf(r2, x, 1);

	r = fmaf(r1, r2, 0);
	//r = r1 * r2;

	return (sign < 0)? 1.0/r : r;
}


int main()
{
	float x = 1.0;
	float y1 =0.0, y2 = 0.0;

	for (int i = 1; i <= 30; x+=.5, i++)
	{
		y1 = myexp(x);
		y2 = expl(x);

		float rel_error = abs((y2 - y1) / y2);

		printf("%+0.9Le %0.9e %0.9Le %0.15Le\n", x, y1, y2, rel_error);
	}

	return 0;
}
