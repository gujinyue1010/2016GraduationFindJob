//
//  main.cpp
//  百度_2个字符串的最大公共子串
//
//  Created by NetEase on 16/9/22.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s1 = "nbitheimanb";
    string s2 = "ithei";
    
    int len1 = s1.length();
    int len2 = s2.length();
    
    int count = 0;
    
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if (s1[i] == s2[j])
            {
                for(int k=1;s1[i+k]==s2[j+k];k++)
                {
                    if (k > count)
                    {
                        count = k;
                    }
                }
            }
        }
    }
    
    if (count == 0)
    {
        cout<<"没有公共子串"<<endl;
    }
    else
    {
        cout<<"公共子串长度:"<<count+1<<endl;
    }
    
    return 0;
}
