//
// Created by nikit on 14.12.2021.
//

#ifndef ATM_BANK_H
#define ATM_BANK_H

#include<string>
#include<vector>
#include "BankAccount.h"
#include "Admin.h"
#include "AccountsDatabaseParser.h"

class Bank
{
protected:
    std::vector<BankAccount> BankAccountVector;
    virtual void Money_Withdrawal(std::string card, unsigned int amount)
    {
        for(int i=0; i<BankAccountVector.size(); i++)
        {
            if(BankAccountVector[i].CardNumber==card)
            {
                BankAccountVector[i]-=amount;
            }
        }

    }
    void Money_Crediting(std::string card, unsigned int amount)
    {
        for(int i=0; i<BankAccountVector.size(); i++)
        {
            if(BankAccountVector[i].CardNumber==card)
            {
                BankAccountVector[i]+=amount;
            }
        }
    }
    void Money_Transfer(std::string cardout, std::string cardin, unsigned int amount)
    {
        BankAccount *a;
        BankAccount *b;
        for(int i=0; i<BankAccountVector.size(); i++)
        {
            if(BankAccountVector[i].CardNumber==cardout)
            {
                 *a=BankAccountVector[i];
            }
        }
        for(int i=0; i<BankAccountVector.size(); i++)
        {
            if(BankAccountVector[i].CardNumber==cardin)
            {
                *b=BankAccountVector[i];
            }
        }
        a-=amount;
        b+=amount;
    }
    Bank()
    {
        AccountsDatabaseParser p;
        std::vector<Account> accs=p.GetAccountsInfo();
        for(int i=0; accs.size(); i++)
        {
            BankAccount b(accs[i].getMoneyAmount(), accs[i].getCardPin(), accs[i].getCardNumber());
            BankAccountVector.push_back(b);
        }
    }
    BankAccount* GetBankAccountLink(std::string Cardnumber)
    {
        for(int i=0; i<BankAccountVector.size(); i++)
        {
            if(BankAccountVector[i].GetCardnumber()==Cardnumber)
            {
                return &BankAccountVector[i];
            }
        }
    }
    friend class Admin;
};


#endif //ATM_BANK_H
