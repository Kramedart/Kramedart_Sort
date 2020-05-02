#include "..\include\sort.h"

using namespace std;

//�������������������鳤��
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

//ϣ������

//��������������Ϸ���1���ݹ���÷���0
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
            if( searchflag )                                                //������
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
            else                                                            //������
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
        quick_sort( arr, left, temp - 1, compare_count, swap_count ) ;      //���ݹ����
        quick_sort( arr, temp + 1, right, compare_count, swap_count ) ;     //�Ҳ�ݹ����
        return 0 ;
    }
    else
        return 1 ;
}
