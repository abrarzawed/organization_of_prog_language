//
//  main.c
//  Assignment1
//  Created by AbrarZawed on 9/14/18.
//  Copyright © 2018 zawed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef int bool;
#define true 1
#define false 0
#define MAX_VAL 200

// function prototype
int acceptArray(int myarray[], int size );
int eqChecker(int seq1[], int seq2[], int newLength);

/* main function
 */
int main () {
    
    // Takes integer values as char array and converts them to array of int
    int length = 0;
    int array[MAX_VAL];
    char temp;
    
    printf("Enter integer values with a space and when done, hit enter: \n");
    do {
        scanf("%d%c", &array[length], &temp);
        length++;
    } while(temp != '\n');
    
    // if 0 or (-ve) number is inputed in the array
    // results in not order equiavalent seq
    
    for(int i = 0; i < length; i++) {
        if (array[i] <= 0){
            printf("\nNot Order Equivalent Because of 0 or Negative Number in the Sequences\n");
            return 0;
        }
    }
    
    // for odd number of inputs the result is not equivalent
    if(length %2 != 0) {
        printf("\nNot Order Equivalent Because of Odd Number of Inputs\n");
        return 0;
    }
    
    // function that accepts a sequence and divide into 2 sequences
    // it also calls eqChecker(seq1,seq2,newLength) in order to test equivalency
    if(acceptArray(array, length)){   // true for order equivalent
        printf("\nOrder Equivalent Sequences\n");
    }
    else{                           // false for order equivalent
        printf("\nNot Order Equivalent Sequences\n");
    }
    
    return 0;
}

/* Function that accepts a sequence and divides it into two sequences
 Also calls eqChecker(seq1,seq2,newLength) in order to test equivalency
 Returns true if the sequences are order equivalent, otherwise returns false
 */
int acceptArray(int myarray[], int size ) {
    
    int newLength = size/2;
    int seq1[newLength];
    int seq2[newLength];
    int num = 0;
    
    printf("The 1st Sequence is: ");
    for(int i = 0; i < newLength; i++) {
        seq1[i] = myarray[i];
        printf("\t%d\t", seq1[i]);
    }
    
    printf("\nThe 2nd Sequence is: ");
    for(int k = newLength; k < size; k++) {
        seq2[num] = myarray[k];
        printf("\t%d\t", seq2[num]);
        num++;
    }
    
    // if else statement based on return type
    if(eqChecker(seq1,seq2,newLength)){
        return true;
    }
    else{
        return false;
    }
}

/* Function that checks equivalency of two sequences
 Returns true if the sequences are order equivalent, otherwise returns false
 */
int eqChecker(int seq1[], int seq2[], int newLength){
    
    int isEquivalent = true;
    
    for(int i = 0; i < newLength && isEquivalent; i++){
        for(int j = 0; j < newLength && isEquivalent; j++) {
            if ((seq1[i] <= seq1[j]) != (seq2[i] <= seq2[j])) {
                isEquivalent = false;
            }
        }
    }
    return isEquivalent;
    
}

