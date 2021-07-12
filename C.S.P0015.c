#include <stdio.h>
#include <stdlib.h>
// small package= 50
// large package= 200
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int checkSmallpackage(float small1, char small2){
	if( (small1<1 || small1>10000) || small2!='\n')
	{
		while(small1<1 || small1>10000 || small2!='\n')
		{
			printf("Reput the price of small package: ");
			fflush(stdin);
			scanf("%f%c",&small1,&small2);
		}
	}
	return small1,small2; 
}

int checkLargepackage(float large1, char large2){
	if( (large1<1 || large1>10000) || large2!='\n')
	{
	 	while(large1<1 || large1>10000 || large2!='\n')
	 	{
			printf("Reput the price of large package: ");
			fflush(stdin);
			scanf("%f%c",&large1,&large2);
		}
	}
	return large1,large2;
}

int checkInvitation(int number1, char number2){
	if( (number1<1 || number1>10000) || number2!='\n')
	{
	 while(number1<1 || number1>10000 || number2!='\n'){
	 	printf("Invitation must less than 10000");
		printf("Reput the number of invitation: ");
		fflush(stdin);
		scanf("%d%c",&number1,&number2);
	}
	}
	return number1,number2;
}
int CaculateInvite(int number1,float large1, float small1)
{
	float d;
	int c,i;
	
	// Invitation less than 100000
	if (number1<10001)
	{
		do
		{
			for(i=0;number1>100;i++)
				number1-=200;
		}	
		while (number1>100);
		do
		{
			for(c=0;number1>0;c++)
				number1-=50;
		}
		while (number1>0);
		printf("You should order %d large package",i);
		printf("\nYou should order %d small package",c);
	}
	else
	// Invitation > 10000
	{
		printf("\nToo many invitations to caculate.");
	}
	
	// Formula to caculate the price 
	d = (large1*i) + (small1*c);
	return d;
}

int main(int argc, char *argv[]) 
{
	float d,e;
	float small1,large1;
	char small2,large2;
	int number1;
	char number2;
	int c,i;
	char key;
	do{
		do
		{
			printf("What is the cost of a small package (in dollars): ");
			scanf("%f%c",&small1,&small2);
			checkSmallpackage(small1,small2);
			printf("What is the cost of a large package (in dollars): ");
			scanf("%f%c",&large1,&large2);
			checkLargepackage(large1,large2);
			printf("How many invitations are you sending out: ");
			scanf("%d%c",&number1,&number2);
			checkInvitation(number1,number2);
		}
		
		// The number user input cannot be negative
		while(small1<=0 || large1<=0 || number1<=0);
		e=CaculateInvite(number1,large1,small1);
		if (e>500)
		{
			printf("\nNot enough money");
		}
		else
		{
			printf("\nYour cost of invitations will be %.2f\n",e);
		}	
		printf("Press any key to continue, Exit if press ESC.");
	
		// Recieve user keyboard
//		key=getchar();
		key=getch();
		printf("\n");
	}
	// Press Esc to complete
	while (key!=27);
	return 0;
}
