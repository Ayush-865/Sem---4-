#include<stdio.h>
#include<conio.h>
#include <limits.h>

#define MAX_SIZE 100000

int arr[MAX_SIZE];

void minMax(){
    int n, minCounter=0, maxCounter=0, i;
    printf("\nEnter the value of n:  ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    int min=array[0] ,max=array[0];
    for(i=1; i<n; i++){
        minCounter++;
        if(array[i]<min)
            min=array[i];
    }
    for(i=1; i<n; i++){
        maxCounter++;
        if(array[i]>max)
            max=array[i];
    }
    arr[n]=minCounter+maxCounter;
}

void main(){
    int option=-1, i;
    for(i=0; i<MAX_SIZE; i++){
        arr[i]=-1;
    }
    while(option!=0){
        printf("\nEnter 1 to find the complexity \nEnter 0 to exit\n");
        scanf("%d", &option);
        if(option==1){
            minMax();
        }
        else if(option==0){
            printf("\nn\tcomplexity");
            for(i=0; i<MAX_SIZE; i++){
                if(arr[i]!=-1)
                    printf("\n%d\t%d", i , arr[i]);
            }
            break;
        }
    }
}
