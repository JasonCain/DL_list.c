#ifndef DL_LIST_H
#define DL_LIST_H

#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

//! Use this macro for casting your destructors.
#define DL_as_dtor(f) ((void (*)(void**, size_t))(f))

//! Use this macro for casting your clone function.
#define DL_as_clone(f) ((void* (*)(void*, size_t))(f))

//! Casting to internal representation.
#define DL_as_data(d) ((void*)(d))

//! Recast in your type.
#define DL_from_data(type, data) ((type*)(data))

//! Private type.
typedef struct _DL_node {
  struct _DL_node* next;
  struct _DL_node* prev;
  void* data; // Data to store we know nothing about it. If were storing an array please use vector like type.
} DL_node;

// Accept only one type of data Undefined behaviour with mixed datatype.
typedef struct {
  DL_node* head; // Private.
  DL_node* tail; // Private
  size_t length; // Private: number of node in the list.
  size_t type_size; // Private: Datatype size equivalent to typeof(T)
  void(*dtor)(void**, size_t); // Private: Destructor for our data.
  void*(*clone)(void*, size_t); // Private: Destructor for our data.
} DL_list;

// Allocate a new list.
// dtor: destructor of for the givien void* data
DL_list* DL_new(size_t size, void(*dtor)(void**, size_t size), void*(*clone)(void*, size_t));

//! return the size O(1).
size_t DL_length(const DL_list* self);

//! return the head. Cause an exit(1) if called on empty list.
void* DL_front(const DL_list* self);

//! return the back. exit(1) with empty list.
void* DL_back(const DL_list*self);

//! Return true if the list is empty.
//! Complexity: O(1)
bool DL_is_empty(const DL_list* self);

// Add on tail.
// Complexity: O(1)
void DL_push_back(DL_list* self, void* data);

// Clean the list but do not free the list itself.
void DL_clear(DL_list* self);

// Add on head.
// Complexity: O(1)
void DL_push_front(DL_list* self, void* data);

//! Concatenate B to A in O(1) with A self modification.
void DL_concat(DL_list* self, DL_list* b);

//! append B to A O(n) and return a new list.
DL_list* DL_concat_mut(const DL_list* self, const DL_list* b);

//! Insert a data in the lista at an index.
void DL_insert(DL_list* self, size_t index, void* data);

//! Copy a list with a `f_cpy` function.
DL_list* DL_copy(const DL_list* self, void*(f_cpy)(void*, size_t));

//! Return a new list reversed from self.
DL_list* DL_reverse(const DL_list* self);

//! Reverse in place self.
void DL_reverse_mut(DL_list* self);

//! TODO
DL_list* DL_sort(const DL_list* self);

//! TODO
void DL_sort_mut(DL_list* self);

//! Return a new list composed of entry that matched the predicate p.
DL_list* DL_filter(const DL_list* self, DL_list*(*p)(void*));

//! Remove last elem and return it.
void* DL_pop(DL_list* self);

//! Delete the list given in parameter and set as null the pointer.
void DL_drop(DL_list** self);

#endif // DL_LIST
