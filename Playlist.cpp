//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#include "Playlist.h"

Playlist::Playlist(const int id) : ID(id) {}

Playlist::~Playlist() {}

void Playlist::setID(int id) {
    ID = id;
}

int Playlist::getID() const {
    return ID;
}