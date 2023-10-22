#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;
List::List()
{
    try
    {
        sentinel_head = new Node();
        sentinel_tail = new Node();
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    size=0;
}
List::~List()
{
    Node *temp = sentinel_tail;
    while (temp->prev != sentinel_head)
    {
        temp = temp->prev;
        delete temp->next;
    }
    delete sentinel_head->next;
    delete sentinel_head;
    size=0;
}

void List::insert(int v)
{
    Node *bef = sentinel_tail->prev;
    Node*temp;
    try
    {
        temp = new Node(v, sentinel_tail, bef);
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
    bef->next = temp;
    sentinel_tail->prev = temp;
    size++;
}

int List::delete_tail()
{
    Node *temp = sentinel_tail->prev->prev;
    int sux = sentinel_tail->prev->get_value();
    delete sentinel_tail->prev;
    temp->next = sentinel_tail;
    sentinel_tail->prev = temp;
    size--;
    return sux;
}
int List::get_size()
{
    return size;
}
Node *List::get_head()
{
    return sentinel_head;
}