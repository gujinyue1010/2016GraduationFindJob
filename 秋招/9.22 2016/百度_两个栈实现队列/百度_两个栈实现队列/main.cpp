//
//  main.cpp
//  百度_两个栈实现队列
//
//  Created by NetEase on 16/9/23.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 1.用两个栈实现一个队列：
 <分析>:
 入队:将元素进栈A。
 出队:如果栈B为空,先将栈A的数据pop,并且push进栈B,栈B出栈。
      如果不为空,直接B出栈。
 
 2.两个队列实现栈:
 <分析>:
 入栈:将元素进队列A。
 出栈:判断A中元素个数是否为1,若为1,出栈。
     否则将队列A中的元素放到队列B,知道队列A中只剩下一个元素,然后A出队列,再把B的元素放到A中。
 */
#include <iostream>
#include <stack>

using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int value)
{
    stack1.push(value);
}

int pop()
{
    int result;
    
    if(!stack2.empty())
    {
        result = stack2.top();
        stack2.pop();
    }
    else
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        result = stack2.top();
        stack2.pop();
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
