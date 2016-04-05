#include "account.h"
#include "factory.h"
#include <cmath>
#include <iostream>

using namespace std;

double Account:: total=0;

Account:: Account(){
	//cout << "You will never see this."<<endl;
}

//Record every transaction
void Account:: record(const Date &date, double amount, const std::string &info){
	accumulation = accumulate(date);
	lastDate = date;
	//amount = (amount*100+0.5)/100;
	balance+=amount;
	total+= amount;
	date.show();
	cout<<"\tID: #"<<id<<"    Amount: "<<amount<<"    Balance: "<<balance<<"    Information: "<<info<<endl;
}

//Deposit for account
void Account:: deposit(const Date &date, double amount, const std::string &info){
			record(date, amount, info);
}

//Deal with error
void Account:: error(const string &msg) const{
	cout<<"Error(#"<<id<<"): "<<msg<<endl;
}

//Show the balance
void Account:: show() const{
	cout<<"ID: "<<id<<"\tBalance: "<<balance;
}

//Constructor for normal account
AccountNormal:: AccountNormal(const Date &date, const std::string &id, double rate){
	this->id = id;
	this->balance = 0;
	this->rate = rate;
	this->accumulation = 0;
	lastDate = date;
	date.show();
	cout<<"\tID: #"<<id<<" has been created"<<endl;
}

//Withdraw function for normal account
void AccountNormal:: withdraw(const Date &date, double amount, const std::string &info){
	if(amount>getBalance()){
		error("not enough money");
	}
	else{
	record(date,-amount,info);
	}
};

//For the yearly settlement of normal account
void AccountNormal:: settle(const Date &date){
	double interest = accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
	if(interest!=0){
		record(date, interest, "interest");
	}
	accumulation=0;
};
	
//Constructor for VIP account
AccountVIP:: AccountVIP(const Date &date, const std::string &id, double rate){
	this->id = id;
	this->balance = 0;
	this->rate = rate;
	this->accumulation = 0;
	lastDate = date;
	date.show();
	cout<<"\tVIP account, ID: #"<<id<<" has been created"<<endl;
}

//Withdraw even if there is no balance
void AccountVIP:: withdraw(const Date &date, double amount, const std::string &info){
	record(date,-amount,info);
}

//For the yearly settlement of VIP account
void AccountVIP:: settle(const Date &date){
	double bonus = balance*rate*0.01;
	double interest = (accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1))) + bonus;
	if(interest!=0){
		record(date, interest, "interest");
	}
	accumulation=0;
}