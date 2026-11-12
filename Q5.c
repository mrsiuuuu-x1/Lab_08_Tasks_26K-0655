#include <stdio.h>

int main() {
    double costPrice, sellPrice, quantity;
    
    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty = &quantity;

    printf("=== Stationery Shop Profit/Loss Calculator ===\n");
    printf("Enter Cost Price per unit: ");
    scanf("%lf", pCost);
    printf("Enter Selling Price per unit: ");
    scanf("%lf", pSell);
    printf("Enter Quantity Sold: ");
    scanf("%lf", pQty);

    double totalCost = (*pCost) * (*pQty);
    double totalSales = (*pSell) * (*pQty);
    double netProfitLoss = totalSales - totalCost;

    printf("\n--- Results ---\n");
    printf("Total Cost: %.2f\n", totalCost);
    printf("Total Sales: %.2f\n", totalSales);

    if (netProfitLoss > 0) {
        printf("Status: Profit of %.2f\n", netProfitLoss);
        double profitPercentage = (netProfitLoss / totalCost) * 100.0;
        printf("Profit Percentage: %.2f%%\n", profitPercentage);
    } else if (netProfitLoss < 0) {
        printf("Status: Loss of %.2f\n", -netProfitLoss);
    } else {
        printf("Status: No profit no loss\n");
    }

    double *pLarger = (*pCost > *pSell) ? pCost : pSell;
    printf("\n[Comparison] The larger value between cost and selling price is: %.2f (stored at address %p)\n", *pLarger, (void*)pLarger);

    printf("\n--- Memory Address Table ---\n");
    printf("%-15s | %-15s | %-18s\n", "Variable", "Value", "Memory Address");
    printf("--------------------------------------------------\n");
    printf("%-15s | %-15.2f | %p\n", "costPrice", *pCost, (void*)&costPrice);
    printf("%-15s | %-15.2f | %p\n", "sellPrice", *pSell, (void*)&sellPrice);
    printf("%-15s | %-15.2f | %p\n", "quantity", *pQty, (void*)&quantity);
    printf("%-15s | %-15s | %p\n", "pCost (ptr)", "N/A", (void*)&pCost);
    printf("%-15s | %-15s | %p\n", "pSell (ptr)", "N/A", (void*)&pSell);
    printf("%-15s | %-15s | %p\n", "pQty (ptr)", "N/A", (void*)&pQty);

    return 0;
}