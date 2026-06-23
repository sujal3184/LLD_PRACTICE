# pragma once

#include<bits/stdc++.h>
using namespace std;

class Bank_service{
public:
    virtual bool process_payment(double amount) = 0;
};


class Paytm_service : public Bank_service{
public: 
    bool process_payment(double amount) override{
        int r = rand() % 100;
        // simulate 50 % success probability
        return r < 50;
    }
};


class Razorpay_service : public Bank_service{
public: 
    bool process_payment(double amount) override{
        int r = rand() % 100;
        // simulate 80 % success probability
        return r < 80;
    }
};