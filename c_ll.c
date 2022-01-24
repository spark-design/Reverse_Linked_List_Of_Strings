/*
Example of a linked list of strings
*/

#include <stdio.h>
#include <stdlib.h> //has functions malloc() and free()
#include <string.h>
#define STOP "STOP" //end the loop
#define END_OF_STRING '\0'

/*
A self-referential structures contains a pointer 
that points to another structure of the same type
and link together to form dynamic data structures.
data: stores a word (string)
next: is a pointer to the next node
*/
struct node{
   char data[256];
   struct node *next;
};

//type definition for "new" data types
typedef struct node Node;
typedef struct node* NodePointer;
/*
  This function reads characters from the input steam,
  and stores the characters in a string, 
  and adds a null character ('\0') after the last character in the string. 
  It will read up to size-1 number of characters.
  And will read until the end of file, newline, blank space, or tab.
  And will leave the rest of the characters on the input stream.
  Warning: If the string array has less than size number of characters,
  this may crash the program, or write over memory!
  If there are no characters added to the string, a 0 is returned. 
  string: An array of characters, with size number of elements.
  size: The number of characters in the string array.
  returns: The number of characters read into the string.  
*/

int getstring(char string[], const int size){
   int index = 0;
   char character = 'z';
   //get input from the user
     for(index=0; index < size-1; index++){
      character = getchar();
      //check for end of file
      if(EOF == character)
         break;
      //check for end of line
      if('\n' == character)
         break;
      //check for space
      if(' ' == character)
         break;
      //check for a tab
      if('\t' == character)
         break;
      string[index] = character;
   }
   //add the null character
   string[index] = END_OF_STRING;
   return index; //number of characters in the string
}

/*
  This function reads characters from the input steam,
  and stores the characters in a string, 
  and adds a null character ('\0') after the last character in the string. 
  It will read up to size-1 number of characters.
  And will read until the end of file or newline.
  And will remove the rest of the characters from the input steam.
  Warning: If the string has less than size number of characters,
  this may crash the program, or write over memory!
  If there are no characters added to the string, a 0 is returned. 
  string: An array of characters, with size number of elements.
  size: The number of characters in the string array.
  returns: The number of characters read into the string.  
*/

int getline2(char string[], const int size){
   int index = 0;
   char character = 'z';
	//get input from the user
      for(index=0; index < size-1; index++){
      character = getchar();
	//check for end of file
      if(EOF == character)
         break;
	//check for end of line
      if('\n' == character)
         break;
      string[index] = character;
   }
   //add the null character
   string[index] = END_OF_STRING;
   
   //remove the rest of the characters from input stream
   while(('\n' != character) && (EOF != character)){
      character = getchar();
   }
   
   return index; //number of characters in the string
}

/*
Inserts a word in alphabetical order into a linked list
word2: is a string
head2: is the a pointer to the 1st node in a linked list 
This parameter is a pointer to a pointer, 
because we are passing the address of the linked list to the function, 
and the linked list itself is a pointer to the 1st node in the list.
*/
void insertIntoLinkedList(char word2[], NodePointer *head2){
//pointer to a new node to be inserted into linked list
   NodePointer newNode = NULL;
//pointer to the previous node in the linked list
   NodePointer previous = NULL;
//pointer to the current node in the linked list
   NodePointer current = *head2;

//create a node on the heap
   newNode = malloc(sizeof(Node));
/*
check to see if space is available
if no space on heap, malloc() will return NULL
*/
   if(NULL != newNode){
   //copy over word to the node
      strcpy(newNode->data, word2);
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
void displayLinkedList(NodePointer current){
   //for empty list
   if(NULL == current){
      printf("The linked list is empty!\n\n");
      return;
   }
   //loop through list
   printf("->");
   while(NULL != current){
   //display each node
      printf("[ %s ]", current->data);
      //go to next node
      current = current->next;
      if(NULL != current){
      printf("<-->");
      }
   }
   printf("<-");
   printf("\n\n");
}//end of function


void reverse(NodePointer *head2)
{
    NodePointer prev   = NULL;
    NodePointer current = *head2;
    NodePointer next;
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
   char word[256]={'\0'};
//stores a pointer to the 1st node in the linked list
   NodePointer head = NULL;
   
   printf("This program will read strings until STOP is entered.");
//keep inserting until user enters "stop"
   while(0 != strcmp(word, STOP)){
      printf("Please enter another strng or enter STOP if finished. \n");
      getline2(word, 256);
      if(0 != strcmp(word, STOP)){
      //&head: send the address of the pointer to the 1st node in list
         insertIntoLinkedList(word, &head);
      }
   }//end of while
   
   if(0 == strcmp(word, STOP)){
     printf("\nHere is a list of the strings you entered:\n");
     displayLinkedList(head);
      }
      
   reverse(&head);
   printf("Here is a reversed list of the strings you entered:\n");
   displayLinkedList(head);
   
   return 0;
}//end of main

   

