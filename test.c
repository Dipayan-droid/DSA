#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "I-LOVE-C";
    char str2[] = {'I', '-', 'L', 'O', 'V', 'E', '-', 'C'};
    int n1 = sizeof(str1) / sizeof(str1[0]);
    int n2 = sizeof(str2) / sizeof(str2[0]);
    printf("str1=%d",strlen(str1));
    printf("n1=%d, n2=%d", n1, n2);
    return 0;
}
