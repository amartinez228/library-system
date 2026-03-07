#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dlist_init(DList *list, void (*destroy)(void *data)) {
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
  return;
}
void dlist_destroy(DList *list) {
  void *data;
  while (dlist_size(list) > 0) {
    if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 &&
        list->destroy != NULL) {
      list->destroy(data);
    }
  }
  memset(list, 0, sizeof(DList));
  return;
}
int dlist_ins_next(DList *list, DListElmt *element, const void *data) {
  DListElmt *new_element;
  if (element == NULL && dlist_size(list) != 0)
    return -1;
  if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
    return -1;
  new_element->data = (void *)data;
  if (dlist_size(list) == 0) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } else {
    new_element->next = element;
    new_element->next = element;
    if (element->next == NULL)
      list->tail = new_element;
    else
      element->next->prev = new_element;
    element->next = new_element;
  }
  list->size++;
  return 0;
}
int dlist_ins_prev(DList *list, DListElmt *element, const void *data) {
  DListElmt *new_element;
  if (element == NULL && dlist_size(list) != 0)
    return -1;
  if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
    return -1;
  new_element->data = (void *)data;
  if (dlist_size(list) == 0) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } else {
    new_element->next = element;
    new_element->prev = element->prev;
    if (element->prev == NULL)
      list->head = new_element;
    else
      element->prev->next = new_element;
    element->prev = new_element;
  }
  list->size++;
  return 0;
}
int dlist_remove(DList *list, DListElmt *element, void **data) {
  if (element == NULL || dlist_size(list) == 0)
    return -1;
  *data = element->data;
  if (element == list->head) {
    list->head = element->next;
    if (list->head == NULL)
      list->tail = NULL;
    else
      element->next->prev = NULL;
  } else {
    element->prev->next = element->next;
    if (element->next == NULL)
      list->tail = element->prev;
    else
      element->next->prev = element->prev;
  }
  free(element);
  list->size--;
  return 0;
}

int cardFillout(struct libraryCard *x) {
  puts("So you'd like to apply for a card.");
  puts("Alright but first we need your name");
  scanf("%s", x->name);
  puts("Alirghty and we need an address on file");
  scanf("%s", x->address);
  puts("And finally a phone number");
  scanf("%d", x->phoneNumber);
  return 0;
}
int printCardInfo(struct libraryCard *x) {
  printf("Alight here we have the name: %s\n", x->name);
  printf("And here we have the address: %s\n", x->address);
  printf("And finally we have the phoneNumber: %d", x->phoneNumber);
  return 0;
}
int who_are_you(struct libraryCard *x) {
  printf("This is the list of everyone with a libraryCard: %s\n", x->name);
  return 0;
}

// still need to implement dlist_head and dlist_tail
int main(int argc, char *argv[]) {
  DList list;
  dlist_init(&list, NULL); // we set destroy to null b/c it should not be freed
  int i = 0;
  int options;
  while (!i) {
    printf("Hello there how can I help you today\n1)Get a new "
           "card\n2)printCardInfo\n3)No just leaving");
    scanf("%d", &options);
    switch (options) {
    case 1:
      // first we will allocate our Dlist element then we have to set the
      // pointer to point at a new libraryCard struct
      DListElmt *new_elmt = malloc(sizeof(DListElmt));
      if (new_elmt->data != NULL)
        perror("Malloc for the new Doubly linked list failed");
      exit(EXIT_FAILURE);
      new_elmt->data = malloc(sizeof(libraryCard));
      if (new_elmt->data == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
        cardFillout(new_elmt->data);
        if (dlist_ins_next(&list, NULL, new_elmt) != 0) {
          perror("Insertion to list failed");
          free(new_elmt->data);
          exit(EXIT_FAILURE);
        }
      }
      break;
    case 2:
      if (list.size != 0) {
        for (int i = 0; i < list.size; i++) {
          // function call to get printed out information
          printf("Alright %s has a libraryCard\n", list.head->data->name);
        }
        break;
      } else {
        printf("It looks like no one has any library cards");
        break;
      }
    case 3:
      puts("Alirght thank you please come again");
      break;
    default:
      puts("Invalid option");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
