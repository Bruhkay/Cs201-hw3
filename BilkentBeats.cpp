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
void BilkentBeats::removeUser( const int userId ){}
void BilkentBeats::printUsers() const {
    if (!users.getHead()) {
        cout << "There are no users to show." << endl;
        return;
    }

    Node<User>* current = users.getHead();
    while (current) {
        string userName = current->data.getName();  // Get the user name
        cout << userName << endl;  // Print the user name
        current = current->next;  // Move to the next user
    }
}

void BilkentBeats::addSong( const int songID, const string songName, const string artists ){}
void BilkentBeats::removeSong( const int songID ){}
void BilkentBeats::printSongs() const{}

void BilkentBeats::addPlaylist( const int userId, const int playlistId ){}
void BilkentBeats::removePlaylist( const int userId, const int playlistId ){}
void BilkentBeats::addSongToPlaylist( const int playlistId, const int songId ){}
void BilkentBeats::removeSongFromPlaylist( const int playlistId, const int songId ){}
void BilkentBeats::printSongsInPlaylist( const int playlistId ) const{}