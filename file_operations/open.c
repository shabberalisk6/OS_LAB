#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char filename[50];
    int fileDescriptor;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Simulate the open system call
    fileDescriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Print the file descriptor
    printf("File opened successfully with file descriptor: %d\n", fileDescriptor);

    // Close the file
    close(fileDescriptor);

    return 0;
}
