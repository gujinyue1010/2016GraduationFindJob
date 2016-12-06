//
//  main.cpp
//  百度_手动实现LRU
//
//  Created by NetEase on 16/9/23.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 1.C++中:队列的基本使用：
       1)back():返回最后一个元素
       2)empty():判断队列是否为空
       3)front():返回第一个元素
       4)pop():删除第一个元素
       5)push():在末尾加入一个元素
       6)size():返回队列中的个数
 
 2.C++中:set容器集合的基本使用：
       1)元素插入:insert()
       2)元素删除:s.erase();
       3)元素的检索:
         set<int> s;
         set<int>::iterator it;
         it = s.find(5);//5为需要查找的值
         if(it != s.end())
         {
            //找到了
         }
         else
         {
            //未找到
         }
 
 */
//LRU:最近最久未使用
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int main(int argc, const char * argv[]) {
    
    //需要使用的内存页面
    int a[9] = {7,0,1,2,0,3,0,4,2};
    
    //假设缓长度为3
    queue<int> queue;
    set<int> s;
    
    int j=0;
    while (queue.size() < 3)
    {
        queue.push(a[j]);
        s.insert(a[j]);
        j++;
    }
    
    for (int i=3;i<9;i++)
    {
        set<int> ::iterator it;
        it = s.find(a[i]);
        
        if (it!=s.end())//已经存在
        {
            //这里存在问题，好像只能重新构造队列
            queue.pop();
            queue.push(a[i]);
        }
        else//不存在
        {
            s.erase(queue.front());
            cout<<queue.front()<<" ";
            
            queue.pop();
            
            queue.push(a[i]);
            s.insert(a[i]);
        }
    }
    
    return 0;
}
