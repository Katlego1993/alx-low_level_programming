#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define BUF_SIZE 1024

/**
 * error_98 - error 98 check
 * @file0: check value
 * @buf: buffer
 * @argv: an argument
 */
void error_98(int file0, char *buf, char *argv)
{
if (file0 < 0)
{
dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv);
free(buf);
exit(98);
}
}

/**
 * error_99 - error 99 check
 * @file0: check value
 * @buf: buffer
 * @argv: an argument
 */
void error_99(int file0, char *buf, char *argv)
{
if (file0 < 0)
{
dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv);
free(buf);
exit(99);
}
}

/**
 * error_100 - error 100 check
 * @file0: check value
 * @buf: buffer
 */
void error_100(int file0, char *buf)
{
if (file0 < 0)
{
dprintf(STDERR_FILENO, "Error: can't close fd %i\n", file0);
free(buf);
exit(100);
}
}

/**
 * main - Copies content of a file to another file
 * @argc: Number of arguments
 * @argv: an array of arguments
 * Return: 0 on success
 *
 */
int main(int argc, char **argv)
{
int file0, file1, r0, r1;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buf = malloc(sizeof(char) * BUF_SIZE);
if (!buf)
return (0);

file1 = open(argv[1], O_RDONLY);
error_98(file1, buf, argv[1]);

file0 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
error_99(file0, buf, argv[2]);

do {
r0 = read(file1, buf, BUF_SIZE);
if (r0 == 0)
break;
error_98(r0, buf, argv[1]);

r1 = write(file0, buf, r0);
error_99(r1, buf, argv[2]);
} while (r1 >= BUF_SIZE);
r0 = close(file0);
error_100(r0, buf);
r0 = close(file1);
error_100(r0, buf);
free(buf);
return (0);
}
