#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* Sum(void* x)
{
	int End=(int)x, sum=0;
	int start= End-100+1;
	int i=start;
	
	for(; i<=End; i++)
	{
		sum+=i;
	}
	return sum;
}


int main()
{
	pthread_t thread[10];
	int i=0, j=0, total=0;
	int *temp=NULL;
	
	for(; i<10; i++)
	{	
		int x=i+1;
		int k=x*100;
		pthread_create(&thread[i], NULL,Sum,(void*)k);
	}
		
	for(; j<10; j++)
	{
		pthread_join(thread[j],((void*)&temp));
		total+=(int)temp;
	}
	
	printf("Sum is %d",total);
	return 0;
}


