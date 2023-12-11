#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>  // Include the header file for lseek system call

#define BUFFER_SIZE 1024

int main() {
    char filename[50];
    int fileDescriptor;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Simulate the open system call
    fileDescriptor = open(filename, O_RDWR);

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

    // Print the initial read data
    printf("Initial data read from the file:\n%s\n", buffer);

    // Use lseek to move the file pointer to the beginning
    off_t newPosition = lseek(fileDescriptor, 3, SEEK_SET);

    if (newPosition == -1) {
        perror("Error seeking file");
        close(fileDescriptor);
        return 1;
    }

    // Read data again from the beginning
    bytesRead = read(fileDescriptor, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fileDescriptor);
        return 1;
    }

    // Print the data read after seeking to the beginning
    printf("Data read from the beginning after seeking:\n%s\n", buffer);

    // Close the file
    close(fileDescriptor);

    return 0;
}
