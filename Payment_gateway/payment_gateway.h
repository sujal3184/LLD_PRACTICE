# pragma once

#include"Payment_req.h"
#include"Bank_service.h"
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Payment_Gateway{
public:
    Bank_service * bs;

    Payment_Gateway(){
        bs = nullptr;
    }

    virtual bool initialize(Payment_req* pr) = 0;
    virtual bool validate(Payment_req* pr) = 0;
    virtual bool finalize(Payment_req* pr) = 0;
    virtual bool process_payment(Payment_req* pr){
        if(!initialize(pr)){
            cout<<"[Payment Gateway] error while initialize payment for "<<pr->sender<<endl;
            return false;
        }
        if(!validate(pr)){
            cout<<"[Payment Gateway] error while validating payment for "<<pr->sender<<endl;
            return false;
        }
        if(!finalize(pr)){
            cout<<"[Payment Gateway] error while finalize payment for "<<pr->sender<<endl;
            return false;
        }
        return true;
    }
};


class PaytmGateway : public Payment_Gateway{
public:
    Bank_service * bs;

    PaytmGateway(){
        bs = new Paytm_service();
    }

    bool initialize(Payment_req* pr) override{
        cout<<"[Paytm Gateway] initialize the payment for "<<pr->sender<<endl;
        return true;
    }

    bool validate(Payment_req* pr) override{
        if(!bs->process_payment(pr->amount)){
            cout<<"[Paytm Gateway] validation failed for "<<pr->sender<<endl;
            return false;
        }
        else{
            cout<<"[Paytm Gateway] validation succeed for "<<pr->sender<<endl;
            return true;
        }
    }

    bool finalize(Payment_req* pr) override{
        cout<<"[Paytm Gateway] finalize the payment for "<<pr->sender<<endl;
        return true;
    }
};


class Razorpay_Gateway : public Payment_Gateway{
public:
    Bank_service * bs;

    Razorpay_Gateway(){
        bs = new Razorpay_service();
    }

    bool initialize(Payment_req* pr) override{
        cout<<"[Razorpay Gateway] initialize the payment for "<<pr->sender<<endl;
        return true;
    }

    bool validate(Payment_req* pr) override{
        if(!bs->process_payment(pr->amount)){
            cout<<"[Razorpay Gateway] validation failed for "<<pr->sender<<endl;
            return false;
        }
        else{
            cout<<"[Razorpay Gateway] validation succeed for "<<pr->sender<<endl;
            return true;
        }
    }

    bool finalize(Payment_req* pr) override{
        cout<<"[Razorpay Gateway] finalize the payment for"<<pr->sender<<endl;
        return true;
    }
};