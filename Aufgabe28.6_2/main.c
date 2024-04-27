#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für ein Element der Liste
struct Node {
    char name[50];
    struct Node *next;
};

// Funktion zum Einfügen eines Elements in eine Liste
void insert(struct Node **head, char *name) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL || strcmp((*head)->name, name) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL && strcmp(current->next->name, name) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Funktion zum Zusammenführen zweier Listen zu einer gemischten Liste
struct Node *merge(struct Node *list1, struct Node *list2) {
    struct Node *mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (strcmp(list1->name, list2->name) <= 0) {
            insert(&mergedList, list1->name);
            list1 = list1->next;
        } else {
            insert(&mergedList, list2->name);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        insert(&mergedList, list1->name);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        insert(&mergedList, list2->name);
        list2 = list2->next;
    }

    return mergedList;
}

// Funktion zum Ausgeben einer Liste
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Hauptfunktion
int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    char name[50];
    int listChoice;

    // Einlesen von Namen in die Listen
    printf("Name: ");
    while (fgets(name, sizeof(name), stdin) && strcmp(name, "\n") != 0) {
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        do{
            printf("Welche Liste (1 oder 2): ");
            scanf("%d", &listChoice);
            printf("\n");
        }while(listChoice != 1 && listChoice != 2);

        getchar(); // Consume newline character after scanf

        if (listChoice == 1) {
            insert(&list1, name);
        }
        else{
            insert(&list2, name);
        }
        printf("Name: ");
    }

    // Zusammenführen der Listen zu einer gemischten Liste
    struct Node *mixedList = merge(list1, list2);

    // Ausgabe der einzelnen Listen und der gemischten Liste
    printf("\n....1. Liste.........\n");
    printList(list1);
    printf("....Listenende.....\n");

    printf("\n....2. Liste.........\n");
    printList(list2);
    printf("....Listenende.....\n");

    printf("\n....Gemischte Liste....\n");
    printList(mixedList);
    printf("....Listenende.....\n");

    // Speicher freigeben
    struct Node *temp;
    while (list1 != NULL) {
        temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        temp = list2;
        list2 = list2->next;
        free(temp);
    }
    while (mixedList != NULL) {
        temp = mixedList;
        mixedList = mixedList->next;
        free(temp);
    }

    return 0;
}
