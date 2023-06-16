#include <stdio.h>
#include <stdlib.h>
//define structure and its data
struct student {
    char first_name[50];
    char second_name[50]
    int std_ID;
    int day ,month, year;
    int score;
 } s;

int main() {
    int operation=0;
    printf("===================================\n");
    printf("   WELCOME TO OUR UNIVERSITY     \n");
    printf("===================================\n");
    printf("\n");
    printf("please choose one of these operations:\n");
    printf("   (1) enter a new student\n");
    printf("   (2) show the current database\n");
    printf("   (3) exit\n");
    scanf("%d",&operation);
     switch(operation){
            case 1:
    printf("Enter information:\n");
    printf("Enter your first_name: ");
    fgets(s.first_name, sizeof(s.first_name),stdin);
    printf("Enter your second_name: ");
    fgets(s.second_name, sizeof(s.second_name),stdin);
    printf("Enter student_ID number: ");
    scanf("%d", &s.std_ID);
    printf("Enter date of birth in this format (dd/mm/yyyy) : ");
    scanf("%d/%d/%d",&s.day,&s.month,&s.year);
    printf("Enter student score of the last year: ");
    scanf("%d", &s.score);
    case 2:
    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s.name);
    printf("student date of birth: ");
    printf("%02d/%02d/%04d\n ",s.day,s.month,s.year);
    printf("student_ID: %d\n", s.std_ID);
    printf("score of the last year: %.1d\n", s.score);
    case 3:
                puts("exit");
                exit(0);
        }

    return 0;
}
