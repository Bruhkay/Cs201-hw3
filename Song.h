//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;

class Song {
public:
    Song(const int id, const string nam, const string artis);
    ~Song();
    void setID(int Id);
    int getID() const;
    void setName(string name);
    string getName() const;
    void setArtist(string artist);
    string getArtist() const;
private:
    int ID;
    string name;
    string artist;
};
#endif //SONG_H
