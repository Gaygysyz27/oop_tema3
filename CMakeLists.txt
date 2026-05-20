cmake_minimum_required(VERSION 3.16)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP_Project
        Banca.cpp
        Client.cpp
        Credit.cpp
        CreditAuto.cpp
        CreditFactory.cpp
        CreditIpotecar.cpp
        CreditNevoiPersonale.cpp
        CreditPrimaCasa.cpp
        Exceptii.cpp
        main.cpp
        Raport.h)
