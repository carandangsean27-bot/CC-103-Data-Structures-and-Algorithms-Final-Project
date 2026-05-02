#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct MovieInfo {
    string status;
    string rating;
};

// Main storage for movies (its like database)
unordered_map<string, MovieInfo> watchlist;

void displayMovies() {
    cout << "\n=== My Watchlist Diary ===\n";
    
    // Check if the list is empty
    if (watchlist.empty()) {
        cout << "Your list is empty! Add some movies.\n";
    } else {
        // Loop through all movies in the list
        for (auto const& pair : watchlist) {
            cout << "- " << pair.first << " | Status: " << pair.second.status 
                 << " | Rating: " << pair.second.rating << "\n";
        }
    }
    
    cout << "====================\n";
}

void addMovie() {
    string title, status, rating;
    
    cout << "\nMovie Title: ";
    // ws is used to clear leftover spaces from previous input
    getline(cin >> ws, title); 
    
    cout << "Status (Watched/Unwatched): ";
    getline(cin, status);
    
    cout << "Rating (e.g., 10/10): ";
    getline(cin, rating);
    
    // Quickly adds or updates a movie (cuz hash map is fast)
    watchlist[title] = {status, rating}; 
    
    cout << "[Success]: Movie added/updated!\n";
}

void deleteMovie() {
    // Check if the list is empty first
    if (watchlist.empty()) {
        cout << "\nList is already empty.\n";
        return;
    }
    
    string title;
    cout << "\nEnter the exact title of the movie to delete: ";
    getline(cin >> ws, title);
    
    // Tries to find and delete the movie
    if (watchlist.erase(title)) {
        cout << "[Success]: Movie deleted.\n";
    } else {
        cout << "[Error]: Could not find a movie with that title.\n";
    }
}

int main() {
    int choice = 0;
    
    // Main loop (keeps running until user exits)
    while (choice != 4) {
        cout << "\n1. Add / Update a Movie\n2. View Watchlist\n3. Delete a Movie\n4. Exit\nChoose an option: ";
        cin >> choice;
        
        if (choice == 1) {
            addMovie();
        } else if (choice == 2) {
            displayMovies();
        } else if (choice == 3) {
            deleteMovie();
        }
    }
    
    cout << "Exiting program...\n";
    return 0;
}
