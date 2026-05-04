# Movie Watchlist (C++)

A simple C++ program to manage a digital movie watchlist.

## ✨ Features
* Add or update a movie
* Delete a movie
* Display the watchlist
* Saves data to a file (`movies.txt`)
* Loads data automatically when the program starts

## ⚙️ How it Works
* Uses an `unordered_map` (Hash Table)
* **Key:** Movie title
* **Value:** Status + rating

## 🛠️ Menu
1. Add/Update Movie
2. View Watchlist
3. Delete Movie
4. Exit

## 🚀 How to Run
Run these commands in your terminal:

```bash
g++ "Digital Watchlist and Rating System.cpp" -o watchlist
./watchlist
```

## 📌 Notes
* The title must be typed exactly when deleting a movie.
* The list is not alphabetically sorted (because hash tables are unordered).
* Uses basic terminal input.
