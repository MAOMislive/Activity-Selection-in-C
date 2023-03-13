#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// define a struct to represent an item
typedef struct {
    float value;
    float weight;
    float ratio;
} Item;

int main() {
    int n, W;
    Item items[MAX_ITEMS]; // create an array of Item structs
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the value and weight of each item:\n");
    // loop through the items and store their value, weight, and ratio
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight; // calculate the ratio
    }
    // sort the items in descending order of their ratio
    Item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[i].ratio) {
                // swap the items
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    // fill the knapsack with items until it's full
    float totalValue = 0;
    int i = 0;
    while (W > 0 && i < n) {
        if (items[i].weight <= W) {
            // take the whole item
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            // take a fraction of the item
            totalValue += W * items[i].ratio;
            W = 0;
        }
        i++;
    }
    printf("Total value of the items in the knapsack is: %.2f\n", totalValue);
    return 0;
}
