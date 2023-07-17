#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

struct node *header = NULL;

struct node *getnode(int n) {
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("\nMemory allocation failed.");
        _getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = ptrnew->prev = NULL;
    return ptrnew;
}

void insertAtFront() {
    int n;
    struct node *ptrnew;

    printf("\nEnter new number: ");
    scanf_s("%d", &n);
    ptrnew = getnode(n);

    if (header == NULL) {
        header = ptrnew;
        header->next = header->prev = header;
    } else {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        (header->prev)->next = ptrnew;
        header->prev = ptrnew;
        header = ptrnew;
    }
    printf("\nNode inserted at the front.");
}

void insertAtLast() {
    int n;
    struct node *ptrnew;

    printf("\nEnter new number: ");
    scanf_s("%d", &n);
    ptrnew = getnode(n);

    if (header == NULL) {
        header = ptrnew;
        header->next = header->prev = header;
    } else {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        (header->prev)->next = ptrnew;
        header->prev = ptrnew;
    }
    printf("\nNode inserted at the end.");
}

void insertAfter() {
    int n, key;
    struct node *ptrthis, *ptrnew;
    if (header == NULL) {
        printf("\nList is empty.");
        return;
    }
    printf("\nEnter a number after which you want to add a new node: ");
    scanf_s("%d", &key);
    ptrthis = header;
    do {
        if (ptrthis->info == key) {
            printf("\nEnter new node to be inserted: ");
            scanf_s("%d", &n);
            ptrnew = getnode(n);
            ptrnew->prev = ptrthis;
            ptrnew->next = ptrthis->next;
            (ptrthis->next)->prev = ptrnew;
            ptrthis->next = ptrnew;
            printf("\nNode inserted after %d", key);
            return;
        }
        ptrthis = ptrthis->next; // go ahead
    } while (ptrthis != header);
    printf("%d not found in the list.", key);
}

void insertBefore() {
    int n, key;
    struct node *ptrthis, *ptrnew;
    if (header == NULL) {
        printf("\nList is empty.");
        return;
    }
    printf("\nEnter a number before which you want to add a new node: ");
    scanf_s("%d", &key);
    ptrthis = header;
    do {
        if (ptrthis->info == key) {
            printf("\nEnter new node to be inserted: ");
            scanf_s("%d", &n);
            ptrnew = getnode(n);
            ptrnew->prev = ptrthis->prev;
            ptrnew->next = ptrthis;
            (ptrthis->prev)->next = ptrnew;
            ptrthis->prev = ptrnew;
            if (ptrthis == header) {
                header = ptrnew;
            }
            printf("\nNode inserted before %d", key);
            return;
        }
        ptrthis = ptrthis->next; // go ahead
    } while (ptrthis != header);
    printf("%d not found in the list.", key);
}

void removeFromFront() {
    struct node *ptrdel;
    if (header == NULL) {
        printf("\nList is empty.");
    } else {
        ptrdel = header;
        if (ptrdel->next == header) { // Single node in the list
            header = NULL;
        } else {
            header = ptrdel->next;
            (ptrdel->prev)->next = header;
            header->prev = ptrdel->prev;
        }
        free(ptrdel);
        printf("\nNode removed from the front.");
    }
}

void removeFromLast() {
    struct node *ptrdel;
    if (header == NULL) {
        printf("\nList is empty.");
    } else {
        ptrdel = header->prev;
        if (ptrdel == header) { // Single node in the list
            header = NULL;
        } else {
            (ptrdel->prev)->next = header;
            header->prev = ptrdel->prev;
        }
        free(ptrdel);
        printf("\nNode removed from the last.");
    }
}

void removeAny() {
    int key;
    struct node *ptrdel;
    if (header == NULL) {
        printf("\nList is empty.");
    } else {
        printf("\nEnter the node value you want to delete: ");
        scanf_s("%d", &key);
        ptrdel = header;
        do {
            if (ptrdel->info == key) {
                if (ptrdel == header) {
                    removeFromFront();
                } else {
                    (ptrdel->prev)->next = ptrdel->next;
                    (ptrdel->next)->prev = ptrdel->prev;
                    free(ptrdel);
                    printf("\nNode with value %d removed.", key);
                }
                return;
            }
            ptrdel = ptrdel->next; // go ahead
        } while (ptrdel != header);
        printf("%d not found in the list.", key);
    }
}

void forwardDisplay() {
    struct node *ptrthis;
    if (header == NULL) {
        printf("\nList is empty.");
    } else {
        printf("\nList contains: \n");
        ptrthis = header;
        do {
            printf("%d\t", ptrthis->info);
            ptrthis = ptrthis->next;

        } while (ptrthis != header);
    }
}

void backwardDisplay() {
    struct node *ptrthis;
    if (header == NULL) {
        printf("\nList is empty.");
    } else {
        printf("\nList contains: \n");
        ptrthis = header->prev;
        do {
            printf("%d\t", ptrthis->info);
            ptrthis = ptrthis->prev;

        } while (ptrthis != header->prev);
    }
}

int main() {
    char ch;
    do {
        printf("\nEnter your choice: \n1. Insert at front \n2. Insert at end \n");
        printf("3. Insert after \n4. Insert before \n5. Remove from the front \n");
        printf("6. Remove from the last \n7. Remove any node \n8. Display Forward\n");
        printf("9. Display backward \nX. Exit\n");
        ch = _getche();
        switch (ch) {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtLast();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            insertBefore();
            break;
        case '5':
            removeFromFront();
            break;
        case '6':
            removeFromLast();
            break;
        case '7':
            removeAny();
            break;
        case '8':
            forwardDisplay();
            break;
        case '9':
            backwardDisplay();
            break;
        case 'x':
        case 'X':
            exit(0);
            break;
        default:
            printf("\nInvalid choice.");
        }
    } while (1);

    return 0;
}

