#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int silent_mode = 0;
    char *extension;
    char executable_name[20] = "program";
    char command[1024];

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--silent") == 0) {
            silent_mode = 1;
        }
    }

    // Extract file extension
    char *dot = strrchr(argv[1], '.');
    if (dot) {
        extension = dot + 1;
    } else {
        extension = "";
    }

    // Determine the compiler required for the file
    if (!silent_mode) {
        printf("Determining the compiler required for the file: %s\n", argv[1]);
    }

    // Compile based on file extension
    if (strcmp(extension, "c") == 0) {
        if (!silent_mode) {
            printf("Determined file type: C\n");
            printf("Compiling C program...\n");
        }
        sprintf(command, "gcc %s -o %s", argv[1], executable_name);
        system(command);
    } else if (strcmp(extension, "cpp") == 0) {
        if (!silent_mode) {
            printf("Determined file type: C++\n");
            printf("Compiling C++ program...\n");
        }
        sprintf(command, "g++ %s -o %s", argv[1], executable_name);
        system(command);
    } else if (strcmp(extension, "java") == 0) {
        if (!silent_mode) {
            printf("Determined file type: Java\n");
            printf("Compiling Java program...\n");
        }
        sprintf(command, "javac %s", argv[1]);
        system(command);
        strcpy(executable_name, argv[1]);
        *strrchr(executable_name, '.') = '\0'; // Remove extension
    } else {
        if (!silent_mode) {
            printf("Error: Unsupported file type, cannot autocompile. Please compile and run manually.\n");
        }
        return 1;
    }

    // Run the compiled program
    if (!silent_mode) {
        printf("Running the program...\n");
    }
    if (strcmp(extension, "java") == 0) {
        sprintf(command, "java %s", executable_name);
    } else {
        sprintf(command, "./%s", executable_name);
    }
    system(command);

    return 0;
}
