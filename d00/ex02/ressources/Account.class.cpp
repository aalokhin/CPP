#include "Account.class.hpp"
#include <iostream>


int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;


int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount = _totalAmount + initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;


}

Account::~Account( void )
{
	_nbAccounts--;
	Account::_displayTimestamp();
	std::cout <<  "index:" << _nbAccounts << ";amount:" << _amount << ";closed" << std::endl;
}


void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount\
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex <<\
	";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << (_amount + deposit) <<\
	";nb_deposits:" << (_nbDeposits + 1) << std::endl;
	 _amount = deposit + _amount;
	_nbDeposits++;
	_totalAmount = deposit + _totalAmount;
	_totalNbDeposits++;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
		";withdrawal:" << withdrawal << ";amount:" << (_amount - withdrawal) << \
		";nb_withdrawals:" << (_nbWithdrawals + 1) << std::endl;
		_amount = _amount - withdrawal;
		_nbWithdrawals++;
		_totalAmount =  _totalAmount - withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex <<\
		";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}	
}

int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount:" << std::endl;
	return 1;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount\
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;

}


 void Account::_displayTimestamp (void)  
{ 
    time_t t ; 
    struct tm *tmp ; 
    char current_time[20]; 
    time( &t ); 
    tmp = localtime(&t); 
    strftime(current_time, sizeof(current_time), "%Y%m%d_%H%M%S", tmp); 
    std::cout << "[" << current_time << "]";
    
}




// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
