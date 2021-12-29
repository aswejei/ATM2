//
// Created by nikit on 29.12.2021.
//

#ifndef ATM_ACCOUNTSDATABASEPARSER_H
#define ATM_ACCOUNTSDATABASEPARSER_H

#include <fstream>
#include <vector>
#include <string>
struct Account
{
    unsigned int MoneyAmount;//located at the end of the string
    unsigned short int CardPIN;//4 chars
    std::string CardNumber;//16 chars
public:
    unsigned int getMoneyAmount() const {
        return MoneyAmount;
    }

    unsigned short getCardPin() const {
        return CardPIN;
    }

    const std::string &getCardNumber() const {
        return CardNumber;
    }
    Account(unsigned int MoneyAmount, unsigned short int CardPIN, std::string CardNumber){
        this->MoneyAmount=MoneyAmount;
        this->CardPIN=CardPIN;
        this->CardNumber=CardNumber;
    }
};
class AccountsDatabaseParser
{
private:
    std::vector<Account> &GetAccountsInfo()
    {
        std::string file1="C:\\Users\\nikit\\ClionProjects\\ATM\\AccountsDatabase.txt";
        std::ifstream l(file1);
//        std::vector<std::string> s1;
        std::vector<Account> a;
        while(!l.eof())
        {
            unsigned int moneyam;
            unsigned short int cardpin;
            std::string cardnumber;
            l>>cardnumber>>cardpin>>moneyam;
            Account a1(moneyam,cardpin, cardnumber);
            a.push_back(a1);
        }
        return a;
    }
    friend class Bank;
};


#endif //ATM_ACCOUNTSDATABASEPARSER_H
