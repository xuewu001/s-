#include <stdio.h>
int a,b;
int k,found;
int *p;
int f(int i)
{
	return 3*i;
}

int g(int i)
{
	return i/2;
}

int changed(int m,int n)
{
	int i,s;
	if(m>k)
		return 0;
	for(i=0;i<2;i++)
	{
		s=n;
		if(i==0)
			s=g(s);
		else 
			s=f(s);
			p[m]=i;
		if(s==b||changed(m+1,s))
		{
			found=1;
			return 1;
		}
	}
		return 0;
}

void compared()
{
	k=1;
	found=0;
	while(!changed(1,a))
	{
		k++;
		if(k>100)
			break;
		if(found!=0)
			break;
	}
}

int main()
{
	p=new int[100];
	int i;
	for(i=0;i<100;i++)
		p[i]=0;
		printf("����������a��b��ֵ: ");
		scanf("%d %d",&a,&b);
		compared();
	if(found)
	{
		printf("�������Ϊ: %d\n",k);
		printf("����ת������Ϊ: ");
		for(i=k;i>=1;i--)
			{
				if(p[i]==0)printf("g");
				if(p[i]==1)printf("f");
			}	
		}		
	else 
		printf("%d �޷�ת����%d ",a,b);
	printf("\n");
}

