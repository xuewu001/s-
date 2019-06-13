#include<stdio.h>
int n;  
 
int main(){
	printf("请输入数据:\n");
    scanf("%d",&n); 
    int **r=new int*[n+1];    
    for(int i=0;i<n+1;i++){
        r[i]=new int[n+1];
    }
    
    for(int i=1;i<n+1;i++){  
        for(int j=i+1;j<n+1;j++)
            scanf("%d",&r[i][j]);
    }
    for(int i=1;i<n+1;i++)  
        r[i][i]=0;
    
    for(int l=2;l<=n;l++){  
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            for(int k=i+1;k<j;k++){
                int temp=r[i][k]+r[k][j];
                if(temp<r[i][j])
                    r[i][j]=temp; 
            }   
        }
    }
	printf("结果为：\n");
   printf("%d",r[1][n]);
    return 0;
}

