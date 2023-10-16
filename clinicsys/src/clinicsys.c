/*
 ============================================================================
 Name        : clinicsys.c
 Author      : Abdo MOhsen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define password 1234
struct patient
{
	char name[10];
	int age;
	char gender;
	int id;
	struct patient * next;
};
struct reservation{
	int slot;
	int idp;
	struct reservation*next;
};

struct patient*head=NULL;
struct reservation*h=NULL;



struct patient * ID_S(int id)
{
	struct patient * p;
	p=head;
	while (p!= NULL)
	{
		if (p->id==id)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void add_patient(){

	struct patient *p = (struct patient*) malloc(sizeof(struct patient));

	printf("Enter ID : ");

	scanf("%d", &p->id);


if(ID_S(p->id)!=NULL){

	printf(" ID exist \n");

      return;
}
else{

	printf("Enter name: ");

	scanf("%s", p->name);

	printf("Enter age: ");

	scanf("%d", &p->age);

	printf("Enter gender :\n ");

	scanf(" %c", &p->gender);

	p->next = head;

	head = p;

	printf("the operation done sucessfully\n");
}

}

void info_patient(int id){

	struct patient * p;

	if(ID_S(id)!=NULL)
	{
		p=ID_S(id);
		printf(" patient ID Is : %d\n",p->id);
		printf(" patient Age Is : %d\n",p->age);
		printf(" patient Gender Is : %c\n",p->gender);
		printf(" patient Name is :%s\n ",p->name);
		printf("\n");
	}
	else{

		puts("the patient not exist\n ");
	}

}



void edit_patient(){
	int id ;
	printf("enter the id to edit\n");

	scanf("%d",&id);

	struct patient *current = head;


	info_patient(id);

	printf("\n");

	while(current != NULL)
	{

		if(current->id == id)
		{

			printf("enter the new name:\n");

			scanf("%s", current->name);

			printf("enter the new gender:\n");

			scanf(" %c",&current->gender);

			printf("enter the new age:\n");

			scanf("%d",&current->age);


			return;

		}
		current = current->next;

	}
	printf("incrorrect id\n");
}




void reserveSlot() {

	int  s1, s2, s3, s4, s5;
	struct reservation *checks = h;
	s1 = s2 = s3 = s4 = s5 = 1;
	while (checks != NULL) {

		if (checks->slot != 1 && s1) {
			s1 = 1;
		}
		else {s1 = 0;}

		if (checks->slot != 2 && s2) {
			s2 = 1;
		}
		else {s2 = 0;}
		if (checks->slot != 3 && s3) {
			s3 = 1;
		}
		else {s3 = 0;}
		if (checks->slot != 4 && s4) {
			s4 = 1;
		}
		else {	s4 = 0;}
		if (checks->slot != 5 && s5) {
			s5 = 1;
		}
		else {s5 = 0;}

		checks = checks->next;
	}
	if (s1==1) {
		printf("1: 2:00pm/2:30pm\n");
	}
	if (s2==1) {
		printf("2: 2:30pm/3:00pm\n");
	}
	if (s3==1) {
		printf("3: 3:00pm/3:30pm\n");
	}
	if (s4==1) {
		printf("4: 4:00pm/4:30pm\n");
	}
	if (s5==1) {
		printf("5: 4:30pm/5:00pm\n");
	}

	int choice_slot, PID;
	printf("Enter patient ID: \n");
	scanf("%d", &PID);

	if(ID_S(PID)==NULL){


		printf("patient with ID :%d not found in system \n", PID);


		return;
	}
	  printf("Enter the number of Appointment you want : \n");


	   scanf("%d", &choice_slot);

	if (choice_slot >5) {


		printf("Invalid n slot\n");


		return;
	}
	  struct reservation *check_reserv = h;


	   while (check_reserv != NULL) {



		if (check_reserv->slot == choice_slot) {



		puts("Appointment reserved");


			return;
		}

	check_reserv = check_reserv->next;


	}
	struct reservation *reserv = (struct reservation*) malloc(sizeof(struct reservation));


	reserv->slot = choice_slot;


	reserv->idp = PID;


	reserv->next = h;

	h = reserv;


	printf("Appointment reserved \n");
}

void cancel_reserv(){
	int PID;

	puts("If you want to cancel enter your id");

	scanf("%d",&PID);

	struct reservation * current=h;

	struct reservation *prevous=NULL;


	while(current!=NULL){
		if (current->idp == PID) {

			if (prevous == NULL) {

				h = current->next;
			}

			else
			{

			prevous->next=current->next;

			}


			free(current);

			printf("the cancelled operation done successfully\n");


			return;
		}

		prevous = current;

		current  = current->next;
	}
	   puts("Incorrect ID");
}

void admin_mode(void){
	int op;
	int pass , T = 0;

	printf("Enter the password \n");

	scanf("%d",&pass);


	while(pass!=password && T!=2){



		printf("Wrong pass enter the password again\n");

		scanf("%d",&pass);

		T++;

		if(T==2){

			printf("warnning the pass entered wrong 3 times the system will shut down\n");

			exit(0);

		}
	}
	printf("\n");
	printf("1. Add new patient \n");
	printf("2. Edit patient \n");
	printf("3. Reserve a appointment \n");
	printf("4. Cancel reservation\n");
	printf("\n");
	printf("Enter your choice\n");
	scanf("%d",&op);
	switch (op) {
	case 1:
		add_patient();
		break;
	case 2:

		edit_patient();
		break;
	case 3:

		reserveSlot();
		break;
	case 4:
		cancel_reserv();
		break;
	default:
		break;
	}

}
void viewReserv() {

	if (h == NULL) {

		printf("No reservations \n");

		return;

	  }

	  printf("\n available reservations\n");


	  struct reservation *currentR = h;


	   while (currentR != NULL) {


	  printf("reservations :%d\n", currentR->slot);

	  printf("Patient ID :%d\n",currentR->idp);

	  currentR = currentR->next;


	}


}


void user(){
	int c;
	while (1) {
		printf("1. View patient record\n");
		printf("2. View today's reservations\n");
		printf("3. Exit user mode\n\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		switch (c) {
		case 1:

			printf("Enter patient ID: ");
			int PID;
			scanf("%d", &PID);
			info_patient(PID);

			break;
		case 2:

			viewReserv();
			break;
		case 3:
			return;
		default:
			printf("NOT valid\n");
		}
	}
}





int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int echioce;
	while (1) {
		printf("1. Admin  \n");
		printf("2. User   \n");

		scanf("%d", &echioce);

		if (echioce == 1) {
			admin_mode();
		}
		else if (echioce == 2) {
			user();
		}
		else {
			printf("Incorrect choice");;
		}


	}
	return 0;
}



