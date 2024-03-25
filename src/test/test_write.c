# include "../../include/tester.h"

static void	invalid_fd_test(const char *str, size_t count)
{

	int		fd = -1;
	ssize_t	return_value_ft_write = ft_write(fd, str, count);
	ssize_t	return_value_write = write(fd, str, count);

	printf("Testing with invalid file descriptor: %d and count: %zu\n", fd, count);
	if (return_value_ft_write == return_value_write && errno == EBADF)
		printf("%sTest passed for invalid file descriptor (ft_write and write returned the same value and set errno to EBADF as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_write(fd, str, %zu) and write(fd, str, %zu) did not return the same value or did not set errno to EBADF%s\n", RED, count, count, RESET);

}

static void	zero_count_test(const char *str, int fd)
{
	size_t	count = 0;
	ssize_t	return_value_ft_write = ft_write(fd, str, count);
	ssize_t	return_value_write = write(fd, str, count);

	printf("Testing with count: %zu\n", count);
	if (return_value_ft_write == return_value_write)
		printf("%sTest passed for count 0 (ft_write and write returned the same value as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_write(fd, str, %zu) and write(fd, str, %zu) did not return the same value%s\n", RED, count, count, RESET);

}

static void	null_string_test(int fd, size_t count)
{

	ssize_t	return_value_ft_write = ft_write(fd, NULL, count);
	ssize_t	return_value_write = write(fd, NULL, count);

	printf("Testing with NULL string\n");
	if (return_value_ft_write == return_value_write && errno == EFAULT)
		printf("%sTest passed for NULL string (ft_write and write returned the same value and set errno to EFAULT as expected)%s\n", GREEN, RESET);
	else
		printf("%sError: ft_write(fd, NULL, %zu) and write(fd, NULL, %zu) did not return the same value or did not set errno to EFAULT%s\n", RED, count, count, RESET);

}

void test_ft_write()
{

	printf("\n%sFT_WRITE%s\n", BLUE, RESET);

	const char	*str = "qwertyuiop\n";
	size_t		count = strlen(str);
	int			fd = open("t", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	errno = 0;

	invalid_fd_test(str, count);
	zero_count_test(str, fd);
	null_string_test(fd, count);

	close(fd);

	return;

}