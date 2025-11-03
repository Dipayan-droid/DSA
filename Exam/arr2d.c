#include <stdio.h>
#include <stdlib.h>
int main(){
    int **arr;
    int r,c,key,i,j,found=0;
    printf("enter number of rows and columns: ");
    scanf("%d",&r);
    scanf("%d",&c);
    arr = (int**)malloc(r*sizeof(int**));
    for (i=0;i<r;i++){
        arr[i]=(int*)malloc(c*sizeof(int*));
    }
    printf("Enter elemets of the array: ");
    for (i = 0;i<r;i++){
        for (j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }    
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < r && !found; i++) {
        for (j = 0; j < c; j++) {
            if (arr[i][j] == key) {
                printf("Element %d found at position [%d][%d]", key, i, j);
                found = 1;
                break;
            }
        }
    }
    return 0;
}