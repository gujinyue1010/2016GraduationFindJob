//
//  main.cpp
//  网易游戏_快排
//
//  Created by NetEase on 16/10/8.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

void QSort(int a[], int low, int high)
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
            last --;
        }
        a[first] = a[last];
        
        while (first < last && a[first] <= key)
        {
            first ++;
        }
        a[last] = a[first];
    }
    
    a[first] = key;
    
    QSort(a, low, first-1);
    QSort(a, first+1, high);
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    QSort(a, 0, 9);
    
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
