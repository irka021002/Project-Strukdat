#include <iostream>
#include "../process/processes.cpp"

void userInterface(){
    return;
}

void adminInterface(){
    return;
}
void loginInterface(){
    char* admin = "admin";
    char* username;
    char* password;
    std::cout << "=====================================================================================================\n";
    std::cout << ".--------------. .--------------. .--------------. .--------------. .--------------. .--------------.\n";
    std::cout << "|   ______     | |  _________   | |    _______   | |   ______     | |     ____     | |  ___  ____   |\n";
    std::cout << "|  |_   __ \   | | |_   ___  |  | |   /  ___  |  | |  |_   _ \    | |   .'    `.   | | |_  ||_  _|  |\n";
    std::cout << "|    | |__) |  | |   | |_  \_|  | |  |  (__ \_|  | |    | |_) |   | |  /  .--.  \  | |   | |_/ /    |\n";
    std::cout << "|    |  ___/   | |   |  _|  _   | |   '.___`-.   | |    |  __'.   | |  | |    | |  | |   |  __'.    |\n";
    std::cout << "|   _| |_      | |  _| |___/ |  | |  |`\____) |  | |   _| |__) |  | |  \  `--'  /  | |  _| |  \ \_  |\n";
    std::cout << "|  |_____|     | | |_________|  | |  |_______.'  | |  |_______/   | |   `.____.'   | | |____||____| |\n";
    std::cout << "'--------------' '--------------' '--------------' '--------------' '--------------' '--------------'\n";
    std::cout << "===============================================|Login|===============================================\n";
    std::cout << " Username : ";
              std::cin >> username;
    std::cout << " Password : ";
              std::cin >> password;

    if(username == admin){
        if(password == admin){
            adminInterface();
        }else{
            std::cout << "Username or Password Invalid !!";
        }
    }else{
        if(password == getPassword(username)){
            userInterface();
        }else{
            std::cout << "Username or Password Invalid !!";
        }
    }
}
