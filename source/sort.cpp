#include "..\include\sort.h"

using namespace std;

//插入排序，正常返回数组长度
int insertion_sort( int arr[], int length, int *compare_count = 0, int *swap_count = 0 )
{
    for( int i = 1 ; i < length ; i++ )
    {
        for( int j = i ; j > 0 ; j-- )
        {
            *compare_count += 1 ;
            if( arr[j-1] > arr[j] )
            {
                *swap_count += 1 ;
                arr[j-1] ^= arr[j] ;
                arr[j] ^= arr[j-1] ;
                arr[j-1] ^= arr[j] ;
            }
            else
                break;
        }
    }
    return length ;
}

//希尔排序

//快速排序，运行完毕返回1，递归调用返回0
int quick_sort( int arr[], int left, int right, int *compare_count, int *swap_count )
{
    if( left < right )
    {
        int temp = right ;
        int i = left ;
        int j = right ;
        bool searchflag = LEFTSEARCH ;
        while ( i < j )
        {
            *compare_count += 1 ;
            if( searchflag )                                                //左搜索
            {
                if ( arr[i] > arr[temp] )
                {
                    *swap_count += 1 ;
                    arr[i] ^= arr[temp] ;
                    arr[temp] ^= arr[i] ;
                    arr[i] ^= arr[temp] ;
                    temp = i ;
                    i++ ;
                    searchflag = RIGHTSEARCH ;
                }
                else
                    i++ ;
            }
            else                                                            //右搜索
            {
                if ( arr[j-1] < arr[temp] )
                {
                    *swap_count += 1 ;
                    arr[j-1] ^= arr[temp] ;
                    arr[temp] ^= arr[j-1] ;
                    arr[j-1] ^= arr[temp] ;
                    temp = j - 1 ;
                    j-- ;
                    searchflag = LEFTSEARCH ;
                }
                else
                    j-- ;
            }
        }
        quick_sort( arr, left, temp - 1, compare_count, swap_count ) ;      //左侧递归调用
        quick_sort( arr, temp + 1, right, compare_count, swap_count ) ;     //右侧递归调用
        return 0 ;
    }
    else
        return 1 ;
}
