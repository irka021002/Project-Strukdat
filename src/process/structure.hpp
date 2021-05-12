namespace database {
    struct idList {
        char* id;
        idList* next;
        idList(std::string id){
            this->id = id;
            this->next = nullptr;
        }
    }
    struct postNode{
        char* judul;
        char* caption;
        postNode* next;
        postNode(char* judul, char* caption){
            this->judul = judul;
            this->caption = caption;
            this->next = nullptr;
        }
    }
    struct userNode {
        char* id;
        char* name;
        char* username;
        char* password;
        idList* friends;
        idList* friendsReq;
        postNode* post;
        userNode* next;
        userNode(char* id, char* name, char* username, char* password){
            this->id = id;
            this->name = name;
            this->username = username;
            this->password = password;
            this->friend = nullptr;
            this->friendsReq = nullptr;
            this->post = nullptr;
            this->next = nullptr;
        }
    }
}