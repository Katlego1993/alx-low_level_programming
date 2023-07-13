#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * file_c - close a fil and print an error message if failure
 * @file: file to close
*/
void file_c(int file)
{
if (close(file) != -1)
return;
write(STDERR_FILENO, "Error: Can't close fd\n", 22);
exit(98);
}

/**
 * file_r - read from file and print error if failure
 * @file: the file to read from
 * @buf: the buffer to write to
 * @num: the number of bytes to read
*/
void file_r(int file, char *buf, size_t num)
{
if (read(file, buf, num) != -1)
return;
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
file_c(file);
exit(98);
}

/**
 * p_magic - print magic of ELF
 * @buf: points to an array with ELF number
*/
void p_magic(const unsigned char *buf)
{
unsigned int num;
if (_strncmp((const char *) buf, ELFMAG, 4))
{  
write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
exit(98);
}

printf("ELF Header:\n  Magic:   ");

for (num = 0; num < 16; ++num)
printf("%02x%c", buf[num], num < 15 ? ' ' : '\n');
}

/**
 * p_class - print class of ELF
 * @buf: points to an array with ELF number
 *
 * Return: bit mode (32 or 64)
 */
size_t p_class(const unsigned char *buf)
{
printf("  %-34s ", "Class:");

if (buf[EI_CLASS] == ELFCLASS64)
{
printf("ELF64\n");
return (64);
}
if (buf[EI_CLASS] == ELFCLASS32)
{
printf("ELF32\n");
return (32);
}
printf("<unknown: %x>\n", buf[EI_CLASS]);
return (32);
}

/**
 * p_data - print data of ELF
 * @buf: points to an array with ELF number
 *
 * Return: 1 if big, otherwise 0
 */
int p_data(const unsigned char *buf)
{
printf("  %-34s ", "Data:");

if (buf[EI_DATA] == ELFDATA2MSB)
{
printf("2's complement, big endian\n");
return (1);
}
if (buf[EI_DATA] == ELFDATA2LSB)
{
printf("2's complement, little endian\n");
return (0);
}
printf("Invalid data encoding\n");
return (0);
}

/**
 * p_version - print version of ELF
 * @buf: points of an array with ELF number
*/
void p_version(const unsigned char *buf)
{
printf("  %-34s %u", "Version:", buf[EI_VERSION]);

if (buf[EI_VERSION] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");
}

/**
 * p_osabi - print osabi of ELF
 * @buf: point of an array with ELF number
*/
void p_osabi(const unsigned char *buf)
{
const char *t_ABI[19] = {
"UNIX - System V",
"UNIX - HP-UX",
"UNIX - NetBSD",
"UNIX - GNU",
"<unknown: 4>",
"<unknown: 5>",
"UNIX - Solaris",
"UNIX - AIX",
"UNIX - IRIX",
"UNIX - FreeBSD",
"UNIX - Tru64",
"Novell - Modesto",
"UNIX - OpenBSD",
"VMS - OpenVMS",
"HP - Non-Stop Kernel",
"AROS",
"FenixOS",
"Nuxi CloudABI",
"Stratus Technologies OpenVOS"
};
printf("  %-34s ", "OS/ABI:");
if (buf[EI_OSABI] < 19)
printf("%s\n", t_ABI[(unsigned int) buf[EI_OSABI]]);
else
printf("<unknown: %x>\n", buf[EI_OSABI]);
}

/**
 * p_abi - print ABI version of ELF
 * @buf: points to an array with ELF number
*/
void p_abi(const unsigned char *buf)
{
printf("  %-34s %u\n", "ABI Version:", buf[EI_ABIVERSION]);
}

/**
 * p_type - print type of ELF
 * @buf: the header of an ELF
 * @e: big endian if non-zero
*/
void p_type(const unsigned char *buf, int e)
{
char *t_type[5] = {
"NONE (No file type)",
"REL (Relocatable file)",
"EXEC (Executable file)",
"DYN (Shared object file)",
"CORE (Core file)"
};
unsigned int t;
printf("  %-34s ", "Type:");

if (e)
t = 0x100 * buf[16] + buf[17];
else
t = 0x100 * buf[17] + buf[16];
if (t < 5)
printf("%s\n", t_type[t]);
else if (t >= ET_LOOS && t <= ET_HIOS)
printf("OS Specific: (%4x)\n", t);
else if (t >= ET_LOPROC && t <= ET_HIPROC)
printf("Processor Specific: (%4x)\n", t);
else
printf("<unknown: %x>\n", t);
}

/**
 * P_entry - print entry point of ELF
 * @buf: string containing the entry point ELF
 * @m: mode number (32 or 64)
 * @e: big endian if non-zero
*/
void p_entry(const unsigned char *buf, size_t m, int e)
{
int size = m / 8;
printf("  %-34s 0x", "Entry point address:");

if (e)
{
while (size && !*(buf))
--size, ++buf;
printf("%x", *buf & 0xff);
while (--size > 0)
printf("%02x", *(++buf) & 0xff);
}
else
{
buf += size;
while (size && !*(--buf))
--size;
printf("%x", *buf & 0xff);
while (--size > 0)
printf("%02x", *(--buf) & 0xff);
}
printf("\n");
}

/**
 * main - Print info of ELF header at the start of ELF file
 * @argc: number of arguments
 * @argv: rray of arguments
 *
 * Return: 0 on success
 */
int main(int argc, const char *argv[])
{
unsigned char buf[18];
unsigned int m;
int e;
int f;

if (argc != 2)
{
write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
exit(98);
}
f = open(argv[1], O_RDONLY);
if (f == -1)
{
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
exit(98);
}

file_r(f, (char *) buf, 18);

p_magic(buf);
m = p_class(buf);
e = p_data(buf);
p_version(buf);
p_osabi(buf);
p_abi(buf);
p_type(buf, e);

lseek(f, 24, SEEK_SET);
file_r(f, (char *) buf, m / 8);
p_entry(buf, m, e);
file_c(f);
return (0);
}
