//
// Created by Burkay Tunçtürk on 27.11.2024.
//

#include "BilkentBeats.h"

#include <iostream>
using namespace std;

BilkentBeats::BilkentBeats() {

}
BilkentBeats::~BilkentBeats() {

}
void BilkentBeats::addUser( const int userId, const string userName ) {

}
void BilkentBeats::removeUser( const int userId ){}
void BilkentBeats::printUsers() const {

}

void BilkentBeats::addSong( const int songID, const string songName, const string artists ){}
void BilkentBeats::removeSong( const int songID ){}
void BilkentBeats::printSongs() const{}

void BilkentBeats::addPlaylist( const int userId, const int playlistId ){}
void BilkentBeats::removePlaylist( const int userId, const int playlistId ){}
void BilkentBeats::addSongToPlaylist( const int playlistId, const int songId ){}
void BilkentBeats::removeSongFromPlaylist( const int playlistId, const int songId ){}
void BilkentBeats::printSongsInPlaylist( const int playlistId ) const{}