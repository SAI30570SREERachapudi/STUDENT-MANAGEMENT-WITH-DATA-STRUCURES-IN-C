#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char firstName[100];
char secondName[100];
char courseCode[100];
char grade;
struct node *next;
}*head=NULL,*ptr,*pre,*newnode;
void add();
void update();
void display();
void deletion();
int main(){
int ch;

while(1){
    
        printf("========= Student Information System ========= \n");
        printf("Enter 1 to add Student Details\n");
        printf("Enter 2 to update the details of a student\n");
        printf("Enter 3 to displaythe details of a student\n");
        printf("Enter 4 to Delete the details of a student\n");
		printf("Enter 5 to search the details of a student\n");
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
                case 5:search();
                       break;
                case 6:printf("Thank You!Please visit again");
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
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                update();
                break;
            default:
                break;
        }
    } else {
        printf("Enter 1 to update First Name of the student\n");
        printf("Enter 2 to update Second Name of the student\n");
        printf("Enter 3 to update Course Code of the student\n");
        printf("Enter 4 to update Grade of the student\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter First Name: ");
                scanf(" %[^\n]", ptr->firstName);
                printf("First Name updated successfully\n");
                break;
            case 2:
                printf("Enter Second Name: ");
                scanf(" %[^\n]", ptr->secondName);
                printf("Second Name updated successfully\n");
                break;
            case 3:
                printf("Enter Course Code: ");
                scanf(" %[^\n]", ptr->courseCode);
                printf("Course code updated successfully\n");
                break;
            case 4:
                printf("Enter Grade: ");
                scanf(" %c", &ptr->grade);
                printf("Grade updated successfully\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
void display() {
    if (head == NULL) {
          printf("No student details to display.\n");
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
void deletion(){
		printf("Enter 1 to delete by First Name of the student\n");
        printf("Enter 2 to delete by Second Name of the student\n");
        int choice;
        char keyFirstName[100];
        char keySecondName[100];
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter First Name: ");
                scanf(" %[^\n]", keyFirstName);
                if(head==NULL){
                	printf("List is empty\n");
				}
                ptr=head;
                if((strcmp(head->firstName, keyFirstName) == 0)&&ptr->next==NULL) {
                	free(ptr);
                	head=NULL;
                	printf("Deleted successfully\n");
				}
                if((strcmp(ptr->firstName, keyFirstName) == 0)) {
       				 	head=head->next;
       				 	free(ptr);
       				 	printf("Deleted Successfully \n");
   					 }
                while (ptr != NULL && (strcmp(ptr->firstName, keyFirstName) != 0)) {
       				 	pre=ptr;
						ptr = ptr->next;
   					 }
   					 if(ptr!=NULL){
   					 	pre->next=ptr->next;
   					 	free(ptr);
   					 	printf("Deleted Successfully\n");
						}
						else{
							printf("Student not found");
						}
                    break;
            case 2:
                printf("Enter Second Name: ");
                scanf(" %[^\n]", keySecondName);
                if(head==NULL){
                	printf("List is empty\n");
				}
                ptr=head;
               if((strcmp(head->secondName, keySecondName) == 0)&&ptr->next==NULL) {
                	free(ptr);
                	printf("Deleted successfully\n");
				}
                if((strcmp(head->secondName, keySecondName) == 0)) {
       				 	ptr=ptr->next;
       				 	head=ptr;
       				 	free(ptr);
       				 	printf("Deleted Successfully \n");
   					 }
                while (ptr != NULL && (strcmp(ptr->secondName, keySecondName) != 0)) {
       				 	pre=ptr;
						ptr = ptr->next;
   					 }
   					 if(ptr!=NULL){
   					 	pre->next=ptr->next;
   					 	free(ptr);
   					 	printf("Deleted Successfully\n");
						}
						else{
							printf("Student not found");
						}
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
}
void search(){
		printf("Enter 1 to search by First Name of the student\n");
        printf("Enter 2 to search by Second Name of the student\n");
        int choice;
        char keyFirstName[100];
        char keySecondName[100];
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter First Name: ");
                scanf(" %[^\n]", keyFirstName);
                if(head==NULL){
                	printf("List is empty\n");
				}
                ptr=head;
                
                if((strcmp(ptr->firstName, keyFirstName) == 0)) {
       			 	printf("First Name : %s\n", ptr->firstName);
        			printf("Second Name: %s\n", ptr->secondName);
        			printf("Course Code: %s\n", ptr->courseCode);
       			 	printf("Grade  : %c\n\n", ptr->grade);
       			 	return;
   					 }
                while (ptr != NULL && (strcmp(ptr->firstName, keyFirstName) != 0)) {
						ptr = ptr->next;
   					 }
   					 if(ptr!=NULL){
   					printf("First Name : %s\n", ptr->firstName);
        			printf("Second Name: %s\n", ptr->secondName);
        			printf("Course Code: %s\n", ptr->courseCode);
       			 	printf("Grade  : %c\n\n", ptr->grade);
						}
						else{
							printf("Student not found");
						}
                break;
            case 2:
                printf("Enter Second Name: ");
                scanf(" %[^\n]", keySecondName);
                if(head==NULL){
                	printf("List is empty\n");
				}
                ptr=head;
                if((strcmp(head->firstName, keyFirstName) == 0)&&ptr->next==NULL) {
                	printf("First Name : %s\n", ptr->firstName);
        			printf("Second Name: %s\n", ptr->secondName);
        			printf("Course Code: %s\n", ptr->courseCode);
       			 	printf("Grade  : %c\n\n", ptr->grade);
				}
                if((strcmp(head->firstName, keyFirstName) == 0)) {
       			 	printf("First Name : %s\n", ptr->firstName);
        			printf("Second Name: %s\n", ptr->secondName);
        			printf("Course Code: %s\n", ptr->courseCode);
       			 	printf("Grade  : %c\n\n", ptr->grade);
   					 }
                while (ptr != NULL && (strcmp(ptr->firstName, keyFirstName) != 0)) {
						ptr = ptr->next;
   					 }
   					 if(ptr!=NULL){
   					printf("First Name : %s\n", ptr->firstName);
        			printf("Second Name: %s\n", ptr->secondName);
        			printf("Course Code: %s\n", ptr->courseCode);
       			 	printf("Grade  : %c\n\n", ptr->grade);
						}
						else{
							printf("Student not found");
						}                break;
            default:
                printf("Invalid choice\n");
                break;
        }
}