#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFSIZE 128

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1] == NULL)
	{
		fprintf(stderr, "Error: arguments");
		return 1;
	}

	char *pattern = argv[1];
	ssize_t pat_len = strlen(pattern);
	char buffer[BUFFSIZE];
	size_t bytes;

	while ((bytes = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0)
	{
		char *pos = buffer;
		while ((pos = memmem(pos, buffer + bytes - pos, pattern, pat_len)))
		{
			memset(pos, '*', pat_len);
			pos += pat_len;
		}
		if (write(STDOUT_FILENO, buffer, bytes) < 0)
		{
			perror("Error: failed to write");
			return 1;
		}
	}
	if (bytes < 0)
	{
		perror("Error: failed to read");
		return 1;
	}
	return 0;
}