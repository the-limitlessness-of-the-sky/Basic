#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){


    //R = Rank
    //S = Suit

    // Sort the Rank array (hidden from viewer)  - working .....
    bool swapped = false;
    do
    {
        // 1 pass of the bubble sort
        swapped = false;
        for(int i=0; i<4; i++)
        {
            if(R[i] > R[i+1])
            {
                int temp = R[i];
                R[i] = R[i+1];
                R[i+1] = temp;
                swapped = true;
            }
        }
    }
    while(swapped == true);







    // check the card of player: working....


    int temp_point = 0;

    // Check for straight flush
    if((R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1) && (S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4]))
    {
        cout << "WoW! You got a straight flush!" << endl;
        temp_point += 10;
    }

    // Check for 4 of a kind
    if( (R[0] == R[1] && R[1]==R[2] && R[2]==R[3]) || (R[1] == R[2] && R[2]==R[3] && R[3]==R[4]) )
    {
        cout << "You got 4 of a kind!" << endl;
        temp_point += 9;
    }

    // Check for full house
    if ( (R[0] == R[1] && R[1]==R[2] && R[3]==R[4]) || (R[0] == R[1] && R[2]==R[3] && R[3]==R[4]))
    {
        cout << "You got a Full House" << endl;
        temp_point += 8;
    }

    // Check for a flush (all the same suit)
    if(S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4])
    {
        cout << "You got a flush!" << endl;
        temp_point += 7;
    }

    // Check for a straight:
    if(R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1)
    {
        cout << "You got a straight!" << endl;
        temp_point += 6;
    }

    // Check for 3 same cards (sundenly forgot name):
    if((R[0] == R[1] && R[1]==R[2]) || (R[1]==R[2] && R[2]==R[3]) || (R[2] == R[3] && R[3] && R[4]))
    {
        cout << "You got a ________!" << endl;
        temp_point += 5;
    }
    
    // Check pair
    if(R[0] == R[1] || R[1]==R[2] || R[2]==R[3] || R[3]==R[4])
    {
        cout << "You got a pair!" << endl;
        temp_point += 4;
    }
    

    
    









    return 0;
}