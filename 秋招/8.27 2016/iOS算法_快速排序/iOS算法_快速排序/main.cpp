//
//  main.cpp
//  iOS算法_快速排序
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//

#include <iostream>
using namespace std;

void Qsort(int a[],int low,int high)
{
    if (low >= high)
    {
        return ;
    }
    
    int first = low;
    int last = high;
    int key = a[first];
    
    while (first < last)
    {
        while (first < last && a[last] >= key)
        {
            
            last--;
        }
        a[first] = a[last];
        
        while (first < last && a[first] <= key)
        {
            first++;
        }
        a[last] = a[first];
    }
    a[first] = key;
    
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
    
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {5,99,23,76,87,46,23,8,66,87};
    Qsort(a, 0, 9);
    
    for (int i=0; i<10; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
