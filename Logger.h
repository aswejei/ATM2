//
// Created by nikit on 14.12.2021.
//

#ifndef ATM_LOGGER_H
#define ATM_LOGGER_H

#include<string>
#include "OperationType.h"
#include "BankAccount.h"
#include "CreditCard.h"
#include "Admin.h"
#include <fstream>

class Logger
    {
    private:
        void GetLogHistory(std::string card)
        {
            std::string file="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+card+".txt";
            std::ifstream l(file);
            while(l){
                std::string lf;
                getline(l,lf);
                std::cout<<lf<<std::endl;
            }
        }
    public:
        void CreateLog(OperationType &o, std::string card, unsigned int sum)
        {
            std::ofstream l;
            std::string file="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+card+".txt";
            l.open(file, std::ios::app | std::ios::ate);
            if(o==OperationType::CASH_WITHDRAWAL)
            {
                l<<"Operation type: cash withdrawal; Account:"<<card<<"; Sum:"<<sum<<std::endl;
            }
            else if(o==OperationType::CREDITING_CASH)
            {
                l<<"Operation type: crediting cash; Account:"<<card<<"; Sum:"<<sum<<std::endl;
            }
            else
            {
                l<<"Invalid operation type was entered, log creation failed"<<std::endl;
            }
            l.close();
        }
        void CreateLog(OperationType o, std::string cardout, std::string cardin, unsigned int sum)
        {
            std::ofstream l1;
            std::ofstream l2;
            std::string file1="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+cardout+".txt";
            std::string file2="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+cardin+".txt";
            l1.open(file1, std::ios::app | std::ios::ate);
            l2.open(file2,std::ios::app | std::ios::ate);
            if(o==OperationType::MONEY_TRANSFER) {
                l1 << "Operation type: Money transfer out; Account-reciever:" << cardin << "; Sum:" << sum << std::endl;
                l2 << "Operation type: Money transfer in; Account-sender:" << cardout << "; Sum:" << sum << std::endl;
            }
            else
            {
                l1<<"Invalid operation type was entered, log creation failed"<<std::endl;
                l2<<"Invalid operation type was entered, log creation failed"<<std::endl;
            }
            l1.close();
            l2.close();
        }
        void CreateNewSession(std::string cardnumber)
        {
            std::ofstream l;
            std::string file="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+cardnumber+".txt";
            l.open(file,std::ios::app | std::ios::ate);
            l<<"ATM session started;"<<std::endl;
            l.close();
        }
        void EndSession(std::string cardnumber)
        {
            std::ofstream l;
            std::string file="C:\\Users\\nikit\\ClionProjects\\ATM\\logs\\"+cardnumber+".txt";
            l.open(file,std::ios::app | std::ios::ate);
            l<<"ATM session ended;"<<std::endl;
            l.close();
        }

    friend class Admin;
    };

#endif //ATM_LOGGER_H
