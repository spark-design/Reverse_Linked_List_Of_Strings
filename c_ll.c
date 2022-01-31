/* Sources: 
https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define STOP "STOP"

struct node{
   char strings[256];
   struct node *next;
}Node;

typedef struct node* NodePointer;

// insert str into linked list
void insert(char word2[], NodePointer *head2){

   // initialize nodes
   NodePointer newNode = NULL;
   NodePointer previous = NULL;
   NodePointer current = *head2;

   // allocate memory for newnode to insert
   newNode = malloc(sizeof(Node));

   // if new node isn't empty, copy strings
   if(newNode != NULL){
      strcpy(newNode->strings, word2);
      
      // if the current node isn't empty, point to next node
      while(current != NULL){
         previous = current;
         current = current->next;
      }
      
      // if previous node is null then this is the head
      if(previous == NULL){
         newNode->next = current;
         *head2 = newNode; 
      }
      
      // if previous node isn't null
      if(previous != NULL){
         previous->next = newNode;
         newNode->next = current;
      }
   }
}

// reverse and then display linked list
void display(NodePointer current){

// initialize nodes
    NodePointer prev   = NULL;
    NodePointer next;
    
    // while the current node isn't null
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    current = prev;
    
   // if current is null then the list is empty and function ends
   if(current == NULL){
      printf("The linked list is empty!\n\n");
      return;
   }
   
   // print start of linked list pointer
   printf("->");
   
   // while current node isn't null, print the node and move to next
   while(current != NULL){
      printf("[ %s ]", current->strings);
      current = current->next;
      
      // separate if for printing purposes
      if(current != NULL){
      printf("<-->");
      }
   }
   
   // print end of linked list pointer
   printf("<-");
   printf("\n\n");
}


int main(){

   // initialize character array and node
   char str[256];
   NodePointer head = NULL;
   
   // get and insert string input
   printf("This program will read strings until STOP is entered.\n");
   scanf("%[^\n]%*c", str);
   insert(str, &head);
   
   // loop until stop is entered
   while(0 != strcmp(str, STOP)){
      printf("Please enter another strng or enter STOP if finished. \n");
      *str;
      scanf("%[^\n]%*c", str);
      if(0 != strcmp(str, STOP)){
         insert(str, &head);
      }
   }
   
   // once stop is entered, display reverse list of strings
   if(0 == strcmp(str, STOP)){
     printf("\nHere is a reversed list of the strings you entered:\n");
     display(head);
      }
      
   
   return 0;
}
