//
//  main.cpp
//  数据结构_逆序打印链表
//
//  Created by 顾金跃 on 16/8/27.
//  Copyright © 2016年 顾金跃. All rights reserved.
//
/*
 链表逆序输出:
 (1)借用栈:栈是先进后出的，链表前面的元素在栈底，后面的元素在栈顶。
 (2)先逆置链表，再顺序输出。
 (3)利用递归。
 (4)利用数组。
 */
#include <iostream>
#include <stack>
using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
    
}ListNode,*List;

//创建链表
void CreateList(List head);
//打印链表
void PrintList(List head);
//逆序打印链表
void ReversePrintList(List head);
//逆置链表(前插法)
List ReverseList(List head);

//递归打印链表(使链表逆序输出)
void fun(List head);

int main(int argc, const char * argv[]) {
    
    
    //分配链表头节点
    ListNode *head;
    head = (ListNode *)malloc(sizeof(ListNode));
    head->data = -1;
    head->next = NULL;

    CreateList(head);
    PrintList(head);
    //ReversePrintList(head);
    
//    cout<<"************************"<<endl;
//    PrintList(ReverseList(head));
    
    cout<<"递归实现链表的逆序输出:";
    fun(head);
    
    return 0;
}

void CreateList(List head)
{
    ListNode *p,*q;
    p = head;
    for (int i=1;i<=10;i++)
    {
        q = (ListNode *)malloc(sizeof(ListNode));
        q->data = i;
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

void PrintList(List head)
{
    ListNode  *p = head->next;
    
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void ReversePrintList(List head)
{
    //遍历链表，然后加入栈，利用栈先进后出的特性。
    ListNode *p = head->next;
    stack<int> stack;
    
    while (p)
    {
        stack.push(p->data);
        p = p->next;
    }
    
    while (!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;
}

List ReverseList(List head)
{
//    ListNode *newHead = (ListNode *)malloc(sizeof(ListNode));
//    newHead->data = -1;
//    newHead->next = NULL;
    
    ListNode *p = head->next;
    ListNode *q = p;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    head->next = NULL;
    
    while (p)
    {
        q = q->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
    
    return head;
}

void fun(List head)
{
    ListNode *p = head;
    if (!p)
    {
        return ;
    }
    fun(p->next);
    cout<<p->data<<" ";
}