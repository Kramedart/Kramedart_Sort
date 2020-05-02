#ifndef ARRAY_MAKE_H_INCLUDED
#define ARRAY_MAKE_H_INCLUDED

//roll出一个可重复的整数数组，长度为length，区间为[low,high]，可选择随机数种子seed，默认为0，随机种子
int rollarr( int arr[], int length, int low, int high, unsigned seed = 0 );

//roll出一个不可重复的整数数组，长度为length，区间为[low,high]，可选择随机数种子seed，默认为0，随机种子
int makearr( int arr[], int length, int low, int high, unsigned seed = 0 );

//数组复制：原数组，原数组长度，待复制数组，待复制数组长度
int copyarr( int orign_arr[], int orign_length, int copy_arr[], int copy_length );

#endif // ARRAY_MAKE_H_INCLUDED
