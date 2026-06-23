#include<bits/stdc++.h>

#include"Payment_req.h"
#include"PaymentController.h"
#include"GatewayFactory.h"
using namespace std;

int main(){
    srand(static_cast<unsigned>(time(nullptr)));

    Payment_req* req1 = new Payment_req("Sujal","Ansh",1000.0,"INR");

    cout<<"processing the payment\n";
    cout<<"-------------------------\n";
    bool res1 = PaymentController::getInstance().handlePayment(Gateway_Type::PAYTM,req1);
    cout<<"Result: "<<(res1 ? "SUCCESS" : "FAIL")<< endl;
    cout<<"---------------------\n\n";


    Payment_req* req2 = new Payment_req("Ansh","Sujal",500.0,"USD");

    cout<<"processing the payment\n";
    cout<<"-------------------------\n";
    bool res2 = PaymentController::getInstance().handlePayment(Gateway_Type::RAZORPAY,req2);
    cout<<"Result: "<<(res2 ? "SUCCESS" : "FAIL")<< endl;
    cout<<"---------------------\n\n";
}