//
//  main.cpp
//  百度_页面调度算法
//
//  Created by NetEase on 16/8/31.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int a[n][2];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<2;j++)
            {
                cin>>a[i][j];
            }
        }
        
        double waitTime = 0;
        
        for (int i=0;i<n-1;i++)
        {
            for (int j=0;j<n-1-i;j++)
            {
                if (a[j][0] > a[j+1][0])
                {
                    int temp1 = a[j][0];
                    a[j][0] = a[j+1][0];
                    a[j+1][0] = temp1;
                    
                    int temp2 = a[j][1];
                    a[j][1] = a[j+1][1];
                    a[j+1][1] = temp2;
                }
            }
        }
        
        for (int i=0;i<n-1;i++)
        {
            for (int j=0;j<n-1-i;j++)
            {
                if (a[j][0] == a[j+1][0])
                {
                    if (a[j][1] > a[j+1][1])
                    {
                        int temp = a[j][1];
                        a[j][1] = a[j+1][1];
                        a[j+1][1] = temp;
                    }
                }
            }
        }
        
        
//        for (int i=0;i<n;i++)
//        {
//            for (int j=0;j<2;j++)
//            {
//                cout<<a[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        
        int i =0;
        int tag = 0;
        
        while (i<n)
        {
            int j;
            for (j = i+1;j<n;j++)
            {
                if (a[i][0] == a[j][0])
                {
                    waitTime += a[i][1];
                }
                else
                {
                    if ((a[j][0]-a[i][0]) < a[i][1])
                    {
                        if (tag == 0)
                        {
                            waitTime += a[i][1]-(a[j][0]-a[i][0]);
                            tag = 1;
                        }
                        else
                        {
                            waitTime += a[i][1];
                            tag = 1;
                        }
                    }
                    else
                    {
                        
                    }
                }
            }
            
            i ++;
        }
        
        //cout<<waitTime<<endl;
        printf("%.4f",waitTime*1.0/n);
    }
    
    
    return 0;
}
