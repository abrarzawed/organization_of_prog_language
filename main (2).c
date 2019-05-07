//
//  main.c
//  Program3
//
//  Created by Abrar Zawed on 10/25/18.
//  Copyright © 2018 zaweda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0
typedef struct node {
    int data;
    struct node * next;
}node;


// function prototype
node * insert(int number);
void bubbleSort(node * head);
void swap(node * a, node * b);
void print(node * head);


node * head = NULL;     //global variable

/**
 Main function
 **/
int main(int argc, const char * argv[]) {
    
    node * start = NULL;    // pointer to the head of the linkedlist
    bool notDone = true;
    while(notDone){
        // takes user input
        char enter[20];
        printf("");
        scanf(" %[^\n]%*c", enter);
        
        // if user inputs insert
        if (strcmp(enter, "insert") == 0){
            int number;
            printf("enter a number: ");
            scanf("%d", &number);
            start = insert(number);
        }
         // if user inputs print
        else if(strcmp(enter, "print") == 0){
            print(start);
        }
         // if user inputs exit
        else if(strcmp(enter, "exit") == 0){
            notDone = false;
        }
         // if user inputs unknown request
        else{
            printf("Error: unknown request 'remove'\n");
        }
    }
    return 0;
}

/**
 Method that creates a node, inserts it in the linkedlist, and finally sorts the input within the linkedlist
 Parameter: user entered value(int)
 Returns: Pointer to the head of the created linkedlist
 **/
node * insert(int number) {
    node * temp = NULL;
    node * p = NULL;
    
        // creates a new node
        temp = (node*)malloc(sizeof(node));
        temp -> data = number;
        temp ->next = NULL;
    
        // checks if the linkedlist is empty
        if(head == NULL){
            head = temp;
        }
        // if the linkedlist has nodes
        else{
            p = head;
            while(p -> next != NULL){
                p = p -> next;
            }
            p -> next = temp;
        }
    
    // sorts the nodes of the linkedlist based on their value
    bubbleSort(head);
    
    return head;
    
}


/** Method that bubble sort the given linkedlist
 Parameter: pointer to head node of the given linkedlist
 Return: void
 **/
void bubbleSort(node * head)
{
    int swapped;
    node *ptr1;
    node *lptr = NULL;
    
    // checking for empty list
    if (head == NULL){
        return;
    }
    // if the linkedlist is not empty
    do
    {
        swapped = 0;
        ptr1 = head;
        
        // loop through the last node of the linkedlist
        while (ptr1->next != lptr)
        {
            // swaps nodes based on their values
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/** Method to swap data of two nodes
 Parameters: Nodes that will be swapped
 Returns: void
 **/
void swap(node * a, node * b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/** Method that prints the linkelist
 Parameters: Pointer to the head of the linkedlist
 Returns: void
 **/
void print(node *head)
{
    node *temp = head;
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
