#include<stdio.h>
int main()
{
	int x,y,temp1=0,temp2=0,sum=0;
	scanf("%d%d",&x,&y);
	temp1=x+y-4;
	temp2=x+2;
	if(x<y)
	{
		if(temp1>temp2)
		{
			sum=11*x+3*temp2;
			printf("%d",sum);
		}
		else
		{
			sum=11*x+temp1*3; 
			printf("%d",sum);
		}
    }
	else
	{
			if(temp1>temp2)
		{
			sum=11*y+3*temp2;
			printf("%d",sum);
		}
		else
		{
			sum=11*y+temp1*3;
			printf(“%d”,sum);
		}
	}
	return 0;
} 