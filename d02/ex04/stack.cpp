#include "Stack.hpp"

void m_stack::push(Fixed value)
{
    t_node *ptr;

    ptr = new t_node;
    ptr->data=value;
    ptr->next=NULL;
    if(head != NULL)
        ptr->next=head;
    head=ptr;
}

/* POP Operation */ 
Fixed m_stack::pop()
{
    t_node *temp;
    Fixed ret(0);

    if(head==NULL)
        return (ret);
    temp=head;
    head=head->next;
    return temp->data;
}

Fixed m_stack::top()
{
    t_node *temp=head;
    return temp->data;
}


/* Show stack util */
void m_stack::show()
{
    t_node *ptr1=head;
    std::cout<<"\nThe stack is\n";
    while(ptr1!=NULL)
    {
        std::cout << ptr1->data.toFloat() <<" ->";
        ptr1=ptr1->next;
    }
    std::cout<<"NULL\n";
}
