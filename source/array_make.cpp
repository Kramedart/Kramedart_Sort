#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "..\include\array_make.h"

using namespace std;

//roll��һ�����ֿ��ظ�����������
int rollarr( int arr[], int length, int low, int high, unsigned seed )
{
    if( low > high )                                //�������ޣ��������ޣ����ش���ֵ-1
        return -1 ;
    int section = high - low + 1 ;
    if( seed )                                      //seed��0��ָ������
        srand( seed );
    else                                            //seed=0���������
        srand( (unsigned)time(NULL) );
    for( int i = 0 ; i < length ; i++ )
        arr[i] = low + rand()%section ;
    return 1 ;
}

//roll��һ�����ֲ����ظ�����������
int makearr( int arr[], int length, int low, int high, unsigned seed )
{
    if( low > high )                                //�������ޣ��������ޣ����ش���ֵ-1
        return -1 ;
    int section = high - low + 1 ;
    if( section < length )                          //���䳤�ȣ����鳤�ȣ����ش���ֵ-2
        return -2 ;
    if( seed )                                      //seed��0��ָ������
        srand( seed );
    else                                            //seed=0���������
        srand( (unsigned)time(NULL) );

    //ϴ���㷨
    int *temparr = NULL;
    temparr = new int[section] ;
    if( temparr != NULL )
    {
        for( int i = 0 ; i < section ; i++ )
            temparr[i] = low + i ;
        for( int i = 0 , temp = 0 ; i < length ; i++ )
        {
            temp = section - rand()%(section-i) - 1 ;
            if( temp != i )                         //����ɹ�ϴ�ƾͽ���������λ�ò���
            {
                temparr[i] ^= temparr[temp] ;
                temparr[temp] ^= temparr[i] ;
                temparr[i] ^= temparr[temp] ;
            }
        }

        for( int i = 0 ; i < length ; i++ )
            arr[i] = temparr[i] ;
    }
    delete []temparr;
    temparr = NULL;
    return 1 ;
}

//���鸴��,�����������鳤�ȣ��쳣����-1
int copyarr( int orign_arr[], int orign_length, int copy_arr[], int copy_length )
{
    if( orign_length <= 0 || copy_length <= 0 )
        return -1 ;
    //ֻ�����ܸ��ƵĲ���
    int length = copy_length < orign_length ? copy_length : orign_length ;
    for( int i = 0 ; i < length ; i++ )
        copy_arr[i] = orign_arr[i] ;
    return length ;
}
