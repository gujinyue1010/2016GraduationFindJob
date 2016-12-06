//
//  main.cpp
//  百度_单词接龙
//
//  Created by NetEase on 16/8/31.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 拉姆刚开始学习英文单词，对单词排序很感兴趣。
 如果给拉姆一组单词，他能够迅速确定是否可以将这些单词排列在一个列表中，使得该列表中任何单词的首字母与前一单词的为字母相同。
 你能编写一个程序来帮助拉姆进行判断吗？
 
 输入描述:
 
 输入包含多组测试数据。
 
 对于每组测试数据，第一行为一个正整数n，代表有n个单词。
 
 然后有n个字符串，代表n个单词。
 
 保证：
 
 2<=n<=200,每个单词长度大于1且小于等于10,且所有单词都是由小写字母组成。
 
 
 
 
 输出描述:
 对于每组数据，输出"Yes"或"No"
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
   
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        vector<string> vector(n);
        for (int i=0;i<n;i++)
        {
            cin>>vector[i];
        }
        
        int tag = 1;
        
        for (int i=0;i<n-1;i++)
        {
            string s1 = vector[i];
            string s2 = vector[i+1];
            int length = s1.length();
            
            if (s1[length-1] != s2[0])
            {
                tag = 0;
                break;
            }
        }
        
        if (tag == 1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
