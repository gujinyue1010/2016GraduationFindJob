//
//  main.cpp
//  iOS算法_冒泡排序
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//

#include <iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[5] = {5,2,3,1,4};
    bubbleSort(a, 5);
    
    for (int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
