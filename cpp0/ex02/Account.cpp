#include <iostream>
#include <ctime>
#include "Account.hpp"

/**========================================================================
 *                           Constructor/Destructor
 *========================================================================**/

Account::Account( int initial_deposit ) : _amount(initial_deposit), _accountIndex(_nbAccounts++),
											_nbDeposits(0), _nbWithdrawals(0)
{
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
 *                           Account handlers
 *========================================================================**/

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_amount -= withdrawal;
	_nbWithdrawals += 1;	
}

/**========================================================================
 *                           Display
 *========================================================================**/

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
	std::time_t	time = std::time(nullptr);
	std::tm	*localTime = std::localtime(&time);
	char	buf[18];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buf;
}