#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

/* ============================= */
/*          ft_strlen            */
/* ============================= */
void test_strlen(void)
{
    printf("\n=== ft_strlen ===\n");

    errno = 0;
    printf("ft_strlen(\"hello\")       = %zu (attendu 5)\n",  ft_strlen("hello"));
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    printf("ft_strlen(\"\")            = %zu (attendu 0)\n",  ft_strlen(""));
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    printf("ft_strlen(\"a\")           = %zu (attendu 1)\n",  ft_strlen("a"));
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    printf("ft_strlen(\"hello world\") = %zu (attendu 11)\n", ft_strlen("hello world"));
    printf("  errno = %d (attendu 0)\n", errno);
}

// /* ============================= */
// /*          ft_strcpy            */
// /* ============================= */
// void test_strcpy(void)
// {
//     printf("\n=== ft_strcpy ===\n");

//     char dst1[50];
//     errno = 0;
//     ft_strcpy(dst1, "hello");
//     printf("ft_strcpy(dst, \"hello\")       = \"%s\" (attendu \"hello\")\n", dst1);
//     printf("  errno = %d (attendu 0)\n", errno);

//     char dst2[50];
//     errno = 0;
//     ft_strcpy(dst2, "");
//     printf("ft_strcpy(dst, \"\")            = \"%s\" (attendu \"\")\n", dst2);
//     printf("  errno = %d (attendu 0)\n", errno);

//     char dst3[50];
//     errno = 0;
//     ft_strcpy(dst3, "hello world");
//     printf("ft_strcpy(dst, \"hello world\") = \"%s\" (attendu \"hello world\")\n", dst3);
//     printf("  errno = %d (attendu 0)\n", errno);
// }

// /* ============================= */
// /*          ft_strcmp            */
// /* ============================= */
// void test_strcmp(void)
// {
//     printf("\n=== ft_strcmp ===\n");

//     errno = 0;
//     int r1 = ft_strcmp("hello", "hello");
//     printf("ft_strcmp(\"hello\", \"hello\") = %d (attendu 0)\n", r1);
//     printf("  errno = %d (attendu 0)\n", errno);

//     errno = 0;
//     int r2 = ft_strcmp("abc", "abd");
//     printf("ft_strcmp(\"abc\", \"abd\")     = %d (attendu < 0)\n", r2);
//     printf("  errno = %d (attendu 0)\n", errno);

//     errno = 0;
//     int r3 = ft_strcmp("abd", "abc");
//     printf("ft_strcmp(\"abd\", \"abc\")     = %d (attendu > 0)\n", r3);
//     printf("  errno = %d (attendu 0)\n", errno);

//     errno = 0;
//     int r4 = ft_strcmp("", "");
//     printf("ft_strcmp(\"\", \"\")           = %d (attendu 0)\n", r4);
//     printf("  errno = %d (attendu 0)\n", errno);

//     errno = 0;
//     int r5 = ft_strcmp("a", "");
//     printf("ft_strcmp(\"a\", \"\")          = %d (attendu > 0)\n", r5);
//     printf("  errno = %d (attendu 0)\n", errno);
// }

/* ============================= */
/*          ft_write             */
/* ============================= */
void test_write(void)
{
    printf("\n=== ft_write ===\n");

    errno = 0;
    ssize_t r1 = ft_write(1, "hello write\n", 12);
    printf("ft_write(stdout, \"hello write\", 12) = %zd (attendu 12)\n", r1);
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    ssize_t r2 = ft_write(1, "", 0);
    printf("ft_write(stdout, \"\", 0)             = %zd (attendu 0)\n", r2);
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    ssize_t r3 = ft_write(-1, "test", 4);
    printf("ft_write(-1, \"test\", 4)             = %zd (attendu -1)\n", r3);
    printf("  errno = %d (attendu 9)\n", errno);
    perror("  perror");
}

/* ============================= */
/*          ft_read              */
/* ============================= */
void test_read(void)
{
    printf("\n=== ft_read ===\n");

    /* test avec un vrai fichier */
    int fd = open("/tmp/test_read.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, "hello read", 10);
    close(fd);

    char buf[50];
    memset(buf, 0, sizeof(buf));
    fd = open("/tmp/test_read.txt", O_RDONLY);
    errno = 0;
    ssize_t r1 = ft_read(fd, buf, 10);
    close(fd);
    printf("ft_read(fd, buf, 10) = %zd, buf = \"%s\" (attendu 10, \"hello read\")\n", r1, buf);
    printf("  errno = %d (attendu 0)\n", errno);

    errno = 0;
    ssize_t r2 = ft_read(-1, buf, 10);
    printf("ft_read(-1, buf, 10) = %zd (attendu -1)\n", r2);
    printf("  errno = %d (attendu 9)\n", errno);
    perror("  perror");
}

// /* ============================= */
// /*          ft_strdup            */
// /* ============================= */
// void test_strdup(void)
// {
//     printf("\n=== ft_strdup ===\n");

//     errno = 0;
//     char *s1 = ft_strdup("hello");
//     printf("ft_strdup(\"hello\")       = \"%s\" (attendu \"hello\")\n", s1);
//     printf("  errno = %d (attendu 0)\n", errno);
//     free(s1);

//     errno = 0;
//     char *s2 = ft_strdup("");
//     printf("ft_strdup(\"\")            = \"%s\" (attendu \"\")\n", s2);
//     printf("  errno = %d (attendu 0)\n", errno);
//     free(s2);

//     errno = 0;
//     char *s3 = ft_strdup("hello world");
//     printf("ft_strdup(\"hello world\") = \"%s\" (attendu \"hello world\")\n", s3);
//     printf("  errno = %d (attendu 0)\n", errno);
//     free(s3);
// }

/* ============================= */
/*            MAIN               */
/* ============================= */
int main(void)
{
    test_strlen();
    /* test_strcpy(); */
    /* test_strcmp(); */
    test_write();
    test_read();
    /* test_strdup(); */

    printf("\n");
    return (0);
}
