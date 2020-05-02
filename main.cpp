#include <iostream>
#include ".\include\sort.h"
#include ".\include\array_make.h"

using namespace std;

const int LENGTH = 100 ;                                                                 //待排序数组长度
const int LOW = -200 ;                                                                   //待排序数组区间最小值
const int HIGH = 200 ;                                                                   //待排序数组区间最大值


int main()
{
    int orign_arr[LENGTH] ;
    int arr[LENGTH] ;
    int compare_count ;
    int swap_count ;

    //制造随机数组
//    int errorflag = rollarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), LOW , HIGH ) ;//产生一个有重复整数的数组
    int errorflag = makearr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), LOW , HIGH ) ;  //产生一个无重复整数的数组
    if( errorflag <= 0 )                                                                        //产生数组错误，返回失败代码：-1 = LOW > HIGH ; -2 = HIGH - LOW + 1 < LENGTH
        return errorflag ;
    cout <<"Original array is " <<  endl ;                                                      //显示排序前的数组
    for( int i = 0 ; i < LENGTH ; i++ )
        cout << orign_arr[i] << "  " ;
    cout << endl << endl ;

    copyarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), arr, sizeof(arr)/sizeof(arr[0]));//复制原数组，计数器清零
    compare_count = 0 ;
    swap_count = 0 ;
    //插入排序算法
    cout << "Insertion sort:"<< endl ;
    insertion_sort( arr, sizeof(arr)/sizeof(arr[0]), &compare_count, &swap_count ) ;
    cout <<"Sorted array is " <<  endl ;
    for( int i = 0 ; i < LENGTH ; i++ )                                                         //显示插入排序后的数组
        cout << arr[i] << "  " ;
    cout << endl ;
    cout <<"Insertion sort: compare_count = " << compare_count << endl ;
    cout <<"Insertion sort: swap_count = " << swap_count << endl ;
    cout << endl ;

    //希尔排序算法

    copyarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), arr, sizeof(arr)/sizeof(arr[0]));//复制原数组，计数器清零
    compare_count = 0 ;
    swap_count = 0 ;
    //快速排序算法
    cout << "Quick sort:"<< endl ;
    quick_sort( arr, 0, sizeof(arr)/sizeof(arr[0])-1, &compare_count, &swap_count ) ;
    cout <<"Sorted array is " <<  endl ;
    for( int i = 0 ; i < LENGTH ; i++ )                                                         //显示快速排序后的数组
        cout << arr[i] << "  " ;
    cout << endl ;
    cout <<"Quick sort: compare_count = " << compare_count << endl ;
    cout <<"Quick sort: swap_count = " << swap_count << endl ;
    cout << endl ;

    return 0;
}
