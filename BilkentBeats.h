//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#ifndef BILKENTBEATS_H
#define BILKENTBEATS_H
#include <string>

using namespace std;
class BilkentBeats {
public:
    BilkentBeats();
    ~BilkentBeats();

    void addUser( const int userId, const string userName );
    void removeUser( const int userId );
    void printUsers() const;

    void addSong( const int songID, const string songName, const string artists );
    void removeSong( const int songID );
    void printSongs() const;

    void addPlaylist( const int userId, const int playlistId );
    void removePlaylist( const int userId, const int playlistId );
    void addSongToPlaylist( const int playlistId, const int songId );
    void removeSongFromPlaylist( const int playlistId, const int songId );
    void printSongsInPlaylist( const int playlistId ) const;
private:

};
#endif //BILKENTBEATS_H
