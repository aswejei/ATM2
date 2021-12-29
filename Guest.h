//
// Created by nikit on 22.12.2021.
//

#ifndef ATM_GUEST_H
#define ATM_GUEST_H

#endif //ATM_GUEST_H
#include "IMoneyCheckable.h"
#include "BankAccount.h"
class Guest:public IMoneyCheckable
{
private:
    BankAccount *b;
public:
    Guest(BankAccount *a){
        b=a;
    }
    void PrintMoneyAm(std::string Cardnumber) override{
        std::cout<<"Money amount on your bank account is "<<b->GetMoneyAmount()<<std::endl;
    }
};