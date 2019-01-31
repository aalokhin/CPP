#include <iostream>
#include <string>
#include "Fixed.class.hpp"

bool Is_Digit(char c)
{
	if ((c >= '0') && (c <= '9'))
		return true;
	return false;
}

bool Is_Digit_or_dot(char c)
{
	if (c == '.' || ((c>= '0') && (c<='9')))
		return true;
	return false;
}

bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	return false;
}

int oper_priority(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/')
		return 2;
	return 0;
}

bool check_Priority(char a, char b)
{
	if (oper_priority(a) >= oper_priority(b))
		return true;
	return false;
}

std::string pop(std::string s)
{
	return s.substr(0, s.size() - 1);
}

std::string Conv_to_Postfix(std::string infix)
{
	std::string	postfix;
	std::string stack;
	size_t i;

	
	for(i=0; i < infix.length(); ++i)
	{
		if(Is_Digit(infix[i]))
		{
			while(Is_Digit_or_dot(infix[i]))
			{
				postfix.push_back(infix[i]);
				i++;
			}
			i--;
			postfix.push_back(',');
		}
		else if(is_operator(infix[i]))
		{
			if(stack.empty())
			{
				stack.push_back(infix[i]);
			}
			else if(!stack.empty())
			{
				if(infix[i]=='(')
				{
				   stack.push_back(infix[i]);
				}
				else if(infix[i]==')')
				{
					while(*(stack.end()-1) != '(')
					{
						postfix.push_back(*(stack.end() - 1));
						stack = pop(stack);
					}
					stack = pop(stack);
				}
				else
				{
					while(check_Priority(*(stack.end() - 1), infix[i]))
					{
						postfix.push_back(*(stack.end() - 1));
						stack = pop(stack);
					}
					if(!(check_Priority(*(stack.end() - 1), infix[i])))
						stack.push_back(infix[i]);
				}
			}
		}
	}
	while(!stack.empty())
	{
		std::string::iterator tos = stack.end() - 1;
		postfix.push_back(*tos);
		stack = pop(stack);
	}
	return postfix;
}