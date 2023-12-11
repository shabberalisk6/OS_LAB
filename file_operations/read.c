#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>  // Include the header file for read system call

#define BUFFER_SIZE 1024

int main() {
    char filename[50];
    int fileDescriptor;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Simulate the open system call
    fileDescriptor = open(filename, O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read data from the file using the read system call
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fileDescriptor);
        return 1;
    }

    // Print the read data
    printf("Data read from the file:\n%s\n", buffer);

    // Close the file
    close(fileDescriptor);

    return 0;
}
