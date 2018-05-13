#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

enum week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

int main()
{
	intmax_t b;
	int a;
	a = 4;
	b = &a;

	printf("%jd\n", b);
}