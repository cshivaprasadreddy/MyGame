#include "Game.h"
#include "Room.h"
#include "TripMine.h"
#include "Hole.h"
#include "Staircase.h"
#include "ExitDoor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game() : numFloors(0) {
    // Player starts on floor1 (index 1), position (0,0)
    player.setPosition(1, 0, 0);
}

Game::~Game() {
    // Free memory for all floors
    for (auto& floor : floors) {
        for (auto& row : floor) {
            for (auto loc : row) {
                delete loc;
            }
        }
    }
}

void Game::loadMap(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening map file: " << filename << endl;
        exit(1);
    }

    infile >> numFloors;
    floors.resize(numFloors);
    floorRows.resize(numFloors);
    floorCols.resize(numFloors);

    // For each floor, read floor name, rows, and columns
    for (int f = 0; f < numFloors; f++) {
        string floorName;
        int rows, cols;
        infile >> floorName >> rows >> cols;
        floorRows[f] = rows;
        floorCols[f] = cols;
        floors[f].resize(rows, vector<Location*>(cols, nullptr));

        string line;
        getline(infile, line); // consume rest of header line
        for (int r = 0; r < rows; r++) {
            getline(infile, line);
            istringstream iss(line);
            for (int c = 0; c < cols; c++) {
                string token;
                iss >> token;
                Location* loc = nullptr;
                // Create a location object based on the token.
                if (token == "room")
                    loc = new Room(false, false);
                else if (token == "room_realkey")
                    loc = new Room(true, true);
                else if (token == "room_fakekey")
                    loc = new Room(true, false);
                else if (token == "hallway")
                    loc = new Location("H");
                else if (token == "trap_hole")
                    loc = new Hole();
                else if (token == "trap_mine")
                    loc = new TripMine();
                else if (token == "staircase")
                    loc = new Staircase();
                else if (token == "exit_door")
                    loc = new ExitDoor();
                else
                    loc = new Location(" ");
                floors[f][r][c] = loc;
            }
        }
    }
}

void Game::displayCurrentFloor() {
    int cf = player.getFloor();
    if (cf < 0 || cf >= numFloors) {
        cout << "Invalid floor!" << endl;
        return;
    }
    int rows = floorRows[cf];
    int cols = floorCols[cf];
    cout << "Current Floor (" << cf << "):" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (r == player.getRow() && c == player.getCol())
                cout << "P "; // Player’s position
            else {
                floors[cf][r][c]->draw();
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Game::playGame() {
    char input;
    while (true) {
        cout << "\n---------------------------------\n";
        displayCurrentFloor();
        player.listKeys();
        cout << "Move: (W/A/S/D) or (Q)uit: ";
        cin >> input;
        input = toupper(input);
        int curFloor = player.getFloor();
        int r = player.getRow();
        int c = player.getCol();
        int newR = r, newC = c;
        switch (input) {
        case 'W': newR = r - 1; break;
        case 'A': newC = c - 1; break;
        case 'S': newR = r + 1; break;
        case 'D': newC = c + 1; break;
        case 'Q':
            cout << "Quitting game." << endl;
            exit(0);
        default:
            cout << "Invalid input!" << endl;
            continue;
        }
        // Check boundaries for current floor
        if (newR < 0 || newR >= floorRows[curFloor] || newC < 0 || newC >= floorCols[curFloor]) {
            cout << "Can't move there, out of bounds!" << endl;
            continue;
        }
        // Update player's position on the current floor
        player.setPosition(curFloor, newR, newC);
        // Trigger the location’s event
        floors[curFloor][newR][newC]->visit(player);
        system("cls");
    }
}
