#include <iostream>
#include ".\include\sort.h"
#include ".\include\array_make.h"

using namespace std;

const int LENGTH = 10 ;                                                                 //数组长度
const int LOW = -20 ;                                                                   //数组区间最小值
const int HIGH = 20 ;                                                                   //数组区间最大值


int main()
{
    int arr[LENGTH] ;
    int swap_count = 0 ;
    int compare_count = 0 ;

    //制造随机数组
//    int errorflag = rollarr( arr, sizeof(arr)/sizeof(arr[0]), LOW , HIGH ) ;          //产生一个有重复整数的数组
    int errorflag = makearr( arr, sizeof(arr)/sizeof(arr[0]), LOW , HIGH ) ;            //产生一个无重复整数的数组
    if( errorflag <= 0 )                                                                //产生数组错误，返回失败代码：-1 = LOW > HIGH ; -2 = HIGH - LOW + 1 < LENGTH
        return errorflag ;

    cout <<"Original array is " <<  endl ;                                              //显示排序前的数组
    for( int i = 0 ; i < LENGTH ; i++ )
        cout << arr[i] << "  " ;
    cout << endl << endl ;

    //插入排序算法
    cout << "Insertion sort:"<< endl ;
    insertion_sort( arr, sizeof(arr)/sizeof(arr[0]), &swap_count, &compare_count ) ;
//    cout <<"Sorted array is " <<  endl ;
//    for( int i = 0 ; i < LENGTH ; i++ )                                               //显示排序后的数组
//        cout << arr[i] << "  " ;
//   cout << endl << endl ;
    cout <<"Insertion sort: swap_count = " << swap_count << endl ;
    cout <<"Insertion sort: compare_count = " << compare_count << endl ;


    return 0;
}
