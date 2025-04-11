#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   if (argc != 4) {
       printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
       return 1;
   }

   int number1, number2, result;
   char operator = argv[2][0];

   // Convert the first and third parameters to integers
   number1 = strtol(argv[1], NULL, 10);
   number2 = strtol(argv[3], NULL, 10);

   // Perform the arithmetic operation
   if (operator == '+') {
       result = number1 + number2;
   } else if (operator == '-') {
       result = number1 - number2;
   } else if (operator == '*') {
       result = number1 * number2;
   } else if (operator == '/') {
       if (number2 == 0) {
           printf("Error: Division by zero is not allowed.\n");
           return 1;
       }
       result = number1 / number2;
   } else if (operator == '%') {
       if (number2 == 0) {
           printf("Error: Modulo by zero is not allowed.\n");
           return 1;
       }
       result = number1 % number2;
   } 
   else {
       printf("Invalid operator: %c\n", operator);
       return 1;
   }

   // Print the result
   printf("Result: %d\n", result);
   return 0;
}