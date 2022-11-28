#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <time.h>
#include "darknet.h"
#include "list.h"

/* calculate the time consuming of 'a', a would be a function or an expression
 */
#define TIME(a) \
    do { \
    double start = what_time_is_it_now(); \
    a; \
    printf("%s took: %f seconds\n", #a, what_time_is_it_now() - start); \
    } while (0)

#define TWO_PI 6.2831853071795864769252866f

/* Return current time. (sec.usec) */
double what_time_is_it_now();

/* arr : an array of elements
 * n   : the amount of all the elements
 * size: the size of each element
 * func: shuffle the array
 */
void shuffle(void *arr, size_t n, size_t size);

/* arr : an array of elements
 * n   : the amount of all the elements
 * size: the size of each element
 * sections: the amount of the sections
 * func: shuffle each section of the array
 */
void sorta_shuffle(void *arr, size_t n, size_t size, size_t sections);

/* pts: an array of pointers
 * n  : the amount of the pointer array
 * func: free all the pointers of this array
 */
void free_ptrs(void **ptrs, int n);

/* c: character value
 * func: character number to int number. (e.g.  '1'-->1 , '2'-->2...)
 */
int alphanum_to_int(char c);

/*func: reverse operation of alphanum_to_int
 */
char int_to_alphanum(int i);

/* fd: file-descriptor of an opened file
 * return: OK: return the integer number read from file
 * func  : read an sizeof(int) bytes from file and convert it an integer
 */
int read_int(int fd);

/* func: reverse operation of read_int.
 */
void write_int(int fd, int n);

/* func: read 'bytes' data into 'buffer' from an opened file.
 *       exit when anything wrong.
 */
void read_all(int fd, char *buffer, size_t bytes);

/* func: reverse operation of read_all.
 */
void write_all(int fd, char *buffer, size_t bytes);

/* func: similar as read_all, but return -1 when anything wrong.
 */
int read_all_fail(int fd, char *buffer, size_t bytes);

/* func: reverse operation of read_all_fail
 */
int write_all_fail(int fd, char *buffer, size_t bytes);

/* func: replace the 'orig' with 'rep' in 'str', and store the new
 *       string into 'output'. (only the one 'orig' firstly found
 *       would be replace)
 */
void find_replace(const char *str, const char *orig, const char *rep, char *output);

/* func: print error message and exit.
 */
void malloc_error();

/* func: print error message and exit.
 */
void file_error(const char *s);

/* func: delete all ' ', '\t', '\n' characters in the string.
 */
void strip(char *s);

/* func: delete the 'bad' character in the string.
 */
void strip_char(char *s, char bad);

/* func: split a string with 'delim'.
 */
list *split_str(char *s, char delim);

/* func: return the line read from the opened file, otherwise,
 *       return NULL.
 *       (the caller is responsible to free the new malloced memory)
 */
char *fgetl(FILE *fp);

/* func: parse a line.
 *       (the caller is responsible to free the list)
 */
list *parse_csv_line(char *line);

/* func: copy a string.
 *       (the caller is responsible to free the new malloced memory)
 */
char *copy_string(char *s);

/* func: count how many fields of this line. Each field is separated
 *       by character ','.
 */
int count_fields(char *line);

/* func: parse a line into an array of floats. each field is separated
 *       by character ','
 *       (the caller is responsible to free the new malloced memory)
 */
float *parse_fields(char *line, int n);

/* func: add 's' to each of element in the array 'a'
 */
void translate_array(float *a, int n, float s);

/* func: clip 'a' such that a is in [min, max]
 */
float constrain(float min, float max, float a);

/* func: integer version of 'constrain'
 */
int constrain_int(int a, int min, int max);


/* func:
 *
 */
float rand_scale(float s);

/* func: return a random integer which is in the range of [min, max].
 */
int rand_int(int min, int max);

/* func: calculate means.
 * n   : the size of each column
 * els : the amount of the columns
 * avg : store the mean value of each column
 */
void mean_arrays(float **a, int n, int els, float *avg);

/* func: calculate distance between vector a and vector b.
 *  sub: the calculation step for each element of the vector
 */
float dist_array(float *a, float *b, int n, int sub);

/* func: convert vector a into one-hot matrix
 * n   : the amount of elements of 'a'
 * k   : how many classes(the value of each element must be in the range of [0, k])
 */
float **one_hot_encode(float *a, int n, int k);

/* func: convert clocks into seconds. (each clock is 0.001sec = 1ms)
 */
float sec(clock_t clocks);

/* func: print mean and variance of the vector 'a'.
 * n   : the size of the vector 'a'
 */
void print_statistics(float *a, int n);

/* func: return the index of the 'val' in the array of 'a'.
 */
int int_index(int *a, int val, int n);

#endif

