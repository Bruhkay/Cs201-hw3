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

}
int User::getID() const {
    return ID;
}
void User::setName(string name) {

}
string User::getName() const {
 return name;
}