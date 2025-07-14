#include <stdio.h>
int main() {
    int n = 5; 
    int i, j, num;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++)
            printf(" ");
        for(j = 0; j < 2 * i + 1; j++) {
            num = n - abs(i - j);
            printf("%d", num);
        }
        printf("\n");
    }
   
    for(i = n - 2; i >= 0; i--) {
        for(j = 0; j < n - i - 1; j++)
            printf(" ");
        for(j = 0; j < 2 * i + 1; j++) {
            num = n - abs(i - j);
            printf("%d", num);
        }
        printf("\n");
    }
    return 0;
}
