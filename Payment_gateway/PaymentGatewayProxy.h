#pragma once

#include"payment_gateway.h"
#include<bits/stdc++.h>
using namespace std;


class PaymentGatewayProxy : public Payment_Gateway{
public:
    Payment_Gateway* pg;
    int maxRetries;

    PaymentGatewayProxy(Payment_Gateway* pg , int retries){
        this->pg = pg;
        maxRetries = retries;
    }

    bool process_payment(Payment_req* pr){
        for(int i=1;i<=maxRetries;i++){
            bool temp = pg->process_payment(pr);
            if(temp){
                cout<<"[PaymentGatewayProxy] payment processed at "<<i<<" th attempt for "<<pr->sender<<endl;
                return true;
            }
        }
        cout<<"[PaymentGatewayProxy] payment failed for "<<pr->sender<<endl;
        return false;
    }

    bool initialize(Payment_req* pr) override{
        return pg->initialize(pr);
    }

    bool validate(Payment_req* pr) override{
        return pg->validate(pr);
    }

    bool finalize(Payment_req* pr) override{
        return pg->finalize(pr);
    }
};