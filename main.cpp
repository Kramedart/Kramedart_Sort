#include <iostream>
#include ".\include\sort.h"
#include ".\include\array_make.h"

using namespace std;

const int LENGTH = 10 ;                                                                 //���鳤��
const int LOW = -20 ;                                                                   //����������Сֵ
const int HIGH = 20 ;                                                                   //�����������ֵ


int main()
{
    int arr[LENGTH] ;
    int swap_count = 0 ;
    int compare_count = 0 ;

    //�����������
//    int errorflag = rollarr( arr, sizeof(arr)/sizeof(arr[0]), LOW , HIGH ) ;          //����һ�����ظ�����������
    int errorflag = makearr( arr, sizeof(arr)/sizeof(arr[0]), LOW , HIGH ) ;            //����һ�����ظ�����������
    if( errorflag <= 0 )                                                                //����������󣬷���ʧ�ܴ��룺-1 = LOW > HIGH ; -2 = HIGH - LOW + 1 < LENGTH
        return errorflag ;

    cout <<"Original array is " <<  endl ;                                              //��ʾ����ǰ������
    for( int i = 0 ; i < LENGTH ; i++ )
        cout << arr[i] << "  " ;
    cout << endl << endl ;

    //���������㷨
    cout << "Insertion sort:"<< endl ;
    insertion_sort( arr, sizeof(arr)/sizeof(arr[0]), &swap_count, &compare_count ) ;
//    cout <<"Sorted array is " <<  endl ;
//    for( int i = 0 ; i < LENGTH ; i++ )                                               //��ʾ����������
//        cout << arr[i] << "  " ;
//   cout << endl << endl ;
    cout <<"Insertion sort: swap_count = " << swap_count << endl ;
    cout <<"Insertion sort: compare_count = " << compare_count << endl ;


    return 0;
}
