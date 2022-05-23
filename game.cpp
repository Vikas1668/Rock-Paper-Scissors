#include <iostream>
#include <unistd.h>
#include "player.cpp"

using namespace std;

int NUM_PLAYERS = 2;

/*
Game:   Represents one game consisting of { user's gesture, computer's gesture, winner }
        also contains logic to decide winner.

Test:
    Game g;
    Player p1("User");
    Player p2("Computer");

    g.play({p1, p2});

    for(auto p: g.get_players()) cout << p.get_name() << endl; // "USER", "COMPUTER"
    for(auto ge: g.get_gestures()) cout << ge.get_gesture() << endl; 

    Player winner = g.choose_winner();

    cout << winner.get_name() << endl;

    cout << g.get_winner().get_name() << endl;

    g.get_result(1);
*/

class Game {
    public:
        // Default constructor
        Game() {}

        // plays a game
        void play(vector<Player> players);

        // chooses a winner after every player has chosen a gesture
        Player choose_winner();

        // get list of players
        vector<Player> get_players();

        // get list of gestures by players in a game
        vector<Gesture> get_gestures();

        // get the chosen winner of the game
        Player get_winner();

        // display the result of game
        void get_result(int);

    private:
        vector<Player> all_players;
        vector<Gesture> all_gestures;
        Player winner;
};

void Game::play(vector<Player> players) {
    cout << "Ready !!!\r" << flush;
    sleep(1);
    cout << "ROCK     \r" << flush;
    sleep(1);
    cout << "PAPER    \r" << flush;
    sleep(1);
    cout << "SCISSOR    " << endl;

    // ask players to choose their gestures
    for(Player player : players) {
        all_gestures.push_back(player.get_gesture());
        all_players.push_back(player);
    }

    winner = choose_winner();
}

Player Game::choose_winner() {
    if(NUM_PLAYERS == 2) {
        int result = all_gestures[0] < all_gestures[1];
        if(result == 0) return all_players[1];
        if(result == 1) return Player();
        else return all_players[0];
    }

    return Player();
}

inline vector<Player> Game::get_players() { return all_players; }

inline vector<Gesture> Game::get_gestures() { return all_gestures; }

inline Player Game::get_winner() { return winner; }

void Game::get_result(int game_num) {
    cout << "\n****** Game " << game_num << " ******\n";

    vector<Player> players = get_players();
    vector<Gesture> gestures = get_gestures();
    Player winner = get_winner();

    int player_num = 0;
    for(auto player: players) {
        cout << player.get_name() << " chose " << gestures[player_num].get_gesture() << endl;
        player_num++;
    }

    if(winner.get_name() != "")
        cout << "WINNER: " << winner.get_name() << " won with gesture " << winner.get_chosen_gesture().get_gesture() << endl;
    else cout << "TIE" << endl; 
    cout << "\n*************************\n";
}