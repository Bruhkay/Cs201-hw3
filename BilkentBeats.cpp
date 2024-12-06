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
    Node<User>* current = users.getHead();

    while (current) {
        if (current->data->getID() == userId) {
            cout << "Cannot add user. There is already a user with ID " << userId << "." << endl;
            return;
        }
        current = current->next;
    }

    User* newUser = new User(userId, userName);


    users.insertSorted(*newUser);
    cout << "Added user " << userId << "." << endl;
}
void BilkentBeats::removeUser( const int userId ) {

    Node<User>* current = users.getHead();
    while (current && current->data->getID() != userId) {
        current = current->next;
    }

    if (!current) {
        cout << "Cannot remove user. There is no user with ID " << userId << "." << endl;
        return;
    }

    users.deleteByValue(*current->data);
    cout << "Removed user " << userId << "." << endl;

}
void BilkentBeats::printUsers() const {
    if (!users.getHead()) {
        cout << "There are no users to show." << endl;
        return;
    }
    cout << "Users in the system:"<< endl;
    Node<User>* current = users.getHead();
    while (current) {
        string userName = current->data->getName();
        int userId = current->data->getID();
        string userPlaylists = current->data->getlistPlaylist();

        cout << "User ID : "<< userId <<", Name : " << userName<<
            ", Playlist IDs : "<< current->data->getlistPlaylist()<< endl;
        current = current->next;
    }
}
void BilkentBeats::addSong( const int songID, const string songName, const string artists ) {
    Node<Song>* current = songs.getHead();

    while (current) {
        if (current->data->getID() == songID) {
            cout << "Cannot add song. BilkentBeats already contains song " << songID << "." << endl;
            return;
        }
        current = current->next;
    }

    Song* newSong = new Song(songID, songName, artists);

    songs.insertSorted(*newSong);

    cout << "Added song " << songID << "." << endl;
}
void BilkentBeats::removeSong( const int songID ) {
    Node<Song>* current = songs.getHead();
    while (current && current->data->getID() != songID) {
        current = current->next;
    }

    if (!current) {
        cout << "Cannot remove song. There is no song with ID " << songID << "." << endl;
        return;
    }

    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
        while (playlistNode) {
            Node<Song>* songNode = playlistNode->data->getSongs().getHead();
            while (songNode) {
                if (songNode->data->getID() == songID) {
                    playlistNode->data->removeSong(*songNode->data);
                }
                songNode = songNode->next;
            }
            playlistNode = playlistNode->next;
        }
        userNode = userNode->next;
    }

    songs.deleteByValue(*current->data);
    cout << "Removed song " << songID << "." << endl;
}
void BilkentBeats::printSongs() const {
    if (!songs.getHead()) {
        cout << "Cannot print songs. There is no song in the music library." << endl;
        return;
    }

    cout << "Music Library:" << endl;

    Node<Song>* current = songs.getHead();
    while (current) {
        int songID = current->data->getID();
        string songName = current->data->getName();
        string artist = current->data->getArtist();

        cout << "Song " << songID << " : " << songName << " - " << artist << endl;

        current = current->next;
    }
}
void BilkentBeats::addPlaylist( const int userId, const int playlistId ) {
    Node<User>* userNode = users.getHead();
    while (userNode && userNode->data->getID() != userId) {
        userNode = userNode->next;
    }

    Node<User>* userNodeTest = users.getHead();
    while (userNodeTest ) {
        Node<Playlist>* playlistNodeTest = userNodeTest->data->getPlaylists().getHead();

        while (playlistNodeTest) {
            if (playlistNodeTest->data->getID() == playlistId && userNodeTest->data->getID() != userId) {
                cout << "Cannot add playlist. There is a user having a playlist with ID " << playlistId<<"."<<endl;
                return;
            }
            playlistNodeTest = playlistNodeTest->next;
        }
        userNodeTest = userNodeTest->next;
    }

    if (!userNode) {
        cout << "Cannot add playlist. There is no user with ID " << userId << "." << endl;
        return;
    }

    Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
    while (playlistNode) {
        if (playlistNode->data->getID() == playlistId) {
            cout << "Cannot add playlist. User " << userId << " already has a playlist with ID " << playlistId << "." << endl;
            return;
        }
        playlistNode = playlistNode->next;
    }


    Playlist* newPlaylist = new Playlist(playlistId);

    userNode->data->addPlaylist(*newPlaylist);
    cout << "Added playlist " << playlistId << " to user " << userId << "." << endl;
}
void BilkentBeats::removePlaylist(const int userId, const int playlistId) {

    Node<User>* userNode = users.getHead();
    while (userNode && userNode->data->getID() != userId) {
        userNode = userNode->next;
    }

    if (!userNode) {
        cout << "Cannot remove playlist. There is no user with ID " << userId << "." << endl;
        return;
    }

    Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
    while (playlistNode) {
        if (playlistNode->data->getID() == playlistId) {
            userNode->data->removePlaylist(*playlistNode->data);
            cout << "Removed playlist " << playlistId << " from user " << userId << "." << endl;
            return;
        }
        playlistNode = playlistNode->next;
    }

    cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." << endl;
}
void BilkentBeats::addSongToPlaylist( const int playlistId, const int songId ) {
    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data->getID() == playlistId) {

                Node<Song>* songNode = songs.getHead();
                while (songNode && songNode->data->getID() != songId) {
                    songNode = songNode->next;
                }

                if (!songNode) {
                    cout << "Cannot add song. There is no song with ID " << songId << "." << endl;
                    return;
                }

                Node<Song>* playlistSongNode = playlistNode->data->getSongs().getHead();
                while (playlistSongNode) {
                    if (playlistSongNode->data->getID() == songId) {
                        cout << "Cannot add song. The playlist already contains song " << songId << "." << endl;
                        return;
                    }
                    playlistSongNode = playlistSongNode->next;
                }

                playlistNode->data->addSong(*songNode->data);

                cout << "Added song " << songId << " to playlist " << playlistId << "." << endl;
                return;
            }
            playlistNode = playlistNode->next;
        }
        userNode = userNode->next;
    }

    cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << endl;
}
void BilkentBeats::removeSongFromPlaylist( const int playlistId, const int songId ) {
    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data->getID() == playlistId) {

                Node<Song>* songNode = playlistNode->data->getSongs().getHead();
                Node<Song>* previous = nullptr;

                while (songNode && songNode->data->getID() != songId) {
                    songNode = songNode->next;
                }

                if (!songNode) {
                    cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << endl;
                    return;
                }

                playlistNode->data->removeSong(*songNode->data);
                cout << "Removed song " << songId << " from playlist " << playlistId << "." << endl;
                return;
            }
            playlistNode = playlistNode->next;
        }
        userNode = userNode->next;
    }

    cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << endl;
}
void BilkentBeats::printSongsInPlaylist( const int playlistId ) const {
    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data->getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data->getID() == playlistId) {

                Node<Song>* songNode = playlistNode->data->getSongs().getHead();
                if (!songNode) {
                    cout << "There are no songs to show in playlist " << playlistId << "." << endl;
                    return;
                }

                cout << "Songs in playlist " << playlistId << ":" << endl;

                while (songNode) {
                    const Song& song = *songNode->data;

                    cout << "Song " << song.getID() << " : "
                         << song.getName() << " - "
                         << song.getArtist() << endl;

                    songNode = songNode->next;
                }
                return;
            }
            playlistNode = playlistNode->next;
        }
        userNode = userNode->next;
    }

    cout << "Cannot print songs. There is no playlist with ID " << playlistId << "." << endl;
}