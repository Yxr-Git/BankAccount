#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include "date.h"
//#include "Subaccount.h"

class Account{
	protected:
			std:: string id;
			double balance;
			double rate;
			Date lastDate;
			double accumulation;
			static double total;

	public:
			Account();
			const std::string &getId() const{
				return id;
			};
			double getBalance(){
				return balance;
			}
			double getRate(){
				return rate;
			}
			static double getTotal(){
				return total;
			}

			//record the date, amount of the money and information for every deal
			void record(const Date &date, double amount, const std::string &info);
			void deposit(const Date &date, double amount, const std::string &info);

			//report error message
			void error(const std::string &msg) const;

			//get the specific date money
			double accumulate(const Date &date) const{
					return accumulation+balance*date.distance(lastDate);
			}

			virtual void withdraw(const Date &date, double amount, const std::string &info) = 0;
			virtual void settle(const Date &date) = 0;
			void show() const;
};

class AccountNormal: public Account{
	public:
		//Constructor for normal account
		AccountNormal(const Date &date, const std::string &id, double rate);

		//Withdraw function for normal account
		void withdraw(const Date &date, double amount, const std::string &info);
		//For the yearly settlement of normal account
		void settle(const Date &date);
};

class AccountVIP: public Account{
	public:
			AccountVIP(const Date &date, const std::string &id, double rate);

			//Withdraw even if there is no balance
			void withdraw(const Date &date, double amount, const std::string &info);
			//For the yearly settlement of VIP account
			void settle(const Date &date);
};

#endif