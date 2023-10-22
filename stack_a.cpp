#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Stack_A::Stack_A()
{
    size=0;
}
void Stack_A::push(int data)
{
    if(size==1024)
    throw runtime_error("Stack Full");
    size++;
    stk[size-1]=data;
}
int Stack_A::pop()
{
    if(size==0)
    throw runtime_error("Empty Stack");
    size--;
    return stk[size];
}
int Stack_A::get_element_from_top(int idx)
{
    if(idx>=size)
    throw runtime_error("Index out of range");
    return stk[size-idx-1];
}
int Stack_A::get_element_from_bottom(int idx)
{
    if(idx>=size)
    throw runtime_error("Index out of range");
    return stk[idx];
}
void Stack_A::print_stack(bool top)
{
    if(top==1)
    {
        for(int i=0;i<size;i++)
        {
            cout<<stk[i]<<"\n";
        }
    }
    else
    {
        for(int i=size-1;i>=0;i--)
        {
            cout<<stk[i]<<"\n";
        }
    }
}
int Stack_A::add()
{
    if(size<2)
    throw runtime_error("Not Enough Arguments");
    size--;
    return stk[size-1]+=stk[size];
}
int Stack_A::subtract()
{
    if(size<2)
    throw runtime_error("Not Enough Arguments");
    size--;
    return stk[size-1]-=stk[size];
}
int Stack_A::multiply()
{
    if(size<2)
    throw runtime_error("Not Enough Arguments");
    size--;
    return stk[size-1]*=stk[size];
}
int Stack_A::divide()
{
    if(size<2)
    throw runtime_error("Not Enough Arguments");
    if(stk[size-1]==0)
    throw runtime_error("Divide by Zero Error");
    size--;
    int hate=stk[size-1]/stk[size];
    int bighate=stk[size-1]%stk[size];
    if((stk[size]>0&&bighate<0)||(stk[size]<0&&bighate>0))
    {
        hate-=1;
    }
    stk[size-1]=hate;
    return hate;
}
int* Stack_A::get_stack()
{
    return stk;
}
int Stack_A::get_size()
{
    return size;
}