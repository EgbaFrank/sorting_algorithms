#ifndef SORT_H
#define SORT_H

#include <stdio.h>

int min(int arr[], int start, int n);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

#endif /*SORT_H*/
