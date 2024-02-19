#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    void *data;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct LL {
    ListNode* head;
    ListNode* tail;
    int length;
};
typedef struct LL LL;

// get, get_front, get_back
// insert, insert_front, insert_back
// remove, remove_front, remove_back
// size
//
// rev, shift_left, shift_right
void LL_init(LL* ll);
LL*  LL_new();
void LL_free(LL* ll);

void *LL_get_node(LL* ll, int index);
void *LL_get_front_node(LL* ll);
void *LL_get_back_node(LL* ll);

void *LL_get(LL* ll, int index);
void *LL_get_front(LL* ll);
void *LL_get_back(LL* ll);

void LL_insert(LL* ll, int index, void *item);
void LL_insert_front(LL* ll, void *item);
void LL_insert_back(LL* ll, void *item);

void *LL_remove(LL* ll, int index);
void *LL_remove_back(LL *ll);
void *LL_remove_front(LL* ll);

int LL_length(LL* ll);

#endif // LINKEDLIST_H