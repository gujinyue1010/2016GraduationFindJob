//
//  main.cpp
//  百度_swap方法
//
//  Created by NetEase on 16/9/26.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    //^ 异或(若参加运算的两个二进制同号,则结果为0,异号则为1)
    // a ^= b;
    //b ^= a;
    //a ^= b;
    
    a = a^b;
    
    b = b^a;
    a = a^b;
}

int main(int argc, const char * argv[]) {
  
    int a = 3,b=4;
    swap(a, b);
    
    cout<<a<<" "<<b<<endl;
    return 0;
}
