#include "structure.hpp"
database::userNode* userDatabase = nullptr;

bool usernameExist(std::string username){
    database::userNode* temp = userDatabase;
    if(temp != nullptr){
        while(temp != nullptr){
            if(temp->username == username){
                return true;
            }
            temp = temp->next;
        }
    }

    return false;
}

bool idExist(std::string id){
    database::userNode* temp = userDatabase;
    if(temp != nullptr){
        while(temp != nullptr){
            if(temp->id == id){
                return true;
            }
            temp = temp->next;
        }
    }

    return false;
}

database::userNode* getUser(std::string username){
    if(userDatabase == nullptr){
        return nullptr;
    }else{
        database::userNode* temp = userDatabase;
        while(temp != nullptr){
            if(temp->username == username){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
}

void addUser(std::string id, std::string name, std::string username, std::string password){
    database::userNode* baru = new database::userNode(id, name, username, password);
    if(userDatabase == nullptr){
        userDatabase = baru;
    }else{
        database::userNode* temp = userDatabase;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteUser(std::string username){
    if(userDatabase == nullptr){
        return;
    }else{
        database::userNode* temp = userDatabase;
        database::userNode* temp1 = nullptr;
        if(temp != nullptr && temp->username == username){
            userDatabase = temp->next;
            delete temp;
            return;
        }else{
            while(temp != nullptr && temp->username != username){
                temp1 = temp;
                temp = temp->next;
            }
            if(temp == nullptr)
                return;
            
            temp1->next = temp->next;
            delete temp;
        }
    }
}

std::string getPassword(std::string username){
    if(userDatabase == nullptr){
        return "just a random password thats not valid";
    }else{
        database::userNode* temp = userDatabase;
        while(temp != nullptr){
            if(temp->username == username){
                return temp->password;
            }
            temp = temp->next;
        }
        return "just a random password thats not valid";
    }
}
