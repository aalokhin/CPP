#ifndef STACK_HPP
#define STACK_HPP

#include "Fixed.class.hpp"

typedef struct			s_node		
{
    Fixed 				data;
    struct	s_node 		*next;
}						t_node;

class m_stack
{
    
    public:
    t_node *head;
    m_stack() { head = NULL;}
    void push(Fixed value);
    Fixed pop();
    Fixed top();
    void show();
};

#endif