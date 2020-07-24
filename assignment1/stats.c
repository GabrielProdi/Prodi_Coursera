/**
 * @file stats.c
 * @brief Performs statistical analysis on a given array of data.
 * 
 * Description: A simple C-Programming that calculate some statistics on a set of numbers:
 *                   - Mean; 
 *                   - Median;
 *                   - Maximum;
 *                   - Minimum;
 *                   - Sort a descending sequence
 * 
 * @author Gabriel Ferreira Prodi
 * @date July 2020
 * 
 **/


#include <stdio.h>
#include "stats.h"

#define LENGTH 40  // Length of array

int main () {
  unsigned char array [LENGTH] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                  114, 88,   45,  76, 123,  87,  25,  23,
                                  200, 122, 150, 90,   92,  87, 177, 244,
                                  201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

  sort_array (array, LENGTH);
/*
  unsigned char median = find_median (array, LENGTH);
  unsigned char mean = find_mean (array, LENGTH);
  unsigned char minimun = find_minimum (array, LENGTH);
  unsigned char maximun = find_maximum (array, LENGTH);
*/  
  print_array (array, LENGTH);
  //print_statistics();

  return 0;
}

// ===================================================================================================
//                                            FUNCTIONS
// ===================================================================================================
 
void print_statistics () {
  

}

void print_array (unsigned char *data, unsigned int n) {
  unsigned int i;

  for ( i = 0; i < (n - 1); i++) {
    printf ("%d ", data [i]);
  }
  printf ("%d \n", data [i]);
}

/*
unsigned char find_median (unsigned char *data, unsigned int n) {
  
}

unsigned char find_mean (unsigned char *data, unsigned int n) {
  
}

unsigned char find_maximum (unsigned char *data, unsigned int n) {
  
}

unsigned char find_minimum (unsigned char *data, unsigned int n) {
  
}
*/

void sort_array (unsigned char *data, unsigned int n){
  unsigned int i, j;
  
  for (i = 0; i < (n - 1) ; i++) {
    for (j = i + 1; j < n ; j++ ){
      if ( *(data + i) < *(data + j)){
        unsigned char aux = *(data + i);
        *(data + i) = *(data + j);
        *(data + j) = aux;
      }
    }
  }

}
