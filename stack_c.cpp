#include "stack_c.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Stack_C::Stack_C()
{
    stk = new List();
}
Stack_C::~Stack_C()
{
    delete stk;
}
void Stack_C::push(int data)
{
    try
    {
        stk->insert(data);
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}
int Stack_C::pop()
{
    if (stk->get_size() == 0)
    {
        throw runtime_error("Empty Stack");
    }
    return stk->delete_tail();
}
int Stack_C::get_element_from_top(int idx)
{
    if (idx >= stk->get_size()||idx<0)
        throw runtime_error("Index out of range");
    idx = stk->get_size() - idx - 1;
    return get_element_from_bottom(idx);
}

int Stack_C::get_element_from_bottom(int idx)
{
    if (idx >= stk->get_size()||idx<0)
        throw runtime_error("Index out of range");
    Node *temp = stk->get_head()->next;
    while (idx > 0)
    {
        temp = temp->next;
        idx--;
    }
    return temp->get_value();
}

void Stack_C::print_stack(bool top_or_bottom)
{
    Node *temp = stk->get_head()->next;
    int arr[stk->get_size()];
    for (int i = 0; i < stk->get_size(); i++)
    {
        arr[i] = temp->get_value();
        temp = temp->next;
    }
    if (top_or_bottom == 0)
    {
        for (int i = 0; i < stk->get_size(); i++)
        {
            cout << arr[i] << "\n";
        }
    }
    else
    {
        for (int i = stk->get_size() - 1; i >= 0; i--)
        {
            cout << arr[i] << "\n";
        }
    }
}
int Stack_C::add()
{
    if (stk->get_size() < 2)
        throw runtime_error("Not Enough Arguments");
    int love = stk->delete_tail();
    int biglove = stk->delete_tail();
    stk->insert(love + biglove);
    return (love + biglove);
}
int Stack_C::subtract()
{
    if (stk->get_size() < 2)
        throw runtime_error("Not Enough Arguments");
    int love = stk->delete_tail();
    int biglove = stk->delete_tail();
    stk->insert(biglove - love);
    return (biglove - love);
}

int Stack_C::multiply()
{
    if (stk->get_size() < 2)
        throw runtime_error("Not Enough Arguments");
    int love = stk->delete_tail();
    int biglove = stk->delete_tail();
    stk->insert(biglove * love);
    return (biglove * love);
}

int Stack_C::divide()
{
    if (stk->get_size() < 2)
        throw runtime_error("Not Enough Arguments");
    int love = stk->delete_tail();
    if (love == 0)
        throw runtime_error("Divide by Zero Error");
    int biglove = stk->delete_tail();
    int hate=biglove/love;
    int bighate=biglove%love;
    if((love>0&&bighate<0)||(love<0&&bighate>0))
    {
        hate-=1;
    }
    stk->insert(hate);
    return hate;
}

List *Stack_C::get_stack()
{
    return stk;
}

int Stack_C::get_size()
{
    return stk->get_size();
}
