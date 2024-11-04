#include "t3_library.h"

int main() 
{
    // nhập số người chơi
    int number_player =  input_number_of_players();

    // Bộ bài 52 lá
    vector<string> pack = return_pack();

    // Xáo bài
    vector<string> shuffled_pack = return_shuffled_pack(pack);

    // Chia bài
    vector<vector<string>> player_cards = deal_cards(shuffled_pack, number_player);

    // In bộ bài của các người chơi
    print_all_player_cards(player_cards, number_player);
        vector<int> player_points(number_player);
    vector<Hand_Rank> player_hand_rank(number_player); // Biến lưu loại bài của từng người chơi

    for (int player_index = 0; player_index < number_player; player_index++) {
        int temp_point = 0;
        Hand_Rank current_rank = HIGH_CARD;

        // Kiểm tra các loại bài
        if ((ranks[player_index * 5 + 1] == ranks[player_index * 5 + 0] + 1 &&
             ranks[player_index * 5 + 2] == ranks[player_index * 5 + 1] + 1 &&
             ranks[player_index * 5 + 3] == ranks[player_index * 5 + 2] + 1 &&
             ranks[player_index * 5 + 4] == ranks[player_index * 5 + 3] + 1) &&
            (suits[player_index * 5 + 0] == suits[player_index * 5 + 1] &&
             suits[player_index * 5 + 1] == suits[player_index * 5 + 2] &&
             suits[player_index * 5 + 2] == suits[player_index * 5 + 3] &&
             suits[player_index * 5 + 3] == suits[player_index * 5 + 4])) {
            cout << "Player " << player_index + 1 << ": Straight Flush!" << endl;
            temp_point = 6;
            current_rank = STRAIGHT_FLUSH;

        } else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3]) ||
                   (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            cout << "Player " << player_index + 1 << ": Four of a Kind!" << endl;
            temp_point = 5;
            current_rank = FOUR_OF_A_KIND;

        } else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4]) ||
                   (ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            cout << "Player " << player_index + 1 << ": Full House!" << endl;
            temp_point = 4;
            current_rank = FULL_HOUSE;

        } else if (suits[player_index * 5 + 0] == suits[player_index * 5 + 1] &&
                   suits[player_index * 5 + 1] == suits[player_index * 5 + 2] &&
                   suits[player_index * 5 + 2] == suits[player_index * 5 + 3] &&
                   suits[player_index * 5 + 3] == suits[player_index * 5 + 4]) {
            cout << "Player " << player_index + 1 << ": Flush!" << endl;
            temp_point = 3;
            current_rank = FLUSH;

        } else if (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 0] + 1 &&
                   ranks[player_index * 5 + 2] == ranks[player_index * 5 + 1] + 1 &&
                   ranks[player_index * 5 + 3] == ranks[player_index * 5 + 2] + 1 &&
                   ranks[player_index * 5 + 4] == ranks[player_index * 5 + 3] + 1) {
            cout << "Player " << player_index + 1 << ": Straight!" << endl;
            temp_point = 2;
            current_rank = STRAIGHT;

        } else if ((ranks[player_index * 5 + 0] == ranks[player_index * 5 + 1] &&
                    ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2]) ||
                   (ranks[player_index * 5 + 1] == ranks[player_index * 5 + 2] &&
                    ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3]) ||
                   (ranks[player_index * 5 + 2] == ranks[player_index * 5 + 3] &&
                    ranks[player_index * 5 + 3] == ranks[player_index * 5 + 4])) {
            cout << "Player " << player_index + 1 << ": Three of a Kind!" << endl;
            temp_point = 1;
            current_rank = THREE_OF_A_KIND;

        } else {
            cout << "Player " << player_index + 1 << ": High Card" << endl;
            current_rank = HIGH_CARD;
        }

        player_points[player_index] = temp_point;
        player_hand_rank[player_index] = current_rank;
    }

    // Tìm người chơi có điểm cao nhất
    int max_points = 0, winning_player_index = 0;
    for (int i = 0; i < number_player; i++) {
        if (player_points[i] > max_points) {
            max_points = player_points[i];
            winning_player_index = i;
        }
    }

    // Hiển thị người thắng với loại bài
    map<Hand_Rank, string> hand_rank_names = {
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

    cout << "Player " << winning_player_index + 1 << " wins with " 
         << hand_rank_names[player_hand_rank[winning_player_index]] << "!" << endl;

    vector <int> ranks[50];
    // thứ hạng của các lá bài
    vector <int> suits[50];
    // lưu trữ chất của lá bài

    //sắp xếp lại lá bài của các người chơi để tính điểm
    rank_player_cards(player_cards, number_player, ranks, suits);

    //hỏi người dùng có muốn sắp xếp lại cách hiển thị thứ tự các lá bài không
    cout << "Do you want to rearrange the order of your cards?\n";
    if(check_Yes_No_Input())   
        print_all_player_cards(player_cards, number_player);
    
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    // kiểm tra loại bài mỗi người chơi
    vector <int> player_points(number_player);

    for (int player_index = 0; player_index < number_player; player_index++) {
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
    for (int i = 0; i < number_player; i++) {
        if (player_points[i] > max_points) {
            max_points = player_points[i];
            winning_player_index = i;
        }
    }

    // Map hand ranks to their string representations
    // map sẽ tự động sắp xếp'
    map<Hand_Rank, string> hand_rank_names = 
    {
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

    cout << "Player " << winning_player_index + 1 << " wins with " << hand_rank_names[static_cast<Hand_Rank>(player_points[winning_player_index])] << " !" << std::endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
    return 0;
}
