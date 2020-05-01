#include "..\include\sort.h"

//�������������������鳤�ȣ��쳣����0
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
