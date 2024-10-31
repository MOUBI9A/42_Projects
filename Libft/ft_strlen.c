#include <stdio.h>

/*
** The ft_strlen() function calculates the length of the string str, excluding the terminating null byte ('\0').
** The function uses a while loop to iterate through the string str until the null byte '\0' is reached.
** The function returns the number of characters in the string str.
*/

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	// Loop until the end of the string ('\0') is reached
	while (str[i] != '\0')
		i++;
	return (i);
}


// int main()
// {
// 	char str[100];

// 	printf("Enter a string: ");
// 	fgets(str, sizeof(str), stdin);

// 	// Remove the newline character from fgets
// 	if (str[ft_strlen(str) - 1] == '\n')
// 	{
// 		str[ft_strlen(str) - 1] = '\0';
// 	}

// 	// Calculate the length of the string using ft_strlen
// 	size_t length = ft_strlen(str);

// 	printf("Length of the string: %zu\n", length);

// 	return 0;
// }
