// CSC275 Final- Auto Battler.cpp : This game showcases the things we learned this semester

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>
#pragma comment(lib, "winmm.lib")
#include "Functions.cpp"

using namespace std;

int main()
{
    char playerAnswer;
    Game game1;
    Player player1;
    srand(time(NULL));

    thread t1(playMusic);  // Thread, baby

    do  // This loop acts as the main menu
    {
        int loop = 0;
        bool loadSave = false;  // Used to determine if player wants to load a previous save
        string name;

        playerAnswer = game1.Introduction();

        if (playerAnswer == '1')  // New game
        {
            cout << "Austin's Auto Battler has been started.\n\n";
            this_thread::sleep_for(chrono::seconds(2));

            player1.SetName();  // Let's the player name their character
            gameplayLoop(player1, loop, loadSave);  // The whole game happens in this recursive loop
        }
        else if (playerAnswer == '2')  // Continue game
        {
            cout << "Loading Austin's Auto Battler's last save. . .\n\n";
            this_thread::sleep_for(chrono::seconds(2));

            loadSave = true;
            gameplayLoop(player1, loop, loadSave);
        }
        else if (playerAnswer == '3')  // Learn how to play
        {
            game1.HowToPlay();
        }
        else  // Quits game, playerAnswer will equal 4
        {
            cout << "Exiting game...\n";
            this_thread::sleep_for(chrono::seconds(2));

            t1.join();
            return 0;
        }
    } while (true);
    return 0;
}