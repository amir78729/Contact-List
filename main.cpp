#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <time.h>
#include <windows.h> 
#include <dos.h>
/*
FINAL PROJECT
AMIRHOSSEIN ALIBAKHSHI
ID: 9731096
CE@AUT
1397 - 2018
*/
HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

typedef struct contact {//defining CONTACT
	int number;
	char firstName[15];
	char lastName[15];
	char id[7]; // ex : 9731096
	char age[3];
	char gender; // 0 = male / 1 = female
	char field;
	char phoneNumber[20];// ex : 09129334535
	char address[100];
	struct contact *next; //next is used to navigate through structures.
	int count;
} contact;

FILE *datafile;
contact *firstc, *currentc, *newc; // 3 pointers to make a LINKED LIST
int cnum = 0;// ***not useable in final version***

void showOwnerInfo(){
	puts("___________________________________");
	puts("|                                 |");
	puts("|          CONTACT LIST           |");

	puts("|              -----              |");
	puts("|     Amirhossein  Alibakhshi     |");
	puts("|              -----              |");
	puts("| AmirkabirUniversityOfTechnology |");
	puts("|    ( Tehran  PolyTechnique )    |");
	puts("|              -----              |");
	puts("|      github.com/amir78729       |");
	puts("|_________________________________|\n");
}

void correct_contact_number(){
	currentc = firstc;
	int i=1;
	while(1){
		if(currentc){
			currentc->number=i;
			currentc = currentc->next;
			//cnum++;
			i++;
		}else{
			break;
		}
	}
	
}

void show(struct contact *currentc){//show a contact
				
	printf("--FIRST-NAME--:\t%s\n", currentc->firstName);      		
	printf("---LASTNAME---:\t%s\n", currentc->lastName);			
	printf("------ID------:\t%.7s\n", currentc->id);	
	printf("------AGE-----:\t%s\n", currentc->age);
	printf("----GENDER----:\t");
	
	switch (currentc->gender) {
		case '0':
			puts("male");
			break;
		case '1':
			puts("female");
			break;
		default:
			puts("-");
			break;
	}
	printf("-----FIELD----:\t");
	switch (currentc->field) {
		case '1':
			puts("ComputerEngineering");
			break;
		case '2':
			puts("ComputerScience");
			break;
		case '3':
			puts("ElectricalEngineering");
			break;
		case '4':
			puts("MechanicalEngineering");
			break;
		case '5':
			puts("ChemicalEngineering");
			break;
		case '6':
			puts("AeroSpaceEngineering");
			break;
		default:
			puts("???");
			break;
	}
	printf("-PHONE-NUMBER-:\t%.11s\n", currentc->phoneNumber);
	printf("----ADDRESS---:\t%s\n", currentc->address);
	puts("");
}

void find_cnum(){// to find out how many contacts do we have (when the program starts...)
	currentc = firstc;
	while(1){
		if(currentc){
			currentc = currentc->next;
			cnum++;
		}else{
			break;
		}
	}
}

void display_all_contacts(void){//display all of the contacts
	system("color 0e");
	system("cls");
	showOwnerInfo();
	puts("-----------------------------------");
	puts("-------DISPLAY ALL CONTACTS--------");
    if(firstc==NULL){
    	puts("-----------------------------------");
    	puts("___________________________________");
    	puts("|                                 |");
        puts("|     NO CONTACTS TO DISPLAY!     |");
        puts("|_________________________________|");
    }else{  
		int num = 1;         
        currentc=firstc;
        do{
        printf("----------------[%d]----------------\n\n",num++);
		show (currentc);
        }
        while((currentc=currentc->next) != NULL);
    }
    	puts("press any key to continue:)");
    getch();
}

void display_all_contacts_with_numbers(void){//display all of the contacts + number

    if(firstc==NULL){
    	puts("___________________________________");
    	puts("|                                 |");
        puts("|     NO CONTACTS TO DISPLAY!     |");
        puts("|_________________________________|");
    }else{           
		int num=1;
        currentc=firstc;
        do{
        printf("----------------[%d]----------------\n",num);
		show (currentc);
		num++;
        }while((currentc=currentc->next) != NULL);
    }

}

int go_to_contact_number_x (int x){//used in "changed" function (going to the next node X times!)(EXTRA!!!)
	currentc = firstc;
	for(int i = 0; i<x-1; i++){
		if(currentc){
			//previousa = currentc;
			currentc = currentc->next;
		}else{
			return -1;//your contacts ar less than X!
		}
	}
		return 1;

}

void add_contact(void) {//add a contact ***not useable in final version***
			system("cls");
	showOwnerInfo();
	int boool =1,isDigit=0;//to check if the input is correct or not
	newc = (struct contact *)malloc(sizeof(struct contact)); //allocate memory for our new structure(CONTACT!!!)
	if (firstc == NULL) //if this contact is our 1st contact...
		firstc = currentc = newc;
	else {
		currentc = firstc;// make the first record the current one
		while (currentc->next != NULL)// pass the previous contacts
			currentc = currentc->next;
		currentc->next = newc; //pointer to next node
		currentc = newc; //make current record the new one
	}
	//update the structure!!
	cnum++;
	puts("-----------------------------------");
	puts("-------ADD A CONTACT TO LIST-------");

	currentc->number = cnum;    //I used "cnum" to give each contact a unique number
		puts("-----------------------------------");
	printf("Enter your contact's 1st name : \n");
		getchar();
		gets(currentc->firstName);
		puts("-----------------------------------");
	printf("Enter %s's last name : \n",currentc->firstName);
	gets(currentc->lastName);
		puts("-----------------------------------");

	printf("Enter %s's student-ID : \n",currentc->firstName);
	while(boool){
        scanf("%s", currentc->id);
        int j=0;
        isDigit = 0;
        while(currentc->id[j]!='\0'){
            if(!isdigit(currentc->id[j])){
                isDigit=1;
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				puts("!!                               !!");
				puts("!!    WRONG INPUT...TRY AGAIN    !!");
				puts("!!                               !!");
				puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				printf("Enter %s's student-ID :\n(only NUMBERs are supported!!!) \n",currentc->firstName);
                break;
            }
            
            j++;
        }
    if(isDigit)
        continue;
    boool=0;
    }
	boool=1;
		puts("-----------------------------------\r");
		
	printf("How old is %s? \n",currentc->firstName);
	while(boool){
        scanf("%s", currentc->age);
        int j=0;
        isDigit = 0;
        while(currentc->age[j]!='\0'){
            if(!isdigit(currentc->age[j])){
                isDigit=1;
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				puts("!!                               !!");
				puts("!!    WRONG INPUT...TRY AGAIN    !!");
				puts("!!                               !!");
				puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				printf("Enter %s's age :\n(age is a NUMBER!!!) \n",currentc->firstName);
                break;
            }
            
            j++;
        }
    if(isDigit)
        continue;
    boool=0;
    }
	boool=1;
		
		puts("-----------------------------------\r");

	printf("Enter your contact's gender\n( 0 = male , 1 = female) : \n");
	while(boool){
		scanf( " %c",&(currentc->gender));
		if(currentc->gender != '0' && currentc->gender != '1'){
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("!!                               !!");
			puts("!!    WRONG INPUT...TRY AGAIN    !!");
			puts("!!                               !!");
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("( 0 = male , 1 = female) : ");
			continue;
		}
		boool=0;
	}
	boool=1;
		puts("-----------------------------------");

	printf("Enter %s's field :  \n",currentc->firstName);
	printf("( 1 =\t Computer Engineering\n");
	printf("  2 =\t Computer Science\n");
	printf("  3 =\t Electrical Engineering\n");
	printf("  4 =\t Mechanical Engineering\n");
	printf("  5 =\t Chemical Engineering\n");
	printf("  6 =\t AeroSpace Engineering )\n");
	while(boool){
		scanf( " %c",&(currentc->field));
		if(currentc->field != '1' && currentc->field != '2' && currentc->field != '3' && currentc->field != '4' && currentc->field != '5' && currentc->field != '6'){
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("!!                               !!");
			puts("!!    WRONG INPUT...TRY AGAIN    !!");
			puts("!!                               !!");
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("( 1 =\t Computer Engineering\n");
			printf("  2 =\t Computer Science\n");
			printf("  3 =\t Electrical Engineering\n");
			printf("  4 =\t Mechanical Engineering\n");
			printf("  5 =\t Chemical Engineering\n");
			printf("  6 =\t AeroSpace Engineering )\n");
			continue;
		}
		boool=0;
	}
	boool=1;
	puts("-----------------------------------");

	printf("Enter %s's phone number : \n",currentc->firstName);

        gets(currentc->phoneNumber);
        gets(currentc->phoneNumber);



		puts("-----------------------------------");
			
	printf("Enter %s's address : \n",currentc->firstName);
	gets(currentc->address);
	system("cls");
	showOwnerInfo();
	puts("-----------------------------------");
	show (currentc);
	puts("___________________________________");
	puts("|                                 |");
    puts("|  CONTACT ADDED SUCCESSFULLY ^_^ |");
    puts("|_________________________________|");
	currentc->count = 0;
	currentc->next = NULL;
	puts("press any key to continue:)");
	getch();
}

int search(contact x){//is the contact in the linkedlist or not?
	contact *temp ;
	temp = firstc;
	while(temp != NULL){
		if(!strcmp(temp->address , x.address) && !strcmp(temp->age , x.age) && temp->field == x.field &&   !strcmp(temp->firstName , x.firstName) && temp->gender==x.gender && !strcmp(temp->id , x.id) && !strcmp(temp->lastName , x.lastName) ){
		return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void add_contact_kiezehrman(){//add a contact
int boool =1,isDigit=0;//to check if the input is correct or not
	contact *ptr = (contact *) malloc (sizeof(contact));
				system("cls");
	showOwnerInfo();

puts("-----------------------------------");
	puts("-------ADD A CONTACT TO LIST-------");

		puts("-----------------------------------");
	printf("Enter your contact's 1st name : \n");
		getchar();
		gets(ptr->firstName);
		puts("-----------------------------------");
	printf("Enter your contact's last name : \n");
			getchar();

	gets(ptr->lastName);
		puts("-----------------------------------");

	printf("Enter your contact's student-ID : \n");
	while(boool){
        scanf("%s", ptr->id);
        int j=0;
        isDigit = 0;
        while(ptr->id[j]!='\0'){
            if(!isdigit(ptr->id[j])){
                isDigit=1;
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				puts("!!                               !!");
				puts("!!    WRONG INPUT...TRY AGAIN    !!");
				puts("!!                               !!");
				puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				printf("Enter %s's student-ID :\n(only NUMBERs are supported!!!) \n",ptr->firstName);
                break;
            }
            
            j++;
        }
    if(isDigit)
        continue;
    boool=0;
    }
	boool=1;
		puts("-----------------------------------\r");
		
	printf("How old is your contact? \n");
	while(boool){
        scanf("%s", ptr->age);
        int j=0;
        isDigit = 0;
        while(ptr->age[j]!='\0'){
            if(!isdigit(ptr->age[j])){
                isDigit=1;
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				puts("!!                               !!");
				puts("!!    WRONG INPUT...TRY AGAIN    !!");
				puts("!!                               !!");
				puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				printf("Enter age :\n(age is a NUMBER!!!) \n");
                break;
            }
            
            j++;
        }
    if(isDigit)
        continue;
    boool=0;
    }
	boool=1;
		
		puts("-----------------------------------\r");

	printf("Enter your contact's gender\n( 0 = male , 1 = female) : \n");
	while(boool){
		scanf( " %c",&(ptr->gender));
		if(ptr->gender != '0' && ptr->gender != '1'){
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("!!                               !!");
			puts("!!    WRONG INPUT...TRY AGAIN    !!");
			puts("!!                               !!");
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("( 0 = male , 1 = female) : ");
			continue;
		}
		boool=0;
	}
	boool=1;
		puts("-----------------------------------");
	printf("Enter field :  \n");

	printf("Enter %s's field :  \n",ptr->firstName);
	printf("( 1 =\t Computer Engineering\n");
	printf("  2 =\t Computer Science\n");
	printf("  3 =\t Electrical Engineering\n");
	printf("  4 =\t Mechanical Engineering\n");
	printf("  5 =\t Chemical Engineering\n");
	printf("  6 =\t AeroSpace Engineering )\n");
	while(boool){
		scanf( " %c",&(ptr->field));
		if(ptr->field != '1' && ptr->field != '2' && ptr->field != '3' && ptr->field != '4' && ptr->field != '5' && ptr->field != '6'){
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			puts("!!                               !!");
			puts("!!    WRONG INPUT...TRY AGAIN    !!");
			puts("!!                               !!");
			puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("( 1 =\t Computer Engineering\n");
			printf("  2 =\t Computer Science\n");
			printf("  3 =\t Electrical Engineering\n");
			printf("  4 =\t Mechanical Engineering\n");
			printf("  5 =\t Chemical Engineering\n");
			printf("  6 =\t AeroSpace Engineering )\n");
			continue;
		}
		boool=0;
	}
	boool=1;
	puts("-----------------------------------");
	
	printf("Enter phone number : \n");


		puts("-----------------------------------");
		
	printf("Enter address : \n",ptr->firstName);
	gets(ptr->address);
	contact *temp ;
	temp = firstc;
	if(firstc != NULL){
		if (search(*ptr)){
			system("cls");
			showOwnerInfo();
			puts("-----------------------------------");
			puts("-------ADD A CONTACT TO LIST-------");
			puts("-----------------------------------");
			puts("___________________________________");
	    	puts("|                                 |");
	        puts("|    THIS CONTACT IS AVAILABLE    |");
	        puts("|    IN YOUR CONTACT LIST.....    |");
	        puts("|    IT IS GOING TO ADD TO THE    |");
	        puts("|        END OF THE LIST:)        |");
	        puts("|_________________________________|");
			while(temp->next) temp = temp->next;
			(*temp).next = ptr;
			ptr->next = NULL;
		}else {
			int place;
			system("cls");
			showOwnerInfo();
			puts("-----------------------------------");
			puts("-------ADD A CONTACT TO LIST-------");
			puts("-----------------------------------");
			puts("___________________________________");
	    	puts("|                                 |");
	        puts("|   THIS CONTACT IS NOT IN YOUR   |");
	        puts("|   LIST...WHERE DO YOU WANT TO   |");
	        puts("|   ADD IT? ENTER THE NUMBER :)   |");
	        puts("|_________________________________|");
			display_all_contacts_with_numbers();
			scanf("%d",&place);
			if(place == 1) {
				ptr->next = temp;
				firstc = ptr;
			}else{
				for(int i = 0 ; i < place-2 && temp->next != NULL ; i++)	{
					temp = temp->next;
				}
				ptr->next = temp->next;
				(*temp).next = ptr;
				
			}
			//print();
		}
	}else{
		firstc = ptr;
		ptr->next = NULL;
	}
	puts("___________________________________");
    	puts("|                                 |");
        puts("|  CONTACT ADDED SUCCESSFULLY ^_^ |");
        puts("|_________________________________|");
        cnum++;
	Sleep(5000);
	system("cls");

}

void remove_contact_by_info(void){//the 1st option of "remove" function...
	system("cls");
	showOwnerInfo();
	puts("-----------------------------------");
	puts("-----REMOVE A CONTACT BY INFO------");
	puts("-----------------------------------");
	char record[7];
    struct contact *previousa;
    if(firstc==NULL){
    	
        puts("___________________________________");
		puts("|                                 |");
		puts("|      There are no contacts      |");
		puts("|           to delete !           |");
		puts("|_________________________________|");
			Sleep(2000);	

	return;
    }
	puts("How do you want to remove your ");
	puts("contact?");
	puts("___________________________________");
	puts("|                                 |");
	puts("| 1) .............. By First Name |");
	puts("| 2) ............... By Last Name |");
	puts("| 3) .............. By Student-ID |");
	puts("| 4) ............ By Phone Number |");
	puts("| 5) ................. By Address |");
	puts("|_________________________________|");
	puts("Now enter a number:");
    int num;
		scanf("%d",&num);
		switch(num){
			case 1://by 1st name
	            puts("Enter contact's firstname:");
	            scanf("%s",&record);
	            currentc = firstc;
	            while(currentc != NULL){
	                if(strcmp(currentc->firstName , record)==0){
		        	    if(currentc == firstc)	/*if record to be deleted is the first record*/
		        		firstc=currentc->next; /*reset firstc to point at next record as first*/
		        	    else
		        		previousa->next = currentc->next;/*previous pointer used if record*/ 
		                                                 /*to delete is not the first*/
		                free(currentc); /*frees memory <deletes>*/	
		        	    puts("___________________________________");
		            	puts("|                                 |");
		                puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
		                puts("|_________________________________|");
		                	Sleep(2000);	
			cnum--;

		        	    return;
		        	}else{
		                previousa = currentc;
		        	    currentc = currentc->next;
		        	}
	            }//while
	            break;
	        case 2://by last name
	            puts("Enter contact's lastname:");
	            scanf("%s",&record);
	            currentc = firstc;
	            while(currentc != NULL){
	                if(strcmp(currentc->lastName , record)==0){
		        	    if(currentc == firstc)	/*if record to be deleted is the first record*/
		        		firstc=currentc->next; /*reset firstc to point at next record as first*/
		        	    else
		        		previousa->next = currentc->next;/*previous pointer used if record*/ 
		                                                 /*to delete is not the first*/
		                free(currentc); /*frees memory <deletes>*/	
		        	    puts("___________________________________");
		            	puts("|                                 |");
		                puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
		                puts("|_________________________________|");
		                	Sleep(2000);	
			cnum--;

		        	    return;
		        	}else{
		                previousa = currentc;
		        	    currentc = currentc->next;
		        	}
	            }//while  
	            break;			  
	         case 3://by id
	            puts("Enter contact's student-ID:");
	            scanf("%s",&record);
	            currentc = firstc;
	            while(currentc != NULL){
	                if(strcmp(currentc->id , record)==0){
		        	    if(currentc == firstc)	/*if record to be deleted is the first record*/
		        		firstc=currentc->next; /*reset firstc to point at next record as first*/
		        	    else
		        		previousa->next = currentc->next;/*previous pointer used if record*/ 
		                                                 /*to delete is not the first*/
		                free(currentc); /*frees memory <deletes>*/	
		        	    puts("___________________________________");
		            	puts("|                                 |");
		                puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
		                puts("|_________________________________|");
		                	Sleep(2000);	
			cnum--;

		        	    return;
		        	}else{
		                previousa = currentc;
		        	    currentc = currentc->next;
		        	}
	            }//while
	            break;
			case 4://by phone

	            puts("Enter contact's phone number:");
	            scanf("%s",&record);
	            currentc = firstc;
	            while(currentc != NULL){
	        //    	printf("%s , %s\n", currentc->id, record);
	                if(strcmp(currentc->phoneNumber , record)==0){
		        	    if(currentc == firstc)	/*if record to be deleted is the first record*/
		        		firstc=currentc->next; /*reset firstc to point at next record as first*/
		        	    else
		        		previousa->next = currentc->next;/*previous pointer used if record*/ 
		                                                 /*to delete is not the first*/
		                free(currentc); /*frees memory <deletes>*/	
		        	    puts("___________________________________");
		            	puts("|                                 |");
		                puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
		                puts("|_________________________________|");
		                	Sleep(2000);	
			cnum--;

		        	    return;
		        	}else{
		                previousa = currentc;
		        	    currentc = currentc->next;
		        	}
	            }//while 
				break;
			case 5://by address
	            puts("Enter contact's address:");
	            scanf("%s",&record);
	            currentc = firstc;
	            while(currentc != NULL){
	                if(strcmp(currentc->address , record)==0){
		        	    if(currentc == firstc)	/*if record to be deleted is the first record*/
		        		firstc=currentc->next; /*reset firstc to point at next record as first*/
		        	    else
		        		previousa->next = currentc->next;
		                free(currentc); /*frees memory <deletes>*/	
		        	    puts("___________________________________");
		            	puts("|                                 |");
		                puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
		                puts("|_________________________________|");
		                Sleep(2000);	
						cnum--;
		        	    return;
		        	}else{
		                previousa = currentc;
		        	    currentc = currentc->next;
		        	}
	            }//while 
				break;
			default://when the user enter sth wrong...
				puts("___________________________________");
				puts("|                                 |");
			    puts("|oops...you entered a wrong value!|");
			    puts("|        try again later:)        |");
			    puts("|_________________________________|");
			 	Sleep(2000);	
				return;
				break;
	}			
    puts("___________________________________");
	puts("|                                 |");
    puts("|       CONTACT NOT FOUND!        |");
    puts("|_________________________________|");
    Sleep(2000);	

}
void remove_contact_by_number(void){//the 2nd option of "remove" function...
	system("cls");
	showOwnerInfo();
	puts("-----------------------------------");
	puts("----REMOVE A CONTACT BY NUMBER-----");
	puts("-----------------------------------");
	int record;
    struct contact *previousa;
    if(firstc==NULL){
        puts("___________________________________");
		puts("|                                 |");
		puts("|      There are no contacts      |");
		puts("|           to delete !           |");
		puts("|_________________________________|");
	return;
    }
	display_all_contacts_with_numbers();		//show all records  
    printf("Enter contact's number to delete: ");
    scanf("%d",&record);
    currentc = firstc;    
    while(currentc != NULL){
        if(currentc->number == record){
	    	if(currentc == firstc)	//if record to be deleted is the first record
				firstc=currentc->next; //reset firstc to point at next record as first
	    	else
				previousa->next = currentc->next;//previous pointer used if record to delete is not the first
        free(currentc); //frees memory
        	system("cls");

    	puts("___________________________________");
    	puts("|                                 |");
        puts("|  CONTACT REMOVED SUCCESSFULLY!  |");
        puts("|_________________________________|");
        	Sleep(2000);	
			cnum--;
	    return;
		}else{
	        previousa = currentc;
		    currentc = currentc->next;
		}
    }
    system("cls");
	puts("___________________________________");
	puts("|                                 |");
    puts("|       CONTACT NOT FOUND!        |");
    puts("|_________________________________|");
	Sleep(2000);		
}

void remove_contact(void){//remove a contact by 1stName or ...
	system("cls");
    system("color 4E"); //red
    showOwnerInfo();
	puts("-----------------------------------");
	puts("----REMOVE A CONTACT FROM LIST-----");
	puts("-----------------------------------");
	if(firstc==NULL){
    	puts("___________________________________");
    	puts("|                                 |");
        puts("|     NO CONTACTS TO REMOVE !     |");
        puts("|_________________________________|");
        Sleep(2000);
    }else{    
		puts("You have two options to remove a\ncontact:");
		puts("___________________________________");
		puts("|                                 |");
		puts("| 1) ............. REMOVE BY INFO |");
		puts("| 2) ........... REMOVE BY NUMBER |");
		puts("| 3) .................... CANCEL! |");
		puts("|_________________________________|");
		puts("now enter a number:");
		char n;
		scanf(" %c",&n);
		while(n!='3'){
			switch(n){
				case '1':
					remove_contact_by_info();
					return;
					break;
				case '2':
					remove_contact_by_number();
					return;
					break;
				default:
					puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
					puts("!!                               !!");
					puts("!!    WRONG INPUT...TRY AGAIN    !!");
					puts("!!                               !!");
					puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
					break;		
			}
		puts("enter '1','2'or'3'!");
		scanf(" %c",&n);
		continue;	
		}
		system("cls");
		puts("___________________________________");
		puts("|                                 |");
		puts("|    REMOVING PROCESS CANCELED!   |");
		puts("|_________________________________|");
		Sleep(2000);
	}
 }

int is_substring_in_string(char str[], char sub[]){//used is "find" function
	int i,j,flag=0;	
	char *p1, *p2, *p3;
	p1 = str;
	p2 = sub;
	for( i = 0; i<strlen(str); i++){
		if(*p1 == *p2){
	  		p3 = p1;
	  		for( j = 0;j<strlen(sub);j++){
	    if(*p3 == *p2){
	      	p3++;p2++;
	    }else
	      break;
	  }
	  p2 = sub;
	  if(j == strlen(sub))
	  {
	     flag = 1;
	    return 1;
	  }
	}
	p1++; 
	}
	if(flag==0)
	{
	//printf("Substring NOT found");
}
return 0;
}

void toUpper(char str[]){// My info -> MY INFO
	int i=0;
	   while(str[i]) {
      str[i]= (toupper(str[i]));
      i++;
   }
}

void find_contact(void){//find a contact by 1stName or ...     
	char buff[15],bufftmp[15],tmp[15];
    int k=0;// at the end of searching if k=0 => contact not found!!!
    system("cls");
	showOwnerInfo();
    puts("-----------------------------------");
	puts("----------FIND A CONTACT-----------");
	puts("-----------------------------------");
    if(firstc==NULL){
        puts("___________________________________");
		puts("|                                 |");
		puts("|      There are no contacts      |");
		puts("|            to find !            |");
		puts("|_________________________________|");
		Sleep(2000);
	    return ;
    }
	puts("How do you wanna find your contact?");
	puts("*you shouldn't type the exact info*");
  	puts("___________________________________");
	puts("|                                 |");
	puts("| 1) .............. By First Name |");
	puts("| 2) ............... By Last Name |");
	puts("| 3) .............. By Student-ID |");
	puts("| 4) ..................... By Age |");
	puts("| 5) .................. By Gender |");
	puts("| 6) ................... By Field |");
	puts("| 7) ............ By Phone Number |");
	puts("| 8) ................. By Address |");
	puts("|_________________________________|");
	puts("Now enter a number:");
	int num;
	scanf("%d",&num);
	switch(num){
		case 1://search by first name...
			printf("Enter contact first name:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);
		    while(currentc != NULL){
		        strcpy(bufftmp,buff);
		        strcpy(tmp,currentc->firstName);
		        toUpper(bufftmp);
		        toUpper(tmp);

		       	if( is_substring_in_string((tmp), (bufftmp)) == 1 ) {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			getch();	
			return;
		    break;
		case 2://search by last name...
			printf("Enter contact last name:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		    currentc = firstc;
		    system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);

		    while(currentc != NULL){
				strcpy(bufftmp,buff);
		        strcpy(tmp,currentc->lastName);
		        toUpper(bufftmp);
		        toUpper(tmp);
		
		       	if( is_substring_in_string((tmp), (bufftmp)) == 1 ) {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
		    
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}
			puts("press any key to continue:)");
			getch();	
			return;
			break;
		case 3://search by id...
			printf("Enter contact student-ID:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);
		    while(currentc != NULL){
		        strcpy(bufftmp,buff);
		        strcpy(tmp,currentc->id);
		        toUpper(bufftmp);
		        toUpper(tmp);
		       	if( is_substring_in_string((tmp), (bufftmp)) == 1 ) {
				//if( strcmp(currentc->id, buff) == 0 )  {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			getch();	
			return;
			break;
		case 4://search by age...
			printf("Enter contact age:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);
		    while(currentc != NULL){
		        if( strcmp(currentc->age, buff) == 0 )  {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			getch();	
			return;
			break;
		case 5://search by gender...
			printf("Enter contact's gender':\n(0=male/1=female)\n ");
		    fflush(stdin);//clears any text from the input stream
		    char gender;
		    //gets(buff);
		    scanf(" %c",&gender);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS :\n");

		    while(currentc != NULL){
		        if( currentc->gender == gender)  {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			getch();	
			return;
			break;	
		case 6://search by field...
			printf("Enter contact's field':\n");
			printf("( 1 =\t Computer Engineering\n");
			printf("  2 =\t Computer Science\n");
			printf("  3 =\t Electrical Engineering\n");
			printf("  4 =\t Mechanical Engineering\n");
			printf("  5 =\t Chemical Engineering\n");
			printf("  6 =\t AeroSpace Engineering )\n");
		    fflush(stdin);//clears any text from the input stream
		    char field;
		    scanf(" %c",&field);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS :\n");
		    while(currentc != NULL){
		        if( currentc->field == field)  {
					show(currentc);
					k++;
			    }
				currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}
			
			
			puts("press any key to continue:)");
			getch();	
			return;
			break;
		case 7://search by phone...
			printf("Enter contact phone number:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		    currentc = firstc;
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);
		    while(currentc != NULL){
		        strcpy(bufftmp,buff);
		        strcpy(tmp,currentc->phoneNumber);
		        toUpper(bufftmp);
		        toUpper(tmp);
		       	if( is_substring_in_string((tmp), (bufftmp)) == 1 ) {
					show(currentc);
					k++;
			    }
				currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			getch();	
			return;
			break;
		case 8://search by address...
			printf("Enter contact address:\n ");
		    fflush(stdin);//clears any text from the input stream
		    gets(buff);
		     system("cls");
			showOwnerInfo();
		 	printf("RESULTS FOR \"%s\"\n",buff);
		    currentc = firstc;
		    while(currentc != NULL){
		        strcpy(bufftmp,buff);
		        strcpy(tmp,currentc->address);
		        toUpper(bufftmp);
		        toUpper(tmp);

		       	if( is_substring_in_string((tmp), (bufftmp)) == 1 ) {
					show(currentc);
					k++;
			    }
					currentc = currentc->next;
		    }
			if(k==0){
				puts("___________________________________");
				puts("|                                 |");
			    puts("|        CONTACT NOT FOUND        |");
			    puts("|_________________________________|");
			}puts("press any key to continue:)");
			 getch();	
			return;
			break;
		default://when the user enter sth wrong...
			puts("___________________________________");
			puts("|                                 |");
		    puts("|oops...you entered a wrong value!|");
		    puts("|        try again later:)        |");
		    puts("|_________________________________|");
		    puts("press any key to continue:)");
			getch();	
			break;
	}
} 

int findnum (int recordnum){// for "change" function ***not useable in final version***
    int record;
    record = recordnum;
    currentc = firstc;
    while(currentc != NULL){           
        if(currentc->number == record){
           return 1;
         }else{
	    currentc = currentc->next;
		}
    }
    return -1;   
}

int update(void){// used in "change" function (CHANGE IT OR NOT?!)(EXTRA!!!)
	char ch;
    fflush(stdin);
	puts("Do you want to make any change?");
	puts("yes: 'Y'\nno: press any key");
	ch = getchar();// 1:'y' / 2:'Y' / 3:something else
	ch = toupper(ch);// 'y' = 'Y'
	fflush(stdin);
	if(ch == 'Y'){
		printf("Enter new value: ");
		return 1;
	}else
		return 0;
}

void change_contact(void){// change a contact (EXTRA!!!)
	int boool=1,isDigit;
    system("color 6f"); 
	int record, result;
	system("cls");
	showOwnerInfo();
    puts("-----------------------------------");
	puts("---------MODIFY A CONTACT----------");
	puts("-----------------------------------");
    if(firstc==NULL){
        puts("___________________________________");
		puts("|                                 |");
		puts("|      There are no contacts      |");
		puts("|           to change !           |");
		puts("|_________________________________|");
		Sleep(2000);
	return;
    }
	puts("Here we're going to show you all of");
	puts("your contacts.  Choose one of  them");
	puts("then enter it's number to change it");
	display_all_contacts_with_numbers();	
	puts("Who is the person whome you want to");
    puts("change? enter it's number:");
    scanf("%d",&record);  /*scan user input to record*/
    result = go_to_contact_number_x (record);
    	
    if( result >0 ){
    	system("cls");
    	showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
	    printf("First Name: %s\n",currentc->firstName);
	    if(update())
			gets(currentc->firstName);
		puts("-----------------------------------");
    	system("cls");
    	showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
		printf("Last Name: %s\n",currentc->lastName);
	    if(update())
		    gets(currentc->lastName);
		puts("-----------------------------------");
		system("cls");
    	puts("___________________________________");
		showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
		printf("Student-ID: %s\n",currentc->id);
		if(update()){
			while(boool){
		        scanf("%s", currentc->id);
		        int j=0;
		        isDigit = 0;
		        while(currentc->id[j]!='\0'){
		            if(!isdigit(currentc->id[j])){
		                isDigit=1;
		                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
						puts("!!                               !!");
						puts("!!    WRONG INPUT...TRY AGAIN    !!");
						puts("!!                               !!");
						puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
						printf("Enter %s's student-ID :\n(only NUMBERs are supported!!!) \n",currentc->firstName);
		                break;
		            }
		            j++;
		        }
		    if(isDigit)
		        continue;
		    boool=0;
		    }
			boool=1;
		}
		puts("-----------------------------------");
		system("cls");
    	showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
		printf("Age: %s\n",currentc->age);
	    if(update()){
			while(boool){
		        scanf("%s", currentc->age);
		        int j=0;
		        isDigit = 0;
		        while(currentc->age[j]!='\0'){
		            if(!isdigit(currentc->age[j])){
		                isDigit=1;
		                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
						puts("!!                               !!");
						puts("!!    WRONG INPUT...TRY AGAIN    !!");
						puts("!!                               !!");
						puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
						printf("Enter %s's age :\n(only NUMBERs are supported!!!) \n",currentc->firstName);
		                break;
		            }
		            j++;
		        }
		    if(isDigit)
		        continue;
		    boool=0;
		    }
			boool=1;
		}
		puts("-----------------------------------");

		system("cls");
    	showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
		printf("PhoneNumber: %s\n",currentc->phoneNumber);
	    if(update())
		    gets(currentc->phoneNumber);
				puts("-----------------------------------");
		system("cls");
    	showOwnerInfo();
    	puts("-----------------------------------");
    	show(currentc);
    	puts("");
		printf("Address: %s\n",currentc->address);
	    if(update())
		    gets(currentc->address);
				puts("-----------------------------------");
		system("cls");
		system("color 2E");//green 
		system("cls");
		puts("___________________________________");
    	puts("|                                 |");
        puts("| CONTACT CHANGED SUCCESSFULLY ^_^|");
        puts("|_________________________________|");
	    Sleep(2000);
	    return;
	}//if
	system("cls");
	system("color 4E");//red 
	system("cls");
	showOwnerInfo();
	puts("___________________________________");
	puts("|                                 |");
    puts("|       CONTACT NOT FOUND!        |");
    puts("|_________________________________|");
    Sleep(2000);

}

void save(){//save
	system("cls");
	char *filename = "D:\\FinalProject-AmirhosseinAlibakhshi.txt";

	system("color 0a");
	showOwnerInfo();
	currentc = firstc;
	if (currentc == NULL){// if we didn't have any contact...
	
	datafile = fopen(filename, "w");//opening the file to write

	if (datafile == NULL){
		printf("Error writing to %s\n", filename);
		return ;// a non-successfull end for our program
	}
	//Write each record to the file...
	while (currentc != NULL){
		fwrite(currentc, sizeof(struct contact), 1, datafile);
		currentc = currentc->next;
	}
	fclose(datafile);//closes data file
	
		puts("___________________________________");
    	puts("|                                 |");
        puts("|     NO DATA TO WRITE ON FILE    |");
        puts("|_________________________________|");
        Sleep(2000);

		return;//--->no saving proccess needed:)
    }
	datafile = fopen(filename, "w");//opening the file to write

	if (datafile == NULL){
		printf("Error writing to %s\n", filename);
		return ;// a non-successfull end for our program
	}
	//Write each record to the file...
	while (currentc != NULL){
		fwrite(currentc, sizeof(struct contact), 1, datafile);
		currentc = currentc->next;
	}
	fclose(datafile);//closes data file
	
		puts("___________________________________");
    	puts("|                                 |");
        puts("|      SAVED SUCCESSFULLY ^_^     |");
        puts("|_________________________________|");
    
    Sleep(2000);
}

int main() {
	//FILE *datafile;
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    
    SMALL_RECT windowSize = {0, 0, 36, 30};
//    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    
//    COORD bufferSize = {10, 10};
//    SetConsoleScreenBufferSize(wHnd, bufferSize);
    
	system("color F0");
	char *filename = "D:\\FinalProject-AmirhosseinAlibakhshi.txt";
	char command;// what user gives to the program as a command!(for SWITCH CASE)
	firstc = NULL;
	datafile = fopen(filename, "r");//open a text file in "D:\\FinalProject-AmirhosseinAlibakhshi.txt"

	if (datafile){
		firstc = (struct contact *)malloc(sizeof(struct contact)); //allocate memory for structure
		currentc = firstc;//make first record current
		while (1){
			newc = (struct contact *)malloc(sizeof(struct contact));
			fread(currentc, sizeof(struct contact), 1, datafile);
			if (currentc->next == NULL)// NULL indicates end of node list
				break;
			currentc->next = newc;//pointer referencing next node
			currentc->count = 0;// initiates count for comments
			currentc = newc;// make current record new
		}
	fclose(datafile);//closing the file:)
	find_cnum();
	correct_contact_number();
	}
	SetConsoleTitle("Contact-list (Amirhossein Alibakhshi)");
	showOwnerInfo();
	fflush(stdin);	
	puts("***** Please enter a command! *****");
	if(cnum)
		printf("       %d CONTACTS AVAILABLE\n",cnum);
	else
		puts("     NO CONTACTS AVAILABLE -_-     ");
	puts("___________________________________");
	puts("|                                 |");
	puts("| A ............... ADD A CONTACT |");
	puts("| R ............ REMOVE A CONTACT |");
	puts("| D ........ DISPLAY ALL CONTACTS |");
	puts("| F .............. FIND A CONTACT |");
	puts("| C ............ CHANGE A CONTACT |");
	puts("| S ................ SAVE TO FILE |");
	puts("| Q ........................ QUIT |");
	puts("|_________________________________|");
	scanf("%c", &command);
	
	while ( command != 'q' && command != 'Q'){
		switch (command) {				
			case 'a'://add
			case 'A':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - add");
				system("color 2E");//green 
				add_contact();
				break;
				
			case 'r'://remove
			case 'R':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - remove");
				system("color 4E"); //red
				remove_contact();
				break;
				
			case 'D'://display
			case 'd':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - display");
				system("color F0");
				display_all_contacts();
				break;
				
			case 'f'://find
			case 'F':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - find");
				system("color 1F");//blue
				find_contact();
				break;
				
			case 'c'://change
			case 'C':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - modify");
				system("color E0"); 
				change_contact();
				break;
				
			case 'S'://save 2 file
			case 's':
				SetConsoleTitle("Contact-list (Amirhossein Alibakhshi) - saving...");
				save();				
				break;
					
			default:
				system("color 4e");
				system("cls");
				puts("___________________________________");
				puts("|                                 |");
				puts("|What you entered is not supported|");
				puts("|         please try again        |");
				puts("|_________________________________|");
				Sleep(2000);
				break;
			}
			fflush(stdin);
			system("cls");
			system("color F0");
			SetConsoleTitle("Contact-list (Amirhossein Alibakhshi)");
			showOwnerInfo();
			fflush(stdin);	
			puts("** Please enter another command! **");
			if(cnum)
				printf("       %d CONTACTS AVAILABLE\n",cnum);
			else
				puts("     NO CONTACTS AVAILABLE -_-     ");
			puts("___________________________________");
			puts("|                                 |");
			puts("| A ............... ADD A CONTACT |");
			puts("| R ............ REMOVE A CONTACT |");
			puts("| D ........ DISPLAY ALL CONTACTS |");
			puts("| F .............. FIND A CONTACT |");
			puts("| C ............ CHANGE A CONTACT |");
			puts("| S ................ SAVE TO FILE |");
			puts("| Q ........................ QUIT |");
			puts("|_________________________________|");
			correct_contact_number();
			scanf(" %c", &command);
			continue;
		}
		system("cls");
		system("color F0");
		showOwnerInfo();
		system("color 0f"); 
		puts("___________________________________");
		puts("|                                 |");
	    puts("|          SAVE CHANGES?          |");
	    puts("|                                 |");
	    puts("|           \"Y\" = SAVE            |");
	    puts("|     other keys = DON'T SAVE!    |");
	    puts("|_________________________________|");
	    char saveOrNot;
	    saveOrNot = getchar();
	    saveOrNot = getchar();// 1:'y' / 2:'Y' / 3:something else
		saveOrNot = toupper(saveOrNot);// 'y' = 'Y'
		fflush(stdin);
		if(saveOrNot == 'Y'){
		showOwnerInfo();
		save();
        puts("___________________________________");
		puts("|                                 |");
		puts("|       END OF PROGRAM ^_^        |");
		puts("|_________________________________|");
		}else{
		
		system("cls");
		system("color 0c");
		showOwnerInfo();	
		puts("___________________________________");
		puts("|                                 |");
		puts("|       END OF PROGRAM ^_^        |");
		puts("|_________________________________|");
	}

		return 0 ;
}

