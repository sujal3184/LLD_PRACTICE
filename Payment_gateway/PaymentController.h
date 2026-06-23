#pragma once

#include"payment_service.h"
#include"GatewayFactory.h"
#include"Payment_req.h"

#include<bits/stdc++.h>
using namespace std;

class PaymentController{
    static PaymentController instance;
    PaymentController() {}
    PaymentController(const PaymentController&) = delete;
    PaymentController& operator=(const PaymentController&) = delete;
public:

    static PaymentController& getInstance(){
        return instance;
    }

    bool handlePayment(Gateway_Type type , Payment_req* pr){
        Payment_Gateway* pg = GatewayFactory::getInstance().get_gateway(type);
        PaymentService::getInstance().setGateway(pg);
        return PaymentService::getInstance().processPayment(pr);
    }
};


PaymentController PaymentController::instance;