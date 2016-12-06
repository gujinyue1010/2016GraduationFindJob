//
//  main.cpp
//  iOS算法_直接插入排序
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//
/*
 直接插入排序的基本思想：每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当位置。
 
 1.初识时:a[0]自成为一个有序区，无序区为a[1...n-1];令i＝1；
 2.将a[i]插入到当前有序区a[0...i-1]的有序区间
 3.i++并重复(2),知道i＝n－1，排序完成。
 
 时间复杂度:o(n^2)
 
 */
#include <iostream>
using namespace std;

void insertSort(int a[],int n)
{
    for (int i=1;i<n;i++)
    {
        if (a[i] < a[i-1])
        {
            int temp = a[i];
            int j;
            for (j=i-1; j>=0;j--)
            {
                if (a[j] > temp)
                {
                    a[j+1] = a[j];
                }
                else
                {
                    break;
                }
            }
            a[j+1] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {10,9,39,1,76,57,33,48,3,99};
    insertSort(a, 10);
    
    for (int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
