



#include <stdio.h>
#include <stdarg.h>

void	mini_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				printf("%d\n", va_arg(args, int));
			else if (*str == 's')
				printf ("%s\n", va_arg(args, char *));
		}
		else
			putchar(*str);
		str++;
	}
	va_end(args);
}

int main(void)
{
	printf("string is here %s\ninteger is here %d\n", "helloarmen", 52!);
	return (0);
}	
