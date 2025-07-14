#include <stdio.h>
int main() {
    int num, temp, rem, sum,x;
    printf("Enter Range: ");
    scanf("%d",&x);
    for(num = 1; num <= x; num++) {
        temp = num;
        sum = 0;
        while(temp > 0) {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if(sum == num)
            printf("%d ", num);
    }
    return 0;
}
