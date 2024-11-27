//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#include "Song.h"

Song::Song(const int id, const string nam, const string artis)
    : ID(id), name(nam), artist(artis) {}

Song::~Song() {}

void Song::setID(int Id) {
    ID = Id;
}

int Song::getID() const {
    return ID;
}

void Song::setName(string nam) {
    name = nam;
}

string Song::getName() const {
    return name;
}

void Song::setArtist(string artis) {
    artist = artis;
}

string Song::getArtist() const {
    return artist;
}