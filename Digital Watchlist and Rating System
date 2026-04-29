#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// struct for storing movie details
struct MovieInfo {
    string status;
    string rating;
};

int main() {
    cout << "To test\n\n";

    // make the hash table
    unordered_map<string, MovieInfo> watchlist;

    // putting sample data manually for testing
    watchlist["San Junipero"] = {"Watched", "10/10"};
    watchlist["Project Hail Mary"] = {"Unwatched", "N/A"};

    // display all data to check if it stored correctly
    cout << "--- Movie Diary Dump ---\n";
    for (auto const& pair : watchlist) {
        cout << "Title: " << pair.first << "\n"
             << " - Status: " << pair.second.status << "\n"
             << " - Rating: " << pair.second.rating << "\n\n";
    }

    return 0;
}
