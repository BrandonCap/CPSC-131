#pragma once


#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef size_t CardNumber;

typedef size_t GateNumber;



struct Authorization
{
	Authorization() { }

	Authorization(CardNumber number, const string& name, const string& startTime, const string& endTime)
	: number_(number), name_(name), startTime_(startTime), endTime_(endTime) { }

	CardNumber number_;

	string name_;

	string startTime_;

	string endTime_;
};

typedef map<CardNumber, Authorization> AuthorizationMap;
typedef	AuthorizationMap::iterator AuthorizationMapIterator;

typedef	vector<Authorization> AuthorizationVector;

struct Transaction
{
	Transaction() { }

	Transaction(CardNumber number, const string& name, const string& date, const string& time, bool accessAllowed)
	: number_(number), name_(name), date_(date), time_(time), accessAllowed_(accessAllowed) { }

	CardNumber number_;

	string name_;

	string date_;

	string time_;

	bool accessAllowed_;
};

typedef	vector<Transaction> TransactionVector;
typedef	TransactionVector::iterator TransactionVectorIterator;

class	GateControl
{
	public:
		bool accessAllowed(CardNumber number);

		bool addAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime);

		bool changeAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime);

		bool deleteAuthorization(CardNumber number);

		void getAllAuthorizations(AuthorizationVector& authorizationVector);

		void getAllTransactions(TransactionVector& transactionVector);

		bool getCardAuthorization(CardNumber number, Authorization& authorization);

		void getCardTransactions(CardNumber number, TransactionVector& transactionVector);

	private:
		AuthorizationMap authorizationMap_;

		TransactionVector transactionVector_;
};

extern string gCurrentDate;
extern string gCurrentTime;



//****************************************************************************************
//
//	TO DO
//
//****************************************************************************************


bool GateControl::accessAllowed(CardNumber number)
{
	AuthorizationMapIterator temp;
	temp = authorizationMap_.find(number);

	if (temp == authorizationMap_.end())
	{
		Transaction transaction1(number, "***", gCurrentDate, gCurrentTime, false);
		transactionVector_.push_back(transaction1);
		return false;
	}
	bool passed = false;
	if ((temp->second.startTime_ >= gCurrentTime) && (temp->second.endTime_ <= gCurrentTime))
	{
		passed = true;
	}

	Transaction transaction2(number, temp->second.name_ , gCurrentDate, gCurrentTime, passed);
	transactionVector_.push_back(transaction2);

	return true;
}


bool GateControl::addAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime)
{
	Authorization authorization1(number, name, startTime, endTime);
	AuthorizationMapIterator temp;
	temp = authorizationMap_.find(authorization1.number_);

	if (temp == authorizationMap_.end())
	{
		authorizationMap_.emplace(number, authorization1);
		return true;
	}

	return false;
}


bool GateControl::changeAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime)
{
	AuthorizationMapIterator temp;
	temp = authorizationMap_.find(number);

	if (temp == authorizationMap_.end())
	{
		return false;
	}
	temp->second.name_ = name;
	temp->second.startTime_ = startTime;
	temp->second.endTime_ = endTime;

	return true;
}


bool GateControl::deleteAuthorization(CardNumber number)
{
	AuthorizationMapIterator temp;
	temp = authorizationMap_.find(number);

	if (temp == authorizationMap_.end())
	{
		return false;
	}
	authorizationMap_.erase(temp);

	return true;
}


void GateControl::getAllAuthorizations(AuthorizationVector& authorizationVector)
{
	AuthorizationMapIterator	it;
	it = authorizationMap_.begin();
	authorizationVector.clear();

	if (authorizationMap_.empty())
	{
		return;
	}
	while(it != authorizationMap_.end())
	{
		authorizationVector.push_back(it->second);
		++it;
	}
}


void GateControl::getAllTransactions(TransactionVector& transactionVector)
{
	if(transactionVector_.empty())
	{
		transactionVector.clear();
	}
	else
	{
		transactionVector.assign(transactionVector_.begin(), transactionVector_.end());
	}
}


bool GateControl::getCardAuthorization(CardNumber number, Authorization& authorization)
{
	AuthorizationMapIterator temp;

	temp = authorizationMap_.find(number);
	if (temp == authorizationMap_.end())
		return false;
	authorization = authorizationMap_[number];
	return true;
}


void GateControl::getCardTransactions(CardNumber number, TransactionVector& transactionVector)
{
	TransactionVector::iterator it = transactionVector_.begin();

	if(transactionVector_.empty())
	{
		transactionVector.clear();
	}
	for(; it < transactionVector_.end(); ++it)
	{
		if(it->number_ == number)
		{
			transactionVector.push_back(*it);
		}
	}
}
