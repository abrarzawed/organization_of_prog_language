//
//  main.c
//  Assignment2
//  Created by AbrarZawed on 9/30/18.
//  Copyright © 2018 zaweda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_VAL 100

// function prototype
int* acceptArray(void);
int* bubbleSort(int arr[], int size, char order[]);
void swap(int *xp, int *yp);


/**
Main Function
**/
int main(int argc, const char * argv[]) {
    
    char enter[20];
    printf("");
    scanf("%[^\n]%*c", enter);
 
    // compare input "sort" with string sort
    int ret = strcmp(enter, "sort");
   
   // if "sort" is inputed properly
    if(ret == 0) {
        char str[20];
        
         // input sort order: up or dowm
        printf("Enter sort order: ");
        scanf("%[^\n]%*c", str);
        
        // accepts the sequence of numbers
        int* arr =acceptArray();
        
        int length = 0;    
        while(arr[length] != 0) {
            length++; //including negative and positive values except 0
        }
        
        // for negative numbers
        int j;
        for(j =0; j < length; j++){
        	if(arr[j] < 0) {
        		printf("You have entered negative values, please add positve values only\n");
        		return 0;
			}
		}
        
        int newLength = 0;
          while(arr[newLength] > 0) {
            newLength++; //include values that are > 0
        }
        
        // returns an array with sorted sequence of numbers
        int* newArr = bubbleSort(arr, newLength, str); 
        int k;
        for(k = 0; k < newLength; k++){
            printf("%d\t", newArr[k]);
        }
        // if "sort" is not inputted properly
    }else{
        return 0;
    }
}

/**
Method that accepts an unsorted array, size of the array, and sorting order
Returns an array with sorted sequence of numbers
**/
int* bubbleSort(int arr[], int size, char order[]) {
    char str1[20];
    char str2[20];
    int ret;
    
    strcpy(str1, "up");
    strcpy(str2, order);
    
    ret = strcmp(str1, str2);

	// if sorting order is "up"
    if(ret == 0) {
        int i, j;
        for (i = 0; i < size-1; i++){
            // Last i elements are already in place
            for (j = 0; j < size-i-1; j++){
                if (arr[j] > arr[j+1]){
                    swap(&arr[j], &arr[j+1]);	// swap elements of the array
                }
            }
        }
        return arr;
    }
    // if sorting order is "down"
    else {
        int i, j;
        for (i = 0; i < size-1; i++){
            // Last i elements are already in place
            for (j = 0; j < size-i-1; j++){
                if (arr[j] < arr[j+1]){
                    swap(&arr[j], &arr[j+1]);	// swap elements of the array
                }
            }
        }
        return arr;
    }
}

/**
Method that swap elements of an array
Returns: void
**/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


/** Method that takes integer values as char array and converts them to array of int
Returns an unsorted array of int
**/
int* acceptArray(){
    int length = 0;
    static int array[MAX_VAL];
    char temp;
    
    printf("Enter a sequence of numbers: ");
    do {
        scanf("%d%c", &array[length], &temp);
        length++;
    } while(temp != '\n');
    return array;
}
