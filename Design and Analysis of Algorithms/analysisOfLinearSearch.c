#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];

void linearSearch(){
    int n ,num, counter=0, i;
    printf("\nEnter the value of n:  ");
    scanf("%d", &n);
    printf("\nEnter the value of number to be searched:  ");
    scanf("%d", &num);
    for(i=0; i<n; i++){
        counter++;
        if(num==n)
            break;
    }
    arr[n]=counter;
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
            linearSearch();
        }
        else if(option==0){
            for(i=0; i<MAX_SIZE; i++){
                if(arr[i]!=-1)
                    printf("\n%d : %d", i , arr[i]);
            }
            break;
        }
    }
}
