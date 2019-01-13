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
	std::cout << "[20150406_153629] " << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;


}

Account::~Account( void )
{
	_nbAccounts--;
	std::cout << "[20150406_153629] " << "index:" << _nbAccounts << ";amount:" << _amount << ";closed" << std::endl;
}


void Account::displayAccountsInfos(void)
{
	//std::cout << "displayAccountsInfos:" << std::endl << std::endl;

	std::cout << "[20150406_153629] " << "accounts:" << _nbAccounts << ";total:" << _totalAmount\
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	//std::cout << " make deposit is : " << deposit << std::endl << std::endl;

	std::cout << "[20150406_153629] " << "index:" << _accountIndex <<\
	";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << (_amount + deposit) <<\
	";nb_deposits:" << (_nbDeposits + 1) << std::endl;


	 _amount = deposit + _amount;
	_nbDeposits++;

	_totalAmount = deposit + _totalAmount;
	_totalNbDeposits++;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	//std::cout << "withdrawal:" <<  withdrawal << std::endl;
	if (withdrawal <= _amount)
	{
		std::cout << "[20150406_153629] "  << "index:" << _accountIndex << ";p_amount:" << _amount << \
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
		std::cout << "[20150406_153629] "  << "index:" << _accountIndex <<\
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
	//std::cout << "displayStatus:" << std::endl;

	std::cout << "[20150406_153629] " << "index:" << _accountIndex << ";amount:" << _amount\
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;

}




// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
