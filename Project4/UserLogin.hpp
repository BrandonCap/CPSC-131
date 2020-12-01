#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class UserLogin
{
private:

    unordered_map< string, string > table;


public:
    UserLogin(); // default constructor

    void readIn(const string& filename); // add data from file to hash table

    size_t numberOfUsers(); // return the number of users

    string passWordCheck(const string& userName); // returns the passWord of the given user

    size_t wordBucketIdMethod1(const string& userName); // return the bucket number where the given user is located

    size_t wordBucketIdMethod2(const string& userName); // another way to find the bucket number where the given user is located

    bool validateUser(const string& userName); // look up given user

    bool authenticateUser(const string& userName, const string& passWord);// authenticate given user and password

};

UserLogin::UserLogin()
{
}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string& filename)
{

    // TO DO

}

size_t UserLogin::numberOfUsers()
{

    // TO DO

}

string UserLogin::passWordCheck(const string& userName)
{

    // TO DO

}

size_t UserLogin::wordBucketIdMethod1(const string& userName)
{

    // TO DO

}

size_t UserLogin::wordBucketIdMethod2(const string& userName)
{

    // TO DO

}

bool UserLogin::validateUser(const string& userName)
{

    // TO DO

}

bool UserLogin::authenticateUser(const string& userName, const string& passWord)
{ 

    // TO DO

 }
