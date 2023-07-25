#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 *  print_buffer - write out the buffers str;
 *  @buf: pointer to a buffer.
 *  Return: nothing
 */
void print_buffer(Buffer *buf)
{
	if (!buf)
		return;
	write(1, buf->str, buf->index);
	buf->index = 0;
}
/**
 *new_buffer - write out the buffers str;
 *
 *Return: nothing
 */
Buffer *new_buffer()
{
	Buffer *buf;

	buf = malloc(sizeof(Buffer));
	if (!buf)
		return (NULL);
	buf->index = 0;
	buf->size = 1024;
	buf->str = malloc(sizeof(char) * buf->size + 1);
	if (!buf->str)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

