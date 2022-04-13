#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "accounts:"<< getNbAccounts(); 
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

int	Account::getNbAccounts(){
    return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ){
    return Account::_totalAmount;
}
int	Account::getNbDeposits( void ){
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
    return Account::_totalNbWithdrawals;
}


Account::Account( int initial_deposit ){
    _displayTimestamp();
    _accountIndex = _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";amount:"<< checkAmount() << ";created";
    std::cout << std::endl;
    _totalAmount += _amount;
}


void	Account::makeDeposit( int deposit ){
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";p_amount:"<< checkAmount();
    std::cout << ";deposit:"<< deposit;
    _amount += deposit;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";nb_deposits:"<< _nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";p_amount:"<< checkAmount();
    if (checkAmount() < withdrawal){
        std::cout << ";withdrawal:"<< "refused";
        std::cout << std::endl;
        return false;
    }
    std::cout << ";withdrawal:"<< withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return true;
}

int		Account::checkAmount( void ) const{
    return (_amount);
}

void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";deposits:"<< _nbDeposits;
    std::cout << ";withdrawals:"<< _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
  	struct tm	*timeinfo;
	  
	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << timeinfo->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << timeinfo->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << timeinfo->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << timeinfo->tm_sec;
	std::cout << "] ";
	
}

Account::~Account( void ){
    _displayTimestamp();
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";amount:"<< checkAmount() << ";closed";
    std::cout << std::endl;
}
