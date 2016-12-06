//
//  main.cpp
//  网易游戏_字符串去重
//
//  Created by NetEase on 16/10/9.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;


int main(int argc, const char * argv[]) {
    
    string str = "dabaccdeff";
    set<char> set1;
    
    for(int i=0;i<str.size();i++)
    {
        set1.insert(str[i]);
    }
    
    set<char>::iterator itr = set1.begin();
    
    for(itr;itr!=set1.end();itr++)
    {
        cout<<*itr<<" ";
    }
    
    return 0;
}
