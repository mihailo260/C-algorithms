#include <stdio.h>
#include <math.h>

int main() {
	int n = 100;
	if (n % 2 == 1) {
		for (int i = 0; i < n / 2; i++)
		{
			
			char slovoLevo = 'a' + i - 1;
			char slovo = 'a';
			char slovoDesno = 'a';
			for (int j = 0; j < n; j++)
			{
				if (i == j) {
					printf(">");
				}
				else if (j == n - 1 - i) {
					printf("<");
				}
				else {
					if (j > i && j < n - 1 - i) {
						printf("%c", slovo);
						if (j < n / 2) {
							slovo++;
						}
						else {
							slovo--;
						}
						
					}
					else {
						if (j < i) {
							printf("%c", slovoLevo);
							slovoLevo--;
						}
						else {
							printf("%c", slovoDesno);
							slovoDesno++;
						}
						
					}
					
				}
			}
			printf("\n");
		}
		char slovoLevo = 'a' + n / 2 - 1 ;
		char slovoLevoPolovina = slovoLevo;
		char slovoDesno = 'a';
		for (int i = 0; i < n; i++)
		{
			if (i == n / 2) {
				printf("*");
			}
			else {
				if (i < n / 2) {
					printf("%c", slovoLevo);
					slovoLevo--;
				}
				else {
					printf("%c", slovoDesno);
					slovoDesno++;
				}
			}
		}
		printf("\n");
		for (int i = n / 2 + 1; i < n; i++)
		{	
			char slovoCentar = 'a';
			char slovoDesno = 'a';
			slovoLevo = slovoLevoPolovina - (i - n/2);
			for (int j = 0; j < n; j++) {
				if (j == n - 1 - i) {
					printf(">");
				}
				else if (i == j) {
					printf("<");
				}
				else {
					if (j < n - i - 1) {
						printf("%c",slovoLevo);
						slovoLevo--;
					}
					else if (j > n - i - 1 && j < i) {
						printf("%c", slovoCentar);
						if (j < n / 2) {
							slovoCentar++;
						}
						else {
							slovoCentar--;
						}
					}
					else {
						printf("%c", slovoDesno);
						slovoDesno++;
					}
				}
			}
			printf("\n");
		}


	}
	/*----------------------------------------------------*/
	else {
		for (int i = 0; i < n / 2 -1; i++)
		{

			char slovoLevo = 'a' + i - 1;
			char slovo = 'a';
			char slovoDesno = 'a';
			for (int j = 0; j < n; j++)
			{
				if (i == j) {
					printf(">");
				}
				else if (j == n - 1 - i) {
					printf("<");
				}
				else {
					if (j > i && j < n - 1 - i) {
						printf("%c", slovo);
						if (j < n / 2-1) {
							slovo++;
							
						}
						else if(j > n/2-1){
							slovo--;
						}

					}
					else {
						if (j < i) {
							printf("%c", slovoLevo);
							slovoLevo--;
						}
						else {
							printf("%c", slovoDesno);
							slovoDesno++;
						}

					}

				}
			}
			printf("\n");
		}
		
		char slovoLevoPolovina = 'a' + n / 2 - 1;
		
		for (int k = 0; k < 2; k++)
		{
			char slovoLevo = 'a' + n / 2 - 2;
			char slovoDesno = 'a';
			for (int i = 0; i < n; i++) {
				if (i == n / 2 || i == n / 2 - 1) {

					printf("*");
				}
				else if(i < n/2){
					printf("%c",slovoLevo);
					slovoLevo--;
				}
				else {
					printf("%c", slovoDesno);
					slovoDesno++;
				}
			}
			printf("\n");
		}
		for (int i = n / 2 + 2; i < n; i++)
		{
			char slovoCentar = 'a';
			char slovoDesno = 'a';
			char slovoLevo = slovoLevoPolovina - (i - n / 2);
			for (int j = 0; j < n; j++) {
				if (j == n - 1 - i) {
					printf(">");
				}
				else if (i == j) {
					printf("<");
				}
				else {
					if (j < n - i - 1) {
						printf("%c", slovoLevo);
						slovoLevo--;
					}
					else if (j > n - i - 1 && j < i) {
						printf("%c", slovoCentar);
						if (j < n / 2-1) {
							slovoCentar++;
						}
						else if(j > n/2-1) {		
							slovoCentar--;
						}
					}
					else {
						printf("%c", slovoDesno);
						slovoDesno++;
					}
				}
			}
			printf("\n");
		}

	}

	return 0;

}