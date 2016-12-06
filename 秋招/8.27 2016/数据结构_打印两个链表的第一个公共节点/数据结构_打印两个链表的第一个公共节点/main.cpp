//
//  main.cpp
//  数据结构_打印两个链表的第一个公共节点
//
//  Created by 顾金跃 on 16/8/28.
//  Copyright © 2016年 顾金跃. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
    
}ListNode,*List;


//创建链表
void CreateList(List head,int n)
{
    ListNode *p,*q;
    p = head;
    
    for (int i=0;i<n;i++)
    {
        q = (ListNode *)malloc(sizeof(ListNode));
        cin>>q->data;
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

//创建两个有共同节点的链表
void CreateListBy2(List firstHead,List secondHead)
{
    ListNode *p,*q,*m,*n,*k;
    p = firstHead;
    q = secondHead;
    
    for(int i=1;i<=8;i++)
    {
        if (i <= 3)
        {
            m = (ListNode *)malloc(sizeof(ListNode));
            m->data = i;
            m->next = NULL;
            p->next = m;
            p = m;
        }
        else if (i <= 6)
        {
            m = (ListNode *)malloc(sizeof(ListNode));
            m->data = i;
            m->next = NULL;
            p->next = m;
            p = m;
            
            n = (ListNode *)malloc(sizeof(ListNode));
            n->data = i;
            n->next = NULL;
            q->next = n;
            q = n;
        }
        else
        {
            k = (ListNode *)malloc(sizeof(ListNode));
            k->data = i;
            k->next = NULL;
            
            p->next = k;
            q->next = k;
            p = k;
            q = k;
        }
    }
}

int GetListLength(List head)
{
    ListNode *p = head->next;
    int length = 0;
    
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}


void FindFirstSameNode(List firstHead,List secondHead)
{
    int firstListLength = GetListLength(firstHead);
    int secondListLength = GetListLength(secondHead);
    
    int dif = firstListLength - secondListLength;
    if (dif > 0)
    {
        ListNode *p = firstHead->next;
        ListNode *q = secondHead->next;
        
        int t = 1;
        while (t <= dif )
        {
            p = p->next;
            t++;
        }
        
        while (p && q)
        {
            if (p == q)
            {
                cout<<p->data<<endl;
                break;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
   
//    ListNode *firstListHead = (ListNode *)malloc(sizeof(ListNode));
//    ListNode *secondListHead = (ListNode *)malloc(sizeof(ListNode));
//    
//    cout<<"创建第一个链表:";
//    CreateList(firstListHead, 5);
//    
//    cout<<"创建第二个链表:";
//    CreateList(secondListHead, 4);
//    
//    
//    cout<<"开始打印两个链表的数据"<<endl;
//    PrintList(firstListHead);
//    PrintList(secondListHead);
    
    
    /*首先遍历两个链表得到他们的长度，就能知道哪个链表比较长，以及长链表比短链表
      多几个节点，在第二次遍历的时候，先在较长的链表上走多的个数的节点，然后再一起走。
     */
    ListNode *firstListHead = (ListNode *)malloc(sizeof(ListNode));
    ListNode *secondListHead = (ListNode *)malloc(sizeof(ListNode));
    
    CreateListBy2(firstListHead, secondListHead);
    PrintList(firstListHead);
    PrintList(secondListHead);
    
    cout<<"开始找两个链表的第一个公共节点:";
    FindFirstSameNode(firstListHead, secondListHead);
    return 0;
}
