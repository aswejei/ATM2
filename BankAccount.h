//
// Created by nikit on 14.12.2021.
//

#ifndef ATM_BANKACCOUNT_H
#define ATM_BANKACCOUNT_H

#include <string>
#include <iostream>

class BankAccount
{
private:
    unsigned int MoneyAmount;//located at the end of the string
    std::string CardPIN;//4 chars
    std::string CardNumber;//16 chars
    BankAccount(int moneyam, unsigned short int carddpin, std::string cardnumber)
    {
        MoneyAmount=moneyam;
        CardPIN=carddpin;
        CardNumber=cardnumber;
    }
   BankAccount& operator += (unsigned int am)
   {
       MoneyAmount += am;
       return *this;
   }
   BankAccount& operator -= (unsigned int am)
    {
        MoneyAmount -= am;
        return *this;
    }
public:
    const unsigned int &GetMoneyAmount()const {
       return MoneyAmount;
   }
    const std::string &GetCardnumber()const {
        return CardNumber;
    }
    bool CheckPIN(std::string enteredpin){
       return (enteredpin==CardPIN);
   }
    friend class Bank;
    friend class ATM;
};


#endif //ATM_BANKACCOUNT_H
