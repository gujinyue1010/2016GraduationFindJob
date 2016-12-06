//
//  main.cpp
//  数据结构_链表中倒数第k个节点
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
    
}ListNode, *List;

//创建链表
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
        p =q;
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

//获取倒数第K个数
int getLastK(List head,int k)
{
    ListNode *p,*q;
    p=q=head->next;
    
    int t = 0;
    
    while (p && q)
    {
        while (t<k)
        {
            p = p->next;
            t++;
        }
        
        p = p->next;
        q = q->next;
    }
    
    return q->data;
}


int main(int argc, const char * argv[]) {
    
    /*
     思想1:遍历链表得到长度，然后重新开始遍历，到n-k+1就是第K个节点了。
     思想2:遍历链表将值压入栈，然后弹出，弹出的第K个就是了。
     思想3:设两个指针，一个先走k-1步，一个停在原地。然后一起走，当前面那个走到最后了，后面那个就在倒数第7个上了。
     */
    
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = -1;
    head->next = NULL;
    
    CreateList(head);
    PrintList(head);
    
    cout<<"获取倒数第三个值:"<<getLastK(head,3);
    
    return 0;
}
