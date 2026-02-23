#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pi 3.14159
#define gravity 9.8

struct person{
	double num1, num2;
	char op;
	double result;
};

double add(struct person *x);
double subtract(struct person *x);
double mult(struct person *x);
double divide(struct person *x);

int main(int argc, char* argv[])
{
	if(argc != 4){
		puts("You made a mistake");
		exit(EXIT_FAILURE);
	}
	struct person h;
	struct person *ptr = &h;
	puts("Enter your numbers");
	//scanf("%lf%lf", &h.num1, &h.num2);
	h.num1 = strtod(argv[1], NULL); //num1
	h.op = argv[2][0];//this iwll be for operation
	h.num2 = strtod(argv[3], NULL); //num2

	printf("num1: %.2lf\nnum2: %.2lf\nop: %c\n", ptr->num1, ptr->num2, ptr->op);

	switch(h.op){
		case '+':
			ptr->result = add(ptr);
			printf("The result was: %.2lf\n",ptr->result);
			//printf("%d", argc);
			break;
		case '-':
			ptr->result = subtract(ptr);
			printf("The result was: %.2lf\n",ptr->result);
			//printf("%d", argc);
			break;
		case 'x':
			strcmp(argv[2], "*") == 0;
			ptr->result = mult(ptr);
			printf("The result was: %.2lf\n",ptr->result);
			break;
		case '/':
			ptr->result = divide(ptr);
			printf("The result was: %.2lf\n",ptr->result);
			//printf("%d", argc);
			break;
		default:
			puts("You did something wrong");
			exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
	
}

double add(struct person *x)
{
	return x->num1 + x->num2;
}
double subtract(struct person *x)
{
	return x->num1 - x->num2;
}
double mult(struct person *x)
{
	return x->num1 * x->num2;
}
double divide(struct person *x)
{
	return x->num1 / x->num2;
}
