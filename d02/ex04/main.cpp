#include "Fixed.class.hpp"
#include "Stack.hpp"

bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool Is_Digit_or_dot2(char c)
{
	if (c == '.' || ((c>= '0') && (c<='9')))
		return true;
	return false;
}

bool Is_Operator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool Is_Bracket(char c)
{
	if(c == '(' || c == ')')
		return true;
	return false;
}

bool Is_Space(char c)
{
	if(c == ' ')
		return true;
	return false;
}



Fixed PerformOperation(Fixed operation, Fixed operand1, Fixed operand2)
{
	if(operation == '+') return operand1 + operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else std::cout<<"Unexpected Error \n";
	exit(1);
}

float EvaluatePostfix(std::string expression)
{
	m_stack mystack;

	size_t i;
	for(i = 0;i < expression.length(); i++)
	{
		if(expression[i] == ',')
			continue;
		else if(Is_Operator(expression[i]))
		{
			Fixed operand2 = mystack.top();
			mystack.pop();
			Fixed operand1 = mystack.top();
			mystack.pop();
			Fixed result = PerformOperation(expression[i], operand1, operand2);
			mystack.push(result);
		}
		else if(IsNumericDigit(expression[i]))
		{
			float operand_input = 0;
			std::stringstream ss(&(expression[i]));
  			ss >> operand_input;
  			Fixed operand(operand_input);
			while(Is_Digit_or_dot2(expression[i]))
  				i++;
			i--;
			mystack.push(operand);
		}
	}
	float res = mystack.top().toFloat();
	return res;
}

int				check_input(std::string expr)
{
	size_t i = 0;
	size_t leng_str = expr.length();
	while (leng_str)
	{
		if (!Is_Operator(expr[i]) && !Is_Digit_or_dot2(expr[i]) &&\
		!Is_Bracket(expr[i]) && !Is_Space(expr[i]) && !IsNumericDigit(expr[i]))
			return (0);
		leng_str--;
		i++;
	}
	return 1;

}

bool 			brackets_match(std::string expr)
{
	size_t r = 0;
	size_t l = 0;
	size_t i = 0;
	size_t leng_str = expr.length();
	while (leng_str)
	{
		if (expr[i] == '(')
			l++;
		else if (expr[i] == ')')
			r++;
		i++;
		leng_str--;
	}
	if (r == l)
		return true ;
	else
		return false;

}

bool 			operators_match(std::string expr)
{
	size_t o = 0;
	size_t d = 0;
	size_t i = 0;
	
	size_t leng_str = expr.length();
	while (leng_str)
	{
		if (Is_Operator(expr[i]))
			o++;
		if (IsNumericDigit(expr[i]))
		{
			d++;
			while((IsNumericDigit(expr[i]) || expr[i] == '.') && leng_str)
			{
				i++;
				leng_str--;
			}
		}
		i++;
		leng_str--;
	}
	if (o == d - 1)
		return true ;
	else
		return false;

}

int 			main( int argc, char **argv )
{
	if (argc != 2 || !strlen(argv[1]) || check_input(argv[1]) == 0)
	{
		system("echo \"\033[0;31m\"");

		std::cerr << "Input Error!!!\nEnter arithmetic expression in the format \"(2.03 + 12.41) * 6\"\nThank you for undertsanding!"  << std::endl;
		return (1);
	}
	std::string cases(argv[1]);

	if (!brackets_match(cases))
	{
		system("echo \"\033[0;31m\"");
		std::cerr << "Input Error!!!\nEnter arithmetic expression in the format \"(2.03 + 12.41) * 6\"\nThank you for undertsanding!"  << std::endl;
		return (1);
	}

	std::string res = Conv_to_Postfix(cases);
	std::cout << res << std::endl;

	if (!operators_match(res))
	{
		system("echo \"\033[0;31m\"");
		std::cerr << "Input Error!!!\nEnter arithmetic expression in the format \"(2.03 + 12.41) * 6\"\nThank you for undertsanding!"  << std::endl;
		return (1);
	}

	float final_res = EvaluatePostfix(res);
	std::cout << final_res <<"\n";
	return 0;
}
