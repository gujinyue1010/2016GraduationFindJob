//
//  main.cpp
//  o(1)时间复杂度，求栈的最大值
//
//  Created by NetEase on 16/10/7.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
1. 一个栈stack,具有push和pop操作，其时间复杂度是o(1).
 现在设计max操作,求栈的最大值,该操作的时间复杂度也要求为o(1).

2.算法描述:
 一个存储所有最大值的栈maxStack。
 1)当push入栈的元素大于当前的最大元素，将该元素压入最大值栈maxStack
 2)maxStack始终保存栈中当前元素的最大值
 3)当前最大元素被pop出栈时，maxStack栈顶对应的最大元素也弹出栈。
 */

#include <iostream>
#include <stack>
using namespace std;

void push(int a)
{
    
}

int main(int argc, const char * argv[]) {
    
    stack<int> mainStack;
    stack<int> maxStack;
    
    return 0;
}
