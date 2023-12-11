#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>  // Include the header file for write system call
#include <string.h>
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

    // Write data to the file using the write system call
    const char *data = "Hello, this is a test!\n";
    ssize_t bytesWritten = write(fileDescriptor, data, strlen(data));

    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }

    printf("Data written successfully to the file. Number of bytes written: %zd\n", bytesWritten);

    // Close the file
    close(fileDescriptor);

    return 0;
}
