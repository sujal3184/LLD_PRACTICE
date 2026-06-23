#pragma once

#include"payment_gateway.h"
#include"PaymentGatewayProxy.h"
#include<bits/stdc++.h>
using namespace std;

enum class Gateway_Type{
    PAYTM,
    RAZORPAY
};

class GatewayFactory{
    static GatewayFactory instance;

    GatewayFactory() {}
    GatewayFactory(const GatewayFactory&) = delete;
    GatewayFactory &operator = (const GatewayFactory&) = delete;
public:
    static GatewayFactory& getInstance(){
        return instance;
    }
    Payment_Gateway* get_gateway(Gateway_Type gt){
        if(gt == Gateway_Type::PAYTM){
            Payment_Gateway* pg = new PaytmGateway();
            return new PaymentGatewayProxy(pg , 3);
        }
        else{
            Payment_Gateway* pg = new Razorpay_Gateway();
            return new PaymentGatewayProxy(pg , 3);
        }
    }
};

GatewayFactory GatewayFactory::instance;