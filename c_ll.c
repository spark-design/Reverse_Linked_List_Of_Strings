/*
Student Name: Connor Sparkman
Student NetID: cps260 
Compiler Used: Linux CMD 
Program Description: 
Take string input, insert into linked list, reverse and then display linked list

Sources: 
https://www.cplusplus.com/reference/cstring/strcpy/
https://www.tutorialspoint.com/cprogramming/c_structures.htm
https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
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
   
   // loop until stop is entered. Loop scans string inputs, puts them into linked list, and once stop is entered reverses and displays list
   while(0 != strcmp(str, STOP)){
      printf("Please enter another strng or enter STOP if finished. \n");
      *str;
      scanf("%[^\n]%*c", str);
      if(0 != strcmp(str, STOP)){
         insert(str, &head1);
      }
      if(0 == strcmp(str,STOP)){
      // once stop is entered, display reverse list of strings
      printf("\nHere is a reversed list of the strings you entered:\n");
      display(head1);
      return 0;
   }}}
