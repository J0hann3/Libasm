#include "unity.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define FILENAME "TestWrite"
ssize_t ft_write(int fd, const void *buf, size_t count);

ssize_t write_in_file(const char *str, bool use_write, char (*buffer)[1024], ssize_t len)
{
	ssize_t res = 0;

	int fd = open(FILENAME, O_RDWR | O_TRUNC | O_CREAT, 00777);
	TEST_ASSERT_NOT_EQUAL_MESSAGE(-1, fd, "Fail to open fd to test write");

	if (use_write == true)
		res = write(fd, str, len);
	else
		res = ft_write(fd, str, len);

	lseek(fd, 0, SEEK_SET);
	read(fd, *buffer, sizeof(*buffer) - 1);
	close(fd);
	return res;
}

void verify_write_behavior(const char *str, ssize_t len)
{
	char std_buffer[1024] = {0};
	char buffer[1024] = {0};

	errno = 0;
	int std_res = write_in_file(str, true, &std_buffer, len);
	int std_errno = errno;

	errno = 0;
	int res = write_in_file(str, false, &buffer, len);
	int new_errno = errno;

	TEST_ASSERT_EQUAL_INT(std_res, res);
	TEST_ASSERT_EQUAL_STRING(std_buffer, buffer);
	TEST_ASSERT_EQUAL_INT(std_errno, new_errno);
}

void test_ft_write_empty_string()
{
	verify_write_behavior("", strlen(""));
}

void test_ft_write_single_character()
{
	verify_write_behavior("A", strlen("A"));
}

void test_ft_write_normal_string()
{
	verify_write_behavior("hello world", strlen("hello world"));
}

void test_ft_write_long_string()
{
	verify_write_behavior("On success, the number of bytes written is returned.  On error, -1 is returned, and errno is set to indicate the cause of the er‐\
	ror.\
\
	Note that a successful write() may transfer fewer than count bytes.  Such partial writes can occur for various reasons; for exam‐\
	ple, because there was insufficient space on the disk device to write all of the requested bytes, or because a blocked write() to\
	a  socket,  pipe, or similar was interrupted by a signal handler after it had transferred some, but before it had transferred all\
	of the requested bytes.  In the event of a partial write, the caller can make another write()  call  to  transfer  the  remaining\
	bytes.  The subsequent call will either transfer further bytes or may result in an error (e.g., if the disk is now full).", 785);
}

void test_ft_write_invalid_fd()
{

	errno = 0;
	int std_res = write(-1, "hello\n", 6);
	int std_errno = errno;

	errno = 0;
	int res = ft_write(-1, "hello\n", 6);
	int new_errno = errno;

	TEST_ASSERT_EQUAL_INT(std_res, res);
	TEST_ASSERT_EQUAL_INT(std_errno, new_errno);
}

void test_ft_write_null_string()
{
	verify_write_behavior(NULL, 6);
}

void test_ft_write_len_too_short()
{
	verify_write_behavior("coucou\n", 15);
}

void test_ft_write(void)
{
	RUN_TEST(test_ft_write_empty_string);
	RUN_TEST(test_ft_write_single_character);
	RUN_TEST(test_ft_write_normal_string);
	RUN_TEST(test_ft_write_long_string);
	RUN_TEST(test_ft_write_invalid_fd);
	RUN_TEST(test_ft_write_null_string);
	RUN_TEST(test_ft_write_len_too_short);
	remove(FILENAME);
}