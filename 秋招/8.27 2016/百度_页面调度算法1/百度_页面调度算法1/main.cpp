//
//  main.cpp
//  百度_页面调度算法1
//
//  Created by NetEase on 16/8/31.
//  Copyright © 2016年 NetEase. All rights reserved.
//

//思路：借鉴了解析中某位大神的思路，之前用的方法太复杂，我竟然给每个cache页面都设置了一个计数器，之后越写越复杂，忽略了FIFO置换算法的原始含义
//设置一个队列，最先进入cache缓冲的肯定在队首。当请求新页面时，有三种情况：1，该页面在cache缓冲中，直接忽略，且不对队列做任何处理；2，该页面
//不在cache缓冲中且有空闲cahce，直接压入队列；3，该页面不在cache中且cahce区已满，置换算法，将队首页面置出，该页面压入队尾。
//本来一个队列足够完成，但是STL中queue模板并没有迭代器，也就无法查找页面是否在队列中，故设置一个set与队列同步变化
#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    
    while(cin >> n >> m){
        
        queue<int> queue;
        set<int> set;
        
        int i, currentPage, cnt = 0;
        
        for(i=0; i<m; ++i){
            
            cin >> currentPage;
            
            if(set.find(currentPage)==set.end())
            {
                //不在cache缓冲中
                ++cnt;
                if(set.size() == n)
                {
                    //cache缓冲区已满，置换队首的页面
                    set.erase(queue.front());
                    set.insert(currentPage);
                    queue.pop();
                    queue.push(currentPage);
                }
                else
                {
                    //cache缓冲区未满
                    set.insert(currentPage);
                    queue.push(currentPage);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}