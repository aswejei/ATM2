cmake_minimum_required(VERSION 3.17)
project(ATM2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATM2 main.cpp AccountsDatabaseParser.h AccountsDatabaseParser.cpp Admin.h Admin.cpp ATM.h ATM.cpp Bank.h Bank.cpp BankAccount.h BankAccount.cpp CardReciever.h CardReciever.cpp CreditCard.h CreditCard.cpp Guest.h Guest.cpp IMoneyCheckable.h Logger.h Logger.cpp OperationType.h OperationType.cpp)