#include <stdio.h>

void display() {
	printf("---------PNS SHIFA----------");
	printf("\nRoom Charges: ");
	printf("\n1. General Ward - 1500/day");
	printf("\n2. Semi-Private Ward - 3500/day");
	printf("\n3. Private Ward - 6000/day");
}

int roomType() {
	int num;
	
	printf("\n");
	printf("\nEnter Room Type: ");
	scanf("%d", &num);
	while ((num < 1) || (num > 3)) {
		printf("\nEnter a Valid Room Type: ");
		scanf("%d", &num);
	}
	return num;
}

int numberOfDays() {
	int stayed;
	printf("\nEnter Number of Days stayed: ");
	scanf("%d", &stayed);
	while ((stayed < 1) || (stayed > 30)) {
		printf("Enter valid number of days: ");
		scanf("%d", &stayed);
	}
	return stayed;
}

int main() {
	int choice;
	int days;
	float discount;
	float total = 0.0;
	float new_medicine = 0.0;
	float service_charge = 0.05;
	float medicine;
	float base_amount;
	float amount = 0;
	
	display();
	
	choice = roomType();
	days = numberOfDays();
	
	switch(choice) {
		case 1:
			base_amount = 1500.0;
			amount = base_amount * days;
			break;
		case 2:
			base_amount = 3500.0;
			amount = base_amount * days;
			break;
		case 3:
			base_amount = 6000.0;
			amount = base_amount * days;
			break;
		default:
			break;
	}
	
	printf("\nEnter medicine charge: ");
	scanf("%f", &medicine);
	
	float service = medicine * service_charge;
	new_medicine += medicine + service;
	
	total += new_medicine + amount;
	
	if (days > 7) {
		discount = total * 0.08;
		total -= discount;
	}
	
	printf("\n---------Total Bill----------");
	
	if (choice == 1) {
		printf("\nRoom Type: General Ward");
	} else if (choice == 2) {
		printf("\nRoom Type: Semi-Private Ward");
	} else {
		printf("\nRoom Type: Private Ward");
	}
	
	printf("\nNumber of Days: %d", days);
	printf("\nRoom Charges (Total): %.2f", amount);
	printf("\nMedicine Charges (incl. service charge): %.2f", new_medicine);
	printf("\nFinal Amount: %.2f", total);
}