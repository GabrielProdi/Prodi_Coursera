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

unsigned char flag_sorted = 0;      // flag to ensure ordering of the database; 0 == false , 1 == true
unsigned char maximum;      // global values for printing purposes
unsigned char minimum;
unsigned char mean;
unsigned char median;

int main () {
  unsigned char array [ LENGTH ] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                  114, 88,   45,  76, 123,  87,  25,  23,
                                  200, 122, 150, 90,   92,  87, 177, 244,
                                  201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};
  flag_sorted = 0;      // when a database is set, the data isn't sorted
  
  //sort_array ( array, LENGTH );      // calling the function in the main makes debugging easier 
  
  // filling variables
  median = find_median ( array, LENGTH );
  mean = find_mean ( array, LENGTH );
  minimum = find_minimum ( array, LENGTH );
  maximum = find_maximum ( array, LENGTH );
  print_array ( array, LENGTH );      

  print_statistics();

  return 0;
}

// ===================================================================================================
//                                            FUNCTIONS DEFINITION
// ===================================================================================================
 
void print_statistics () {
  printf ( "In the database:\n" );
  printf ( "Maximum: %d\n" , maximum );
  printf ( "Minimum: %d\n" , minimum );
  printf ( "Mean: %d\n" , mean );
  printf ( "Median: %d\n" , median );
}

void print_array ( unsigned char *data, unsigned int n ) {
  unsigned int i;

  for ( i = 0 ; i < ( n - 1 ) ; i++ ) {
    printf  ("%d ", data [ i ] );
  }
  printf ( "%d \n", data [ i ] );
}

unsigned char find_median ( unsigned char *data, unsigned int n ) {
  unsigned int median;

  if ( n <= 0 ) {
    n = 1;
  }

  if ( ! flag_sorted ) {      // for finding the median, the dataset must be sorted
    sort_array ( data, n );
    flag_sorted = 1;
  }
  
  if ( n % 2 ) {      // if the length is odd, median is the central index
    median = *( data + ( n / 2 ) );
  } else {      // if the length is even, median is the average between the central indices
    median = ( ( ( *( data + ( n / 2 ) - 1 ) ) + ( *( data + ( n / 2 ) ) ) ) / 2 );
  }

  return median;
}

unsigned char find_mean ( unsigned char *data, unsigned int n ) {
  unsigned int i, sum = 0;

  if ( n <= 0 ) {
    n = 1;
  }
  for ( i = 0 ; i < n ; i++ ) {
    sum += data [i] ;
  }

  return ( sum / n );
}

unsigned char find_maximum ( unsigned char *data, unsigned int n ) {
  if ( ! flag_sorted ) {      // if the dataset is sorted, maximum value stands at position 0
    sort_array ( data, n );
    flag_sorted = 1;
  }

  return data [ 0 ];
}

unsigned char find_minimum ( unsigned char *data, unsigned int n ) {
  if ( ! flag_sorted ) {      // if the dataset is sorted, minimum value stands at last position
    sort_array ( data, n );
    flag_sorted = 1;
  }

  return data [ n - 1 ];
}


void sort_array ( unsigned char *data, unsigned int n ){
  unsigned int i, j;
  
  for ( i = 0 ; i < ( n - 1 ) ; i++ ) {
    for ( j = i + 1 ; j < n ; j++ ){
      if ( *( data + i ) < *( data + j ) ){
        unsigned char aux = *( data + i );
        *( data + i ) = *( data + j );
        *( data + j ) = aux;
      }
    }
  }

  flag_sorted = 1;
}
