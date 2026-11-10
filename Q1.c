#include <stdio.h>

int options() {
	int num;
	printf("\nSelect Package: ");
	scanf("%d", &num);
	
	while ((num < 1) || (num > 4)) {
		printf("\nEnter a Valid Package: ");
		scanf("%d", &num);
	}
	
	return num;
}

long long phone_number() {
	long long num;
	printf("\nEnter Phone Number: ");
	scanf("%lld", &num);
	
	return num;
}

void print_slip(long long phone, float amount, float tax, float total_bal) {
	printf("\n--- RECHARGE SLIP ---");
	printf("\nMobile Number: %lld", phone);
	printf("\nBase Amount: Rs. %.2f", amount);
	printf("\nTax (15%%): Rs. %.2f", tax);
	printf("\nTotal Balance Credited: Rs. %.2f\n", total_bal);
}

int main() {
	int chosen;
	float tax_rate = 0.15;
	float bonus_rate = 0.10;
	float total_money_spent = 0.0;
	long long number;
	
	for (int i = 0; i < 3; i++) {
		printf("\n=== Transaction %d of 3 ===", i + 1);
		printf("\nAvailable Recharge Package: ");
		printf("\n1. Rs. 100");
		printf("\n2. Rs. 200");
		printf("\n3. Rs. 500");
		printf("\n4. Rs. 1000\n");
		
		chosen = options();
		number = phone_number();
		
		float base_amount = 0.0;
		switch(chosen) {
			case 1: base_amount = 100.0; break;
			case 2: base_amount = 200.0; break;
			case 3: base_amount = 500.0; break;
			case 4: base_amount = 1000.0; break;
			default: base_amount = 0.0; break;
		}
		
		float tax_charged = base_amount * tax_rate;
		float total_cost = base_amount + tax_charged;
		
		float bonus_earned = 0.0;
		if (base_amount >= 500.0) {
			bonus_earned = base_amount * bonus_rate;
		}
		
		float total_balance = base_amount + bonus_earned;
		
		print_slip(number, base_amount, tax_charged, total_balance);
		
		total_money_spent += total_cost;
	}
	
	printf("\n=================================");
	printf("\nTotal Money Spent in Session: Rs. %.2f\n", total_money_spent);
	
	return 0;
}
