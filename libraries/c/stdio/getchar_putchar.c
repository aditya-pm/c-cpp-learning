/*
char type recap:
- char is at least 8 bits = at least 256 distinct values.
- char: may be signed or unsigned (implementation-defined).
- signed char: guaranteed range -128 to 127.
- unsigned char: guaranteed range 0 to 255.

ASCII:
- Standard ASCII is 7-bit.
- Valid ASCII values range from 0 to 127.

Why EOF cannot be stored in char:
- char may or may not support negative values.
- EOF is a negative integer constant (commonly -1).
- If stored in a char, EOF may wrap (e.g., -1 -> 255).
- int is guaranteed by the C standard to represent negative values.
- Therefore, functions that return EOF must be stored in int.
- int is guaranteed to be at least 16 bits (most modern systems use 32 bits).

Text streams:
- A text stream is a sequence of characters divided into lines.
- Each line ends with a newline character.

getchar():
- Reads the next character from stdin.
- Returns the character as an unsigned char converted to int, or EOF.

putchar(c):
- Writes the character corresponding to value c to stdout.

EOF:
- Usually a negative value so it does not conflict with any valid unsigned char value (0–255).
  Actually value of EOF does not matter, it is implementation defined.
- Returned by getchar() when no more input is available.
- On terminals, end-of-input is signaled by:
  - Ctrl+D (Linux/macOS)
  - Ctrl+Z then Enter (Windows)
*/

#include <stdio.h>

void copy_file() {
    int c;
    // in C, every assignment is an expression whose value is LHS
    // () around the assignment is necessary due to != having higher precedence than =
    while ((c = getchar()) != EOF)
        putchar(c);

    printf("Loop exited!\n");
}

int main() {
    copy_file();

    return 0;
}
