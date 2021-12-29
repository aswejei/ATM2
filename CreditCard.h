//
// Created by nikit on 14.12.2021.
//

#ifndef ATM_CREDITCARD_H
#define ATM_CREDITCARD_H


#include <string>

class CreditCard
{
private:
    std::string cardNumber;
    unsigned short int cvv;
    unsigned short int expDate;

public:

    const std::string &getCardNumber() const {
        return cardNumber;
    }

    unsigned short getCvv() const {
        return cvv;
    }

    unsigned short getExpDate() const {
        return expDate;
    }


};


#endif //ATM_CREDITCARD_H
