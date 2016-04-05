#include<iostream>
#include<fstream>
#include<string>
#include "account.h"
#include "factory.h"

using namespace std;

int main(){
	char buffer[256], *resource;
	string accountID[2];
	int year, month, day, i;
	double accountRate[2];

	ifstream client("2015-6-1.txt"); //Read the resource file.
	if (!client.is_open())
	{
		cout << "Error opening file"; 
		exit (1); 
	}
	client.getline(buffer, 20);
	year = atoi(strtok(buffer, "."));
	month = atoi(strtok(NULL, "."));
	day = atoi(strtok(NULL, "."));

	for (i=0; !client.eof(); i++)  
	{  
		client.getline (buffer,20);
		accountID[i] = strtok(buffer, ",");
		accountRate[i] = atof(strtok(NULL, ","));
	}

	Date date(year, month, day); // set the system initial day.

	Factory *factoryA = new FactoryA();//create account type1
	Account *account_normal_A = factoryA->CreateAccount(date, accountID[0], accountRate[0]);

	Factory *factoryB = new FactoryB ();//create account type2
	Account *account_vip_B = factoryB->CreateAccount(date, accountID[1], accountRate[1]);

	//const int length = sizeof(accounts)/sizeof(Account);
	//while(1);
	account_normal_A->deposit(Date(2015,10,20), 100, "salary");
	account_normal_A->deposit(Date(2015,11,20), 300, "salary");
	account_normal_A->withdraw(Date(2015,11,28), 430, "purchase");
	account_normal_A->withdraw(Date(2015,11,28), 130, "purchase");
	cout<<endl;

	account_vip_B->deposit(Date(2015,10,10), 2000, "sell stock 007");
	account_vip_B->withdraw(Date(2015,12,15), 1500, "buy a car");
	cout<<endl;

	account_normal_A->settle(Date(2016, 1 ,1));
	account_normal_A->show();
	cout<<endl;

	account_vip_B->settle(Date(2016, 1 ,1));
	account_vip_B->show();
	cout<<endl;

	//cout<<"Total: "<<SavingAccount:: getTotal()<<endl;
	//while(1);
	system("pause");

	return 0;
}