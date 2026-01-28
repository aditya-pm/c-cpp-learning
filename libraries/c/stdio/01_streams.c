/*
    01_streams.c
    --------------------------------
    Demonstrates the concept of streams in C using stdio.h.

    Key ideas shown in this file:
    1. stdin, stdout, stderr are FILE* streams
    2. printf is just fprintf(stdout, ...)
    3. stderr is separate from stdout
    4. Stream redirection works without code changes
    5. Streams may be buffered or unbuffered

    This file is NOT about:
    - scanf details
    - file I/O (fopen)
    - parsing input

    Compile:
        gcc 01_streams.c -o streams

    Try running:
        ./streams
        ./streams > out.txt
        ./streams 2> err.txt
*/

#include <stdio.h>
#include <unistd.h>  // for sleep()

int main(void) {
    /* --------------------------------------------------
       1. stdin, stdout, stderr are FILE* pointers
       -------------------------------------------------- */

    printf("Addresses of standard streams:\n");
    printf("  stdin  : %p\n", (void*)stdin);
    printf("  stdout : %p\n", (void*)stdout);
    printf("  stderr : %p\n", (void*)stderr);

    printf("\n");

    /* --------------------------------------------------
       2. printf == fprintf(stdout, ...)
       -------------------------------------------------- */

    printf("This is printed using printf\n");
    fprintf(stdout, "This is printed using fprintf(stdout, ...)\n");

    printf("\n");

    /* --------------------------------------------------
       3. stderr is a separate stream
       -------------------------------------------------- */

    fprintf(stderr, "This is an error message (stderr)\n");

    /*
        Try:
            ./streams > out.txt

        Observation:
        - stdout goes into out.txt
        - stderr still appears in the terminal
    */

    printf("\n");

    /* --------------------------------------------------
       4. Redirection works without code changes
       -------------------------------------------------- */

    printf("This line goes to stdout\n");
    fprintf(stderr, "This line goes to stderr\n");

    /*
        Try:
            ./streams > output.txt 2> error.txt

        Your program code does not change.
        Only the streams are redirected.
    */

    printf("\n");

    /* --------------------------------------------------
       5. Buffering behavior (observable difference)
       -------------------------------------------------- */

    fprintf(stdout, "stdout message (may be buffered)...");
    sleep(3);  // pause before newline
    fprintf(stdout, "done\n");

    fprintf(stderr, "stderr message (usually unbuffered)\n");

    /*
        Observation:
        - stdout may not appear immediately
        - stderr usually appears instantly

        This is why stderr is preferred for errors/logs.
    */

    return 0;
}
