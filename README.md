Movie Watchlist (C++)

Simple C++ program to manage a movie watchlist.

Features
-Add or update movie
-Delete movie
-Display list
-Saves data to a file
-Loads data when program starts

How it works
-Uses unordered_map (hash table)
-Movie title = key
-Status + rating = value

Menu
1. Add/Update Movie
2. Delete Movie
3. Refresh List
4. Exit

File
Data is saved in:
movies.txt

Run
g++ main.cpp -o watchlist
./watchlist

Notes
-Title must be exact when deleting
-Not sorted
-Basic input only
