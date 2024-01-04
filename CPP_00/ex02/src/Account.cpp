#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit) :	_accountIndex(getNbAccounts()), _amount(initial_deposit),
										_nbDeposits(0), _nbWithdrawals(0){
	Account ::_nbAccounts++;
	Account :: _totalAmount += initial_deposit;
	_displayTimestamp();
	std :: cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account() {}

Account::~Account() {
	_displayTimestamp();
	std :: cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std :: cout	<< " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std :: cout	<< " index:" << this->_accountIndex << ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account :: _totalNbDeposits += 1;
	Account :: _totalAmount += deposit;
	std :: cout	<< ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std :: cout	<< " index:" << this->_accountIndex << ";p_amount:" << this->_amount
				<< ";withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused\n";
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account :: _totalNbWithdrawals += 1;
	Account :: _totalAmount -= withdrawal;
	std :: cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << '\n';
	return true;
}

int Account::checkAmount() const {
	return 0;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std :: cout	<< " index:" << this->_accountIndex << ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << '\n';
}

void Account::_displayTimestamp() {
	time_t				now = time(0);
	struct std :: tm	*current_time = localtime(&now);

	std :: cout << std :: put_time(current_time, "[%Y%m%d_%H%M%S]");
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
