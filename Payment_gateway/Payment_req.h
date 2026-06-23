# pragma once

#include<bits/stdc++.h>
#include<string>
using namespace std;

class Payment_req{
public:
    string sender;
    string reciever;
    double amount;
    string currency;

    Payment_req(string sen , string rec , double amount , string curr){
        sender = sen;
        reciever = rec;
        this->amount = amount;
        currency = curr;
    }
};