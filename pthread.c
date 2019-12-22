#include<stdio.h> 
#include<time.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<sys/types.h> /* need to calculate which I will implement later */ 

void *fibr(void *n); 
void *fibr_1(void *k); 
signed long long int fibonacci(signed long long int); 

int main(){ 
 
	pthread_t tid,tid1; 
	int result,result1; 
	signed long long int n=6; 
	signed long long int m=7; 

	result=pthread_create(&tid,NULL,fibr,&n); 
	if(result){ 
		perror("pthread_create"); 
		return 1; 
	} 
	result1=pthread_create(&tid1,NULL,fibr,&m); 
	if(result1){ 
		perror("pthread_create"); 
		return 1; 
	} 
	if(pthread_join(tid,NULL)){ 
		perror("pthread_join"); 
		return 1; 
	} 
	if(pthread_join(tid1,NULL)){ 
		perror("pthread_join"); 
		return 1; 
	} 
	printf("Fib value=%lld\n",n+m); 
	pthread_exit(NULL); 
} 
void *fibr(void *n){ 
	signed long long int *y=n; 
	signed long long int x=*y; 
	pthread_t tid2,tid3; 
	signed long long int i,j; 
	/* How do I assign values to i , j in order to 
	achieve the level viz fib(n-2)....fib(n-4) */ 
	if(pthread_create(&tid2,NULL,fibr_1,&i)) 
	{ 
		perror("pthread_create"); 
	} 

	if(pthread_create(&tid3,NULL,fibr_1,&j)) 
	{ 
		perror("pthread_create"); 
	} 
	if(pthread_join(tid2,NULL)) 
	{ 
		perror("pthread_join"); 
	} 

	if(pthread_join(tid3,NULL)) 
	{ 
		perror("pthread_join"); 
	} 
	/* How to return the values of i, j combined with *y . if I do *y+i+j, the result 
	is not coming correctly */ 
	*y=fibonacci(x); 
	return NULL; 
} 

void *fibr_1(void *k){ 
	long long int *a=k; 
	long long int b=*a; 
	*a=fibonacci(b); 
	return NULL; 
} 

signed long long int fibonacci(signed long long int x){ 
	if((x==0)||(x==1)) 
	return x; 
	return fibonacci(x-1)+fibonacci(x-2); 
}