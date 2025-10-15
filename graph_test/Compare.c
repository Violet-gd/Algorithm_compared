#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>


float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;						// evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

#ifndef Q3_VM
#ifdef __linux__
	assert( !isnan(y) ); // bk010122 - FPE?
#endif
#endif
	return y;
}

float difference(float f, double d){
	float value = fabs(f-d) / fabs(d);
	return value;
}

int main(){
	const float MAX_VALUE = 1e6f;
	FILE * file =fopen("output.txt","w");
	FILE * file1 =fopen("output1.txt","w");
	srand((unsigned)time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		float number0 = ((float)rand() / RAND_MAX) * MAX_VALUE;
		double number1 = number0;
		float resOf_rsqrt = Q_rsqrt(number0);
		float resOf_sqrtf = 1.0f / sqrtf(number0);
		double resOf_sqrt = 1.0 / sqrt(number1);
		float error1 = difference(resOf_rsqrt,resOf_sqrt);
		float error2 = difference(resOf_sqrtf,resOf_sqrt);
		fprintf(file, "%f %.20f\n", number0, error1);
		fprintf(file1, " %f %.20f\n", number0, error2);

	}
	fclose(file);
	fclose(file1);

	return 0;
}

