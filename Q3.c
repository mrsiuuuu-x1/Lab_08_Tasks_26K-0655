#include <stdio.h>

void display() {
	printf("-------ROUTES--------");
	printf("\n1. Karachi -> Hyderabad: Rs. 800");
	printf("\n2. Karachi -> Sukkur: Rs. 2200");
	printf("\n3. Karachi -> Multan: Rs. 3500");
}

int routeType() {
	int num;
	
	printf("\nEnter Route Number: ");
	scanf("%d", &num);
	
	while ((num < 1) || (num > 3)) {
		printf("\nEnter Valid Route Number: ");
		scanf("%d", &num);
	}
	
	return num;
}

int numberOfSeats() {
	int num;
	printf("\nEnter number of Seats: ");
	scanf("%d", &num);
	
	while ((num < 1) || (num > 6)) {
		printf("\nEnter Valid Number of Seats: ");
		scanf("%d", &num);
	}
	
	return num;
}

int main() {
	char seat_type;
	int choice;
	int seats;
	float fare;
	float amount;
	float extra;
	float company_total_earnings = 0.0;
	
	display();
	
	for (int i = 1; i <= 2; i++) {
		float passenger_total = 0.0;
		printf("\n\n--- Booking for Passenger %d ---", i);
		
		choice = routeType();
		seats = numberOfSeats();
		
		switch(choice) {
			case 1:
				fare = 800.0;
				amount = fare * seats;
				break;
			case 2:
				fare = 2200.0;
				amount = fare * seats;
				break;
			case 3:
				fare = 3500.0;
				amount = fare * seats;
				break;
			default:
				break;
		}
		
		printf("\nEnter Seat Type (Economy(E) or Business(B)): ");
		scanf(" %c", &seat_type);
		
		while ((seat_type != 'E') && (seat_type != 'e') && (seat_type != 'B') && (seat_type != 'b')) {
			printf("\nEnter Valid Seat Type: ");
			scanf(" %c", &seat_type);
		}
		
		if (seat_type == 'B' || seat_type == 'b') {
			extra = amount * 0.30;
			passenger_total += amount + extra;
		}
		else {
			passenger_total += amount;
		}
		
		printf("\n-------Passenger %d Ticket--------", i);
		
		if (choice == 1) {
			printf("\nRoute Type: Karachi -> Hyderabad");
		} else if (choice == 2) {
			printf("\nRoute Type: Karachi -> Sukkur");
		} else {
			printf("\nRoute Type: Karachi -> Multan");
		}
		
		printf("\nNumber Of Seats Selected: %d", seats);
		
		if (seat_type == 'B' || seat_type == 'b') {
			printf("\nSeat Type: Business");
		} else {
			printf("\nSeat Type: Economy");
		}
		
		printf("\nTotal Fare for Passenger %d: %.2f", i, passenger_total);
		
		company_total_earnings += passenger_total;
	}
	
	printf("\n\n========================================");
	printf("\nTotal Earnings of the Bus Company: %.2f", company_total_earnings);
	printf("\n========================================");
	
	return 0;
}