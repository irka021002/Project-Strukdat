#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <Windows.h>
#include "../process/processes.cpp"

void tambahTeman(database::userNode* user){
    char yakin;
    std::string userName;
    int jmlhChar = user -> name.length() + 91;
    for(int i = 1; i <= (jmlhChar-14)/2; i++){std::cout << "=";} 
    std::cout << "|Tambah Teman|";
    for(int i = 1; i <= (jmlhChar-14)/2; i++){std::cout << "=";}
    std::cout << "\n";
    std::cout << " Username : ";
    std::getline(std::cin, userName);
    for(int i = 1; i <= (jmlhChar)/2; i++){std::cout << "=";}
    std::cout << "\n";
    database::userNode* userToAdd = getUser(userName);
    std::cout << " Nama : " << userToAdd->name << "\n";
    std::cout << " Tambah menjadi teman (Y/N) ? : ";
    (std::cin >> yakin).get();
    if(tolower(yakin) == 'y'){
        addFriend(userToAdd, user->username);
    }
    for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
    sleep(2);
}

void buatPost(database::userNode* user){
    int jmlhChar = user -> name.length() + 91;
    std::string judul, caption;
    for(int i = 1; i <= (jmlhChar-11)/2; i++){std::cout << "=";} 
    std::cout << "|Buat Post|";
    for(int i = 1; i <= (jmlhChar-11)/2; i++){std::cout << "=";}
    std::cout << "\n";
    std::cout << " Judul : ";
    std::getline(std::cin, judul);
    std::cout << " Caption : ";
    std::getline(std::cin, caption);
    addPost(user, judul, caption);
    for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
    sleep(2);
}

void lihatPost(database::userNode* userLogin){
    std::string username;
    int jmlhChar = userLogin -> name.length() + 91;
    for(int i = 1; i <= (jmlhChar-12)/2; i++){std::cout << "=";}
    std::cout << "|Lihat Post|";
    for(int i = 1; i <= (jmlhChar-12)/2; i++){std::cout << "=";}
    std::cout << "\n";
    std::cout << " Username : ";
    std::getline(std::cin, username);
    for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
    std::cout << "\n";
    database::userNode* user = getUser(username);
    if(user != nullptr){
        if(user->post != nullptr){
            database::postNode* postList = user->post;
            bool postContinuity = true;
            while(postContinuity){
                std::string command;
                std::cout << " Nama : " << user->name << "\n";
                std::cout << " Judul : " << postList->judul << "\n";
                std::cout << " Caption : " << postList->caption << "\n";
                for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
                std::getline(std::cin, command);
                for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
                if(command == "next"){
                    postList = postList->next;
                }else if(command == "exit"){
                    postContinuity = false;
                }
            }
        }
    }
}

void userInterface(database::userNode* user){
    bool menuCondition = true;
    std::string name = user->name;
    int jmlhChar = name.length() + 91;
    while(menuCondition){
        system("cls");
        int pilihanMenu;
        std::cout << "===================================|Selamat Datang Kembali, " << name << "|====================================\n";
        for(int i = 1; i <= (jmlhChar-15)/2; i++){std::cout << "=";} 
        std::cout << "|Menu Aplikasi|";
        for(int i = 1; i <= (jmlhChar-15)/2; i++){std::cout << "=";}
        std::cout << "\n";
        std::cout << " 1. Tambah teman\n";
        std::cout << " 2. Buat post\n";
        std::cout << " 3. Lihat post\n";
        std::cout << " 4. Teman kamu\n";
        std::cout << " 5. Permintaan Pertemanan\n";
        std::cout << " 6. Keluar\n";
        for(int i = 1; i <= (jmlhChar); i++){std::cout << "=";}
        std::cout << "\n";
        std::cout << " Pilih : ";
        std::cin >> pilihanMenu;
        switch(pilihanMenu){
            case 1: tambahTeman(user);
                    break;
            case 2: buatPost(user);
                    break;
            case 3: lihatPost(user);
                    break;
            /*case 4: lihatTeman();
                    break;
            case 5: lihatPermintaan();
                    break;*/
            case 6: menuCondition = false;
                    break;
        }
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
                userInterface(getUser(username));
            }else{
                std::cout << "Username or Password Invalid !!";
                sleep(5);
            }
        }
    }
}
