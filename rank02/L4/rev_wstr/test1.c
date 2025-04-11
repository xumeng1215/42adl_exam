#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

void add_word(Node **head, char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->word = strdup(word); // Create a copy of the word
    if (new_node->word == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head->word); // Free the word
        free(head); // Free the node
        head = next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char *input_string = strdup(argv[1]); // Create a copy of the input string
    if (input_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    char *current_word = strtok(input_string, " \t");
    Node *head = NULL;
    while (current_word != NULL) {
        add_word(&head, current_word);
        current_word = strtok(NULL, " \t");
    }
    print_list(head);
    printf("\n");
    free_list(head); // Free the linked list
    free(input_string); // Free the input string
    return 0;
}