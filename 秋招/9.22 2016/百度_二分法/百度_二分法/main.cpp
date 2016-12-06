//
//  main.cpp
//  百度_二分法
//
//  Created by NetEase on 16/9/26.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

//递归
int fun1(int a[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int middle = (low+high)/2;
    if (a[middle] == key)
    {
        return middle;
    }
    else if (a[middle] > key)
    {
        return fun1(a, key, low, middle-1);
    }
    else if (a[middle] < key)
    {
        return fun1(a, key, middle+1, high);
    }
    
    return -1;
}

//非递归
int fun2(int a[],int key,int low, int high)
{
    int middle = (low+high)/2;
    int left = low;
    int right = high;
    
    while (left < right && a[middle]!=key)
    {
        if (a[middle] > key)
        {
            high = middle-1;
        }
        else if (a[middle] < key)
        {
            left = middle + 1;
        }
        
        middle = (low + high)/2;
    }
    
    if (a[middle] == key)
    {
        return middle;
    }
    else
    {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    
    int a[]={1,2,3,4,5,6,7,8,9};
    
    cout<<fun1(a, 5, 0, 8);
    return 0;
}
