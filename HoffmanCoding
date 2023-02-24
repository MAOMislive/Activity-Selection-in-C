#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

int main()
{
    int n, W;
    float items[MAX_ITEMS][3];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &items[i][0], &items[i][1]);
        items[i][2] = items[i][0] / items[i][1];  // store ratio
    }
    // sort items in descending order of their ratio
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (items[i][2] < items[j][2])
            {
                float temp_ratio = items[i][2];
                float temp_value = items[i][0];
                float temp_weight = items[i][1];
                items[i][2] = items[j][2];
                items[i][0] = items[j][0];
                items[i][1] = items[j][1];
                items[j][2] = temp_ratio;
                items[j][0] = temp_value;
                items[j][1] = temp_weight;
            }
        }
    }
    float P = 0.0;
    // loop through items and add to knapsack
    for (int i = 0; i < n; i++)
    {
        if (W >= items[i][1])
        {
            // add entire item to knapsack
            P += items[i][0];
            W -= items[i][1];
        }
        else
        {
            // add a fraction of the item to knapsack
            float fraction = (float) W / items[i][1];
            P += fraction * items[i][0];
            W = 0;
        }
        if (W == 0)
        {
            break;
        }
    }
    printf("Total value of items in the knapsack: %f\n", P);
    return 0;
}
