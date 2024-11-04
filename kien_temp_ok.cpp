#include "t3_library.h"

enum Hand_Rank {
    HIGH_CARD = 0,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};

struct Player {
    int number;
    int total_games;
    int wins;
    float win_rate;
    std::map<std::string, int> win_situations;
};
using namespace std;

int main()
    {
    int number_player; 
    // Thêm vào chứ để player không nó hiện cái lỗi thấy khó chịu quá
    //R = Rank
    //S = Suit
    
    vector<vector<string>> player_cards

    int ranks[50];
    // thứ hạng của các lá bài
    int suits[50];
    // lưu trữ chất của lá bài 


    // Sort the Rank array (hidden from viewer)  - done
   // Sort each player's hand based on the rank array

   // Sếp nhóm 5
    for (int player_index = 0; player_index < number_player; player_index++) 
    {
        // Assuming R[i] corresponds to the rank of the i-th card in playerIndex's hand
        // 2 dòng for so sánh và sắp xếp các quân bài trên tay của mỗi người chơi theo thứ tự tăng dần của rank
        for (int i = 0; i < 4; i++) 
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (ranks[player_index * 5 + i] > ranks[player_index * 5 + j]) 
                {
                    // Swap the cards in the player_cards vector
                    swap(player_cards[player_index][i], player_cards[player_index][j]); 
                    // Tham khảo biến từ file Trí
                    // Swap the corresponding ranks in the R array
                    std::swap(ranks[player_index * 5 + i], ranks[player_index * 5 + j]);
                    
                }
            }
        }
    }
}

    // check the card of player
    // kiểm tra loại bài mỗi người chơi
    int player_points[10];

    for (int player_index = 0; player_index < player; player_index++) {
        int temp_point = 0;
        // Check for hand combinations (straight flush, four of a kind, etc.)

        //Straight Flush
        if ((ranks[player_index * 5 + 1] == ranks[player_index * 5 + 0] + 1 &&
            ranks[player_index * 5 + 2] == ranks[player_index * 5 + 1] + 1 &&
            ranks[player_index * 5 + 3] == ranks[player_index * 5 + 2] + 1 &&
            ranks[player_index * 5 + 4] == ranks[player_index * 5 + 3] + 1) &&
            (suits[player_index * 5 + 0] == suits[player_index * 5 + 1] &&
             suits[player_index * 5 + 1] == suits[player_index * 5 + 2] &&
             suits[player_index * 5 + 2] == suits[player_index * 5 + 3] &&
             suits[player_index * 5 + 3] == suits[player_index * 5 + 4])) {
            std::cout << "Player " << player_index + 1 << ": Straight Flush!" << std::endl;
            temp_point += 6;

        //Four of a Kind!
        } else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3]) ||
                   (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            std::cout << "Player " << player_index + 1 << ": Four of a Kind!" << std::endl;
            temp_point += 5;

        } 
        //Full House
        else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4]) ||
                   (ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            std::cout << "Player " << player_index + 1 << ": Full House!" << std::endl;
            temp_point += 8;
        }
        //Flush
        else if (suits[player_index * 5 + 0] == suits[player_index * 5 + 1] &&
                   suits[player_index * 5 + 1] == suits[player_index * 5 + 2] &&
                   suits[player_index * 5 + 2] == suits[player_index * 5 + 3] &&
                   suits[player_index * 5 + 3] == suits[player_index * 5 + 4]) {
            std::cout << "Player " << player_index + 1 << ": Flush!" << std::endl;
            temp_point += 4;

        } 
        //Straight
        else if (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 0] + 1 &&
                   ranks[player_index * 5 + 2] == ranks[player_index * 5 + 1] + 1 &&
                   ranks[player_index * 5 + 3] == ranks[player_index * 5 + 2] + 1 &&
                   ranks[player_index * 5 + 4] == ranks[player_index * 5 + 3] + 1) {
            std::cout << "Player " << player_index + 1 << ": Straight!" << std::endl;
            temp_point += 3;

        }
        //Three of a Kind
        else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2]) ||
                   (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3]) ||
                   (ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            std::cout << "Player " << player_index + 1 << ": Three of a Kind!" << std::endl;
            temp_point += 2;

        } 
        //Pair
        else if (ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] ||
                   ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] ||
                   ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] ||
                   ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4]) {
            std::cout << "Player " << player_index + 1 << ": Pair!" << std::endl;
            temp_point += 1;

        } 
        //High Card
        else 
        {
            std::cout << "Player " << player_index + 1 << ": High Card" << std::endl;
        }

        player_points[player_index] = temp_point;
    }


    //Dertemine the winner
    int max_points = 0, winning_player_index = 0;
    for (int i = 0; i < player; i++) {
        if (player_points[i] > max_points) {
            max_points = player_points[i];
            winning_player_index = i;
        }
    }

    // Map hand ranks to their string representations
    std::map<Hand_Rank, std::string> hand_rank_names = {
        {HIGH_CARD, "High Card"},
        {PAIR, "Pair"},
        {TWO_PAIR, "Two Pair"},
        {THREE_OF_A_KIND, "Three of a Kind"},
        {STRAIGHT, "Straight"},
        {FLUSH, "Flush"},
        {FULL_HOUSE, "Full House"},
        {FOUR_OF_A_KIND, "Four of a Kind"},
        {STRAIGHT_FLUSH, "Straight Flush"}
    };

    std::cout << "Player number: " << winning_player_index + 1 << " wins with " << hand_rank_names[static_cast<Hand_Rank>(player_points[winning_player_index])] << " points!" << std::endl;
    

    // output to file txt
    std::vector<Player> players;

    players[winning_player_index].total_games++;
    players[winning_player_index].wins++;

    for (Player & player : players) {
        // Read player data from the file
    std::ifstream infile("player_data.txt");
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            int number, total_games, wins;
            float win_rate;
            std::string most_frequent_situation;

            iss >> number >> total_games >> wins >> win_rate >> most_frequent_situation;

            Player player;
            player.number = number;
            player.total_games = total_games;
            player.wins = wins;
            player.win_rate = win_rate;
            player.win_situations[most_frequent_situation]++;

            players.push_back(player);
        }
        infile.close();
    } else {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1; // Indicate error
    }

    // Modify player data (example: increment wins for player with number 2)
    for (Player& player : players) {
        if (player.number == 2) {
            player.wins++;
            player.win_rate = (float)player.wins / player.total_games * 100;
            break;
        }
    

        // Write the modified data back to the file
        std::ofstream outfile("player_data.txt");
        if (outfile.is_open()) {
            for (const Player& player : players) {
                
            }outfile << player.number << " " << player.total_games << " " << player.wins << " " << player.win_rate << " ";
            
            for (const auto& entry : player.win_situations) {
                outfile << entry.first << " ";
            }

            outfile.close();
            std::cout << "Player data saved successfully!" << std::endl;
        } else {
            std::cout << "Error: Unable to open file." << std::endl;
            return 1; // Indicate error
        }
    }
    

    return 0;
}