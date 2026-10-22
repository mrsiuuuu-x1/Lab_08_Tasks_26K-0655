#include <stdio.h>

int main() {
	int sales[3][3];
	int prices[3][2];
	int total[3][2] = {0};
	int quantity;
	int price;
	int i, j, k;
	int profit[3] = {0};
	
	// Initializing Sale Quantity Array
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (j == 0) {
				printf("Enter Sale Quantity for Charger, Branch %d: ", i + 1);
				scanf("%d", &quantity);
				sales[i][j] = quantity;
			}
			else if (j == 1) {
				printf("Enter Sale Quantity for Earphone, Branch %d: ", i + 1);
				scanf("%d", &quantity);
				sales[i][j] = quantity;
			}
			else {
				printf("Enter Sale Quantity for Cover, Branch %d: ", i + 1);
				scanf("%d", &quantity);
				sales[i][j] = quantity;
			}
		}
	}
	
	// Initializing Prices Array
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (i == 0) {
				if ( j == 0) {
					printf("\nEnter Cost Price of Charger: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
				else {
					printf("\nEnter Selling Price of Charger: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
			}
			else if (i == 1) {
				if ( j == 0) {
					printf("\nEnter Cost Price of Earphones: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
				else {
					printf("\nEnter Selling Price of Earphones: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
			}
			else {
				if ( j == 0) {
					printf("\nEnter Cost Price of Cover: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
				else {
					printf("\nEnter Selling Price of Cover: ");
					scanf("%d", &price);
					prices[i][j] = price;
				}
			}
			
		}
	}
	
	// Calculating Total Prices
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				total[i][j] += sales[i][k] * prices[k][j];
			}
		}
	}
	
	// Computing Profit
	for (i = 0; i < 3; i++) {
		profit[i] = total[i][1] - total[i][0];
	}
	
	int max[1] = {0};
	for (i = 0; i < 3; i++) {
		if (profit[i] > max) {
			max = profit[i];
		}
	}
	printf("\nHighest Profit is %d", max[0]);
	
	
}
