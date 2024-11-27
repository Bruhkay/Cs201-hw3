//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#include "User.h"


User::User(const int id, const string nam) {
    ID = id;
    name = nam;
}
User::~User() {

}
void User::setID(int Id) {
 ID = Id;
}
int User::getID() const {
    return ID;
}
void User::setName(string nam) {
 name = nam;
}
string User::getName() const {
 return name;
}

LinkedList<Playlist> User::getPlaylists() const {
    return playlists;
}