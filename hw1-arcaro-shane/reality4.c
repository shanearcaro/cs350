#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#define NNN 2048

void copyij();
void copyji();
void init_mat();
double time_diff();

int src[NNN][NNN], dst[NNN][NNN];

int main(int argc,char **argv) {
  
  double elapsed_time;
  struct timeval tv_s,tv_e;

  init_mat();
  gettimeofday(&tv_s, NULL); 
  copyij();
  gettimeofday(&tv_e, NULL); 

  /* fill here to compute elapsed time */
  elapsed_time = time_diff(tv_s, tv_e); 
  printf("copyji(): dim=%d: elapsed=%03f secs\n",NNN, elapsed_time);


  init_mat();
  gettimeofday(&tv_s, NULL); 
  copyji();
  gettimeofday(&tv_e, NULL); 
  elapsed_time = time_diff(tv_s, tv_e);
  /* fill here to compute elapsed time */
  
  printf("copyji(): dim=%d: elapsed=%03f secs\n",NNN, elapsed_time);

  return 0;
}

void copyij(){
  int i,j;

  for (int i = 0; i < NNN; i++) {
	  for (int j = 0; j < NNN; j++) {
		dst[i][j] = src[i][j];
	  }
  }

}

void copyji(){
  int i,j;

  for (int j = 0; j < NNN; j++) {
	  for (int i = 0; i < NNN; i++) {
		  dst[i][j] = src[i][j];
	  }
  }

}

void init_mat(){
  int i,j;

  for (i=0;i<NNN;i++)
    for (j=0;j<NNN;j++) src[i][j] = dst[i][j] = 1;

}

double time_diff(struct timeval start, struct timeval end) {
	double elapsed_time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 1e-6;
	return elapsed_time;
}
