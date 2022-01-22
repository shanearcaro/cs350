#include "stdio.h"
#include "stdlib.h"

void reality1();
void reality2();
void reality3(int number);
double fun(int number);

typedef struct {
	int a[2];
	double d;
} struct_t;


int main(int argc, char *argv[]) {
	int number;
	reality1();
	reality2();

	// Get user input for n
	if (argc == 1)
		number = 5;
	else
		number = atoi(argv[1]);
	reality3(number);

	return 0;
}

void reality1() {
	float fnumber = 50000;
	int inumber   = 40000;

	float fsquared;
	int   isquared;
	
	// Reality 1 test 1 with floating number
	printf("reality_1_example_1_float: f = %f\n", fnumber);
	printf("f*f=");
	
	fsquared = fnumber * fnumber;
	if (fsquared >= 0)
		printf("%f which is greater than 0\n\n", fsquared);
	else
		printf("%f which is less than 0\n\n", fsquared);

	// Reality 1 test 1 with int test 1
	printf("reality_1_example_1_int: i = %d\n", inumber);
	printf("i*i=");

	isquared = inumber * inumber;
	if (isquared >= 0)
		printf("%d which is greater than 0\n\n", isquared);
	else
		printf("%d which is less than 0\n\n", isquared);

	// Reality 1 test 1 with int test 2
	inumber = 50000;
	printf("reality_1_example_1_int: i = %d\n", inumber);
	printf("i*i=");

	isquared = inumber * inumber;
	if (isquared >= 0)
		printf("%d which is greater than 0\n\n", isquared);
	else
		printf("%d which is less than 0\n\n", isquared);
}

void reality2() {
	float fx = 1e20, fy = -1e20, fz = 3.14;
	unsigned int uix = 12, uiy = 34, uiz = 56;
	int          six = 12, siy = 34, siz = 56;

	// Reality 1 test 2 with unisnged int
	printf("reality_1_example_2_unsigned: uix = %d, uiy = %d, uiz = %d\n", uix, uiy, uiz);
	unsigned int eq1 = ((uix + uiy) + uiz), eq2 = (uix + (uiy + uiz));
	printf("((uix + uiy) + uiz)=%d == ((uix + (uiy + uiz))=%d\n\n", eq1, eq2);

	// Reality 1 test 2 with signed int
	printf("reality_1_example_2_signed: six = %d, siy = %d, siz = %d\n", six, siy, siz);
	int eq3 = ((six + siy) + siz), eq4 = (six + (siy + siz));
	printf("((six + siy) + siz)=%d == ((six + (siy + siz))=%d\n\n", eq3, eq4);

	// Reality 1 test 2 with float
	printf("reality_1_example_2_float: fx = %f, fy = %f, fz = %f\n", fx, fy, fz);
	float eq5 = ((fx + fy) + fz), eq6 = (fx + (fy + fz));
	printf("((fx + fy) + fz)=%f != ((fx + (fy + fz))=%f\n\n", eq5, eq6);

}

void reality3(int number) {
	double d;
	int i;

	printf("reality_3: n = %d iterations\n", number);
	for (int i = 0; i <= number; i++) {
		fun(i);
	}
}

double fun(int number) {
	volatile struct_t s;

	s.d = 3.14;
	s.a[number] = 1073741824;
	printf("fun(%d) -> %f\n", number, s.d);

	return s.d;
}
