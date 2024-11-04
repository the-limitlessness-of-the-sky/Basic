#pragma once
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