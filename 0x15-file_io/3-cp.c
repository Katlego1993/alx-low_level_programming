#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Copies content of a file to another file
 * @argc: Number of arguments
 * @argv: an array of arguments
 * Return: 0 on success
 *
 * Description : if arguments count incorrect -exit code 97
 * if file does not exit or cannot be read -exit code 98
 * if file cannot be created or written -exit code 99
 * if file to/ from cannot be closed -exit 100
 */

int main(int argc, char *argv[])
{
int from, to;
int r = 1024, w = 0;
char buffer[1024];

if (argc != 3)
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
from = open(argv[1], O_RDONLY);
if (from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
S_IRGRP | S_IWGRP | S_IROTH);
if (to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(from), exit(99);
}
while (r == 1024)
{
r = read(from, buffer, 1024);
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
w = write(to, buffer, r);
if (w < r)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
}

if (close(from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from), exit(100);

if (close(to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);

return (0);
}
