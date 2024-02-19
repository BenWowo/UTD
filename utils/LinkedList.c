#include <assert.h>
#include <stdlib.h>
#include "LinkedList.h"

void LL_init(LL* ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
}

LL*  LL_new() {
    LL* ll = (LL*)malloc(sizeof(LL));
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
    return ll;
}

void LL_free(LL* ll) {
    // TODO - actually make this good...
    free(ll);
    ll = NULL;
}


void *LL_get_node(LL* ll, int index) {
    assert(0 <= index && index < ll->length);
    if(index == 0) {
        return LL_get_front_node(ll);
    } else if(index == ll->length-1) {
        return LL_get_back_node(ll);
    }
    ListNode* cur = ll->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur;
}
void *LL_get_front_node(LL* ll) {
    assert(ll->length > 0);
    return ll->head;
}
void *LL_get_back_node(LL* ll) {
    assert(ll->length > 0);
    return ll->tail;
}

void *LL_get(LL* ll, int index) {
    ListNode* node = LL_get_node(ll, index);
    return node->data;
}
void *LL_get_front(LL* ll) {
    ListNode* node = LL_get_front_node(ll);
    return node->data;
}
void *LL_get_back(LL* ll) {
    ListNode* node = LL_get_back_node(ll);
    return node->data;
    // return NULL;
}

void LL_insert(LL* ll, int index, void *item) {
    if (index == 0) {
        LL_insert_front(ll, item);
        return;
    }

    // assert position
    assert(0 <= index && index <= ll->length);
    if (index == ll->length) {
        LL_insert_back(ll, item);
    } else {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->data = item;
        ListNode* old_prev = LL_get_node(ll, index-1);
        ListNode* new_next = LL_get_node(ll, index);
        old_prev->next = node;
        node->next = new_next;
        ll->length += 1;
    }
}
void LL_insert_front(LL* ll, void *item) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    if (ll->length == 0) {
        ll->head = node;
        ll->tail = node;
    } else {
        ListNode* oldhead = ll->head;
        ll->head = node;
        ll->head->next = oldhead;
    }
    ll->length += 1;
}
void LL_insert_back(LL* ll, void *item) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    if (ll->length == 0) {
        ll->head = node;
        ll->tail = node;
    } else {
        ll->tail->next = node;
        ll->tail = node;
    }
    ll->length += 1;
}

// We can't free deleted node because they might use it :(
// This results in a ussage that will look like this
// free(LL_remove_back(ll))
// there probably will be memory leaks :(
// what if I create a copy of the node and free the original one?
void *LL_remove(LL* ll, int index) {
    assert(ll->length > 0);
    assert(0 <= index && index < ll->length);
    if (index == 0) {
        return LL_remove_front(ll);
    } else if (index == ll->length-1) {
        return LL_remove_back(ll);
    } else {
        ListNode* prev = LL_get_node(ll, index - 1);
        ListNode* node = LL_get_node(ll, index);
        ListNode* next = LL_get_node(ll, index + 1);
        prev->next = next;
        ll->length -= 1;
        return node;
    }
}
void *LL_remove_back(LL *ll) {
    assert(ll->length > 0);

    ListNode* tail = ll->tail;
    void* tail_data = ll->tail->data;
    if (ll->length == 1) {
        ll->head = NULL;
        ll->tail = NULL;
    } else{
        ListNode* new_tail = LL_get_node(ll, ll->length - 1);
        ll->tail = new_tail;
    }

    // free(tail);
    // tail = NULL;
    ll->length -= 1;
    return tail_data;
}
void *LL_remove_front(LL* ll) {
    assert(ll->length > 0);

    ListNode* head = ll->head;
    void* head_data = head->data;
    if (ll->length == 1) {
        ll->head = NULL;
        ll->tail = NULL;
    } else {
        ll->head = ll->head->next;
    }

    // free(head);
    // head=NULL;
    ll->length -= 1;
    return head_data;
}

int LL_length(LL* ll) {
    return ll->length;
}