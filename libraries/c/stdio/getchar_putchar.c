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

// IMPORTANT:
// getchar() must be stored in an int, not a char,
// because it needs to represent all unsigned char values plus EOF.

long:
- long is guaranteed by the C standard to be at least 32 bits.
- long is guaranteed to be no smaller than int.
- On many modern 64-bit Unix systems, long is 64 bits.
- On Windows (LLP64), long is 32 bits even on 64-bit systems.
*/

#include <stdio.h>

void copy_file(void) {
    int c;
    // in C, every assignment is an expression whose value is LHS
    // () around the assignment is necessary due to != having higher precedence than =
    while ((c = getchar()) != EOF)
        putchar(c);

    printf("Loop exited!\n");
}

void character_counting(void) {
    // NOTE: \n is counted too
    long count;
    count = 0;
    while (getchar() != EOF)
        count++;
    printf("%ld\n", count);
}

void character_counting_for(void) {
    // double is used here only to demonstrate an alternative counting approach.
    // Note: double cannot represent all integers exactly for very large values.
    // C89, double = %f. C99+, double = %lf = %f
    double count;
    for (count = 0; getchar() != EOF; count++);
    printf("%.0f\n", count);
}

void line_counting(void) {
    // standard library ensures that an input text stream appears as a sequence of
    // lines, each terminated by a newline. Hence to count lines, just count newlines.
    int c, newline_count;
    newline_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            newline_count++;
    }
    printf("%d\n", newline_count);
}

void ex_1_8(void) {
    int c, nl, tab, blank;

    nl = tab = blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blank;
        else if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++tab;
    }

    printf("blanks: %d\n", blank);
    printf("tabs: %d\n", tab);
    printf("newlines: %d\n", nl);
}

void ex_1_9(void) {
    int c;
    int prev_space = 0;  // boolean

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!prev_space)
                putchar(c);
            prev_space = 1;
        } else {
            putchar(c);
            prev_space = 0;
        }
    }
}

void ex_1_10(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}

int main() {
    // copy_file();
    // character_counting();
    // line_counting();
    // ex_1_8();
    ex_1_10();
    return 0;
}
