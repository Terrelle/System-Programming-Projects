#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char countryName[100]; // to store the search string entered by the user
    char line[1000]; // to store a line read from the file
    char word[1000]; // to store a word read from the line
    int i, j, len;

    // Check if filename is provided as command-line argument
    if (argc < 2) {
        printf("Error: Please provide a filename as command-line argument.\n");
        return 1;
    }

    // Prompt user for search string
    printf("Enter search string: ");
    scanf("%s", countryName);

    // Open file
    FILE *countryFile = fopen(argv[1], "r");

    // Check if file exists
    if (countryFile == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // reads the text file one line at a time using the fgets function.
    while (fgets(line, sizeof(line), countryFile) != NULL) // reads up to sizeof(line) characters from the file, and stores them in the line array
    {
        len = strlen(line); // limit the for loop to the length of the line.
        j = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0') 
            /*
             checks if the current character is a space, newline, or null character. 
            If it is, the current word is considered to be finished. */
            
            {
                word[j] = '\0'; // sets the last character of the current word to the null character, indicating the end of the string.
                if (strncmp(word, countryName, strlen(countryName)) == 0) // compares the current word with the search string entered by the user.
                {
                    printf("%s ", word); // prints the current word on the screen.
                }
                j = 0; // resets to allow next word to be stored in array
            } else {
                word[j] = line[i];
                j++;
            }
        }
    }
    printf("\n");
    // Close file
    fclose(countryFile);
    return 0;
}
