#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
struct Node* insert(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
void display(struct Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}
struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum)
                result = insert(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main() {
    struct Node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int n, coeff, exp;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        p1 = insert(p1, coeff, exp);
    }
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        p2 = insert(p2, coeff, exp);
    }
    printf("\nFirst Polynomial: ");
    display(p1);
    printf("Second Polynomial: ");
    display(p2);
    sum = add(p1, p2);
    printf("Sum of Polynomials: ");
    display(sum);
    return 0;
}
