#include <stdio.h>
#include <math.h>

main() {
	int n = 10;
	if (n % 2 == 1) {
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) {
					printf(">");
				}
				else if (j == n - 1 - i) {
					printf("<");
				}
				else {
					printf("-");
				}
			}
			printf("\n");
		}
		for (int i = 0; i < n; i++)
		{
			if (i == n / 2) {
				printf("*");
			}
			else {
				printf("-");
			}
		}
		for (int i = n/2+1; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				if (j == n - 1 - i) {
					printf(">");
				}
				else if (i == j) {
					printf("<");
				}
				else {
					printf("-");
				}
			}
			printf("\n");
		}


	}
	
	
	
}