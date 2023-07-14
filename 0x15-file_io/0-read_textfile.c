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
char *b;
ssize_t f;
ssize_t a;
ssize_t c;

f = open(filename, O_RDONLY);
if (f == -1)
return (0);
b = malloc(sizeof(char) * letters);
c = read(f, b, letters);
a = write(STDOUT_FILENO, b, c);

free(b);
close(f);
return (a);
}
