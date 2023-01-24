#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - Custum printf function
 * @format: A string containing the caracters to print
 * Return: the count of the printed charecters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i, j, length = 0;
	char c, *p, *ptr;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				count += write(1, &c, 1);
			}
			if (format[i] == 's')
			{
				ptr = va_arg(args, char *);
				while (*ptr != '\0')
				{
					length++;
					ptr++;
				}
				p = malloc((length + 1) * sizeof(char));
				for (j = 0; j < (length + 1); j++)
				{
					p[length - j] = *(ptr - j);
				}
				count += write(1, p, length);
				free(p);
			}
			if (format[i] == '%')
				count += write(1, &format[i], 1);
		}
		else if (format[i] == '\n')
			count += write(1, &format[i], 1) - 1;
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
