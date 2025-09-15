#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[20];
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *current = NULL;
    int choice;
    char url[20];
    for (;;) {
        printf("\nMenu:\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter URL: ");
            scanf("%19s", url);

            // Create new node
            struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            strcpy(newNode->url, url);
            newNode->prev = NULL;
            newNode->next = NULL;

            if (current == NULL) {
                // First page visited
                current = newNode;
            } else {
                // Remove forward history using for loop
                for (struct Node *temp = current->next; temp != NULL;) {
                    struct Node *nextNode = temp->next;
                    free(temp);
                    temp = nextNode;
                }
                current->next = NULL;

                // Insert new node after current
                current->next = newNode;
                newNode->prev = current;
                current = newNode;
            }
            printf("Visited %s\n", url);
        }
        else if (choice == 2) {
            if (current != NULL && current->prev != NULL) {
                current = current->prev;
                printf("Went back to %s\n", current->url);
            } else {
                printf("No previous page\n");
            }
        }
        else if (choice == 3) {
            if (current != NULL && current->next != NULL) {
                current = current->next;
                printf("Went forward to %s\n", current->url);
            } else {
                printf("No next page\n");
            }
        }
        else if (choice == 4) {
            if (current != NULL) {
                printf("Current page is %s\n", current->url);
            } else {
                printf("No page visited yet\n");
            }
        }
        else if (choice == 5) {
            // Move to start of list using for loop
            for (; current != NULL && current->prev != NULL; current = current->prev);

            // Free all nodes from start using for loop
            for (; current != NULL;) {
                struct Node *temp = current;
                current = current->next;
                free(temp);
            }

            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
