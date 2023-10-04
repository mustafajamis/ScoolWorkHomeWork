// Mustafa Jamshidi
// CS400LinkedListApplication(PlayList).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
struct Song {
    string title;
    string artist;
    Song* next;
};

class PlayList {
private:
    Song* head;

public:
    PlayList() {
        head = nullptr;
    }

    void addSong(string title, string artist) {
        Song* newSong = new Song{ title, artist, nullptr };

        if (head == nullptr) {
            head = newSong;
            return;
        }

        Song* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newSong;
    }

    void removeSong(string title) {
        if (head == nullptr) {
            return;
        }

        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Song* current = head;
        while (current->next != nullptr && current->next->title != title) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Song* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void displayPlaylist() const {
        Song* current = head;
        while (current != nullptr) {
            cout << "Title: " << current->title << ", Artist: " << current->artist << endl;
            current = current->next;
        }
    }
};

int main() {
    PlayList myPlaylist;

    myPlaylist.addSong("Song 1", "Artist 1");
    myPlaylist.addSong("Song 2", "Artist 2");
    myPlaylist.addSong("Song 3", "Artist 3");
    myPlaylist.addSong("Song 4", "Artist 4");

    myPlaylist.displayPlaylist();

    myPlaylist.removeSong("Song 2");

    myPlaylist.displayPlaylist();

    return 0;
}
