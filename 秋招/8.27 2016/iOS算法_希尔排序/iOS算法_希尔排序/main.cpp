//
//  main.cpp
//  iOS算法_希尔排序
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//
//希尔排序，也称减小增量排序。将待排序的记录分成若干个子序列分别进行直接插入排序。

#include <iostream>
using namespace std;

void ShellSort(int a[],int n)
{
    for(int gap = n/2;gap>=1;gap/=2)
    {
        for (int i=0;i<gap;i++)
        {
            for (int j=i+gap;j<n;j+=gap)
            {
                int temp = a[j];
                int k;
                for (k = j-gap;k>=0;k-=gap)
                {
                    if (a[k] > temp)
                    {
                        a[k+gap] = a[k];
                    }
                    else
                    {
                        break;
                    }
                }
                a[k+gap] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[5] = {67,34,1,99,55};
    ShellSort(a, 5);
    
    for (int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
