/* Print a float in binary: ftob.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void float_to_string(float f, char *s, int n);
void float_to_string(float,char *,int);
void print_float();

#define LEN 32
#define EXP_32 8		/* ending index of s for exponent */
#define MAN_32 9		/* starting index of s for significand */

int main(int argc, char **argv) {
  int length=LEN;
  float number;
  char string[LEN];

  number = atof(argv[1]);
  printf("f=%f\n",number);
  float_to_string(number,string,length);
  print_float(string,length);

  return 0;
}

/* convert float to binary and store in s, a string of 32 chars */
void float_to_string(float number, char* string, int length) {
  unsigned int u_int;

  // Handle first bit
  *string++ = number >= 0 ? '0' : '1';

  char exp[EXP_32], mant[length - MAN_32];
  int exp_length = 0, mant_length = 0;

  u_int = (unsigned int) number;
  number -= (int) number;

  for (int i = 0; i < (length - (MAN_32 - 1)); i++) {
    number *= 2;
    if (number != 0)
      mant_length++;
    if (number >= 1) {
      mant[i] = '1';
      number -= 1;
    }
    else
      mant[i] = '0';
  }

  for (int i = EXP_32 - 1; i >= 0; i--) {
    if (u_int > 0)
      exp_length++;
    exp[i] = u_int % 2 == 0 ? '0' : '1';
    u_int = u_int >> 1;
  }

  // End of exponent smash with start of mantissa
  int exponent = exp_length - 1;
  exponent += 127;
  u_int = exponent;

  string = string + (EXP_32 - 1);
  for (int i = MAN_32; i > 1; i--) {
    *string-- = u_int % 2 == 0 ? '0' : '1';
    u_int = u_int >> 1;
  }

  string = string + EXP_32 + 1;
  for (int i = 0; i < (length - MAN_32); i++) {
    if (i < (exp_length - 1))
      *string++ = exp[exp_length - 1 + i];
    else
      *string++ = mant[i - (exp_length - 1)];
  }
}

/* print space in between sign bit, exponent, and significand */
void print_float(char* string, int length) {
  int i = 0;

  for (i = 0; i < length; i++) {
    if (i == 1 || i == MAN_32)
      printf(" ");
    printf("%c", *string++);
  }
  printf("\n");
}

/* End of ftob.c */