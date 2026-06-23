#pragma once

#include"payment_gateway.h"
#include"Payment_req.h"

#include<bits/stdc++.h>
using namespace std;

class PaymentService{
    static PaymentService instance;
    Payment_Gateway* gateway;

    PaymentService(){
        gateway = nullptr;
    }

    PaymentService(const PaymentService&) = delete;
    PaymentService operator=(const PaymentService&) = delete;

public:

    static PaymentService& getInstance(){
        return instance;
    }

    void setGateway(Payment_Gateway* g){
        if(gateway) delete(gateway);
        gateway = g;
    }

    bool processPayment(Payment_req* req){
        if(!gateway){
            cout<<"[PaymentService] No payment gateway selected "<<endl;
            return false;
        }
        return gateway->process_payment(req);
    }
};

PaymentService PaymentService::instance;