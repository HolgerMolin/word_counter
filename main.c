#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc > 2) {
        printf("Too many arguments given; only filename is supported\n");
        return 1;
    }

    if (argc == 1) {
        printf("File name not given\n");
        return 1;
    }

    FILE *file;

    file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Could not open the file.\n");
        return 1; // Return an error code
    }

    char line[256];

    int counter = 0;

     while (fgets(line, sizeof(line), file) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                counter += 1;
            }
        }
    }

    printf("%d\n", counter);

    fclose(file);

    return 0;
}