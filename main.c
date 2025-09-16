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

typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

static void stack_init(Stack *stack){
    //Måske skal data initialiseres på en anden måde
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 1;
}

static void stack_push(Stack *stack) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
    }
}

static void stack_pop(Stack *stack) {
    if (stack->size > 0) {
        stack->size--;
    }
}

int main() {

    Stack stack;
    stack_init(&stack);
    int count = 0;

    const char msg[] = "\nInput a string:";
    write(1, msg, sizeof(msg) - 1);

    for (;;) {
        char cmd = read_char();

        if (cmd == 'a') {
            stack_push(&stack);
            // De to linjer under skal måske ud for loppet og ind i stack_push
            stack.data[stack.size] = count;
            stack.size == stack.size + 1;
            count++;
        } else if (cmd == 'b') {
            count++;
        } else if (cmd == 'c') {
            stack_pop(&stack);
            count++;
        } else {
            write_string("Count: ");
            write_int(count);
            write_string("\nCollection: ");
            for (int i = 0; i < stack.size; ++i) {
                write_char(stack.data[i]);
                write_string(", ");
            }
        }
    }
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

