#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - text file that print STDOUT
 * @filename: Name of a text file
 * @letters: number of letters
 * Return: Number of bytes 0 when function fails or filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t a, b, c;
char *buffer;

if (filename == NULL)
return (0);
buffer = malloc(sizeof(char) * letters);

if (buffer == NULL)
return (0);

a = open(filename, O_RDONLY);
b = read(a, buffer, letters);
c = write(STDOUT_FILENO, buffer, b);

if (a == -1 || b == -1 || c == -1 || c != b)
{
free(buffer);
return (0);
}
free(buffer);
close(a);

return (c);
}
