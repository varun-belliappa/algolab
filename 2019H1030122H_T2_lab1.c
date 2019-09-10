#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


struct node{
int val;
struct node *next;
} *head;

void createlist(int m)
{
	head = (struct node*)malloc(sizeof(struct node));     //Allocate space for the head node	
	struct node *tmp = head;
	head->next = NULL;
	printf("Enter the value of head\n");
	scanf("%d",&(head->val));
	for(int i=0;i<m-1;i++)                                    //Allocate space to remaining n-1 nodes and assign their next pionters correctly
	{
		struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	tmp->next = NULL;     //The last node points to NULL
} 


void elementk(int m)                   //This function finds the kth node from the last
{
	struct node *firstPointer = head; 
	struct node *endPointer = head;
	for(int i = 1;i<m;i++)
	{
		endPointer = endPointer->next; //endpointer points to a node that is k places away from the head
	}
	while(endPointer->next!=NULL)   //We traverse endpointer until it reaches the last node
	{
		endPointer = endPointer->next;  //For each endpointer traversal, traverse the frontpointer by one node
		firstPointer = firstPointer->next;
	}
	printf("%dth node from last is %d\n",m,firstPointer->val);
	}
	

void main()
{
	int n,i,k;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	createlist(n);
	printf("enter the remaining values\n");   //Enter the values of the nodes
	struct node *tmp = head->next;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&(tmp->val));
		tmp = tmp->next;
	}
	printf("list is\n");
	tmp = head;
	
	while(tmp!=NULL)
		{
			printf("%d->",tmp->val);
			tmp = tmp->next;
		}
	printf("\n Enter the required 'n'\n");
	scanf("%d",&k);
	elementk(k);	
}
