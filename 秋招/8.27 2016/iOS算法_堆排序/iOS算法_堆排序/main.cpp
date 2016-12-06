//
//  main.cpp
//  iOS算法_堆排序
//
//  Created by NetEase on 16/8/29.
//  Copyright © 2016年 NetEase. All rights reserved.
//
/*
 1.堆:堆实际上是一棵完全二叉树，以大顶堆为例：任何一非叶子节点的值大于其左右孩子节点的值。
 2.堆排序:
    1）基本操作:
      (1)创建堆(创建堆的过程也是堆调整的过程，从size/2向下取整的位置开始)
      (2)堆调整
    2）创建完初始堆后进行堆排序：
       (1)将堆顶元素与最后一个元素交换，得到新的无序区R[0...n-2],和新的有序区R[n-1];
       (2)由于交换之后新的堆顶可能违反堆的性质，所以需要进行堆调整。
 
 3.堆插入:每次插入都是先将新数据放到数组的最后，然后堆调整。
 4.堆删除:堆中每次都只能删除堆顶元素。为了便于重建堆，实际操作是将最后一个数据的值赋给根节点然后
       从根节点开始从上向下调整。
 */
#include <iostream>
#include <algorithm>
using namespace std;

//建立堆
void HeapBuild(int a[],int size);
//调整堆
void HeapAdjust(int a[],int i,int size);
//堆排序
void HeapSort(int a[],int size);
//堆插入
//void HeapInsert();
//堆删除
void HeapDelete(int a[],int size);

int main(int argc, const char * argv[]) {
    
    //此处以大顶堆为例，得到的是递增序列
    
    //int a[] = {16,7,3,20,17,8,98,57,87,25};
    int a[] = {16,7,3,20,17,8};
    //HeapBuild(a, 6);//建堆
    HeapSort(a, 6);//堆排序
//    cout<<"建完堆后:";
    for (int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    
//    cout<<"删除堆顶元素";
//    HeapDelete(a, 6);
//    for (int i=0;i<5;i++)
//    {
//        cout<<a[i]<<" ";
//    }
    return 0;
}

void HeapAdjust(int a[],int i,int size)
{
    int lChild = 2*i;//i的左孩子节点序号
    int rChild = 2*i+1;//i的右节点序号
    int max = i;//临时变量
    
    if (i<=size/2)//(从最后一个非叶子节点开始调整,叶子节点不需要进行调整了)
    {
        if (lChild <= size && a[lChild-1] > a[max-1])
        {
            max = lChild;
        }
        if (rChild <= size && a[rChild-1] > a[max-1])
        {
            max = rChild;
        }
        
        if (max != i)
        {
            swap(a[i-1], a[max-1]);
            HeapAdjust(a, max, size);//避免调整之后以max为节点的子树不满足堆的性质
        }
    }
}

void HeapBuild(int a[],int size)
{
    for (int i=size/2;i>=1;i--)//非叶子节点的最大序号值是size/2(向下取整)
    {
        HeapAdjust(a, i, size);
    }
}

void HeapSort(int a[],int size)
{
    HeapBuild(a, size);//先创建初始堆(创建堆的过程也是堆调整的过程)
    for (int i=size;i>=1;i--)
    {
        swap(a[0], a[i-1]);//交换堆顶和最后一个元素,即每次将剩余元素中的堆顶(最大值)防到最后面。
        HeapAdjust(a, 1, i-1);//重新调整堆节点成为大顶堆
    }
}

void HeapDelete(int a[],int size)
{
    a[0] = a[size-1];
    HeapAdjust(a, 1, size-1);
}