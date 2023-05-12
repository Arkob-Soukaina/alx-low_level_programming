#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL)
        return 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    char *buffer = (char *)malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        close(fd);
        return 0;
    }

    ssize_t bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        free(buffer);
        close(fd);
        return 0;
    }

    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    free(buffer);
    close(fd);

    if (bytes_written == -1 || bytes_written != bytes_read)
        return 0;

    return bytes_written;
}

