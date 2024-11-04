#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
    Thư viện này bao các hàm:
        return_pack ()            : tạo và trả về bộ bài 52 lá
        input_number_of_players() : nhập và kiểm tra số người chơi (cần cải tiến)
*/

// Hàm nhập số người chơi (chưa tối ưu trường hợp 1a)
int input_number_of_players() 
{
    int number_player;
    cout << "Enter number of players: " << endl;
    while (!(cin >> number_player) || number_player < 4 || number_player >= 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter again: ";
    }
    return number_player;
}


//tạo và trả về bộ bài 52 lá
 vector < string > return_pack ()
 {
    vector <string> pack;
    for(int i = 1; i <= 52; i++){
        switch (i % 13 ) 
        {
            case 10: pack.push_back("10");
                break;
            case 11: pack.push_back("J");
                break;
            case 12: pack.push_back("Q");
                break;
            case 0: pack.push_back("K");
                break;
            case 1: pack.push_back("A");
                break;
            default: 
                string s;
			    s = (char)(i % 13 + 48 );
                pack.push_back(s); 
                break;
        }
        if (i >= 1 && i <= 13){
            pack[pack.size() - 1] += " spade";
        }
        if (i >= 14 && i <= 26){
            pack[pack.size() - 1] += " club";
        }
        if (i >= 27 && i <= 39){
            pack[pack.size() - 1] += " diamond";
        }
        if (i >= 40 && i <= 52){
            pack[pack.size() - 1] += " heart";
        }
    }
    return pack;
 }

