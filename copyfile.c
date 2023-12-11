#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

void copyFileStandardIO(const char *sourceFileName, const char *destinationFileName) {
    FILE *sourceFile = fopen(sourceFileName, "rb");
    FILE *destinationFile = fopen(destinationFileName, "wb");

    if (sourceFile == NULL || destinationFile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}

void copyFileSystemCalls(const char *sourceFileName, const char *destinationFileName) {
    int sourceFile = open(sourceFileName, O_RDONLY);
    int destinationFile = open(destinationFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IRUSR  );

    if (sourceFile == -1 || destinationFile == -1) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(sourceFile, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destinationFile, buffer, bytesRead);

        if (bytesWritten != bytesRead) {
            perror("Error writing to file");
            exit(EXIT_FAILURE);
        }
    }

    close(sourceFile);
    close(destinationFile);
}

int main() {
    char sourceFileName[256];
    char destinationFileName[256];

    // Get source file name from user
    printf("Enter source file name: ");
    scanf("%255s", sourceFileName);

    // Get destination file name from user
    printf("Enter destination file name: ");
    scanf("%255s", destinationFileName);

    // Using Standard I/O functions
    copyFileStandardIO(sourceFileName, destinationFileName);
    printf("File copied using Standard I/O functions.\n");

    // Using System Calls
    copyFileSystemCalls(sourceFileName, destinationFileName);
    printf("File copied using System Calls.\n");

    return EXIT_SUCCESS;
}
