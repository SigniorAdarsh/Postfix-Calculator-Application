#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    try
    {
        stk = new int[capacity];
    }
    catch(bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}
Stack_B::~Stack_B()
{
    delete []stk;
}
void GrowMeBaby(int *&str, int &capacity)
{
    int *lubu;
    try
    {
        lubu = new int[capacity * 2];
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
    for (int i = 0; i < capacity; i++)
    {
        lubu[i] = str[i];
    }
    delete []str;
    str = lubu;
    capacity *= 2;
}
void KillMeBaby(int *&str, int &capacity)
{
    int*dlubu;
    try
    {
        dlubu = new int[capacity / 4];
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
    for (int i = 0; i < capacity / 4; i++)
    {
        dlubu[i] = str[i];
    }
    delete[] str;
    str = dlubu;
    capacity /= 4;
}
void Stack_B::push(int data)
{
    if (size == capacity)
    {
        GrowMeBaby(stk, capacity);
    }
    size++;
    stk[size - 1] = data;
}
int Stack_B::pop()
{
    if (size == 0)
        throw runtime_error("Empty Stack");
    int dummy = stk[size - 1];
    if (size <= (capacity / 4 + 1) && capacity >= 4096)
    {
        KillMeBaby(stk, capacity);
    }
    size--;
    return dummy;
}
int Stack_B::get_element_from_top(int idx)
{
    if (idx >= size)
        throw runtime_error("Index out of range");
    return stk[size - idx - 1];
}
int Stack_B::get_element_from_bottom(int idx)
{
    if (idx >= size)
        throw runtime_error("Index out of range");
    return stk[idx];
}
void Stack_B::print_stack(bool top)
{
    if (top == 1)
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << "\n";
        }
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << stk[i] << "\n";
        }
    }
}
int Stack_B::add()
{
    if (size < 2)
        throw runtime_error("Not Enough Arguments");
    int dummy = stk[size - 1];
    if (size <= (capacity / 4 + 1) && capacity >= 4096)
    {
        KillMeBaby(stk, capacity);
    }
    size--;
    return stk[size - 1] += dummy;
}
int Stack_B::subtract()
{
    if (size < 2)
        throw runtime_error("Not Enough Arguments");
    int dummy = stk[size - 1];
    if (size <= (capacity / 4 + 1) && capacity >= 4096)
    {
        KillMeBaby(stk, capacity);
    }
    size--;
    return stk[size - 1] -= dummy;
}
int Stack_B::multiply()
{
    if (size < 2)
        throw runtime_error("Not Enough Arguments");
    int dummy = stk[size - 1];
    if (size <= (capacity / 4 + 1) && capacity >= 4096)
    {
        KillMeBaby(stk, capacity);
    }
    size--;
    return stk[size - 1] *= dummy;
}
int Stack_B::divide()
{
    if (size < 2)
        throw runtime_error("Not Enough Arguments");
    if (stk[size - 1] == 0)
        throw runtime_error("Divide by Zero Error");
    int dummy = stk[size - 1];
    if (size <= (capacity / 4 + 1) && capacity >= 4096)
    {
        KillMeBaby(stk, capacity);
    }
    size--;
    int hate=stk[size-1]/dummy;
    int bighate=stk[size-1]%dummy;
    if((dummy>0&&bighate<0)||(dummy<0&&bighate>0))
    {
        hate-=1;
    }
    stk[size-1]=hate;
    return hate;
}
int *Stack_B::get_stack()
{
    return stk;
}
int Stack_B::get_size()
{
    return size;
}