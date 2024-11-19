/*#include <stdio.h>
//Deletion of a particular value from an array and readjusting the space.
int main(){
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the values of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++){
        array[i] = array[i+1];// Here the space will be reduced for each cell of the array until it reaches the cell before the required cell to be deleted
    }//and then after this loop the array will be reduced
    n=n-1;//new array size is updated
    for(i=0;i<n;i++){
        printf("%d",array[i]);
    }
    return 0;
}
*/
#include <stdio.h>

int main(){
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++){
        printf("Array[%d]: ",i);
        scanf("%d",&array[i]);
    }
    int data,pos;
    printf("Enter the data and position to insert: ");
    scanf("%d %d",&data,&pos);
    for(i=n-1;i>=pos;i--){
        array[i+1] = array[i];
    }
    array[pos] = data;
    n = n+1;
    for(i=0;i<n;i++){
        printf("%d",array[i]);
    }
    return 0;
}