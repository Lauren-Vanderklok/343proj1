#include <stdio.h>

/*
 * reads data from filename file
 * inner pointer of double pointer parameter points to data
 * returns 0 if there is an error, size of data in bytes if not
 */
size_t read_file (char* filename, char** buffer);

/*
 * writes contents of buffer of size size to filename file
 * returns 0 if there is an error
 */
size_t write_file(char* filename, char* buffer, size_t size);
