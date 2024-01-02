#include "Account.hpp"
#include <iostream>
#include <ctime>

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

static void	displayPartOfDate(int number) {
	if (number < 10)
		std :: cout << '0';
	std :: cout << number;
}

void Account::_displayTimestamp() {
	time_t		now = time(0);
	struct tm	*current_time = localtime(&now);

	std :: cout << '[';
	displayPartOfDate(current_time->tm_year + 1900);
	displayPartOfDate(current_time->tm_mon + 1);
	displayPartOfDate(current_time->tm_mday);
	std :: cout << '_';
	displayPartOfDate(current_time->tm_hour);
	displayPartOfDate(current_time->tm_min);
	displayPartOfDate(current_time->tm_sec);
	std :: cout << ']';
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
