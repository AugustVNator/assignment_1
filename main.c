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

struct Node {
    int data;
    struct Node *next;
} Node;

// static void stack_init(Stack *stack){
//     //Måske skal data initialiseres på en anden måde
//     stack->data = NULL;
//     stack->size = 0;
//     stack->capacity = 1;
// }
//
// static void stack_push(Stack *stack) {
//     if (stack->size == stack->capacity) {
//         stack->capacity *= 2;
//     }
// }

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
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

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    if (temp->next == NULL) {
        write_int(temp->data);
        return;
    }
    while (temp != NULL) {
        write_int(temp->data);
        if (temp->next != NULL) {
            write_char(',');
        }

        temp = temp->next;
    }
}

// static void stack_pop(Stack *stack) {
//     if (stack->size > 0) {
//         stack->size--;
//     }
// }

int main() {

    //Stack stack;
    //stack_init(&stack);
    struct Node *head;
    int count = 0;

    // const char msg[] = "\nInput a string:";
    // write(1, msg, sizeof(msg) - 1);

    write_string("Input a string:\n");

    char cmd;
    do {
        cmd = read_char();


        if (cmd == 'a') {
            write_string("Im here a\n");
            //stack_push(&stack);
            // De to linjer under skal måske ud for loppet og ind i stack_push
            //stack.data[stack.size] = count;
            insertAtEnd(&head, count);
            count++;
        } else if (cmd == 'b') {
            write_string("Im here b\n");
            count++;
        } else if (cmd == 'c') {
            write_string("Im here c\n");
            deleteFromEnd(&head);
            count++;
        }

    } while (cmd == 'a' || cmd == 'b' || cmd == 'c');

        write_string("Count: ");
        write_int(count);
        write_string("\nCollection: ");
        printLinkedList(head);
        // for (int i = 0; i < stack.size; ++i) {
        //     write_int(stack.data[i]);
        //     write_string(", ");
        // }
    return 0;
    }



  /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *  
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/

