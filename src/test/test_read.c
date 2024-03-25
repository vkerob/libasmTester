# include "../../include/tester.h"


static void	invalid_fd_test(char *buf_ft_read, char *buf_read, size_t count)
{

	int 	fd = -1;
	ssize_t	return_value_ft_read = ft_read(fd, buf_ft_read, count);
	ssize_t	return_value_read = read(fd, buf_read, count);

	printf("Testing with invalid file descriptor: %d and count: %zu\n", fd, count);
	if (return_value_ft_read == return_value_read && errno == EBADF)
		printf("%sTest passed for invalid file descriptor (ft_read and read returned the same value and set errno to EBADF as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_read(fd, buf_ft_read, %zu) and read(fd, buf_read, %zu) did not return the same value or did not set errno to EBADF%s\n", RED, count, count, RESET);

}

static void	zero_count_test(char *buf_ft_read, char *buf_read, int fd)
{

	size_t 	count = 0;
	ssize_t	return_value_ft_read = ft_read(fd, buf_ft_read, count);
	ssize_t	return_value_read = read(fd, buf_read, count);

	printf("Testing with count: %zu\n", count);
	if (return_value_ft_read == return_value_read)
		printf("%sTest passed for count 0 (ft_read and read returned the same value as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_read(fd, buf_ft_read, %zu) and read(fd, buf_read, %zu) did not return the same value%s\n", RED, count, count, RESET);

}

static void	null_buffer_test(size_t count, int fd)
{

	ssize_t	return_value_ft_read = ft_read(fd, NULL, count);
	ssize_t	return_value_read = read(fd, NULL, count);

	printf("Testing with NULL buffer\n");
	if (return_value_ft_read == return_value_read && errno == EFAULT)
		printf("%sTest passed for NULL buffer (ft_read and read returned the same value and set errno to EFAULT as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_read(fd, NULL, %zu) and read(fd, NULL, %zu) did not return the same value or did not set errno to EFAULT%s\n", RED, count, count, RESET);

}

void test_ft_read()
{

	size_t count = 9;
	int fd = open("Makefile", O_RDONLY);

	char *buf_ft_read = malloc(count * sizeof(char));

	char *buf_read = malloc(count * sizeof(char));

	printf("\n%sFT_READ%s\n", BLUE, RESET);

	errno = 0;
	invalid_fd_test(buf_ft_read, buf_read, count);

	zero_count_test(buf_ft_read, buf_read, fd);
	null_buffer_test(count, fd);

	close(fd);
	free(buf_read);
	free(buf_ft_read);

	return;

}