#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

const bool LEFTSEARCH = true ;
const bool RIGHTSEARCH = false ;

//�����������飬���鳤�ȣ��Ƚϴ���������������������
int insertion_sort( int arr[], int length, int *compare_count = 0 , int *swap_count = 0 );

//ϣ���������飬���鳤�ȣ��Ƚϴ���������������������
int shell_sort( int arr[], int length, int *compare_count = 0, int *swap_count = 0 );

//�����������飬������˵��±꣬�����Ҷ˵��±꣬�Ƚϴ�������������������
int quick_sort( int arr[], int left, int right, int *compare_count = 0, int *swap_count = 0 );

#endif // SORT_H_INCLUDED
