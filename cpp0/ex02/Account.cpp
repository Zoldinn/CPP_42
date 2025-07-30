#include <iostream>
#include <ctime>
#include "Account.hpp"

/**========================================================================
 *                           Constructor/Destructor
 *========================================================================**/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	return ;
}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts++),
											_nbDeposits(0), _nbWithdrawals(0)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
	return ;
}

/**========================================================================
 *                           Getters
 *========================================================================**/

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/**========================================================================
 *                     Account handlers and display
 *========================================================================**/

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
		<< std ::endl;
}

int		Account::checkAmount( void ) const
{
	return 0;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:";
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:"
			<< _nbWithdrawals << std ::endl;
	}
	else
		std::cout << "refused" << std::endl;
	return true;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

/**========================================================================
 *                           Utils
 *========================================================================**/

void	Account::_displayTimestamp( void )
{
	std::time_t	time = std::time(NULL);
	std::tm	*localTime = std::localtime(&time);
	char	buf[18];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buf;
}