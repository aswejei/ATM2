//
// Created by nikit on 14.12.2021.
//

#ifndef ATM_ATM_H
#define ATM_ATM_H


#include "Bank.h"
#include "CreditCard.h"
#include "Guest.h"
#include "Admin.h"
#include <iostream>
#include <fstream>


class ATM: public Bank
{
private:
    unsigned int MoneyContainer;
    Guest *g;
    Admin *a;
    std::vector<CreditCard> AccessableCreditCardsVector;
    void Money_Withdrawal(std::string card, unsigned int amount) override
    {
        for(int i=0; i<Bank::BankAccountVector.size(); i++)
        {
            if(Bank::BankAccountVector[i].CardNumber==card)
            {
                Bank::BankAccountVector[i]-=amount;
            }
        }
    }

public:
    ATM()
    {
        unsigned int am;
        std::ifstream s("C:\\Users\\nikit\\ClionProjects\\ATM\\MoneyContainer.txt");
        s>>am;
        MoneyContainer=am;
        //заполнение вектора карт доступными картами из файла CreditcardList
        std::cout<<"Please choose from the list the card you would like to use and enter its number:"<<std::endl;
        for(int i=0; i<AccessableCreditCardsVector.size(); i++)
        {
            std::cout<<AccessableCreditCardsVector[i].getCardNumber()<<std::endl;
        }
        std::string cardnumber;
        std::cin>>cardnumber;
        bool cr=false;
        while(cr!=true)
        {
            for(int i=0; i<AccessableCreditCardsVector.size(); i++){
                if(cardnumber==AccessableCreditCardsVector[i].getCardNumber()){
                    cr=true;
                }
            }
            if(!cr)
            {

            }
        }
    }
    void LaunchATM()
    {

    }
    /*void CheckPin(unsigned short int enteredPin){}*/
};


#endif //ATM_ATM_H
