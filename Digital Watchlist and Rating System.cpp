#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// struct for storing movie details
// no need to include title here since it will be the key in the hash table
struct MovieInfo {
    string status;
    string rating;
};

// this is our hash table
// it connects a movie title (key) to its info (value)
unordered_map<string, MovieInfo> watchlist;

// function to save movies into a file
void saveMovies() {
    ofstream file("movies.txt");

    // loop through the hash table
    // pair.first = title
    // pair.second = MovieInfo (status + rating)
    for (auto const& pair : watchlist) {
        file << pair.first << "\n" 
             << pair.second.status << "\n" 
             << pair.second.rating << "\n";
    }

    file.close();
}

// function to load movies from the file
void loadMovies() {
    ifstream file("movies.txt");
    string title, status, rating;

    // read 3 lines at a time (title, status, rating)
    while (getline(file, title)) {
        getline(file, status);
        getline(file, rating);

        // rebuild the hash table
        watchlist[title] = {status, rating};
    }

    file.close();
}

// display all movies
void displayMovies() {
    cout << "--- My Watchlist ---\n";

    if (watchlist.empty()) {
        cout << "No movies added yet.\n";
    } else {
        int count = 1;

        // loop and print each movie
        for (auto const& pair : watchlist) {
            cout << count++ << ". " << pair.first 
                 << " | " << pair.second.status 
                 << " | " << pair.second.rating << "\n";
        }
    }

    cout << "--------------------\n";
}

// add new movie or update existing one
void addOrUpdateMovie() {
    string title, status, rating;

    cout << "\nMovie Title: ";
    // ws removes leftover newline from previous input
    getline(cin >> ws, title);

    cout << "Status (Watched/Unwatched): ";
    getline(cin, status);

    cout << "Rating: ";
    getline(cin, rating);

    // this line handles both adding and updating
    // if title exists -> update
    // if not -> create new entry
    watchlist[title] = {status, rating};

    saveMovies();
    cout << "\nSaved successfully!\n";
}

// delete a movie
void deleteMovie() {
    if (watchlist.empty()) return;

    string title;
    cout << "Enter the EXACT title of the movie to delete: ";
    getline(cin >> ws, title);

    // erase returns 1 if found, 0 if not
    if (watchlist.erase(title)) {
        saveMovies();
        cout << "\nDeleted.\n";
    } else {
        cout << "\nMovie not found.\n";
    }
}

int main() {
    loadMovies(); // load saved data first

    int choice = 0;

    while (choice != 4) {
        displayMovies();

        cout << "\n1. Add/Update Movie\n2. Delete Movie\n3. Refresh List\n4. Exit\n\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            addOrUpdateMovie();
        } else if (choice == 2) {
            deleteMovie();
        }
    }

    return 0;
}
