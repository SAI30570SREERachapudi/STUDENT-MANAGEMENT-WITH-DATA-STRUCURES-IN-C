#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
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
		case 4:deletion();
		       break;
		case 5:printf("Thank You!Please visit again");
		       exit(1)
		default:printf("Invalid Choice");
	}
}
}

 void add() {
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter First Name: ");
    scanf(" %[^\n]", newnode->firstName);

    printf("Enter Second Name: ");
    scanf(" %[^\n]", newnode->secondName);

    printf("Enter Course Code: ");
    scanf(" %[^\n]", newnode->courseCode);

    printf("Enter Grade: ");
    scanf(" %s", newnode->grade);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

    printf("Student details added successfully\n");
}

void update() {
    printf("Enter First Name of the Student to update the details: ");
    char keyFirstName[100];
    char keySecondName[100];
    scanf(" %[^\n]", keyFirstName);
    printf("Enter Second name of the Student to update the details: ");
    scanf(" %[^\n]", keySecondName);
    ptr = head;
    while (ptr != NULL && (strcmp(ptr->secondName, keySecondName) != 0 || strcmp(ptr->firstName, keyFirstName) != 0)) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("There is no such student with the name %s %s\n", keyFirstName, keySecondName);
        printf("Enter 1 to search again\n");
        printf("Enter any other number to exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
        	case 1: update();
        	break;
        	default:break;
		}
    }
    else {
    	printf("Enter 1 to update First Name of the student\n");
    	printf("Enter 2 to update Second Name of the student\n");
    	printf("Enter 3 to update Course Code of the student\n");
    	printf("Enter 4 to update Grade of the student\n");
    	int ch;
    	printf("Enter your choice");
    	scanf("%d",&ch);
    	switch(ch){
    		case 1:printf("Enter First Name :")
    		gets(ptr->firstName);
    		printf("First Name updated successfully\n");
    		break;
    		case 2:printf("Enter Second Name :")
    		gets(ptr->secondName);
    		printf("Second Name updated successfully\n");
    		break;
    		case 3:printf("Enter Course Code :")
    		gets(ptr->courseCode);
    		printf("Course code updated successfully\n");
    		break;
    		case 4:printf("Enter Grade :")
    		getc(ptr->grade);
    		printf("Grade updated successfully\n");
    		break;
		}
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
        printf("Details of Student %d:\n", i);
        printf("First Name : %s\n", ptr->firstName);
        printf("Second Name: %s\n", ptr->secondName);
        printf("Course Code: %s\n", ptr->courseCode);
        printf("Grade  : %c\n\n", ptr->grade);
        ptr = ptr->next;
}
}
