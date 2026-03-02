#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
};

// Create new node
Node* createNode(int c, int p) {
    Node* newNode = new Node;
    newNode->coeff = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending order of power
void insertTerm(Node*& head, int c, int p) {
    Node* newNode = createNode(c,p);

    if(head == NULL || head->power < p) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next && temp->next->power > p)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display polynomial
void display(Node* head) {
    while(head) {
        cout << head->coeff << "x^" << head->power;
        if(head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Add two polynomials
Node* addPolynomial(Node* p1, Node* p2) {
    Node* result = NULL;

    while(p1 && p2) {
        if(p1->power > p2->power) {
            insertTerm(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else if(p1->power < p2->power) {
            insertTerm(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
        else {
            insertTerm(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while(p1) {
        insertTerm(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while(p2) {
        insertTerm(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node *poly1=NULL, *poly2=NULL;

    // Polynomial 1 → 5x^2 + 4x + 2
    insertTerm(poly1,5,2);
    insertTerm(poly1,4,1);
    insertTerm(poly1,2,0);

    // Polynomial 2 → 3x^3 + 2x^2 + 1
    insertTerm(poly2,3,3);
    insertTerm(poly2,2,2);
    insertTerm(poly2,1,0);

    cout<<"Polynomial 1:\n";
    display(poly1);

    cout<<"Polynomial 2:\n";
    display(poly2);

    Node* sum = addPolynomial(poly1, poly2);

    cout<<"Sum of Polynomials:\n";
    display(sum);
}