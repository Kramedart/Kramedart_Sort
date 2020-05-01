#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "..\include\array_make.h"

using namespace std;

//roll出一个数字可重复的整数数组
int rollarr( int arr[], int length, int low, int high, unsigned seed )
{
    if( low > high )                                //区间下限＞区间上限，返回错误值-1
        return -1 ;
    int section = high - low + 1 ;
    if( seed )                                      //seed≠0，指定种子
        srand( seed );
    else                                            //seed=0，随机种子
        srand( (unsigned)time(NULL) );
    for( int i = 0 ; i < length ; i++ )
        arr[i] = low + rand()%section ;
    return 1 ;
}

//roll出一个数字不可重复的整数数组
int makearr( int arr[], int length, int low, int high, unsigned seed )
{
    if( low > high )                                //区间下限＞区间上限，返回错误值-1
        return -1 ;
    int section = high - low + 1 ;
    if( section < length )                          //区间长度＜数组长度，返回错误值-2
        return -2 ;
    if( seed )                                      //seed≠0，指定种子
        srand( seed );
    else                                            //seed=0，随机种子
        srand( (unsigned)time(NULL) );

    //洗牌算法
    int *temparr = new int[section] ;
    for( int i = 0 ; i < section ; i++ )
        temparr[i] = low + i ;
    for( int i = 0 , temp = 0 ; i < length ; i++ )
    {
        temp = section - rand()%(section-i) - 1 ;
        if( temp != i )                             //如果成功洗牌就交换，否则位置不变
        {
            temparr[i] ^= temparr[temp] ;
            temparr[temp] ^= temparr[i] ;
            temparr[i] ^= temparr[temp] ;
        }
    }

    for( int i = 0 ; i < length ; i++ )
        arr[i] = temparr[i] ;
    delete []temparr;
    return 1 ;
}
