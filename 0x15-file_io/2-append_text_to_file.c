#include "main.h"

/**
 * append_text_to_file - at the edn of file text must append
 * @filename: Name of the file
 * @text_content: string added to end of the file
 * Return: 1 if the file exists and -1 if the file does not exist
 */
int append_text_to_file(const char *filename, char *text_content)
{
int a, b, l = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (l = 0; text_content[l];)
l++;
}
a = open(filename, O_WRONLY | O_APPEND);
b = write(a, text_content, l);
if (a == -1 || b == -1)
return (-1);
close(a);
return (1);
}
