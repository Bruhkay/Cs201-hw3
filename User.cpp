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

LinkedList<Playlist>& User::getPlaylists() {
    return playlists;
}

string User::getlistPlaylist() const {
    string playliststring = "";
    if (!playlists.getHead()) {
        return "None";
    }

    Node<Playlist>* current = playlists.getHead();
    playliststring +="[";
    while (current) {
        int playlistid = current->data.getID();
        playliststring += to_string(playlistid);
        if (current->next) {
            playliststring += ",";
        }
        current = current->next;
    }
    playliststring +="]";
    return playliststring;
}
void User::addPlaylist(Playlist& playlist) {
    playlists.insertSorted(playlist);
}
void User::removePlaylist(Playlist& playlist) {
    playlists.deleteByValue(playlist);
}