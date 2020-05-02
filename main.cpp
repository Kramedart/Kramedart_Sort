#include <iostream>
#include ".\include\sort.h"
#include ".\include\array_make.h"

using namespace std;

const int LENGTH = 100 ;                                                                 //���������鳤��
const int LOW = -200 ;                                                                   //����������������Сֵ
const int HIGH = 200 ;                                                                   //�����������������ֵ


int main()
{
    int orign_arr[LENGTH] ;
    int arr[LENGTH] ;
    int compare_count ;
    int swap_count ;

    //�����������
//    int errorflag = rollarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), LOW , HIGH ) ;//����һ�����ظ�����������
    int errorflag = makearr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), LOW , HIGH ) ;  //����һ�����ظ�����������
    if( errorflag <= 0 )                                                                        //����������󣬷���ʧ�ܴ��룺-1 = LOW > HIGH ; -2 = HIGH - LOW + 1 < LENGTH
        return errorflag ;
    cout <<"Original array is " <<  endl ;                                                      //��ʾ����ǰ������
    for( int i = 0 ; i < LENGTH ; i++ )
        cout << orign_arr[i] << "  " ;
    cout << endl << endl ;

    copyarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), arr, sizeof(arr)/sizeof(arr[0]));//����ԭ���飬����������
    compare_count = 0 ;
    swap_count = 0 ;
    //���������㷨
    cout << "Insertion sort:"<< endl ;
    insertion_sort( arr, sizeof(arr)/sizeof(arr[0]), &compare_count, &swap_count ) ;
    cout <<"Sorted array is " <<  endl ;
    for( int i = 0 ; i < LENGTH ; i++ )                                                         //��ʾ��������������
        cout << arr[i] << "  " ;
    cout << endl ;
    cout <<"Insertion sort: compare_count = " << compare_count << endl ;
    cout <<"Insertion sort: swap_count = " << swap_count << endl ;
    cout << endl ;

    //ϣ�������㷨

    copyarr( orign_arr, sizeof(orign_arr)/sizeof(orign_arr[0]), arr, sizeof(arr)/sizeof(arr[0]));//����ԭ���飬����������
    compare_count = 0 ;
    swap_count = 0 ;
    //���������㷨
    cout << "Quick sort:"<< endl ;
    quick_sort( arr, 0, sizeof(arr)/sizeof(arr[0])-1, &compare_count, &swap_count ) ;
    cout <<"Sorted array is " <<  endl ;
    for( int i = 0 ; i < LENGTH ; i++ )                                                         //��ʾ��������������
        cout << arr[i] << "  " ;
    cout << endl ;
    cout <<"Quick sort: compare_count = " << compare_count << endl ;
    cout <<"Quick sort: swap_count = " << swap_count << endl ;
    cout << endl ;

    return 0;
}
