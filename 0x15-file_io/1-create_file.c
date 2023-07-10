#include "main.h"

/**
 * create_file - File to be created
 * @filename: file name will be created
 * @text_content: string for writing a file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int f, a, l = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (l = 0; text_content[l];)
l++;
}
f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
a = write(f, text_content, l);
if (f == -1 || a == -1)
return (-1);
close(f);
return (1);
}
