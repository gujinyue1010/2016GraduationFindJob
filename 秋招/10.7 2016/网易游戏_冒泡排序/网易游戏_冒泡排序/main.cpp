//
//  main.cpp
//  网易游戏_冒泡排序
//
//  Created by NetEase on 16/10/8.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
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
    
    int a[] = {6,5,4,3,2,1};
    bubbleSort(a, 6);
    
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
