#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Thêm thư viện này để dùng srand
#include <ctime>   // Thêm thư viện này để dùng time
/*
    Thư viện này bao các hàm:
        return_shuffled_pack   ()  : xào bài rồi trả về bộ bài đã được xáo
        deal_cards             ()  : in bài của tất cả người chơi
        print_player_cards     ()  : in bài của một người chơi
        print_all_player_cards ()  : in bài của tất cả người chơi
*/

//xào bài
    vector <string> return_shuffled_pack (vector <string> shuffled_pack)
{
    // Nhận một số ngẫu nhiên khác nhau mỗi lần chương trình chạy
    //tham khảo ở https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    srand(time(0));
    //xáo bài tham khảo ở https://www.w3schools.com/cpp/ref_algorithm_random_shuffle.asp
    random_shuffle(shuffled_pack.begin(), shuffled_pack.end());
    return shuffled_pack;
}


// Chia bài 
vector<vector<string>> deal_cards(const vector<string>& shuffled_pack, int number_player) 
{
    vector<vector<string>> player_cards(number_player); // Mỗi người chơi sẽ có một vector riêng
    for (int i = 0; i < number_player * 5; i++) 
    {
        player_cards[i % number_player].push_back(shuffled_pack[i]);
    }
    return player_cards;
}

//in bài của người chơi
void print_player_cards(vector<string> player_cards)
{
    for (const string& card : player_cards)
    {
        cout << card << endl; // In từng lá bài trên một dòng
    }
    cout << endl; 
    // Xuống dòng sau khi in xong lá bài của người chơi
}

//in bài của tất cả người chơi 
void print_all_player_cards(const vector<vector<string>>& player_cards, int number_player) 
{
    // In ra từng lá bài của từng người chơi theo từng dòng
    for (int i = 0; i < number_player; i++) {
        cout << "Cards of player " << i + 1 << ":" << endl;

        for (const string& card : player_cards[i]) {
            cout << card << endl; // In từng lá bài trên một dòng
        }

        cout << endl; // Xuống dòng sau khi in xong lá bài của người chơi
    }
}



