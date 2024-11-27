//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#ifndef USER_H
#define USER_H
#include "Playlist.h"
using namespace std;

class User {
public:
    User(const int id, const string nam);
    ~User();
    void setID(int Id);
    int getID() const;
    void setName(string name);
    string getName() const;
private:
    int ID;
    string name;
    LinkedList<Playlist> playlists;
};
#endif //USER_H
