#include <stdio.h>
#include <stdlib.h>

void printStock(int *stock, int n) {
    int totalStock = 0;
    int lowest = stock[0];
    for (int i = 0; i < n; i++) {
        totalStock += stock[i];
        if (stock[i] < lowest) lowest = stock[i];
    }
    printf("-> Current Stock: ");
    for (int i = 0; i < n; i++) printf("[%d] ", stock[i]);
    printf("\n-> Total Stock Count: %d | Lowest Item Stock: %d\n", totalStock, lowest);
}

int main() {
    int n;
    printf("=== Bilal's Grocery Shop Inventory ===\n");
    do {
        printf("Enter starting stock item count (3 to 8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter stock quantity for item %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    int choice;
    do {
        printf("\n--- Inventory Menu ---\n");
        printf("1. Display Stock\n");
        printf("2. Update Stock of an item\n");
        printf("3. Insert a new item\n");
        printf("4. Delete an item\n");
        printf("5. Sort Stock (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStock(stock, n);
                break;
            case 2: {
                int pos, val;
                printf("Enter position to update (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n) {
                    printf("Enter new quantity: ");
                    scanf("%d", &val);
                    stock[pos - 1] = val;
                    printf("Stock updated successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                printStock(stock, n);
                break;
            }
            case 3: {
                int pos, val;
                printf("Enter position to insert new item (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n + 1) {
                    printf("Enter quantity of new item: ");
                    scanf("%d", &val);

                    int *newStock = (int *)malloc((n + 1) * sizeof(int));
                    for (int i = 0, j = 0; i < n + 1; i++) {
                        if (i == pos - 1) {
                            newStock[i] = val;
                        } else {
                            newStock[i] = stock[j++];
                        }
                    }
                    free(stock);
                    stock = newStock;
                    n++;
                    printf("New item inserted successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                printStock(stock, n);
                break;
            }
            case 4: {
                if (n <= 1) {
                    printf("Cannot delete further, stock is empty!\n");
                    break;
                }
                int pos;
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n) {
                    int *newStock = (int *)malloc((n - 1) * sizeof(int));
                    for (int i = 0, j = 0; i < n; i++) {
                        if (i == pos - 1) continue;
                        newStock[j++] = stock[i];
                    }
                    free(stock);
                    stock = newStock;
                    n--;
                    printf("Item deleted successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                printStock(stock, n);
                break;
            }
            case 5: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (*(stock + j) > *(stock + j + 1)) {
                            int temp = *(stock + j);
                            *(stock + j) = *(stock + j + 1);
                            *(stock + j + 1) = temp;
                        }
                    }
                }
                printf("Stock sorted in ascending order!\n");
                printStock(stock, n);
                break;
            }
            case 6:
                printf("Exiting program and freeing memory...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    free(stock);
    stock = NULL;
    return 0;
}