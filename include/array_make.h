#ifndef ARRAY_MAKE_H_INCLUDED
#define ARRAY_MAKE_H_INCLUDED

//roll��һ�����ظ����������飬����Ϊlength������Ϊ[low,high]����ѡ�����������seed��Ĭ��Ϊ0���������
int rollarr( int arr[], int length, int low, int high, unsigned seed = 0 );

//roll��һ�������ظ����������飬����Ϊlength������Ϊ[low,high]����ѡ�����������seed��Ĭ��Ϊ0���������
int makearr( int arr[], int length, int low, int high, unsigned seed = 0 );

//���鸴�ƣ�ԭ���飬ԭ���鳤�ȣ����������飬���������鳤��
int copyarr( int orign_arr[], int orign_length, int copy_arr[], int copy_length );

#endif // ARRAY_MAKE_H_INCLUDED
