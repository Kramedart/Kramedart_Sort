#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

const bool LEFTSEARCH = true ;
const bool RIGHTSEARCH = false ;

//插入排序：数组，数组长度，比较次数计数，交换次数计数
int insertion_sort( int arr[], int length, int *compare_count = 0 , int *swap_count = 0 );

//希尔排序：数组，数组长度，比较次数计数，交换次数计数
int shell_sort( int arr[], int length, int *compare_count = 0, int *swap_count = 0 );

//快速排序：数组，数组左端点下标，数组右端点下标，比较次数计数交换次数计数
int quick_sort( int arr[], int left, int right, int *compare_count = 0, int *swap_count = 0 );

#endif // SORT_H_INCLUDED
