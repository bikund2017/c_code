#include <ctype.h>
#include <stdio.h>

#define TEST(f) printf("  %c  ", f((unsigned char)*p) ? 'x' : ' ')

int main(void)
{
    char *p;

    printf("  alnum  cntrl  graph  print"
    "  space  xdigit\n"
    "      alpha     digit    lower   punct"
    "  upper\n");

    for (p = "azAZ0 !\t"; *p != '\0'; p++) {
        if (iscntrl((unsigned char)*p))
            printf("\\x%02x:", (unsigned char)*p);
        else
            printf("  %c:", *p);

        TEST(isalnum);
        TEST(isalpha);
        TEST(iscntrl);
        TEST(isdigit);
        TEST(isgraph);
        TEST(islower);
        TEST(isprint);
        TEST(ispunct);
        TEST(isspace);
        TEST(isupper);
        TEST(isxdigit);

        printf("\n");
    }

    return 0;
}
