//
//  main.cpp
//  数据结构_在o(1)时间删除某节点
//
//  Created by 顾金跃 on 16/8/28.
//  Copyright © 2016年 顾金跃. All rights reserved.
//
/*
 1.在o(1)时间删除链表节点:
 
 2.给定链表的头指针和一个节点指针。
 */
#include <iostream>
using namespace std;

typedef  struct ListNode
{
    int data;
    struct ListNode *next;
    
}ListNode, *List;

//创建链表
void CreateList(List head)
{
    ListNode *p ,*q;
    p = head;
    
    for (int i=1;i<=5;i++)
    {
        q = (ListNode *)malloc(sizeof(ListNode));
        q->data = i;
        q->next = NULL;
        
        p->next = q;
        p = q;
    }
}

//打印链表
void PrintList(List head)
{
    ListNode *p = head->next;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data =-1;
    head->next = NULL;
    CreateList(head);
    PrintList(head);
    
    cout<<"现在我们假设已经有指针指向第三个节点，我们要在o(1)内删除它"<<endl;
    ListNode *p = head;
    int t = 0;
    while (t<3)
    {
        p = p->next;
        t++;
    }
    
    p->data = p->next->data;
    free(p->next);
    p->next = p->next->next;
    
    PrintList(head);
    
    return 0;
}
