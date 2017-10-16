#include <stdio.h>
#include <stdlib.h>

struct node { char c; struct node *next;};

void print_list(struct node *a){
  printf("%c", a->c);    
  if (a->next != 0){
    print_list(a-> next);
  }
}

struct node * insert_front(struct node *a, char c){
  struct node *newnood;
  newnood = malloc(sizeof(struct node));
  newnood->c = c;
  newnood->next = a;
  return newnood;
  }

struct node * free_list(struct node *a){
  if (a->next != 0){
    free_list(a-> next);
  }
  free(a);
}

int main(){
  struct node * noodle;
  noodle = malloc(sizeof(struct node));
  noodle->c = 'a';
  noodle->next = 0;
  
  printf("print_list(noodle): ");
  print_list(noodle);
  printf("\n\n");

  printf("insert_front mutiple times \n");
  noodle = insert_front(noodle, 'k');
  noodle = insert_front(noodle, 'a');
  noodle = insert_front(noodle, 'b');

  printf("print_list(noodle): ");
  print_list(noodle);
  printf("\n\n");

  free_list(noodle);

  printf("after free_listing noodle expected bad stuff \n");
  printf("%c \n", noodle->c);
  printf("print_list(noodle): ");
  print_list(noodle);
  printf("\n");
  
	
}
