//
//  main.cpp
//  iOS算法_直接选择排序
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//
/*
 直接选择排序：
 1.直接选择排序和直接插入排序类似，都是将数据分为有序区和无序区，所不同的是直接插入排序是将无序区的第一个直接插入到有序区以形成一个更大的有序区。
 2.而直接选择排序是从无序区选一个最小的元素直接放到有序区的最后。
 
 描述如下：
 （1）初始时，数组全为无序区a[0...n-1].令i＝0；
 （2）在无序区a[i..n-1]中选取一个最小的元素，将其与a[i]交换。交换之后a[0...i]就是有序区了
 （3）i++并且重复第二步。直到i＝n－1，排序完成。
 
 时间复杂度:o(n^2)
 */
#include <iostream>
using namespace std;

void selectSort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int minLocation = i;
        
        for (int j=i+1;j<n;j++)
        {
            if (a[j] < a[minLocation])
            {
                minLocation = j;
            }
        }
        
        if (i!=minLocation)
        {
            int temp = a[i];
            a[i] = a[minLocation];
            a[minLocation] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    selectSort(a, 10);
    
    for (int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
