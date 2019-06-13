#include <stdio.h>
int n;
int m;
int d;
int w[100][100];
int p[100][100];
int price,weight,min;
int temp[100],best[100];
 
void dfs(int t)
{
	if(t==n)
	{
		if(price<=d && weight<min)
		{
			min=weight;
			for(int i=0;i<n;i++)
				best[i]=temp[i] ; 
		}
		return ;
	}
	
	for(int i=0;i<m;i++)
	{
		weight+=w[t][i];
		price+=p[t][i];
		temp[t]=i;
		if(price<=d && weight<min)
			dfs(t+1);
		weight-=w[t][i];
		price-=p[t][i];
		temp[t]=0;
	}
	
}
 
int main()
{
	printf("请输入数据：\n");
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	price=0;
	min=9999;
	weight=0;
	dfs(0);
	
	printf("结果为：\n");
	printf("%d\n",min);
	for(int i=0;i<n;i++)
	{
		printf("%d   ",best[i]+1);
	}
	printf("\n");
	
 
} 

