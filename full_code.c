#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void add_in_tail(void);
int length(void);
void display_linkedlist();
void addafter(void);
void add_at_head(void);
void inputNodeData();
void studentsinputdata();
void students_node_data();
void printstudenteData();
int loadListFromFile();
void insert_node ();
void calc_time_linkedlist();
   int n;
struct student
{   char first_name[20];
   char surname[20];
   char birthday[15];
    int score;
   int roll_no;
}*p;
struct student *s;
struct node
{
    struct student  data;
    struct node * next;
};
struct node *head;
int len=0;
 void insert_at_pos();
 void insert ();
 void calc_time_array();
void display_array();
 void insert_info(struct student *s);
struct student *ptr;
int i,array_size;
int no_stud;

int main()
{
printf("===================================\n");
        printf("   WELCOME TO OUR UNIVERSITY     \n");
        printf("===================================\n");
        printf("\n");
    struct node *head ;
     struct node *temp,*prev;
    int i,n;
     printf ("number of elements in linked list:");
     scanf("%d",&n);
    for(i=0;i<n;i++)
    { add_in_tail();
      }
        printf("Enter the beginning size of array : ");
        scanf("%d",&array_size);
        printf("Enter the number of students  : ");
        scanf("%d",&no_stud);
        p=(struct student*)malloc(array_size*sizeof(struct student));
        for(i=0;i<no_stud;i++){
        insert();}
    while (1)
    {   printf("\n what do you want to do \n");
        int choose;
        printf("\n enter 1 for inserting a student at wanted position in linked list");
        printf("\n enter 2 for displaying the linked list ");
        printf("\n enter 3 to calculate time taken to inset a student in linked list");
        printf("\n enter 4 for inserting a student at wanted position in array");
        printf("\n enter 5 for displaying the array");
         printf("\n enter 6 to calculate size of structure in the memory");
          printf("\n enter 7 to calculate size of node in the memory");
        printf("\n enter 8 to calculate time taken to inset a student in array");
        printf("\n enter 9 Exit ");
        printf("\n Enter your choice \n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1: insert_node();
            break;

            case 2: display_linkedlist();
            break;

            case 3: calc_time_linkedlist();
            break;
            case 4: insert_at_pos();
            break;

            case 5: display_array();
            break;
            
            case 6:printf("%d size of struct is :", sizeof(struct student));
            break;
            
            case 7: printf("%d size of struct is :", sizeof(struct node));
            break;
            
            case 8: calc_time_array();
            break;
            
            case 9:
                exit(0);
            return 0;
        }
    }

    }


 void insert(){

    printf("\nFor student number %d",(i+1) );
    printf("\nEnter the first name of the student : " );
    scanf("%s",&(p+i)->first_name);
    printf("\nEnter the last name of the student : " );
    scanf("%s",&(p+i)->surname);
    printf("\nEnter date of birth in this format (dd/mm/yyyy)  : ");
    scanf("%s",&(p+i)->birthday);
    printf("\nEnter the student ID : ");
    scanf("%d",&(p+i)->roll_no);
    printf("\nEnter the student score : ");
    scanf("%d",&(p+i)->score);
      }
void insert_info(struct student *s){
    printf("\nEnter the first name of the student : " );
    scanf("%s",&s->first_name);
    printf("\nEnter the last name of the student : " );
    scanf("%s",&s->surname);
    printf("\nEnter date of birth in this format (dd/mm/yyyy)  : ");
    scanf("%s",&s->birthday);
    printf("\nEnter the student ID : ");
    scanf("%d",&s->roll_no);
    printf("\nEnter the student score : ");
    scanf("%d",&s->score);
}

void insert_at_pos(){
    //check if array is  full
    if (no_stud==array_size)
    array_size++;
    p = (struct student *)realloc(p, array_size * sizeof(struct student));
    int choose;
    printf("\nenter 1 insert a student at start\nenter 2 insert a student at middle\nenter 3 insert a student at end");
    printf("\n Enter your choice \n");
    scanf("%d",&choose);
    switch(choose){
        case 1:
         for (int i = no_stud; i > 0; i--)
        { // this loop to shift array to the right
            *(p + i) = *(p + i - 1);
        } // insert data at the beginning
        insert_info(p);
        no_stud++;
        break;
        case 2:
        {
        int pos;
        printf("\nEnter position you want to insert at");
        scanf("%d", &pos);
        for (int i = no_stud; i >= pos; i--)
        { //  this loop to shift array to the right
            *(p + i) = *(p + i - 1);
        }
          // insert student at wanted position
        ptr=p + pos ;
        insert_info(ptr);
        no_stud++;
        break;
    }
    case 3:
        *(p + no_stud) = *(p + no_stud - 1);
        ptr=p + no_stud ;
        insert_info(ptr);
        no_stud++;
    }
}
void display_array(){
    for (i=0;i<no_stud;i++){
    printf("\n first name:\t %s\n", (p+i)->first_name);
    printf(" last name:\t %s\n",(p+i)->surname);
    printf(" roll.no:\t %d\n", (p+i)->roll_no);
    printf(" birthday:\t %s\n",(p+i)->birthday);
    printf(" score:\t %d\n", (p+i)->score);
    }
}
void calc_time_array() {
     clock_t start = clock();
   insert_at_pos();
     clock_t stop = clock();
    double elapsed = (double)(stop -  start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);}




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
void display_linkedlist()
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
    printf("\nstudent date of birthday dd/mm/yyyy: ");
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
void insert_node (){
    int pos;
        printf("\n enter 1 insert a student at start\nenter 2 insert a student at middle\nenter 3 insert a student at end");
        printf("\n Enter your choice \n");
        scanf("%d",&pos);
       switch(pos)
        {
            case 1: add_at_head();
            break;

            case 2: addafter();
            break;

            case 3: add_in_tail();
            break;

        }
    }
    void calc_time_linkedlist() {
     clock_t start = clock();
    insert_node();
     clock_t stop = clock();
    double elapsed = (double)(stop -  start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);}