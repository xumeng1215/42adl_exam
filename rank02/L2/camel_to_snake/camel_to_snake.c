#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lowerCamelToSnakeCase(char* input, char* output) {
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++, j++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            if (i > 0) {
                output[j++] = '_';
            }
            output[j] = input[i] + 32; // Convert uppercase to lowercase
        } else {
            output[j] = input[i];
        }
    }
    output[j] = '\0'; // Null-terminate the converted string
}

int main() {
    char input[100];
    printf("Enter a lowerCamelCase string: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from the input string
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Calculate the maximum possible length of the output string
    size_t max_len = strlen(input) + 1; // +1 for the null terminator
    char* output = (char*)malloc(max_len * sizeof(char));
    if (output == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }

    lowerCamelToSnakeCase(input, output);
    printf("The converted snake_case string is: %s\n", output);

    free(output); // Remember to free the allocated memory

    return 0;
}