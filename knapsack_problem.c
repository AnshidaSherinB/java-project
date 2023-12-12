//write pgm to implement dynamic programming algorithn for the 0/1 knapsack problem

#include<stdio.h>

#define MAX_ITEMS  100
#define MAX_CAPACITY 100
int max(int a,int b)
{
	return(a>b)?a:b;
}
	int knapsack(int values[],int weights[],int n,int capacity)
	{
		int dp[MAX_ITEMS+1][MAX_CAPACITY+1];
		int i,j;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<=capacity;j++)
			{ 
				if(i==0||j==0)
				{
					dp[i][j]=0;
				}
				else if (weights[i-1]<=j )
				{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
				}else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		    	int result=dp[n][capacity];
				int remaining_capacity=capacity;
				
				printf("selected items: ");
				
				for(i=n;i>0 && result>0;i--)
				{
					if(result !=dp[i-1][remaining_capacity])
					{
						printf("item %d ",i);
						result-=values[i-1];
						remaining_capacity -=weights[i-1];
						
					}
				}     
			
			printf("\n");
			
			return dp[n][capacity];
}
int main(){
	int n;
	int capacity;
	int i;
	printf("enter the number of items: ");
	scanf("%d",&n);
			
	int values[MAX_ITEMS],weights[MAX_ITEMS];  
	
	printf("enter the values and weights of the items:\n");
	for(i=0;i<n;i++)
	{
	     	printf("enter values %d  :",i+1);
	     	scanf("%d",&values[i]);
			printf("enter weight %d :  ",i+1);
			scanf("%d",&weights[i]);
		}
		
		printf("enter the knapsack capacity: ");
        scanf("%d",&capacity);
        
        int max_value=knapsack(values,weights,n,capacity);
        
        printf("maximum value : %d\n", max_value);
        return 0;
	}
	


