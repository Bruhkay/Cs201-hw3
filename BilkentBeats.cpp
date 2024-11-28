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

    // Check if the user already exists
    while (current) {
        if (current->data.getID() == userId) {
            cout << "Cannot add user. There is already a user with ID " << userId << "." << endl;
            return;
        }
        current = current->next;
    }

    // Create a new User object
    User newUser(userId, userName);

    // Create a new node to store the user
    Node<User>* newNode = new Node<User>(newUser);
    newNode->next = nullptr;

    // If the list is empty or the new user's ID is smaller than the first user's ID
    if (!users.getHead() || users.getHead()->data.getID() > userId) {
        newNode->next = users.getHead();
        users.setHead(newNode);
    } else {
        // Traverse the list to find the correct position
        Node<User>* temp = users.getHead();
        while (temp->next && temp->next->data.getID() < userId) {
            temp = temp->next;
        }

        // Insert the new user at the correct position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Added user " << userId << "." << endl;
}
void BilkentBeats::removeUser( const int userId ) {
    if (!users.getHead()) {
        cout << "Cannot remove user. There is no user with ID " << userId << "." << endl;
        return;
    }

    Node<User>* current = users.getHead();
    Node<User>* previous = nullptr;

    // Traverse the list to find the user
    while (current && current->data.getID() != userId) {
        previous = current;
        current = current->next;
    }

    // If the user is not found
    if (!current) {
        cout << "Cannot remove user. There is no user with ID " << userId << "." << endl;
        return;
    }

    // If the user is found
    if (!previous) { // The user is the head of the list
        users.setHead(current->next);
    } else { // The user is in the middle or end of the list
        previous->next = current->next;
    }

    // Delete the user's node and associated memory
    delete current;

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
        string userName = current->data.getName();
        int userId = current->data.getID();
        string userPlaylists = current->data.getlistPlaylist();

        cout << "User ID : "<< userId <<", Name : " << userName<<
            ", Playlist IDs : "<< current->data.getlistPlaylist()<< endl;
        current = current->next;
    }
}

void BilkentBeats::addSong( const int songID, const string songName, const string artists ) {
    Node<Song>* current = songs.getHead();

    // Check if the song already exists
    while (current) {
        if (current->data.getID() == songID) {
            cout << "Cannot add song. BilkentBeats already contains song " << songID << "." << endl;
            return;
        }
        current = current->next;
    }

    // Create a new Song object
    Song newSong(songID, songName, artists);

    // Insert the song in sorted order
    songs.insertSorted(newSong);

    cout << "Added song " << songID << "." << endl;
}
void BilkentBeats::removeSong( const int songID ) {
    Node<Song>* current = songs.getHead();
    Node<Song>* previous = nullptr;

    // Traverse the list to find the song
    while (current && current->data.getID() != songID) {
        previous = current;
        current = current->next;
    }

    // If the song is not found
    if (!current) {
        cout << "Cannot remove song. There is no song with ID " << songID << "." << endl;
        return;
    }

    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data.getPlaylists().getHead();
        while (playlistNode) {
            Node<Song>* songNode = playlistNode->data.getSongs().getHead();
            while (songNode) {
                if (songNode->data.getID() == songID) {
                    playlistNode->data.removeSong(songNode->data);
                }
                songNode = songNode->next;
            }
            playlistNode = playlistNode->next;
        }
        userNode = userNode->next;
    }

    // If the song is found
    if (!previous) { // The song is the head of the list
        songs.setHead(current->next);
    } else { // The song is in the middle or end of the list
        previous->next = current->next;
    }

    delete current;

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
        int songID = current->data.getID();
        string songName = current->data.getName();
        string artist = current->data.getArtist();

        cout << "Song " << songID << " : " << songName << " - " << artist << endl;

        current = current->next;
    }
}
void BilkentBeats::addPlaylist( const int userId, const int playlistId ) {
    Node<User>* userNode = users.getHead();
    while (userNode && userNode->data.getID() != userId) {
        userNode = userNode->next;
    }

    Node<User>* userNodeTest = users.getHead();
    while (userNodeTest ) {
        Node<Playlist>* playlistNodeTest = userNodeTest->data.getPlaylists().getHead();

        while (playlistNodeTest) {
            if (playlistNodeTest->data.getID() == playlistId && userNodeTest->data.getID() != userId) {
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

    // Check if the playlist ID already exists
    Node<Playlist>* playlistNode = userNode->data.getPlaylists().getHead();
    while (playlistNode) {
        if (playlistNode->data.getID() == playlistId) {
            cout << "Cannot add playlist. User " << userId << " already has a playlist with ID " << playlistId << "." << endl;
            return;
        }
        playlistNode = playlistNode->next;
    }

    // Add the new playlist
    Playlist newPlaylist(playlistId);
    userNode->data.addPlaylist(newPlaylist);
    cout << "Added playlist " << playlistId << " to user " << userId << "." << endl;
}
void BilkentBeats::removePlaylist( const int userId, const int playlistId ) {
    Node<User>* userNode = users.getHead();
    while (userNode && userNode->data.getID() != userId) {
        userNode = userNode->next;
    }

    if (!userNode) {
        cout << "Cannot remove playlist. There is no user with ID " << userId << "." << endl;
        return;
    }

    // Attempt to remove the playlist
    LinkedList<Playlist> playlists = userNode->data.getPlaylists();
    Node<Playlist>* playlistNode = playlists.getHead();
    Node<Playlist>* previous = nullptr;

    while (playlistNode && playlistNode->data.getID() != playlistId) {
        previous = playlistNode;
        playlistNode = playlistNode->next;
    }

    if (!playlistNode) {
        cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." << endl;
        return;
    }

    // Remove the playlist
    if (!previous) {
        playlists.setHead(playlistNode->next);
    } else {
        previous->next = playlistNode->next;
    }

    delete playlistNode;
    cout << "Removed playlist " << playlistId << " from user " << userId << "." << endl;
}
void BilkentBeats::addSongToPlaylist( const int playlistId, const int songId ) {
    Node<User>* userNode = users.getHead();
    while (userNode) {
        Node<Playlist>* playlistNode = userNode->data.getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data.getID() == playlistId) {

                // Check if the song exists in the music library
                Node<Song>* songNode = songs.getHead();
                while (songNode && songNode->data.getID() != songId) {
                    songNode = songNode->next;
                }

                if (!songNode) {
                    cout << "Cannot add song. There is no song with ID " << songId << "." << endl;
                    return;
                }

                // Check if the song is already in the playlist
                Node<Song>* playlistSongNode = playlistNode->data.getSongs().getHead();
                while (playlistSongNode) {
                    if (playlistSongNode->data.getID() == songId) {
                        cout << "Cannot add song. The playlist already contains song " << songId << "." << endl;
                        return;
                    }
                    playlistSongNode = playlistSongNode->next;
                }

                playlistNode->data.addSong(songNode->data);

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
        Node<Playlist>* playlistNode = userNode->data.getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data.getID() == playlistId) {
                // Playlist found, now validate the song

                // Check if the song exists in the playlist by song ID
                Node<Song>* songNode = playlistNode->data.getSongs().getHead();
                Node<Song>* previous = nullptr;

                while (songNode && songNode->data.getID() != songId) {
                    previous = songNode;
                    songNode = songNode->next;
                }

                if (!songNode) {
                    cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << endl;
                    return;
                }

                // If song is found, remove it from the playlist
                if (!previous) {
                    playlistNode->data.getSongs().setHead(songNode->next);  // Remove from the head
                } else {
                    previous->next = songNode->next;  // Remove from the middle or end
                }

                delete songNode;  // Free the memory occupied by the song node
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
        Node<Playlist>* playlistNode = userNode->data.getPlaylists().getHead();
        while (playlistNode) {
            if (playlistNode->data.getID() == playlistId) {
                // Playlist found, now print the songs in the playlist

                // Access the songs in the playlist
                Node<Song>* songNode = playlistNode->data.getSongs().getHead();
                if (!songNode) {
                    cout << "There are no songs to show in playlist " << playlistId << "." << endl;
                    return;
                }

                cout << "Songs in playlist " << playlistId << ":" << endl;

                // Traverse the song objects in the playlist
                while (songNode) {
                    const Song& song = songNode->data;  // Get the Song object

                    // Print the song details: ID, Name, Artist
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