/*
Entities involved: Players, Gestures/Symbol, GameManager

Initial Requirements:   2 Players (User and Computer)
                        3 Gestures (Rock, Paper, Scissor)
                        1 Winner (User or Computer) Ties can happen

Good to have extension:   Addition of more gestures
*/


#include "gamemanager.cpp"

vector<Gesture> GestureList::game_gestures = {};

int main() {
    cout << "How many games of Rock Paper Scissors would you like to play ?";
    int num_games = 0;
    cin >> num_games;

    GameManager manager(num_games);

    GestureList::init();
    manager.start();
    return 0;
}