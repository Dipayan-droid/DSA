#include <stdio.h>
#include <stdlib.h>
int main(){
    int r, c,found,i,j,x=2;
    scanf("%d %d",&r,&c);
    int **arr= (int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        arr[i]=(int*)malloc(c*sizeof(int*));
    }
    printf("Enter elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(arr[i][j] == x) {
                printf("Element %d found at (%d,%d)\n", x, i+1, j+1);
                found=1;
            }
    if(!found) printf("Element not found\n");
    return 0;
}