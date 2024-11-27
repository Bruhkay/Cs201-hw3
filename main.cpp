
#include <iostream>
using namespace std;
#include "BilkentBeats.h"
int main() {
    cout << "Hello World!" << endl;
    BilkentBeats bilkentBeats;
    // Add users
    bilkentBeats.addUser(3, "John");
    bilkentBeats.addUser(1, "Alice");
    bilkentBeats.addUser(2, "Bob");

    // Print users to verify the list is sorted
    bilkentBeats.printUsers();

    return 0;
}