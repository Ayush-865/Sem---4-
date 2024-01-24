#include<stdio.h>
#include<conio.h>
#include <math.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int arr1[MAX_SIZE];

void binarySearch(){
    int num, counter=0, low=0, high;
    printf("\nEnter the value of n:  ");
    scanf("%d", &high);
    printf("\nEnter the value of number to be searched:  ");
    scanf("%d", &num);
    while (low <= high) {
        int m = low + (high - low) / 2;
        counter++;
 
        // Check if x is present at mid
        if (arr[m] == num)
            break;
 
        // If x greater, ignore left half
        if (arr[m] < num)
            low = m + 1;
 
        // If x is smaller, ignore right half
        else
            high = m - 1;
    }
    arr[high]=counter;
    arr1[high]=ceil(log(high)/log(2));
}

void main(){
    int option=-1, i;
    for(i=0; i<MAX_SIZE; i++){
        arr[i]=-1;
        arr1[i]=-1;
    }
    while(option!=0){
        printf("\nEnter 1 to find the complexity \nEnter 0 to exit\n");
        scanf("%d", &option);
        if(option==1){
            binarySearch();
        }
        else if(option==0){
            printf("n\tsplits\tlogn");
            for(i=0; i<MAX_SIZE; i++){
                if(arr[i]!=-1)
                    printf("\n%d\t%d\t%d", i , arr[i], arr1[i]);
            }
            break;
        }
    }
}
