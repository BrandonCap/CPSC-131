#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>

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

  ifstream in;
  in.open(filename);

  string str;
  while(getline(in, str))
  {
    stringstream input(str);

    string userName, password;
    input >> userName >> password;

    table[userName] = password;
  }
}

size_t UserLogin::numberOfUsers()
{
  return table.size();
}

string UserLogin::passWordCheck(const string& userName)
{

  if (table.find(userName) != table.end())
  {
    return table[userName];
  }
  else
  {
    return "Non-existent User";
  }
}

size_t UserLogin::wordBucketIdMethod1(const string& userName)
{

  return table.bucket(userName);

}

size_t UserLogin::wordBucketIdMethod2(const string& userName)
{
  int count = table.bucket_count();

  for (int i = 0; i < count; i++)
  {
    for(auto it = table.begin(i); it != table.end(i); ++it)
    {
      if (it->first == userName)
      {
        return i;
      }
    }
  }
}

bool UserLogin::validateUser(const string& userName)
{
  return table.find(userName) != table.end();
}

bool UserLogin::authenticateUser(const string& userName, const string& passWord)
{
  bool realUser = table.find(userName) != table.end();

  if(realUser)
  {
    return table.find(userName)->second == passWord;
  }
  else
  {
    return false;
  }
}
