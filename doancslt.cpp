#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

int Shuffle_cards();


int main(){
    // nhập số người chơi
    int player;
    cout << "Enter number of players :" << endl;
    while (!(cin >> player) || player > 1 || player <= 12) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter again: ";
    }

    // bộ bài 52 lá
    vector < string > pack;
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
    vector < string > shuffled_pack = pack;
    // Nhận một số ngẫu nhiên khác nhau mỗi lần chương trình chạy. tham khảo ở https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    srand(time(0));
    //xáo bài tham khảo ở https://www.w3schools.com/cpp/ref_algorithm_random_shuffle.asp
    random_shuffle(shuffled_pack.begin(), shuffled_pack.end());
    //chia bài 
    vector <string> player_card[10];
    for (int i = 0; i < player * 5; i++){
        player_card[i % player].push_back(shuffled_pack[i]);
    }

    return 0;
}
