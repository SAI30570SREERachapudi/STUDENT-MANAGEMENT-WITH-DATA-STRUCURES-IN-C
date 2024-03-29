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
		case 1:add();
		       break;
		case 2:update();
		       break;
		case 3:update();
		       break;
		case 4:delete();
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
    scanf("%[^\n]s",newnode->firstName);
    
    printf("Enter Second Name: ");
    scanf("%[^\n]s", newnode->secondName);
    
    printf("Enter Course Code: ");
    scanf("%[^\n]s", newnode->courseCode);
    
    printf("Enter Grade:");
    scanf("%c",&newnode->grade); 
 	
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
    }
    
    printf("Student details added successfully\n");
}

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
		//To enable the user to give input again and again to search
		update();		
	}

}
