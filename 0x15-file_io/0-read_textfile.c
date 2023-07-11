#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - text file that print STDOUT
 * @filename: Name of a text file
 * @letters: number of letters
 * Return: Number of bytes 0 when function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int f;
ssize_t byt;
char buf[READ_BUF_SIZE * 8];

if (!filename || !letters)
return (0);
f = open(filename, O_RDONLY);
if (f == -1)
return (0);
byt = read(f, &buf[0], letters);
byt = write(STDOUT_FILENO, &buf[0], byt);
close(f);
return (byt);
}
