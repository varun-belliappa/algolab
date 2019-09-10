#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


struct node{
int val;
struct node *next;
} *head;

void createlist(int m)
{
	head = (struct node*)malloc(sizeof(struct node));
	struct node *tmp = head;
	head->next = NULL;
	printf("Enter the value of head\n");
	scanf("%d",&(head->val));
	for(int i=0;i<m-1;i++)
	{
		struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	tmp->next = NULL;
} 


void reverseList()
{
	struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;
		prevNode->next = NULL;

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;

        
    }
    struct node *tmp = head;
	
	while(tmp!=NULL)
		{
			printf("%d->",tmp->val);
			tmp = tmp->next;
		}
	printf("\n");
	
    
}
	
	
	


void main()
{
	int n,i;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	createlist(n);
	printf("enter the remaining values\n");
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
	printf("\n");
	reverseList();
}
