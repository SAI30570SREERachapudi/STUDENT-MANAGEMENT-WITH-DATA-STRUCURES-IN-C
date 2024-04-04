#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char firstName[100];
char secondName[100];
char courseCode[100];
char grade;
struct node *next;
}*head=NULL,*ptr,*newnode;
void add();
void update();
void display();

int main(){
int ch;
while(1){
        printf("========= Student Information System ========= \n");
        printf("Enter 1 to add Student Details\n");
        printf("Enter 2 to update the details of a student\n");
        printf("Enter 3 to diaplaythe details of a student\n");
        printf("Enter 4 to Delete the details of a student\n");
        printf("Enter 5 to exit\n");
        printf("Enter Your Choice");
        scanf("%d",&ch);
        switch(ch){
                case 1:add();
                       break;
                case 2:update();
                       break;
                case 3:display();
                       break;
                case 4://delete();
                       break;
                case 5:printf("Thank You!Please visit again");
                       exit(1);
                       break;
                default:printf("Invalid Choice");
        }
}
}

 void add() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter First Name: ");
      fflush(stdin);
    scanf("%[^\n]s",newnode->firstName);
    fflush(stdin);
    printf("Enter Second Name: ");
    scanf("%[^\n]s", newnode->secondName);
      fflush(stdin);
    printf("Enter Course Code: ");
    scanf("%[^\n]s", newnode->courseCode);
      fflush(stdin);
    printf("Enter Grade:");
    scanf("%c",&newnode->grade);
          fflush(stdin);
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next=NULL;
    }
    printf("Student details added successfully\n");
}

void update(){
printf("Enter First Name of the Student to update the details\n");
char keyFirstName[100];
char keySecondName[100];
scanf("%[^\n]s",keyFirstName);
printf("Enter Second name of the Student to update the datails\n");
scanf("%[^\n]s",keySecondName);
ptr=head;
while(ptr!->NULL&&strcpm(ptr->secondName,keySecondName)&&strcmp(ptr->firstName,keyFirstName)
                {
                ptr=ptr->next;
                }
        if(ptr==NULL){
                printf("There is no such student with the name %s %s",keyFirstName,keySecondName);
                printf("Enter 1 to search again");
                int ch;
                scanf("%d",&ch);
                update();
        }
}
void display() {
    if (head == NULL) {
          printf("No    student   details to display.\n");
            return;
    }
    printf("Student Details are\n");
    ptr = head;
    int i = 1;
    while (ptr != NULL) {
        printf("Student %d:\n", i);
        printf("First Name : %s\n", ptr->firstName);
        printf("Second Name: %s\n", ptr->secondName);
        printf("Course Code: %s\n", ptr->courseCode);
        printf("Grade  : %c\n\n", ptr->grade);
        ptr = ptr->next;
        i++;
    }
}
