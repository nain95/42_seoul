#include "Account.hpp"
#include <iostream>

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
    _nbAccounts %= 8;
    _accountIndex = _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_amount = initial_deposit;
    std::cout << "index:"<< _accountIndex ;
    std::cout << ";amount:"<< checkAmount() << ";created";
    std::cout << std::endl;
    _totalAmount += this->_amount;

}


void	Account::makeDeposit( int deposit ){
    _displayTimestamp();
    this->_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:"<< this->_accountIndex ;
    std::cout << ";p_amount:"<< checkAmount();
    std::cout << ";deposit:"<< deposit;
    this->_amount += deposit;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";nb_deposits:"<< this->_nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout << "index:"<< this->_accountIndex ;
    std::cout << ";p_amount:"<< checkAmount();
    if (checkAmount() < withdrawal){
        std::cout << ";withdrawal:"<< "refused";
        std::cout << std::endl;
        return false;
    }
    std::cout << ";withdrawal:"<< withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    return true;
}

int		Account::checkAmount( void ) const{
    return (_amount);
}

void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:"<< this->_accountIndex ;
    std::cout << ";amount:"<< checkAmount();
    std::cout << ";deposits:"<< this->_nbDeposits;
    std::cout << ";withdrawals:"<< this->_nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp( void ){
    std::cout <<"[19920104_091532] ";
}

Account::~Account( void ){
    _displayTimestamp();
    std::cout << "index:"<< this->_accountIndex ;
    std::cout << ";amount:"<< checkAmount() << ";closed";
    std::cout << std::endl;
}