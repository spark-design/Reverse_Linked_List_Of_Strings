/* Sources: 
https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define STOP "STOP"

struct node{
   char strings[256];
   struct node *after;
}Node;

typedef struct node* ptr;

// insert str into linked list
void insert(char word2[], ptr *newhead1){

   // initialize nodes
   ptr node1 = NULL;
   ptr before = NULL;
   ptr start = *newhead1;

   // allocate memory for node1 to insert
   node1 = malloc(sizeof(Node));

   // if new node isn't empty, copy strings
   if(node1 != NULL){
      strcpy(node1->strings, word2);
      
      // if the start node isn't empty, point to after node
      while(start != NULL){
         before = start;
         start = start->after;
      }
      
      // if before node is null then this is the head1
      if(before == NULL){
         node1->after = start;
         *newhead1 = node1; 
      }
      
      // if before node isn't null
      if(before != NULL){
         before->after = node1;
         node1->after = start;
      }
   }
}

// reverse and then display linked list
void display(ptr start){

// initialize nodes
    ptr prev   = NULL;
    ptr after;
    
    // while the start node isn't null
    while (start != NULL)
    {
        after  = start->after;  
        start->after = prev;   
        prev = start;
        start = after;
    }
    start = prev;
    
   // if start is null then the list is empty and function ends
   if(start == NULL){
      printf("The linked list is empty!\n\n");
      return;
   }
   
   // print start of linked list pointer
   printf("->");
   
   // while start node isn't null, print the node and move to after
   while(start != NULL){
      printf("[ %s ]", start->strings);
      start = start->after;
      
      // separate if for printing purposes
      if(start != NULL){
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
   ptr head1 = NULL;
   
   // get and insert string input
   printf("This program will read strings until STOP is entered.\n");
   scanf("%[^\n]%*c", str);
   insert(str, &head1);
   
   // loop until stop is entered
   while(0 != strcmp(str, STOP)){
      printf("Please enter another strng or enter STOP if finished. \n");
      *str;
      scanf("%[^\n]%*c", str);
      if(0 != strcmp(str, STOP)){
         insert(str, &head1);
      }
   }
   
   // once stop is entered, display reverse list of strings
   if(0 == strcmp(str, STOP)){
     printf("\nHere is a reversed list of the strings you entered:\n");
     display(head1);
      }
      
   
   return 0;
}
