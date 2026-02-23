#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define buffer 10
struct library_card_info
{
	char name[100], address[100];
	int age, phoneNum;
};

void new_lib_card(struct library_card_info *x);
void check_availability();
void checkout();

int main(int argc, char* argv[])
{
	int option;
	struct library_card_info *city = NULL; //we should be setting this to null initally bc we dont know if they want it yet
	struct library_card_info **ptr = NULL; //redo logic b/c we are using dbl ptr now
	puts("Hey there welcome to our community library how can I help you");
	puts("1) getting a library card\n2)Checking Avaiablility\n3)Checking something out");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			new_lib_card(ptr);
		case 2:
			check_availability();
		case 3:
			checkout();
		default:
			printf("Thank you for coming hope to see you next time");
		free(ptr);
		free(city);
		exit(EXIT_SUCCESS);
	}
}

//function to add get information for the library card move from main
void new_lib_card(struct library_card_info *x)
{
	char cont;
	int struct_ptr_count = 0;
	printf("Looks likes you want a library card is that right [y/n]");
	scanf("%c", &cont);
	cont = (cont == 'y') ? true : false;
	if(!cont){
		puts("Okay have a nice day");
		exit(EXIT_SUCCESS);
	}

	while(cont != 'n')
	{
		x += struct_ptr_count;
		if (x != NULL){ free(x);}
		struct library_card_info *city = (struct library_card_info*)(city, sizeof(struct library_card_info));
		if(x != NULL){perror("Realloc failed");}

		printf("Alright we are gonna need some information first\n");
		printf("We need your name\n");
		scanf("%s", (*x).name); //considered an array so the address isnt needed
		printf("And your address\n");
		scanf("%s", (*x).address);
		printf("And your age\n");
		scanf("%d", &(x->age)); //must add address b/c the data can be modified
		printf("And finally your phone number\n");
		scanf("%d", &(x->phoneNum));
		//ptr++;//redo b/c it overwrites ptr data
		printf("would you like to continue? [y/n]\n");
		scanf("%c", &cont);
		cont = (cont == 'y') ? true : false;
		struct_ptr_count = (cont =='y') ? struct_ptr_count++ : struct_ptr_count;
		
	}
}

void check_availability()
{

}

void checkout()
{

}