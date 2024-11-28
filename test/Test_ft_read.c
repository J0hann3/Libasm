#include "unity.h"
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define FILENAME "TestRead"

ssize_t ft_read(int fd, void *buf, size_t count);

void verify_read_behavior(const char *str, ssize_t read_size)
{
	char std_buffer[1024] = {0};
	char buffer[1024] = {0};

	int fd = open(FILENAME, O_RDWR | O_TRUNC | O_CREAT, 00777);
	TEST_ASSERT_NOT_EQUAL_MESSAGE(-1, fd, "Fail to open fd to test write");
	write(fd, str, strlen(str));

	lseek(fd, 0, SEEK_SET);
	errno = 0;
	ssize_t std_res = read(fd, std_buffer, read_size);
	int std_errno = errno;

	lseek(fd, 0, SEEK_SET);
	errno = 0;
	ssize_t res = ft_read(fd, buffer, read_size);
	int new_errno = errno;
	close(fd);

	TEST_ASSERT_EQUAL_INT(std_res, res);
	TEST_ASSERT_EQUAL_STRING(std_buffer, buffer);
	TEST_ASSERT_EQUAL_INT(std_errno, new_errno);
}

void test_ft_read_size_zero()
{
	verify_read_behavior("coucou", 0);
}

void test_ft_read_size_in_empty_file()
{
	verify_read_behavior("", 56);
}

void test_ft_read_single_character()
{
	verify_read_behavior("coucou", 1);
	verify_read_behavior("", 1);
}

void test_ft_read_normal_string()
{
	verify_read_behavior("read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.", 50);
}

void test_ft_read_long_string()
{
	verify_read_behavior("read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.\
\
	On  files that support seeking, the read operation commences at the file offset, and the file offset is incremented by the number\
	of bytes read.  If the file offset is at or past the end of file, no bytes are read, and read() returns zero.\
\
	If count is zero, read() may detect the errors described below.  In the absence of any errors, or if read() does  not  check  for\
	errors, a read() with a count of 0 returns zero and has no other effects.\
\
	According  to POSIX.1, if count is greater than SSIZE_MAX, the result is implementation-defined; see NOTES for the upper limit on\
	Linux.", 600);
}

void test_ft_read_all_file()
{
	verify_read_behavior("coucou", 6);
}

void test_ft_read_more_than_all_file()
{
	verify_read_behavior("coucou", 40);
}

void test_ft_read(void)
{
	RUN_TEST(test_ft_read_size_zero);
	RUN_TEST(test_ft_read_size_in_empty_file);
	RUN_TEST(test_ft_read_single_character);
	RUN_TEST(test_ft_read_normal_string);
	RUN_TEST(test_ft_read_long_string);
	RUN_TEST(test_ft_read_all_file);
	RUN_TEST(test_ft_read_more_than_all_file);
	remove(FILENAME);
}