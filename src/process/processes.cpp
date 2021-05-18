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

std::string getName(std::string username) {
    if (userDatabase == nullptr) {
        return "Not Exists";
    }else {
        database::userNode* temporary = userDatabase;
        while (temporary != nullptr) {
            if (temporary->username == username) {
            return temporary->name;
            }
            temporary = temporary->next;
        }
        return "Not Exsits";
    }
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

void confirmFriend(database::userNode* user, std::string username){
    database::idList* baru = new database::idList(username);
    database::idList* baru2 = new database::idList(user->username);
    if(user->friends == nullptr){
        user->friends = baru;
    } else {
        database::idList* temp = user->friends;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = baru;
    }
    user = getUser(username);
    if(user->friends == nullptr){
        user->friends = baru2;
    } else {
        database::idList* temp = user->friends;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = baru2;
    }
    database::idList* temp2 = user->friendsReq;
    database::idList* temp2p = nullptr;
    while(temp2 != nullptr){
        if(temp2->id == username){
            if(temp2p == nullptr){
                user->friendsReq = temp2->next;
                temp2->next = nullptr;
                delete temp2;
            } else {
                temp2p->next = temp2->next;
                temp2->next = nullptr;
                delete temp2;
            }
        }
        temp2p = temp2;
        temp2 = temp2->next;
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

void addFriend(database::userNode* userToAdd, std::string usernameAdded){
    database::idList* baru = new database::idList(usernameAdded);
    if(userToAdd->friendsReq == nullptr){
        userToAdd->friendsReq = baru;
    }else{
        baru->next = userToAdd->friendsReq;
        userToAdd->friendsReq = baru;
    }
}

void addPost(database::userNode* user, std::string judul, std::string caption){
    database::postNode* baru = new database::postNode(judul, caption);
    if(user->post == nullptr){
        user->post = baru;
    }else{
        baru->next = user->post;
        user->post = baru;
    }
}
