//
// Created by nikit on 22.12.2021.
//

#ifndef ATM_ADMIN_H
#define ATM_ADMIN_H


#include "Bank.h"
#include "IMoneyCheckable.h"
#include <iostream>

class Admin:public IMoneyCheckable
{
private:
    Bank *b;
public:
    Admin(Bank &a)
    {
        b=&a;
    }
    void PrintMoneyAm(std::string Cardnumber) override
    {
        std::cout<<"Enter card number of bank account you would like to check:"<<std::endl;
        std::cin>>Cardnumber;
        for(int i=0; i<(b->BankAccountVector.size()); i++)
        {
            if((b->BankAccountVector[i].GetCardnumber())==Cardnumber)
            {
                std::cout<<b->BankAccountVector[i].GetMoneyAmount()<<std::endl;
                break;
            }
        }
    }
};


#endif //ATM_ADMIN_H
