#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct node{
int val;
struct node *next;
} *head;


void initialize()
{
head = malloc(sizeof(struct node));  
printf("Enter value of head\n");             //This function is used to create the head of the list
scanf("%d",&(head->val));
head->next = NULL;
}


void display()
{
	struct node *tmp = head;
	while(tmp!= NULL)        
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

void insert()
{
	if(head == NULL)
	{
	
		exit(0);     //Exit is user tries to insert nodes without inserting head first
	}
	struct node *tmp = head;
	struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
	//tmp->next = tmp2;
	while(tmp->next!=NULL)
		tmp = tmp->next;
	
	printf("Enter the value of node\n");
	scanf("%d",&(tmp2->val));
	tmp2->next = NULL;
	tmp->next = tmp2;
}

void insertAtFront()
{
	
	struct node *tmp =(struct node*)malloc(sizeof(struct node));
	printf("Enter value of new head\n");
	scanf("%d",&(tmp->val));
	tmp->next = head;
	head = tmp;	
}

void ins()  //This function inserts node at position k as specified by user
{
	int n;
	struct node *tmp = head; 
	struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
	printf("Enter position to insert\n");
	scanf("%d",&n);
	for(int i=1;i<(n-1);i++)
		{
			if(tmp->next==NULL)
				{
					printf("Position greater than list length\n");
					exit(0);
				}
			tmp = tmp->next;
		}
	printf("Enter value of node\n");
	scanf("%d",&(tmp2->val));
	tmp2->next = tmp->next;
	tmp->next = tmp2;
}
			
	

void length()
{
	int count = 1;
	struct node *tmp = head;
	
	while(tmp->next!=NULL)
		{
			count++;
			tmp = tmp->next;
		}
	
	printf("Length is %d\n",count);
}

void delete()
{
	int n;
	printf("1:Delete from begining\n2:Delete from end\n3:Delete from middle");
	scanf("%d",&n);
	if(n==1)
	{
		struct node *tmp = head;
		head = head->next;
		free(tmp);
	}
	else if(n==2)
	{
	struct node *tmp = head;
	while(tmp->next->next!=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	free(tmp->next);
	}
	else
	{
		int k;
		struct node *tmp = head;
		printf("Enter position\n");
		scanf("%d",&k);
		for(int i=1;i<k;i++)
		{
			if(tmp->next==NULL)
				{
					printf("Position greater than list length\n");
					exit(0);
				}
			tmp = tmp->next;
		}
		(tmp->val)--;
	}		
}


void main()
{	
	int choice;
	initialize();
	while(1)
	{
		printf("1:Create List\n2:Insert at front\n3:Insert at end\n4:Display\n5:Compute Length\n6:Insert at specified position\n7:Delete\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
			break;
			case 2: insertAtFront();
			break;
			case 3: insert();
			break;
			case 4: display();
			break;
			case 5: length();
			break;
			case 6: ins();
			break;
			case 7:delete();
			break;
			
			default:return;
		
		}
	}
}

