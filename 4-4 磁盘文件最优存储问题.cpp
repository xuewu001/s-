#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int   A[SIZE];
int   B[SIZE];
void  sort(int A[],int n);
float greedy(int  A[],int n);
 
int main()
{
    int i ,n;
    printf("请输入文件个数：\n");
    scanf("%d",&n);
    printf("请输入检索概率\n");
    for(i = 0;i < n;i++){
        scanf("%d",&A[i]);
    }
 
    printf("最小期望检索时间为：%f",greedy(A,n));
    return 0;
}

void sort(int A[],int n)
{
    int i,j,temp;
    for(i = 0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

float greedy(int A[],int n)
{
    double sum = 0,t = 0;
 
    int i,j,k = (n-1)/2;
    B[k] = A[n-1];               
    sort(A,n);
    for(i = k+1;i < n;i++)
    {
        B[i] = A[n-2*(i-k)];    
    }
    for(i = k-1;i >= 0;i--)
    {
        B[i] = A[n-2*(k-i)-1];   
    }
    for (i = 0;i < n;i++)
    {
        sum += A[i];
        for(j = i+1; j < n;j++)
            t += B[i]*B[j]*(j-i);
    }
    return t/sum/sum;         
}
