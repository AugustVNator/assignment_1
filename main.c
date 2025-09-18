#include <stdlib.h>

#include "io.h"

#include <unistd.h>
/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        write_int(temp->data);
        //Undgå at skrive komma, hvis kun et tal
        if (temp->next != NULL) {
            write_char(',');
        }
        temp = temp->next;
    }
    write_char(';');
    free(temp);
}

ssize_t flushInputBuffer() {
    char buf[1000];
    size_t nbytes = sizeof(buf);
    ssize_t bytes_read = read(STDIN_FILENO, buf, nbytes);
    // Returnér bytes_read for at undgå advarsel for ubrugt variabel
    return bytes_read;
}
int main() {

    Node *head;
    int count = 0;

    // cmd bliver initialiseret her, så while do-while
    // kan "se" ændringerne
    char cmd;

    do {
        cmd = read_char();

        if (cmd == 'a') {
            insertAtEnd(&head, count);
            count++;
        } else if (cmd == 'b') {
            count++;
        } else if (cmd == 'c') {
            deleteFromEnd(&head);
            count++;
        }

    } while (cmd == 'a' || cmd == 'b' || cmd == 'c');

    printLinkedList(head);


    // Vi tjekker om cmd er EOF, hvilket ellers ville
    // fryse programmet i flushInputBuffer funktionen
    if (cmd != EOF) {
        flushInputBuffer(); // Vi sikrer os, at inputbufferen ikke påvirker vores terminal
    }

    return 0;
}


