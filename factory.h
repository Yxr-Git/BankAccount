#include "account.h"
//#include "Subaccount.h"
#include <iostream>

using namespace std;

class Factory
{
public:
	virtual Account *CreateAccount(const Date &date, const std::string &id, double rate) = 0;
};

//Create normal account
class FactoryA : public Factory
{
public:
	AccountNormal *CreateAccount(const Date &date, const std::string &id, double rate)
	{
		return new AccountNormal(date, id, rate);
	}
};

//Create VIP account
class FactoryB : public Factory
{
public:
	AccountVIP *CreateAccount(const Date &date, const std::string &id, double rate)
	{
		return new AccountVIP(date, id, rate);
	}
};