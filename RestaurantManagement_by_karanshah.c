

#include<stdio.h>
#include<stdlib.h>

/* the code is written & executed by karan shah */

struct Node
{
   int data;
   struct Node *next;
}*head = NULL;

void place();
void view();
void cancel();
void display();

int main()
{
printf("Welcome to Karan Restaurant!\n");
int i = 0;int a;
while(i == 0)
{
    printf("\nEnter 1 to place order.");
    printf("\nEnter 2 to view bill.");
    printf("\nEnter 3 to cancel the last order.");
    printf("\nEnter 4 to exit.\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:place();
        break;
        case 2:view();
        break;
        case 3:cancel();
        break;
        case 4:
        printf("\nHope to see you again!");
        i = 1;
        break;
        default :
        printf("\nPlease select a valid choice!");
    }
}
return 0;

}

void place()
{  
    int c,b,p,value;
    display();
    printf("\nEnter the food code : ");
    scanf("%d",&c);
    if(c==1) b=150;
    else if(c == 2) b=250;
    else if(c == 3) b=350;
    else if(c == 4) b=75;
    printf("\nEnter the number of pieces you would like to order: ");
    scanf("%d",&p);
    value = b*p;
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void cancel()
{
    if(head == NULL)
	printf("\n\nNo orders were placed!!!\n\n");
    else
    {
        struct Node *temp = head;
        if(head->next == NULL)
        {
	        head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
            printf("\nLast order cancelled!\n\n");
        }
   }
}

void view()
{
   if(head == NULL)
   {
        printf("\nNo Payment pending\n");
   }
   else
   {
        struct Node *temp = head;
        printf("\n\nPayment pending - \n");
        while(temp->next != NULL)
        {
        	 printf("%d + ",temp->data);
        	 temp = temp->next;
        }
        printf("%d\n\n",temp->data);
   }
}

void display()
{
    printf("\n\nFood Code\t\tAvailable Food items\t\tCost\n");
    printf("1.\t\t\tPav Bhaaji \t\t\t 150\n");
    printf("2.\t\t\tPizza \t\t\t\t 250\n");
    printf("3.\t\t\tPasta \t\t\t\t 350\n");
    printf("4.\t\t\tDosa \t\t\t\t 75\n");
}