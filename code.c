#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char firstName[100];
char secondName[100]
char courseCode[100];
char grade[10];
struct node *next;
}*head=NULL,*ptr,*newnode;
int main(){ 
int ch;
while(1){
	printf("========= Student Information System ========= \n");
	printf("Enter 1 to add Student Details\n);
	printf("Enter 2 to Search the details of a student\n");
	printf("Enter 3 to Update the details of a student\n");
	printf("Enter 4 to Delete the details of a student\n");
	printf("Enter 5 to exit\n");
	printf("Enter Your Choice");
	scanf("%d",&ch);
	switch(ch){
		case 1:void add();
		       break;
		case 2:void update();
		       break;
		case 3:void update();
		       break;
		case 4:void delete();
		       break;
		case 5:printf("Thank You!Please visit again");
		       exit(1);
		       break;
		default:printf("Invalid Choice");
	}
}
}
void add(){
	void add() {
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter First Name: ");
    scanf("%s", newnode->firstName);
    
    printf("Enter Second Name: ");
    scanf("%s", newnode->secondName);
    
    printf("Enter Course Code: ");
    scanf("%s", newnode->courseCode);
    
    printf("Enter Grade:(first ,second....10th grade) ");
    scanf("%s", &newnode->grade); 
    
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    
    printf("Student details added \n");
}

}
