#include <stdio.h>

#define MAX_LINES 10

int main(int argc, char* argv[]) {
    // Check if a filename is provided as an argument
    if (argc < 2) {
        printf("Error: Please provide a filename as an argument.\n");
        return -1;
    }

    char buffer[MAX_LINES][1000]; // buffer to store the last 10 lines
    int bufferIndex = 0; // current index of the buffer
    int c; // variable to store the current character read from the file
    int lineIndex = 0; // current index of the line being read
    int lineCount = 0; // total number of lines read
    FILE* file = fopen(argv[1], "r"); // open the file for reading

    // Check if the file was successfully opened
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Read the file one character at a time
    while ((c = getc(file)) != EOF) {
        // Check if the current character is a newline
        if (c == '\n') {
            buffer[bufferIndex][lineIndex] = '\0'; // add a null character to the end of the line
            bufferIndex = (bufferIndex + 1) % MAX_LINES; // move to the next index in the buffer
            lineIndex = 0; // reset the line index
            lineCount++; // increment the line count
        } else {
            buffer[bufferIndex][lineIndex] = c; // add the character to the current line
            lineIndex++; // move to the next index in the line
        }
    }

    // Print the last 10 lines
    int start = (lineCount > MAX_LINES) ? (bufferIndex + MAX_LINES - 1) % MAX_LINES : 0;
    for (int i = 0; i < MAX_LINES; i++) {
        int index = (start + i) % MAX_LINES;
        printf("%s\n", buffer[index]);
    }

    fclose(file); // close the file
    return 0;
}
