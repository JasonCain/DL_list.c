#include <stdlib.h>
#include <stdio.h>

#include "DL_list.h"
#include "mini_projet.h"

void read_file (FILE* f) {
  char* tmp = NULL;
  GetChaine(f, 100000, tmp);
  printf("%s", tmp);
}

book* new_book (char* t, char* a, int n) {
  book* tmp = malloc (sizeof(book));
  tmp->title = t;
  tmp->author = a;
  tmp->num = n;
  return tmp;
}

void* data (book* book) {
  void* tmp = book;
  return book;
}

int main () {
  FILE* file = fopen("GdeBiblio.txt", "r");
  read_file (file);
  int input;
  bool exit = false;
  printf ("Bonjour, que souhaiter vous faire ?\n");
  while (exit =! true) {
    printf ("1. Crée une liste\n");
    printf ("2. Ajouter un élément en début de liste\n");
    printf ("3. Ajouter un élément en fin de liste\n");
    printf ("4. Assembler deux listes\n");
    printf ("5. Inserer dans une liste\n");
    printf ("6. Copier une liste\n");
    scanf ("%d", &input);
    switch (input) {
      case 1 :
        printf ("Donner un élément pour initialiser la liste : ");
        scanf ("%d", &input);

        break;
      default :
        exit = true;
        break;
    }
  }
  int fclose(FILE* file);
}
