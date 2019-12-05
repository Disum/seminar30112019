#ifndef ARRAY_H
#define ARRAY_H

#define DEFAULT_LENGTH 1000
int read_array(const char *name, char **array, int n);
void print_array(char **array, int n);
void free_array(char **array, int n);

#endif
