#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *c_buffer(char *f);
void close_f(int fd);

/**
 * c_buffer - 1024 bytes of buffer
 * @f: name of file buffer
 * Return: Pointer to new buffer
 */
char *c_buffer(char *f)
{
char *buf;
buf = malloc(sizeof(char) * 1024);
if (buf == NULL)
{
dprintf(STDERR_FILENO,
"Error: can't write to %s\n", f);
exit(99);
}
return (buf);
}

/**
 * close_f - close the file description
 * @fd: file of decsription to be closed
 */
void close_f(int fd)
{
int a;
a = close(fd);
if (a == -1)
{
dprintf(STDERR_FILENO, "Error: can't close f %d\n", fd);
exit(100);
}
}

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
int frm, to, a, b;
char *buf;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buf = c_buffer(argv[2]);
frm = open(argv[1], O_RDONLY);
a = read(frm, buf, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (frm == -1 || a == -1)
{
dprintf(STDERR_FILENO,
"Error: can't read from file %s\n", argv[1]);
free(buf);
exit(98);
}
b = write(to, buf, a);
if (to == -1 || b == -1)
{
dprintf(STDERR_FILENO,
"Error: can't write to %s\n", argv[2]);
free(buf);
exit(99);
}
a = read(frm, buf, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (a > 0);
free(buf);
close_f(frm);
close_f(to);
return (0);
}
