//
//  main.cpp
//  网易游戏_插入排序
//
//  Created by NetEase on 16/10/8.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

void insertSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        if (a[i] < a[i-1])
        {
            for(int j=i-1;j>=0;j--)
            {
                if (a[j+1] < a[j])
                {
                    int temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[]={6,5,4,3,2,1};
    
    insertSort(a, 6);
    
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
