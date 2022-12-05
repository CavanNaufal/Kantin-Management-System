#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "headerFunction.h"
#include "functionRestaurant.c"

int main()
{
	char choose[3];
	loadingScreen();
	printf("1. Main Menu\n2. Help Desk\n3. Exit");
	printf("\nChoose : ");
	scanf("%s", &choose);
	do{
		if(strcmp(choose, "1") == 0){
			UserMenu();
		}
		else if(strcmp(choose, "2") == 0){
			helpdesk();
			printf("1. Main Menu\n2. Exit");
			printf("\nChoose : ");
			scanf("%s", &choose);
		}
		else if(strcmp(choose, "3") == 0){
			close();
		}
		else{
			printf("Invalid Input");
			error();
			printf("\nChoose : ");
			scanf("%s", &choose);
		}
	}while(strcmp(choose, "1") != 0 || strcmp(choose, "2") != 0 || strcmp(choose, "3") != 0);

    return 0;
}