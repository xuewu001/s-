#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#define SIZE 10   
int s,n;  
int B[SIZE];  
int C[SIZE]; 
double  greedy(int A[]);  
void sort(int A[]);  
void swap(int *a,int *b);  

int main()  
{  
    int i,j,temp;  
    printf("������˿���Ŀ�ͷ���������\n");  
    scanf("%d %d",&n,&s);  
    int A[n];
    printf("������ÿ���˿͵ķ���ʱ�䣺\n");  
    for(i = 0;i < n;i++)  
    {  
        scanf("%d",&A[i]);  
    } 
    
	for(i=0;i<n;i++){  
       for(j=i+1;j<n;j++){
            if(A[i]>A[j]){
                temp=A[i];A[i]=A[j];A[j]=temp;
            }
        }
    } 
    printf("��Сƽ���ȴ�ʱ�䣺%f",greedy(A));  
    return 0;  
}  

double greedy(int A[])  
{  
    int i= 0 ,j = 0;  
    while(i < n)  
    {  
        B[j] += A[i];  
        C[j] += B[j];      
        i++;  
        j++;  
        if(j == s)          
        {  
            j = 0;  
        }  
    }  
    double t=0;
    for(i = 0;i < s;i++)  
        t += C[i];       
    return  t/n;  
}
