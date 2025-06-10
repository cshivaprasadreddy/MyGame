#include "Staircase.h"
#include "Player.h"

Staircase::Staircase() : Location("S") {}

void Staircase::visit(Player& player) {
    int currentFloor = player.getFloor();
    cout << "You are at a staircase. ";
    if (currentFloor == 0) { // Base floor: can only go up
        cout << "You can only go up from here." << endl;
        cout << "Go up? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            player.setPosition(currentFloor + 1, player.getRow(), player.getCol());
            cout << "Moving up to floor " << currentFloor + 1 << endl;
        }
    }
    else if (currentFloor == 3) { // Top floor: can only go down
        cout << "You can only go down from here." << endl;
        cout << "Go down? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            player.setPosition(currentFloor - 1, player.getRow(), player.getCol());
            cout << "Moving down to floor " << currentFloor - 1 << endl;
        }
    }
    else {
        cout << "Do you want to go (U)p or (D)own? ";
        char choice;
        cin >> choice;
        if (choice == 'U' || choice == 'u') {
            player.setPosition(currentFloor + 1, player.getRow(), player.getCol());
            cout << "Moving up to floor " << currentFloor + 1 << endl;
        }
        else if (choice == 'D' || choice == 'd') {
            player.setPosition(currentFloor - 1, player.getRow(), player.getCol());
            cout << "Moving down to floor " << currentFloor - 1 << endl;
        }
    }
}
