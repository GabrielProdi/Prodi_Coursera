/**
 * @file stats.h
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

#ifndef __STATS_H__
#define __STATS_H__

/**
 * Function: print_statistics
 * Description: 
 *     Prints the statistics of an array including minimum, maximum, mean, and median.
 *  
 */
void print_statistics();

/**
 * Function: print_array
 * Description: 
 *     Given an array of data and a length, prints the array to the screen
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 */
void print_array( unsigned char *data, unsigned int n );

/**
 * Function: find_median
 * Description: 
 *     Given an array of data and a length, returns the median value.
 *     For finding the median, the dataset must be sorted.
 *     If the length is odd, median is the central index. 
 *     If the length is even, median is the average between 
 *     the central indices
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 * 
 * @return unsigned char median : char result for median of array values
 */
 unsigned char find_median( unsigned char *data, unsigned int n );

/**
 * Function: find_mean
 * Description: 
 *     Given an array of data and a length, returns the mean. 
 *     
 * 
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 * 
 * @return unsigned char mean : char result for mean of array values
 */
unsigned char find_mean( unsigned char *data, unsigned int n );

/**
 * Function: find_maximum
 * Description: 
 *     Given an array of data and a length, returns the maximum.
 *     If the dataset is sorted, minimum value stands at last position
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 * 
 * @return unsigned char maximum : char result for maximum of array values
 */
unsigned char find_maximum( unsigned char *data, unsigned int n );

/**
 * Function: find_minimum
 * Description: 
 *     Given an array of data and a length, returns the minimum.
 *     If the dataset is sorted, maximum value stands at position 0
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 * 
 * @return unsigned char minimum : char result for minimum of array value
 */
unsigned char find_minimum( unsigned char *data, unsigned int n );

/**
 * Function: sort_array
 * Description: 
 *     Given an array of data and a length, sorts the array from largest to smallest. (The zeroth
 *     Element should be the largest value, and the last element (n-1) should be the smallest value.)
 * 
 *     To sort the data, each index is compared with the others. If the primary index is higher than the
 *     other, it is placed first in the ranking. Once all the indices are compared, at the end of the
 *     process, the data will be ordered from highest to lowest.
 * 
 * @param unsigned char *data : pointer to an n-element data array
 * @param unsigned int n : integer as the size of the array
 * 
 * @return unsigned char array: array of char result from the sort data array
 */
void sort_array ( unsigned char *data, unsigned int n );


#endif // __STATS_H__ 