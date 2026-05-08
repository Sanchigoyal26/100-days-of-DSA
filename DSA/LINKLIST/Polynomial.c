#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

/* Create new node */
struct node* create_node(int coeff, int exp)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    return newnode;
}

/* Insert at end */
struct node* insert_end(struct node *head, int coeff, int exp)
{
    struct node *newnode, *temp;

    newnode = create_node(coeff, exp);

    if(head == NULL)
        return newnode;

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

/* Display polynomial */
void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if(head->next != NULL)
            printf(" + ");

        head = head->next;
    }
    printf("\n");
}

/* Add two polynomials */
struct node* add_polynomials(struct node *p, struct node *q)
{
    struct node *result = NULL;

    while(p != NULL && q != NULL)
    {
        /* Same exponent → add coefficients */
        if(p->exp == q->exp)
        {
            result = insert_end(result, p->coeff + q->coeff, p->exp);
            p = p->next;
            q = q->next;
        }
        /* Higher exponent → copy term */
        else if(p->exp > q->exp)
        {
            result = insert_end(result, p->coeff, p->exp);
            p = p->next;
        }
        else
        {
            result = insert_end(result, q->coeff, q->exp);
            q = q->next;
        }
    }

    /* Copy remaining terms */
    while(p != NULL)
    {
        result = insert_end(result, p->coeff, p->exp);
        p = p->next;
    }

    while(q != NULL)
    {
        result = insert_end(result, q->coeff, q->exp);
        q = q->next;
    }

    return result;
}

/* Main */
int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *result = NULL;

    /* Polynomial 1 → 5x^3 + 2x^2 + 7 */
    poly1 = insert_end(poly1, 5, 3);
    poly1 = insert_end(poly1, 2, 2);
    poly1 = insert_end(poly1, 7, 0);

    /* Polynomial 2 → 3x^3 + 4x + 8 */
    poly2 = insert_end(poly2, 3, 3);
    poly2 = insert_end(poly2, 4, 1);
    poly2 = insert_end(poly2, 8, 0);

    printf("Polynomial 1:\n");
    display(poly1);

    printf("Polynomial 2:\n");
    display(poly2);

    result = add_polynomials(poly1, poly2);

    printf("Resultant Polynomial:\n");
    display(result);

    return 0;
}