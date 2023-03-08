#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int cap = 1000; 
    int begin = atoi(argv[1]); // convert beginning of range to integer
    int end = atoi(argv[2]);
    FILE *file1 = fopen("countries.txt", "r");

    int currentLine = 1; // keep track of current line its reading
    
    if (argc < 3) {
        printf("Error: Not enough arguments.\n");
        return -1;
    }
    


    if (file1 == NULL) {
        printf("Error: Can't open file.\n");
        return -1;
    }
    char *line = NULL;
    size_t len = 0;
    int read;

    while ((read = getline(&line, &len, file1)) != -1) {
        if (currentLine >= begin && currentLine <= end) {
            printf("%s", line);
        }
        currentLine++;
    }
    fclose(file1);
    free(line);
    return 0;
}
