#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <Windows.h>
#include "../process/processes.cpp"


void userInterface(database::userNode* user){
    bool menuCondition = true;
    while(menuCondition){
        system("cls");
        std::cout << "===================================|Selamat Datang Kembali, " << user->name << "|====================================\n";

    }
}

void tambahUser(){
    std::string username;
    std::string name;
    std::string password;
    std::cout << "============================================|Tambah User|============================================\n";
    std::cout << " Username : ";
    std::getline(std::cin, username);
    std::cout << " Nama : ";
    std::getline(std::cin, name);
    std::cout << " Password : ";
    std::getline(std::cin, password);
    if(!usernameExist(username)){
        std::string id = std::to_string(rand());
        while(idExist(id)){
           id = std::to_string(rand());
        }
        addUser(id, name, username, password);
    }else{
        std::cout << "Username already exist !!\n";
    }
}

void hapusUser(){
    std::string username;
    char yakin;
    std::cout << "============================================|Delete User|============================================\n";
    std::cout << " Username : ";
    std::getline(std::cin, username);
    std::cout << " Yakin? (Y/N) : ";
    std::cin >> yakin;
    if(tolower(yakin) == 'y'){
        deleteUser(username);
    }
}

void adminInterface(){
    bool menuCondition = true;
    while(menuCondition){
        system("CLS");
        int pilihanMenu;
        std::cout << "===================================|Selamat Datang Kembali, Admin|===================================\n";
        std::cout << "===========================================|Menu Aplikasi|===========================================\n";
        std::cout << "1. Tambah User\n";
        std::cout << "2. Delete User\n";
        std::cout << "3. Keluar\n";
        std::cout << "=====================================================================================================\n";
        std::cout << "Pilih : ";
        (std::cin >> pilihanMenu).get();
        switch(pilihanMenu){
            case 1: tambahUser();
                    break;
            case 2: hapusUser();
                    break;
            case 3: menuCondition = false;
                    break;
        }
    }
    return;
}
void loginInterface(){
    std::string admin = "admin";
    std::string username;
    std::string password;
    while(true){
        system("cls");
        std::cout << "=====================================================================================================\n";
        std::cout << ".--------------. .--------------. .--------------. .--------------. .--------------. .--------------.\n";
        std::cout << "|   ______     | |  _________   | |    _______   | |   ______     | |     ____     | |  ___  ____   |\n";
        std::cout << "|  |_   __ \\   | | |_   ___  |  | |   /  ___  |  | |  |_   _ \\    | |   .'    `.   | | |_  ||_  _|  |\n";
        std::cout << "|    | |__) |  | |   | |_  \\_|  | |  |  (__ \\_|  | |    | |_) |   | |  /  .--.  \\  | |   | |_/ /    |\n";
        std::cout << "|    |  ___/   | |   |  _|  _   | |   '.___`-.   | |    |  __'.   | |  | |    | |  | |   |  __'.    |\n";
        std::cout << "|   _| |_      | |  _| |___/ |  | |  |`\\____) |  | |   _| |__) |  | |  \\  `--'  /  | |  _| |  \\ \\_  |\n";
        std::cout << "|  |_____|     | | |_________|  | |  |_______.'  | |  |_______/   | |   `.____.'   | | |____||____| |\n";
        std::cout << "'--------------' '--------------' '--------------' '--------------' '--------------' '--------------'\n";
        std::cout << "===============================================|Login|===============================================\n";
        std::cout << " Username : ";
                    getline(std::cin, username);
        std::cout << " Password : ";
                    getline(std::cin, password);

        if(username == admin){
            if(password == admin){
                adminInterface();
            }else{
                std::cout << "Username or Password Invalid !!";
                sleep(5);
            }
        }else{
            if(password == getPassword(username)){
                userInterface();
            }else{
                std::cout << "Username or Password Invalid !!";
                sleep(5);
            }
        }
    }
}
