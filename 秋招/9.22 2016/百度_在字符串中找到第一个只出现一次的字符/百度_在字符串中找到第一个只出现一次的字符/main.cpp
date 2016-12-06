//
//  main.cpp
//  百度_在字符串中找到第一个只出现一次的字符
//
//  Created by NetEase on 16/9/23.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 题目:在一个字符串中找到第一个只出现一次的字符。
 
 1.直观想法:当我们访问到某一个字符的时候，就拿该字符和后面的每个字符比较，如果后面再也没有出现过，则该字符就是只出现一次的字符。时间复杂度 O(n^2)
 
 2.字符(char)是长度为8的数据类型，因此256种可能。创建一个数组，数组下标是该字符，数组值是该字符出现的次数。o(n)
 
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
   
    string s = "abcebad";
    int *a = new int[256];
    
    for(int i=0;i<256;i++)
    {
        a[i] = 0;
    }
    
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-1]++;
    }
    
    int count = 0;
    for(int i=0;i<256;i++)
    {
        if (a[i] == 2)
        {
            count ++;
        }
        else if (a[i] == 1)
        {
            count++;
            cout<<count<<endl;
            break;
        }
    }
    return 0;
}
