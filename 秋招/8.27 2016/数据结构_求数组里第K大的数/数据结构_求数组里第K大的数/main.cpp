//
//  main.cpp
//  数据结构_求数组里第K大的数
//
//  Created by NetEase on 16/8/29.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 求数组里第K大的数:
 (1)通过各种排序手法可得。
 (2)如果不能排序，利用快排的思想来解：
    每一次的快排，都需要找到一个基准值，一次快排结束后，左边的比基准值小，右边的比基准值大。
    如果此时基准值的下标为i，那么这个数就是N－i+1大的数了。如果正好等于K，那就得到了，如果k
    比N-i+1小，说明目标值在key右边，否则在左边。
 */
#include <iostream>
#include <vector>
using namespace std;

int getKth(vector<int>a,int low,int high,int K)
{
    if (low > high)
    {
        return 0;
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
    
    if (K < ((a.size()-1)-first+1))//说明目标值在右边
    {
        return getKth(a, first+1, high,K);
    }
    else if (K > ((a.size()-1)-first+1))//说明目标值在左边
    {
        return getKth(a, low, first-1, K);
    }
    else if (K == (a.size()-1)-first+1)
    {
        return a[first];
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    vector<int> vector(10);
    for (int i=0;i<10;i++)
    {
        vector[i] = i+1;
    }
    
    int result = getKth(vector, 0, 9, 1);

    if (result == 0)
    {
        cout<<"寻找有误"<<endl;
    }
    else
    {
        cout<<result<<endl;
    }
    return 0;
}
