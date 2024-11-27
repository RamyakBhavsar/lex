// AIM: Efficient Memory Allocation in Firmware Development:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

// Define the structure for items
typedef struct {
    int id;
    char name[20];
} Item;

// Static memory allocation
Item static_items[MAX_ITEMS] = {
    {1, "Item 1"},
    {2, "Item 2"},
    {3, "Item 3"},
    {4, "Item 4"},
    {5, "Item 5"}
};

// Function to allocate memory dynamically
Item* allocate_dynamic_items(int count) {
    Item* dynamic_items = (Item*)malloc(count * sizeof(Item));
    if (!dynamic_items) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    return dynamic_items;
}

// Function to free dynamically allocated memory
void free_dynamic_items(Item* items) {
    free(items);
}

int main() {
    printf("Static Items:\n");
    // Display static items
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("ID: %d, Name: %s\n", static_items[i].id, static_items[i].name);
    }

    // Define the number of additional items for dynamic allocation
    int additional_count = 3;

    // Allocate memory dynamically for additional items
    Item* dynamic_items = allocate_dynamic_items(additional_count);
    if (dynamic_items) {
        // Initialize the dynamically allocated items
        for (int i = 0; i < additional_count; i++) {
            dynamic_items[i].id = MAX_ITEMS + i + 1;
            snprintf(dynamic_items[i].name, sizeof(dynamic_items[i].name), "Dynamic Item %d", i + 1);
        }

        // Display the dynamically allocated items
        printf("\nDynamic Items:\n");
        for (int i = 0; i < additional_count; i++) {
            printf("ID: %d, Name: %s\n", dynamic_items[i].id, dynamic_items[i].name);
        }

        // Free the dynamically allocated memory
        free_dynamic_items(dynamic_items);
    }

    return 0;
}