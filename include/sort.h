#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

//插入排序：数组，数组长度，比较次数计数，交换次数计数
int insertion_sort( int arr[], int length, int *compare_count, int *swap_count );

//希尔排序
int shell_sort();

//快速排序
int quick_sort();

#endif // SORT_H_INCLUDED
