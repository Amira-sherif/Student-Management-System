#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
void add_in_tail(void);
int length(void);
void display();
void addafter(void);
void add_at_head(void);
void inputNodeData();
void studentsinputdata();
void students_node_data();
void printstudenteData();
int loadListFromFile();
   int n;
struct student
{   char first_name[20];
   char surname[20];
   char birthday[15];
    int score;
   int roll_no;


};

struct node
{
    struct student  data;
    struct node * next;
};
struct node *head;
int len=0;

int main()
{
    struct node *head ;
     struct node *temp,*prev;
    int i,n;
     printf ("number of elements:");
     scanf("%d",&n);
    for(i=0;i<n;i++)
    { add_in_tail();
      }


    printf("\n what do you want to do \n");
    while (1)
    {
         int choose;
        printf("\n enter 1 for adding a node at the end");
        printf("\n enter 2 for displaying the list");
        printf("\n enter 3 adding a node in middle");
        printf("\n enter 4 adding at start");
        printf("\n enter 5 Exit ");
        printf("\n Enter your choice \n");
        scanf("%d",&choose);


        switch(choose)
        {
            case 1: add_in_tail();
            break;

            case 2: display();
            break;

            case 3: addafter();
            break;

            case 4: add_at_head();
            break;

            case 5:
                exit(0);
            return 0;


        }
    }

    }

  void add_in_tail()
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        inputNodeData(temp);
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;

            }
            else
            {
                struct node *prev;
                  prev=head;
            while( prev->next != NULL)
            {
                prev = prev->next;
            }
            prev->next=temp;

            }

    }

   int length()
    {
        int count =0;
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
          count++;
          temp=temp->next;

        }
        return count;
    }
void display()
    {
        struct node * temp ;
        temp =head;
        if (temp==NULL)
        {
            printf("\n list is empty \n");
        }
        else
        {
            while(temp !=NULL)
            {
                students_node_data(&temp->data);
                temp=temp->next;

             }
            printf("\n\n");
        }
    }



void add_at_head()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    inputNodeData(temp);
    temp->next=NULL;
    if(head == NULL)
        {
            head = temp;

        }
        else
        {
            temp->next=head;
            head=temp;
        }

}
void students_node_data(struct node * d)
{
    printstudenteData( &d ->data);
}

void printstudenteData(struct student * stds)
{
    printf("\n first name:\t %s\n", stds->first_name);
    printf(" last name:\t %s\n", stds->surname);
    printf(" roll.no:\t %d\n", stds->roll_no);
    printf("\n birthday:\t %s\n", stds->birthday);
    printf("\n score:\t %d\n", stds->score);

}
void inputNodeData(struct node * d)
{
   studentsinputdata(& d->data);
}
void studentsinputdata(struct student *stds)
{
    printf("\nEnter the first name of the student: ");
    scanf("%s", &(stds->first_name));
    printf("\nEnter the last name of the student: ");
    scanf("%s", &(stds-> surname));
    printf("\nEnter the roll.no of the student: ");
    scanf("%d", &(stds->roll_no));
    printf("student date of birthday dd/mm/yyyy: ");
    scanf("%s", &(stds-> birthday));
    printf("\nEnter the score of the student: ");
    scanf("%d", &(stds->score));
    printf("\nRecord entered !\n");
}
void addafter()
{ int loc;
    struct node *temp,*prev;
    printf("\n enter the number of student from where you want to enter a node ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\n Error");
    }
    else
    {
        int i=1;
        prev = head;
        while (i<loc)
        {
            prev=prev->next;
            i++;
        }
        temp =(struct node*)malloc(sizeof(struct node));

       inputNodeData(temp);
        temp->next=NULL;
        temp->next= prev->next;
        prev->next=temp;

    }
}
