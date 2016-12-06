//
//  main.cpp
//  百度_找出一个字符串的最长数字串
//
//  Created by NetEase on 16/9/23.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 以下几个问题比较相似：
 1.找出字符串中最长数字子串
 2.找出字符串中最长递增子串
 3.找出两个字符串中的最大公共子串
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

//    string s = "fafda5678hruqa12343fa43faf56454354fas";
//    
//    int length = 0;
//    int index = 0;
//    
//    for (int i=0;i<s.size();i++)
//    {
//        if (s[i] >= 48 && s[i] <= 57)
//        {
//            int j;
//            for(j = 1;s[i+j]>=48&&s[i+j]<=57;j++)
//            {
//                
//            }
//            if (j > length)
//            {
//                length = j;
//                index = i;
//            }
//        }
//    }
//    
//    cout<<length<<endl;
//    
//    for(int i=index;i<index+length;i++)
//    {
//        cout<<s[i];
//    }
//    cout<<endl;
    
//    string s = "123434567893470";
//    int length = 0;
//    int index = 0;
//    
//    for(int i=0;i<s.size()-1;i++)
//    {
//        if (s[i] < s[i+1])
//        {
//            int k;
//            for(k=1;s[i+k] < s[i+k+1];k++)
//            {
//                
//            }
//            if((k+1) > length)
//            {
//                length = k+1;
//                index = i;
//            }
//        }
//    }
//    
//    cout<<length<<endl;
//    
//    for(int i=index;i<index+length;i++)
//    {
//        cout<<s[i]<<" ";
//    }
    
    
    string s1 = "abcfgjabcdefghfkddfskj";
    string s2 = "abcjgfdkabcdefghkdsfkl";
    
    int length = 0;
    int index = 0;
    
    for (int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            if (s1[i] == s2[j])
            {
                int k;
                for(k=1;s1[i+k]==s2[j+k];k++)
                {
                    
                }
                
                if (k > length)
                {
                    length = k;
                    index = i;
                }
            }
        }
    }
    
    for(int i=index;i<index+length;i++)
    {
        cout<<s1[i]<<" ";
    }
    return 0;
}
