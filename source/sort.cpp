#include "..\include\sort.h"

using namespace std;

//插入排序，正常返回数组长度，异常返回-1
int insertion_sort( int arr[], int length, int *compare_count, int *swap_count )
{
    if( length < 0 )
        return -1 ;
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
                break ;
        }
    }
    return length ;
}

//希尔排序，正常返回数组长度，异常返回-1
int shell_sort( int arr[], int length, int *compare_count, int *swap_count )
{
    if( length < 0 )
        return -1 ;
    //Sedgewick希尔排序增量序列
    int sedgewick[28] =
    {
               1,        5,       19,       41,       109,       209,        505,
             929,     2161,     3905,     8929,     16001,     36289,      64769,
          146305,   260609,   587521,  1045505,   2354689,   4188161,    9427969,
        16764929, 37730305, 67884289,150958081, 268386305, 603906049, 1073643521
    };
    int round = 0 ;
    while( round < 28 && length > sedgewick[round] )
        round++ ;
    while( round-- > 0 )
    {
        int roundlength = sedgewick[round] ;
        for( int i = 0 ; i < roundlength ; i++  )
        {
            //步长为增量的插入排序
            for( int j = i + roundlength ; j < length ; j += roundlength )
                for( int k = j ; k > roundlength - 1 ; k -= roundlength )
                {
                    *compare_count += 1 ;
                    if( arr[k-roundlength] > arr[k] )
                    {
                        *swap_count += 1 ;
                        arr[k-roundlength] ^= arr[k] ;
                        arr[k] ^= arr[k-roundlength] ;
                        arr[k-roundlength] ^= arr[k] ;
                    }
                    else
                        break ;
                }
        }
    }
    return length ;
}

//快速排序，运行完毕返回1，递归调用返回0，异常返回-1
int quick_sort( int arr[], int left, int right, int *compare_count, int *swap_count )
{
    if( left < 0 || right < 0)
        return -1 ;
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
