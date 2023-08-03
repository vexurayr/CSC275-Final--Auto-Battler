// Source file for functions, classes, and definitions

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

using namespace std;

// Beginning of the BaseCharacter class
class BaseCharacter  // Superclass has a name, health, and damage associated with it
{
public:
    BaseCharacter(string name = "Player", int health = 10, int damage = 1) :
        m_Name(name),
        m_Health(health),
        m_Damage(damage)
    {}

    string const GetName()  // All of the gets and sets are so the protected and private data members can be accessed, read, and changed
    {
        return m_Name;
    }

    void virtual SetName(string name)  // This function demonstrates polymorphism
    {
        m_Name = name;
    }

    int const GetHealth()
    {
        return m_Health;
    }

    void SetHealth(int x)
    {
        m_Health = x;
    }

    int const GetDamage()
    {
        return m_Damage;
    }

    void SetDamage(int x)  // Level up upgrade for the player subclass
    {
        m_Damage = x;
    }

    void virtual Attack()  // This function also demonstrates polymorphism
    {
        cout << m_Name << " is attacking.\n";
    }

protected:
    string m_Name;
    int m_Health;
    int m_Damage;
};

// Beginning of the Player class
class Player : public BaseCharacter  // Inherits from BaseCharacter, adds new members max health, xp, xp gain, and level
{
public:
    Player(string name = "Player", int health = 20, int damage = 2, int maxHealth = 20, int xp = 2, int xpGain = 1, int level = 1, bool firstTime = true) :  // Default values different from BaseCharacter
        BaseCharacter(name, health, damage),
        m_MaxHealth(maxHealth),
        m_XP(xp),
        m_XPGain(xpGain),
        m_Level(level),
        m_FirstTime(firstTime)
    {}

    void SetName()
    {
        string name;
        do
        {
            cout << "State the character's name: ";

            if (m_FirstTime == true)  // This is to fix the bug I found while I recorded the game running
            {
                cin.ignore();  // Now anytime this function is called after the first in one session will not delete the first character the player inputs
                m_FirstTime = false;
            }
            getline(cin, name);  // getline will prevent cin from freaking out later if the player had a space in their name

            if (name.length() >= 10)
            {
                cout << "Please keep the name under 10 characters.\n\n";
            }

        } while (name.length() >= 10);
        
        m_Name = name;
    }

    int const GetXP()
    {
        return m_XP;
    }

    void SetXP(int x)
    {
        m_XP = x;
    }
    
    int const GetXPGain()
    {
        return m_XPGain;
    }

    void SetXPGain(int x)  // Level up upgrade
    {
        m_XPGain = x;
    }

    int const GetLevel()
    {
        return m_Level;
    }

    void SetLevel(int x)
    {
        m_Level = x;
    }

    int const GetMaxHealth()
    {
        return m_MaxHealth;
    }

    void SetMaxHealth(int x)
    {
        m_MaxHealth = x;
    }

    void IncMaxHealth(int x)  // Level up upgrade
    {
        m_MaxHealth = m_MaxHealth + x;
        m_Health = m_Health + x;
    }

    void Heal()  // Level up upgrade
    {
        m_Health = m_MaxHealth;
    }

    void Attack()
    {
        int random = rand() % 6;  // 0-5, for randomized dialogue
        if (random == 0)
        {
            cout << m_Name << " strikes swiftly and cleanly, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 1)
        {
            cout << m_Name << " notifies the enemy by email that they will die soon, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 2)
        {
            cout << m_Name << " calls upon the Gods and anime, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 3)
        {
            cout << m_Name << " gives the enemy a look of dissapointment, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 4)
        {
            cout << m_Name << " is trying their best not to roast the enemy too hard, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else
        {
            cout << m_Name << " laughs at the enemy, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
    }

private:  // The protected and private data members plus the get and set functions fulfill encapsulation and abstraction
    int m_MaxHealth;
    int m_XP;
    int m_XPGain;
    int m_Level;
    bool m_FirstTime;
};

// Beginning of the Enemy class
class Enemy : public BaseCharacter  // Inherits from BaseCharacter, adds new function that makes enemies harder the longer the game goes on
{
public:
    Enemy(const string& name = "Enemy", int health = 3, int damage = 1) :  // Default values different from BaseCharacter
        BaseCharacter(name, health, damage)
    {}

    void Attack()
    {
        int random = rand() % 6;  // 0-5, for randomized dialogue
        if (random == 0)
        {
            cout << "The enemy bites you with nasty teeth, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 1)
        {
            cout << "The enemy splashes you with their tears, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 2)
        {
            cout << "The enemy throws its weapon on the ground in a fit, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 3)
        {
            cout << "The enemy pulls out the Uno Reverse card, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (random == 4)
        {
            cout << "The enemy curses you in a foreign language, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
        else
        {
            cout << "The enemy tries to act menacing, dealing " << m_Damage << " damage!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
        }
    }

    void LoopMultiplier(int loop)  // Function that makes enemies harder linearly the more the gameplayLoop loops
    {
        double mult = (1 + (loop * .2));
        m_Health = floor(m_Health * mult);
        m_Damage = floor(m_Damage * mult);
    }
};

// Beginning of the Game class
class Game
{
public:
    char Introduction()
    {
        char playerAnswer;
        bool repeat = true;
        cout << "Welcome to Austin's Auto Battler!\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "What would you like to do?\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "1 - New Game\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "2 - Continue Game\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "3 - How to play\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "4 - Quit Game\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        do
        {
            cout << "Your input: ";
            cin >> playerAnswer;
            cout << endl;
            switch (playerAnswer)
            {
            case '1':
                repeat = false;
                break;

            case '2':
                repeat = false;
                break;

            case '3':
                repeat = false;
                break;

            case '4':
                repeat = false;
                break;

            default:
                repeat = true;
                cin.clear();
                cin.ignore(1);
                cout << "Please input 1, 2, 3, or 4.\n\n";
            }
        } while (repeat);

        return playerAnswer;
    }

    void HowToPlay()
    {
        cout << "How to play Austin's Auto Battler:\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You are battling for domination until you drop.\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Kills grant you XP, and with enough XP, you level up.\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Spend your level up point to increase your max health, your damage,\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "or spend the level on healing. Your character will do the rest.\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "But be warned, there's always another enemy.\n\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
};

class Exception  // Class purely for exception handling
{
public:
    void ReadSaveError()
    {
        cout << "Could not find a save file. Have you played a game previously?\n\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
} static exception1;

// Start of the functions section
int inline gameplayLoop(Player player1, int loop, bool loadSave)
{
    Enemy enemy1;
    ofstream writeSave;
    ifstream readSave;
    string dataPoint; // Used to read from the save file
    char delimiter = '\n'; // Used to move to the next line in the save file
    bool death = false;  // Exits a battle encounter if it's true
    bool repeat = true;  // Used for player's decision making
    char playerAnswer;  // Used to change the game based on player input
    int temp;  // Used for calculations that change class data members
    int firstAttack = rand() % 4;  // 0-3

    string playerName;
    int playerHealth;
    int playerMaxHealth;
    int playerDamage;
    int playerXP;
    int playerLevel;
    int playerXPGain;

    vector<int> randomXPUp = { 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 20 };  // Uses vectors as another means for randomness with varying odds
    vector<int> randomDamageUp = { 2, 2, 3, 3, 3, 4, 4, 10 };
    vector<int> randomMaxHealthUp = { 10, 10, 15, 15, 15, 20, 20, 25 };

    if (loadSave == true)  // Load save only happens once to continue the game where you left off
    {
        loadSave = false;
        int i = 0;

        try  // Exception handler prevents a crash if the user tries to load a save when there is none
        {
            readSave.open("SaveFile.txt");

            if (readSave.fail())
            {
                throw exception1;
            }
        }
        catch (Exception& e)
        {
            e.ReadSaveError();
            return 0;
        }

        if (readSave.is_open())  // If it exists, the information from the save is imported and the data is set to the right value
        {
            while (!readSave.eof())
            {
                for (int i = 0; i < 8; i++)  // Iterates through every line of the save file to gather every variable
                {
                    if (i == 0)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerName = dataPoint;
                        player1.BaseCharacter::SetName(playerName);  // Must use the SetName in the BaseCharacter class over the SetName in the Player class
                    }
                    else if (i == 1)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerHealth = std::stoi(dataPoint);
                        player1.SetHealth(playerHealth);
                    }
                    else if (i == 2)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerMaxHealth = std::stoi(dataPoint);
                        player1.SetMaxHealth(playerMaxHealth);
                    }
                    else if (i == 3)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerDamage = std::stoi(dataPoint);
                        player1.SetDamage(playerDamage);
                    }
                    else if (i == 4)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerXP = std::stoi(dataPoint);
                        player1.SetXP(playerXP);
                    }
                    else if (i == 5)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerXPGain = std::stoi(dataPoint);
                        player1.SetXPGain(playerXPGain);
                    }
                    else if (i == 6)
                    {
                        getline(readSave, dataPoint, delimiter);
                        playerLevel = std::stoi(dataPoint);
                        player1.SetLevel(playerLevel);
                    }
                    else
                    {
                        getline(readSave, dataPoint, delimiter);
                        loop = std::stoi(dataPoint);
                    }
                }
            }
            readSave.close();
        }
    }

    playerName = player1.GetName();  // Gathers all the data members that need to be printed and changed
    playerHealth = player1.GetHealth();  // All of the gets and sets are important to make sure the right information
    playerMaxHealth = player1.GetMaxHealth();  // is calculated, displayed, and written to the save file
    playerDamage = player1.GetDamage();
    playerXP = player1.GetXP();
    playerXPGain = player1.GetXPGain();
    playerLevel = player1.GetLevel();

    string enemyName = enemy1.GetName();
    enemy1.LoopMultiplier(loop);
    int enemyHealth = enemy1.GetHealth();
    int enemyDamage = enemy1.GetDamage();

    if (firstAttack == 0)  // 25% chance the enemy attacks first
    {
        do  // Enemy and Player fight until one dies
        {
            cout << playerName << "'s current health: " << playerHealth << "/" << playerMaxHealth << "\n";
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << playerName << "'s XP needed to level up: " << playerXP << "\n";
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << playerName << "'s current Level: " << playerLevel << "\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            cout << enemyName << "'s current health: " << enemyHealth << "\n\n";
            this_thread::sleep_for(chrono::seconds(2));

            if (firstAttack == 0)  // Warns the player the enemy got to attack first
            {
                firstAttack = 1;
                cout << "The enemy got the jump on " << playerName << "!\n";
                this_thread::sleep_for(chrono::seconds(2));
            }

            enemy1.Attack();  // The Enemy attacks
            temp = playerHealth - enemyDamage;
            player1.SetHealth(temp);
            playerHealth = player1.GetHealth();

            if (playerHealth <= 0)  // Check to see if the Player is dead
            {
                cout << playerName << " has been killed! Game over.\n";
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Total enemies beaten: " << (loop) << "\n\n";
                this_thread::sleep_for(chrono::seconds(4));
                return 0;  // If the Player dies it will exit the function
            }

            player1.Attack();  // The Player attacks
            temp = enemyHealth - playerDamage;
            enemy1.SetHealth(temp);
            enemyHealth = enemy1.GetHealth();

            if (enemyHealth <= 0)  // Check to see if the Enemy is dead
            {
                cout << "The enemy has been slain.\n";
                this_thread::sleep_for(chrono::seconds(2));
                death = true;
            }
        } while (!death);
    }
    else  // The Player attacks first
    {
        do  // The Player and the Enemy fight until one dies
        {
            cout << playerName << "'s current health: " << playerHealth << "/" << playerMaxHealth << "\n";
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << playerName << "'s XP needed to level up: " << playerXP << "\n";
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << playerName << "'s current Level: " << playerLevel << "\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            cout << enemyName << "'s current health: " << enemyHealth << "\n\n";
            this_thread::sleep_for(chrono::seconds(2));

            if (firstAttack != 0)  // Tells the player they are attacking first
            {
                firstAttack = 0;
                cout << playerName << " throws hands first!\n";
                this_thread::sleep_for(chrono::seconds(2));
            }

            player1.Attack();  // The Player attacks
            temp = enemyHealth - playerDamage;
            enemy1.SetHealth(temp);
            enemyHealth = enemy1.GetHealth();

            if (enemyHealth <= 0)  // Check to see if the Enemy is dead
            {
                cout << "The enemy has been slain.\n";
                this_thread::sleep_for(chrono::seconds(2));
                death = true;
            }

            if (!death)  // If the Enemy is not dead, they get to attack
            {
                enemy1.Attack();  // Enemy attacks
                temp = playerHealth - enemyDamage;
                player1.SetHealth(temp);
                playerHealth = player1.GetHealth();
            }

            if (playerHealth <= 0)  // Check if the Player is dead
            {
                cout << playerName << " has been killed! Game over.\n";
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Total enemies beaten: " << (loop) << "\n\n";
                this_thread::sleep_for(chrono::seconds(4));
                return 0;  // If the Player dies it will exit the function
            }
        } while (!death);
    }

    cout << "Gained: " << playerXPGain << " XP.\n\n";  // The player's XP is being decreased to tell the player how much more XP they need rather than how much XP they have
    this_thread::sleep_for(chrono::seconds(2));
    playerXP = (playerXP - playerXPGain);
    player1.SetXP(playerXP);
    playerXP = player1.GetXP();

    if (playerXP <= 0)  // The player has gotten enough XP to level up
    {
        cout << "You have leveled up!\n";  // Increase the player's level
        this_thread::sleep_for(chrono::seconds(2));
        ++playerLevel;
        player1.SetLevel(playerLevel);
        playerLevel = player1.GetLevel();

        playerXP = (playerLevel + 1);  // Requirements to level up increases with each level up
        player1.SetXP(playerXP);
        playerXP = player1.GetXP();

        cout << "What would you like to spend your level up on?\n";  // Spending the level up on a stat increase
        this_thread::sleep_for(chrono::seconds(2));
        cout << "1 - +Random Damage\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "2 - +Random Max Health\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "3 - +Random XP Gain\n";
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "4 - Full Heal\n";
        this_thread::sleep_for(chrono::milliseconds(800));

        do
        {
            cout << "Your input: ";
            cin >> playerAnswer;
            cout << endl;
            switch (playerAnswer)
            {
            case '1':  // Increases the player's damage by a random amount, most likely to go up by 3 but could go up by 10
                repeat = false;
                random_shuffle(randomDamageUp.begin(), randomDamageUp.end());

                playerDamage = (playerDamage + randomDamageUp.front());
                player1.SetDamage(playerDamage);
                playerDamage = player1.GetDamage();

                cout << playerName << " now deals " << randomDamageUp.front() << " more damage!\n\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            case '2':  // Increases the player's health and max health by a random amount, most likely to go up by 15, but could go up by 25
                repeat = false;
                random_shuffle(randomMaxHealthUp.begin(), randomMaxHealthUp.end());

                player1.IncMaxHealth(randomMaxHealthUp.front());
                playerHealth = player1.GetHealth();
                playerMaxHealth = player1.GetMaxHealth();

                cout << playerName << " now has " << randomMaxHealthUp.front() << " more max health!\n\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            case '3':  // Increases the XP the player gains from killing an enemy by a random amount, most likely to go up by 4, but could go up by 20
                repeat = false;
                random_shuffle(randomXPUp.begin(), randomXPUp.end());

                playerXPGain = (playerXPGain + randomXPUp.front());
                player1.SetXPGain(playerXPGain);
                playerXPGain = player1.GetXPGain();

                cout << playerName << " now gains " << randomXPUp.front() << " more XP from killing an enemy!\n\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            case '4':  // Matches the player's health to their max health
                repeat = false;
                
                player1.Heal();
                playerHealth = player1.GetHealth();

                cout << playerName << " has been fully healed!\n\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            default:
                repeat = true;
                cin.clear();
                cin.ignore(1);
                cout << "Please input 1, 2, 3, or 4.\n\n";
            }
        } while (repeat);
    }

    ++loop;

    cout << "What would you like to do next?\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "1 - Fight Onwards\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "2 - Save And Fight\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "3 - Save And Quit\n";
    this_thread::sleep_for(chrono::milliseconds(800));

    do
    {
        cout << "Your input: ";
        cin >> playerAnswer;
        cout << endl;
        switch (playerAnswer)
        {
        case '1':
            repeat = false;
            cout << playerName << " fights on fearlessly!\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
            
        case '2':
            repeat = false;
            cout << "Austin's Auto Battler is saving. . .\n";
            this_thread::sleep_for(chrono::seconds(2));

            writeSave.open("SaveFile.txt");
            writeSave << playerName << delimiter;
            writeSave << playerHealth << " = Player Heath" << delimiter;
            writeSave << playerMaxHealth << " = Player Max Health" << delimiter;
            writeSave << playerDamage << " = Player Damage" << delimiter;
            writeSave << playerXP << " = Player XP Until Level Up" << delimiter;
            writeSave << playerXPGain << " = XP gained from killing an enemy" << delimiter;
            writeSave << playerLevel << " = Player Level" << delimiter;
            writeSave << loop << " = loop#";
            writeSave.close();

            cout << playerName << " is ready for another round!\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case '3':
            repeat = false;
            cout << "Austin's Auto Battler is saving. . .\n";
            this_thread::sleep_for(chrono::seconds(2));

            writeSave.open("SaveFile.txt");
            writeSave << playerName << delimiter;
            writeSave << playerHealth << " = Player Heath" << delimiter;
            writeSave << playerMaxHealth << " = Player Max Health" << delimiter;
            writeSave << playerDamage << " = Player Damage" << delimiter;
            writeSave << playerXP << " = Player XP Until Level Up" << delimiter;
            writeSave << playerXPGain << " = XP gained from killing an enemy" << delimiter;
            writeSave << playerLevel << " = Player Level" << delimiter;
            writeSave << loop << " = loop#";
            writeSave.close();

            cout << "Exiting to main menu.\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            return 0;
            break;

        default:
            repeat = true;
            cin.clear();
            cin.ignore(1);
            cout << "Please input 1, 2, or 3.\n\n";
        }
    } while (repeat);
    
    return gameplayLoop(player1, loop, loadSave);
}

// Function that plays music from a thread while the program runs
void inline playMusic()  // Well, it turns out a thread isn't actually needed but I spent too much time on this to not complete the objective
{
    bool played = PlaySound(TEXT("CSC275 Final.wav"), NULL, SND_LOOP | SND_ASYNC);
}