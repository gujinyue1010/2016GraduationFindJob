//
//  main.cpp
//  网易游戏_选择排序
//
//  Created by NetEase on 16/10/8.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

void selectSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minLocation = i;
        
        for(int j=i+1;j<n;j++)
        {
            if (a[minLocation] > a[j])
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
    
    int a[] = {6,5,4,3,2,1};
    selectSort(a, 6);
    
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
