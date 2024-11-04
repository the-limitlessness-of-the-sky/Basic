#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
#include <ctime>
#include <algorithm>
#include "setup_52_cards.h"
#include "use_52_cards.h"
using namespace std;

enum Hand_Rank 
{
    HIGH_CARD = 1,
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

// hỏi người dùng nhập Yes hoặc No 
bool check_Yes_No_Input() {
    char input;
    while (true) {
        std::cout << "Please enter Y (Yes) or N (No): ";
        std::cin >> input;

        if (input == 'y' || input == 'Y') {
            return true; // Người dùng nhập Y
        } else if (input == 'n'|| input == 'N') {
            return false; // Người dùng nhập N
        } else {
            std::cout << "Invalid input. "; // Thông báo nếu đầu vào không hợp lệ
        }
    }
}

int get_rank(const string& card) {
    // Tách giá trị thứ hạng từ chuỗi
    string rank_str = card.substr(0, card.find(" "));

    // Map các quân bài vào giá trị số mong muốn
    map<string, int> rank_map = {
        {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
        {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
    };

    return rank_map[rank_str]; // Trả về giá trị số tương ứng
}

int get_suit(const string& card) {
    // Tách chất từ chuỗi (giả sử chất nằm sau khoảng trắng)
    string suit_str = card.substr(card.find(" ") + 1);

    // Map chất vào số (nếu bạn cần xử lý chất)
    map<string, int> suit_map = {
        {"spade", 0}, {"heart", 1}, {"diamond", 2}, {"club", 3}
    };

    return suit_map[suit_str]; // Trả về giá trị số của chất
}

void rank_player_cards(vector<vector<string>>& player_cards, int number_player, int ranks[], int suits[]) {
    for (int player_index = 0; player_index < number_player; player_index++) {
        for (int i = 0; i < 5; i++) {
            ranks[player_index * 5 + i] = get_rank(player_cards[player_index][i]);
            suits[player_index * 5 + i] = get_suit(player_cards[player_index][i]);
        }

        // Sắp xếp các lá bài theo thứ tự tăng dần
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (ranks[player_index * 5 + i] > ranks[player_index * 5 + j]) {
                    swap(player_cards[player_index][i], player_cards[player_index][j]);
                    swap(ranks[player_index * 5 + i], ranks[player_index * 5 + j]);
                }
            }
        }
    }
}
// Tính điểm cho từng người chơi
void calculate_player_points(int number_player, const vector<vector<string>>& player_cards, int* player_points) {
    for (int player_index = 0; player_index < number_player; player_index++) {
        int temp_point = 0;
        // Logic xử lý các trường hợp bài để tính điểm (thêm logic ở đây)
        player_points[player_index] = temp_point;
    }
}

// Xác định người thắng cuộc
int determine_winner(int number_player, const int* player_points) {
    int max_points = 0, winning_player_index = 0;
    for (int i = 0; i < number_player; i++) {
        if (player_points[i] > max_points) {
            max_points = player_points[i];
            winning_player_index = i;
        }
    }
    return winning_player_index;
}