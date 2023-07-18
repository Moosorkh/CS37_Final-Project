// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    string username;
    string status;

public:
    Account(const string &username, const string &status = "Regular");
    ~Account();
    string getStatus() const;
};

#endif // ACCOUNT_H
