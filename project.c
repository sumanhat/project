#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define tab printf("\t\t\t\t\t")
struct list{
	char name[40];
	char email[100];
	long long int number;
	char address[50];
}s,check;
void addcontact(){
	FILE *p;
	p=fopen("contact.txt","a+");
	if(p==NULL)
	{
		tab; printf("file opening error");
	}
	tab; printf("-------------\n");
	tab; printf("NEW CONTACT\n");
	tab; printf("-------------\n");
	tab; printf("enter name:");
	fflush(stdin);
	gets(s.name);
	tab; printf("enter email:");
	fflush(stdin);
	gets(s.email);
	tab; printf("enter number:");
	fflush(stdin);
	scanf("%lld",&s.number);
	tab; printf("enter address:");
	fflush(stdin);
	gets(s.address);
	fprintf(p,"name: %s\nemail: %s\nnumber: %u\naddress: %s\n", s.name, s.email, s.number, s.address);
	fclose(p);
	tab; printf("-----------\n");
	tab; printf("SUCCESFULL.\n");
	tab; printf("-----------\n");
}
void editcontact() {
    int a, f = 0;
    FILE *p;
    FILE *n;
    p = fopen("contact.txt", "r");
    if (p == NULL) {
        tab; printf("Error opening file");
        return;
    }
    n = fopen("temp.txt", "w");
    if (n == NULL) {
        tab; printf("Error opening temporary file");
        fclose(p);
        return;
    }
    tab; printf("-------------\n");
    tab; printf("EDIT CONTACT\n");
    tab; printf("-------------\n");
    tab; printf("Enter name: ");
    fflush(stdin);
    gets(check.name);

    while (fscanf(p, "name: %[^\n]\nemail: %[^\n]\nnumber: %lld\naddress: %[^\n]\n", s.name, s.email, &s.number, s.address) != EOF) {
        if (strcmp(check.name, s.name) == 0) {
            f = 1;
            tab; printf("-------------\n");
            tab; printf("EDIT CONTACT\n");
            tab; printf("-------------\n");
            tab; printf("What do you want to edit:\n");
            tab; printf("1. Name\n");
            tab; printf("2. Email\n");
            tab; printf("3. Number\n");
            tab; printf("4. Address\n");
            tab; printf("5. Exit\n");
            tab; printf("----------------\n");
            tab; printf("Enter your choice: ");
            scanf("%d", &a);

            switch (a) {
                case 1:
                    tab; printf("Enter new name: ");
                    fflush(stdin);
                    gets(s.name);
                    break;
                case 2:
                    tab; printf("Enter new email: ");
                    fflush(stdin);
                    gets(s.email);
                    break;
                case 3:
                    tab; printf("Enter new number: ");
                    fflush(stdin);
                    scanf("%lld", &s.number);
                    break;
                case 4:
                    tab; printf("Enter new address: ");
                    fflush(stdin);
                    gets(s.address);
                    break;
                case 5:
                	exit(0);
                    break;
                default:
                    tab; printf("Invalid choice\n");
                    break;
            }
        }
        fprintf(n, "name: %s\nemail: %s\nnumber: %u\naddress: %s\n", s.name, s.email, s.number, s.address);
    }

    fclose(p);
    fclose(n);

    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if (f == 0) {
        tab; printf("Contact not found\n\n");
    } else {
        tab; printf("CONTACT EDITED SUCCESSFULLY.\n\n");
    }
}
void searchcontact(){
	int f=0;
	FILE *p;
	p=fopen("contact.txt","r");
	if(p==NULL)
	{
		tab; printf("file opening error");
	}
	tab; printf("-----------\n");
	tab; printf("SEARCH CONTACT\n");
	tab; printf("-----------\n");
	tab; printf("Enter name: ");
    fflush(stdin);
    gets(check.name);
    while(fscanf(p, "name: %[^\n]\nemail: %[^\n]\nnumber: %lld\naddress: %[^\n]\n", s.name, s.email, &s.number, s.address)!= EOF) {
        if (strcmp(check.name,s.name) == 0) {
        	f=1;
        	tab; printf("---------------\n");
        	tab; printf("Name:%s\n",s.name);
        	tab; printf("email:%s\n",s.email);
        	tab; printf("Number:%lld\n",s.number);
        	tab; printf("Address:%s\n",s.address);
        	tab; printf("----------------\n");
        	break;
        }
    }
    fclose(p);
        if(f==0)
        {
        	printf("contact not found");
		}
}
void listcontact(){
		int f=0;
		FILE *p;
	p=fopen("contact.txt","r");
	if(p==NULL)
	{
		tab; printf("file opening error");
	}
	tab; printf("-----------\n");
	tab; printf("SEARCH CONTACT\n");
	tab; printf("-----------\n");
    tab; printf("%-20s %-30s %-15s %s\n", "NAME", "EMAIL", "NUMBER", "ADDRESS");
    while (fscanf(p, "name: %[^\n]\nemail: %[^\n]\nnumber: %lld\naddress: %[^\n]\n", s.name, s.email, &s.number, s.address)!= EOF) {
       
    tab; printf("%-20s %-30s %-15u %s\n", s.name, s.email, s.number, s.address);
        	
    }
        fclose(p);
        
}
void deletecontact() {
    int f = 0;
    FILE *p;
    FILE *n;
    p = fopen("contact.txt", "r");
    if (p == NULL) {
        tab; printf("Error opening file\n");
        return;
    }
    n = fopen("temp.txt", "w");
    if (n == NULL) {
        tab; printf("Error opening temporary file\n");
        fclose(p);
        return;
    }
    tab; printf("-------------\n");
    tab; printf("DELETE CONTACT\n");
    tab; printf("-------------\n");
    tab; printf("Enter name: ");
    fflush(stdin);
    gets(check.name);

    while (fscanf(p, "name: %[^\n]\nemail: %[^\n]\nnumber: %lld\naddress: %[^\n]\n", s.name, s.email, &s.number, s.address) != EOF) {
        if (strcmp(check.name, s.name) != 0) {
            fprintf(n, "name: %s\nemail: %s\nnumber: %lld\naddress: %s\n", s.name, s.email, s.number, s.address);
        } else {
            f = 1;
        }
    }

    fclose(p);
    fclose(n);

    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if (f == 0) {
        tab; printf("Contact not found\n\n");
    } else {
        tab; printf("CONTACT DELETED SUCCESSFULLY.\n\n");
    }
}





	

int main()
{
	int a;
	
	
	while(1){
		su:
	tab; printf("-----------\n");
	tab; printf("MAIN MENU\n");
	tab; printf("-----------\n");
	tab; printf("1.Create new contact.\n");
	tab; printf("2.Edit contact.\n");
	tab; printf("3.Search contact.\n");
	tab; printf("4.List contact.\n");
	tab; printf("5.Delete contact.\n");
	tab; printf("6. Exit.\n");
	tab; printf("----------------\n");
	tab; printf("enter your choice:");
	     scanf("%d",&a);
	switch(a)
	{
		case 1:
			addcontact();
		 break;
		case 2:
			editcontact();
		break;
		case 3:
			searchcontact();
		break;
		case 4:
			listcontact();
		break;
		case 5:
			deletecontact();
		break;
		case 6:
			tab; printf("THANK YOU VISIT AGAIN");
			exit(0);
		break;
		default:
			tab; printf("invalid entry\n");
			goto su;
		break;
	}
 }
}
