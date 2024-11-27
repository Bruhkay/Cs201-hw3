//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
using namespace std;

#include "Song.h"
#include "LinkedList.cpp"
using namespace std;

class Playlist {
public:
    Playlist(const int id);
    ~Playlist();

    void setID(int id);
    int getID() const;
    LinkedList<Song> getSongs() const;

private:
    int ID;
    LinkedList<Song> songs;
};

#endif //PLAYLIST_H
