//
//  main.cpp
//  网易游戏_堆排序
//
//  Created by NetEase on 16/10/8.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

//构造初始堆
void heapBuild(int a[], int n);
//堆调整
void heapAdjust(int a[], int n, int i);
//堆排序
void heapSort(int a[], int n);

int main(int argc, const char * argv[])
{
    int a[] = {16,7,3,20,17,8};
    
    //heapBuild(a, 6);
    heapSort(a, 6);
    
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}

void heapAdjust(int a[],int n,int i)
{
    int lChild = 2*i;
    int rChild = 2*i + 1;
    int max = i;
    
    if (i<=n/2)
    {
        if (lChild <= n && a[max-1] < a[lChild-1])
        {
            max = lChild;
        }
        
        if (rChild <= n && a[max-1] < a[rChild-1])
        {
            max = rChild;
        }
        
        if (max != i)
        {
            swap(a[i-1], a[max-1]);
            
            heapAdjust(a, n, max);
        }
    }
}

void heapBuild(int a[],int n)
{
    for (int i=n/2;i>=1;i--)
    {
        heapAdjust(a, n, i);
    }
}

void heapSort(int a[],int n)
{
    heapBuild(a, n);

    for (int i=n;i>=1;i--)
    {
        swap(a[0],a[i-1]);
        heapAdjust(a, i-1, 1);
    }
}