#include <iostream>
#include "gesturelist.cpp"

using namespace std;

/*
Player:     Represents an entity that does gestures. Can be a human or a computer.

Test: 
    Player p1("User");
    Player p2("Computer");

    cout << p1.get_name() << endl; // "USER"

    Gesture g1 = p1.get_gesture();
    Gesture g2 = p2.get_gesture();

    cout << p1.get_chosens_gesture().get_gesture() << endl; 
    cout << p2.get_chosen_gesture().get_gesture() << endl; 
*/

class Player {
    public:
        // Default constructor
        Player() : player_name { "" } {}

        // Parametrized constructor
        Player(string name) {
            for(auto &ch: name) ch = toupper(ch);
            player_name = name;
        }

        // asks players to choose a gesture (computer and human player)
        Gesture get_gesture();

        // asks a computer to choose a gesture
        Gesture get_computer_gesture();

        // asks a human to choose a gesture
        Gesture get_player_gesture();

        // Rerturn the name of player
        string get_name();

        // Get the gesture chosen by the player in a game.
        Gesture get_chosen_gesture();

    private:
        // player name 
        string player_name;

        // gesture chosen by the player
        Gesture player_gesture;
};

Gesture Player::get_gesture() {
    Gesture chosen_gesture;
    if(player_name == "COMPUTER") chosen_gesture = get_computer_gesture();
    else chosen_gesture = get_player_gesture();

    player_gesture = chosen_gesture;

    return chosen_gesture;
}

inline Gesture Player::get_computer_gesture() { return GestureList::get_random_gesture(); }

inline Gesture Player::get_player_gesture() {
    bool valid_gesture = false;
    Gesture chosen_gesture;

    // continue to ask for a gesture while a valid gesture is not privided by the user.
    while(!valid_gesture) {
        cout << player_name << ", what did you choose?" << endl;
        string symbol = "";
        cin >> symbol;

        for(auto &ch : symbol) ch = toupper(ch);

        chosen_gesture = Gesture(symbol);
        valid_gesture = GestureList::validate_gesture(chosen_gesture);
    }

    return chosen_gesture;
}

inline string Player::get_name() { return player_name; } 

inline Gesture Player::get_chosen_gesture() { return player_gesture; }

