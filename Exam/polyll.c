#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

// Create a new term node
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Insert term in ascending order by exponent
void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*head == NULL || (*head)->exp > exp) {
        // Insert at beginning
        newTerm->next = *head;
        *head = newTerm;
        return;
    }
    struct Term* temp = *head;
    while (temp->next != NULL && temp->next->exp < exp) {
        temp = temp->next;
    }
    if (temp->exp == exp) {
        // If term with same exponent exists, add coefficients
        temp->coeff += coeff;
        free(newTerm);
    } else if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newTerm);
    } else {
        newTerm->next = temp->next;
        temp->next = newTerm;
    }
}

// Display the polynomial
void displayPolynomial(struct Term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Term* temp = head;
    while (temp != NULL) {
        if (temp->coeff != 0) {
            printf("%dx^%d", temp->coeff, temp->exp);
            if (temp->next != NULL && temp->next->coeff >= 0)
                printf(" + ");
            else if (temp->next != NULL)
                printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Sample main to demonstrate
int main() {
    struct Term* poly = NULL;

    insertTerm(&poly, 5, 2);  // 5x^2
    insertTerm(&poly, 3, 0);  // 3
    insertTerm(&poly, 4, 1);  // 4x
    insertTerm(&poly, 2, 2);  // Adds to 5x^2, making 7x^2

    displayPolynomial(poly);  // Output: 3x^0 + 4x^1 + 7x^2

    return 0;
}
