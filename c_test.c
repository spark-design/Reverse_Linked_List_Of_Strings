/*
Example of a linked list of strings
*/

#include <stdio.h>
#include <stdlib.h> //has functions malloc() and free()
#include <string.h>
#include <stdbool.h>

/*
A self-referential structures contains a pointer 
that points to another structure of the same type
and link together to form dynamic data structures.
strings: stores a word (string)
next: is a pointer to the next node
*/
struct node{
   char strings[256];
   struct node *next;
};

/*
word2: is a string
head2: is the a pointer to the 1st node in a linked list 
This parameter is a pointer to a pointer, 
because we are passing the address of the linked list to the function, 
and the linked list itself is a pointer to the 1st node in the list.
*/
void insertIntoLinkedList(char str2[], struct node** head2){
//pointer to a new node to be inserted into linked list
   struct node *newNode = NULL;
//pointer to the previous node in the linked list
   struct node *previous = NULL;
//pointer to the current node in the linked list
   struct node *current = *head2;

//create a node on the heap
   newNode = malloc(sizeof(struct node));
/*
check to see if space is available
if no space on heap, malloc() will return NULL
*/
   if(NULL != newNode){
   //copy over word to the node
      strcpy(newNode->strings, str2);
   //figure out where to insert in linked list
      while(NULL != current){
      //move previous to current
         previous = current;
      //move current to next node
         current = current->next;
      }//end of while
      //insert at beginning of linked list
      if(NULL == previous){
         newNode->next = current;
         //change the address stored in head
         *head2 = newNode; 
      }//end of if
      else{
      //insert between previous and current
         previous->next = newNode;
         newNode->next = current;
      }//end of else
   }//end of if
}//end of function


//displays the linked list
void displayLinkedList(struct node *current){
   //for empty list
   if(NULL == current){
      printf("The linked list is empty!\n\n");
      return;
   }
   // Output style from code written by me previously for data structures course.
   printf("->");
   while(NULL != current){
   //display each node
      printf("[ %s ]", current->strings);
      //go to next node
      current = current->next;
      if(NULL != current){
      printf("<-->");
      }
   }
   printf("<-");
   printf("\n\n");
}//end of function


void reverse(struct node** head2)
{
    struct node *prev   = NULL;
    struct node *current = *head2;
    struct node *next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head2 = prev;
}

/*
main method - asks the user to enter a word,
and inserts the word into a linked list in alphabetical order, 
and deletes words at the user's request.
*/
int main(){
//stores each word
   char str[256];
//stores a pointer to the 1st node in the linked list
   struct node *head = NULL;
   
   printf("This program will read strings until STOP is entered.\n");
   char STOP[] = {"STOP"};
   scanf("%[^\n]%*c", str);
   insertIntoLinkedList(str, &head);
   while(strcmp(str, STOP) != 0){
       printf("Please enter another string or enter STOP if finished.\n");
       *str;
       scanf("%[^\n]%*c", str);
             if(0 != strcmp(str, STOP)){
      //&head: send the address of the pointer to the 1st node in list
         	insertIntoLinkedList(str, &head);
                }
   }
  
   printf("Here is a list of the strings you entered.\n");
   displayLinkedList(head);
   
   reverse(&head);
   printf("Here is a reversed list of the strings you entered:\n");
   displayLinkedList(head);
   
   return 0;
}//end of main

