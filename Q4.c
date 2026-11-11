#include <stdio.h>

void display() {
	printf("--------Rodeo Rides Rules(creative to ho phir me)---------");
	printf("\n1. Base Fare = Rs. 150");
	printf("\n2. Rs. 60 for the first 10 km");
	printf("\n3. Rs 45 per km after that");
}

int askDistance() {
	int dist;
	
	printf("\nEnter Distance(0-200): ");
	scanf("%d", &dist);
	
	while ((dist <= 0) || (dist > 200)) {
		printf("\nEnter Valid Distance: ");
		scanf("%d", &dist);
	}
	
	return dist;
}

int waitingTime() {
	int waiting;
	
	printf("\nEnter Waiting Time(0-120): ");
	scanf("%d", &waiting);
	
	while ((waiting < 0) || (waiting > 120)) {
		printf("\nEnter Valid Waiting Time: ");
		scanf("%d", &waiting);
	}
	
	return waiting;
}

int currentHour() {
	int time_hour;
	printf("\nEnter current hour(0-23): ");
	scanf("%d", &time_hour);
	
	while ((time_hour < 0) || (time_hour > 23)) {
		printf("\nEnter Valid Hour(0-23): ");
		scanf("%d", &time_hour);
	}
	
	return time_hour;
}

int main() {
	int distance;
	int time;
	int hour;
	int fine = 0;
	int charges = 0;
	int amount = 0;
	int total = 0;
	int charges_after_ten = 0;
	int fare = 150;
	
	display();
	
	distance = askDistance();
	time = waitingTime();
	hour = currentHour();
	
	if (distance <= 10) {
		charges += fare + (60 * distance);
	} else {
		charges_after_ten = 45 * (distance - 10);
		charges += charges_after_ten + fare + (60 * 10);
	}
	
	if (time <= 5) {
		fine = 0;
	} else {
		fine = 10 * (time - 5);
	}
	amount += charges + fine;
	total += amount;
	
	if ((hour >= 22) || (hour < 6)) {
		int extra_fare = amount * 0.25;
		total += extra_fare;
	}
	
	printf("\n--- Trip Receipt ---");
	printf("\nDistance: %d km", distance);
	printf("\nWaiting Time: %d mins", time);
	printf("\nFinal Fare: Rs. %d\n", total);
}