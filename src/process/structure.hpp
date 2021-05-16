namespace database {
    struct idList {
        std::string id;
        idList* next;
        idList(std::string id){
            this->id = id;
            this->next = nullptr;
        }
    };
    struct postNode{
        std::string judul;
        std::string caption;
        postNode* next;
        postNode(std::string judul, std::string caption){
            this->judul = judul;
            this->caption = caption;
            this->next = nullptr;
        }
    };
    struct userNode {
        std::string id;
        std::string name;
        std::string username;
        std::string password;
        idList* friends;
        idList* friendsReq;
        postNode* post;
        userNode* next;
        userNode(std::string id, std::string name, std::string username, std::string password){
            this->id = id;
            this->name = name;
            this->username = username;
            this->password = password;
            this->friends = nullptr;
            this->friendsReq = nullptr;
            this->post = nullptr;
            this->next = nullptr;
        }
    };
}