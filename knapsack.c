#include <stdio.h>

#define MAX_ITEMS 100


struct Item {
    int weight;
    int value;
};


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsack(struct Item items[], int n, int capacity) {
    
    if (n == 0 || capacity == 0)
        return 0;

    
    if (items[n - 1].weight > capacity)
        return knapsack(items, n - 1, capacity);

    else
        return max(items[n - 1].value + knapsack(items, n - 1, capacity - items[n - 1].weight),
                   knapsack(items, n - 1, capacity));
}

int main() {
    int n; 
    int capacity; 
    struct Item items[MAX_ITEMS];


    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    
    int max_value = knapsack(items, n, capacity);
    printf("The maximum value that can be obtained is: %d\n", max_value);

    return 0;
}
