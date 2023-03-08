#include <stdio.h>

int main() {
    int characters = 0;
    int words = 0;
    int lines = 0;
    int lastCharWasSpace = 1; // To keep track of whether the last character was a space

    printf("Enter characters, press 'q' to quit: \n");

    int c = getchar();
    while (c != 'q') {
        ++characters;

        if (c == '\n') {
            ++lines;
        } else if (c == ' ') {
            lastCharWasSpace = 1;
        } else if (lastCharWasSpace) {
            ++words;
            lastCharWasSpace = 0;
        }

        c = getchar();
    }

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
