#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void title() {
    cout << R"(
   _____      _                ____                      _
  / ____|    | |              |  _ \                    | |
 | |    _   _| |__   ___ _ __ | |_) |_ __ ___  __ _  ___| |__
 | |   | | | | '_ \ / _ \ '__||  _ <| '__/ _ \/ _` |/ __| '_ \
 | |___| |_| | |_) |  __/ |   | |_) | | |  __/ (_| | (__| | | |
  \_____\__, |_.__/ \___|_|   |____/|_|  \___|\__,_|\___|_| |_|
         __/ |
        |___/

)";
    cout << "              [ CYBER BREACH // TERMINAL GAME ]\n";
    cout << "========================================================\n\n";
}

struct Player {
    string name;
    int level = 1;
    int xp = 0;
    int xpNeeded = 100;
    int hp = 100;
    int maxHp = 100;
    int attack = 15;
    int money = 50;
    int firewall = 0;
};

struct Enemy {
    string name;
    int hp;
    int attack;
    int rewardXp;
    int rewardMoney;
};

void showStats(const Player& player) {
    cout << "\n=========== YOUR PROFILE ===========\n";
    cout << " Hacker       : " << player.name << endl;
    cout << " Level        : " << player.level << endl;
    cout << " XP           : " << player.xp << "/" << player.xpNeeded << endl;
    cout << " HP           : " << player.hp << "/" << player.maxHp << endl;
    cout << " Attack Power : " << player.attack << endl;
    cout << " Firewall     : " << player.firewall << endl;
    cout << " CryptoCoins  : " << player.money << endl;
    cout << "====================================\n";
}

void levelUp(Player& player) {
    while (player.xp >= player.xpNeeded) {
        player.xp -= player.xpNeeded;
        player.level++;
        player.xpNeeded += 50;

        player.maxHp += 20;
        player.hp = player.maxHp;
        player.attack += 5;

        cout << "\n==================================\n";
        cout << "          !!! LEVEL UP !!!\n";
        cout << "      You are now level " << player.level << "!\n";
        cout << "==================================\n";

        cout << "+20 Max HP\n";
        cout << "+5 Attack Power\n";
        cout << "HP fully restored\n";
    }
}

Enemy generateEnemy(int level) {
    int type = rand() % 5;

    Enemy enemy;

    switch (type) {
        case 0:
            enemy.name = "Basic Firewall";
            break;
        case 1:
            enemy.name = "Sentinel Antivirus";
            break;
        case 2:
            enemy.name = "IDS System";
            break;
        case 3:
            enemy.name = "Security Agent";
            break;
        default:
            enemy.name = "AI Defender";
            break;
    }

    enemy.hp = 40 + (level * 25) + (rand() % 20);
    enemy.attack = 8 + (level * 4) + (rand() % 8);
    enemy.rewardXp = 30 + (level * 15);
    enemy.rewardMoney = 15 + (level * 10);

    return enemy;
}

void fight(Player& player) {
    clearScreen();
    title();

    Enemy enemy = generateEnemy(player.level);

    cout << "WARNING: Security system detected!\n\n";
    cout << "Target          : " << enemy.name << endl;
    cout << "System Integrity: " << enemy.hp << endl;
    cout << "Defense Power   : " << enemy.attack << endl;

    waitForEnter();

    while (player.hp > 0 && enemy.hp > 0) {
        clearScreen();
        title();

        cout << "=========== BATTLE ===========\n\n";

        cout << player.name << " HP: " << player.hp
             << "/" << player.maxHp << endl;

        cout << enemy.name << " HP: " << enemy.hp << endl;

        cout << "\n1. SQL Injection\n";
        cout << "2. DDoS Attack\n";
        cout << "3. Zero-Day Exploit\n";
        cout << "4. Escape\n";

        cout << "\nCommand > ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int damage = player.attack + rand() % 10;

            cout << "\nInjection successful! -" << damage
                 << " system integrity\n";

            enemy.hp -= damage;
        }
        else if (choice == 2) {
            int damage = player.attack + 10 + rand() % 15;

            cout << "\nDDoS attack launched! -" << damage
                 << " system integrity\n";

            enemy.hp -= damage;
        }
        else if (choice == 3) {
            int chance = rand() % 100;

            if (chance < 40) {
                int damage = player.attack * 3;

                cout << "\n!!! ZERO-DAY FOUND !!!\n";
                cout << "CRITICAL HIT! -" << damage
                     << " system integrity\n";

                enemy.hp -= damage;
            } else {
                cout << "\nThe exploit was blocked by the system...\n";
            }
        }
        else if (choice == 4) {
            int chance = rand() % 100;

            if (chance < 50) {
                cout << "\nYou successfully disappeared from the network!\n";
                waitForEnter();
                return;
            } else {
                cout << "\nEscape failed! Your IP has been traced!\n";
            }
        }
        else {
            cout << "\nInvalid command!\n";
            waitForEnter();
            continue;
        }

        if (enemy.hp <= 0) {
            break;
        }

        waitForEnter();

        int realDamage = enemy.attack - player.firewall;

        if (realDamage < 1) {
            realDamage = 1;
        }

        if (rand() % 100 < 20) {
            realDamage += 10;
            cout << "\n!!! CRITICAL COUNTERATTACK !!!\n";
        }

        cout << enemy.name << " attacks your system!\n";
        cout << "You lose " << realDamage << " HP.\n";

        player.hp -= realDamage;

        if (player.hp < 0) {
            player.hp = 0;
        }

        waitForEnter();
    }

    if (player.hp <= 0) {
        clearScreen();
        title();

        cout << "\n====================================\n";
        cout << "           SYSTEM FAILURE\n";
        cout << "====================================\n";

        cout << "\nYour system has been compromised...\n";
        cout << "Your data has been encrypted.\n";
        cout << "Connection lost.\n";

        player.hp = player.maxHp;
        player.money /= 2;

        cout << "\nYou lost half of your CryptoCoins.\n";
    }
    else {
        cout << "\n====================================\n";
        cout << "         SYSTEM COMPROMISED!\n";
        cout << "====================================\n";

        cout << "\n+" << enemy.rewardXp << " XP\n";
        cout << "+" << enemy.rewardMoney << " CryptoCoins\n";

        player.xp += enemy.rewardXp;
        player.money += enemy.rewardMoney;

        levelUp(player);
    }

    waitForEnter();
}

void shop(Player& player) {
    int choice;

    do {
        clearScreen();
        title();

        cout << "=========== DARK WEB SHOP ===========\n";
        cout << "Available CryptoCoins: " << player.money << "\n\n";

        cout << "1. Restore 30 HP        [20 coins]\n";
        cout << "2. +5 Attack Power      [60 coins]\n";
        cout << "3. +2 Firewall          [50 coins]\n";
        cout << "4. Return\n";

        cout << "\nChoice > ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (player.money >= 20) {
                    player.money -= 20;
                    player.hp += 30;

                    if (player.hp > player.maxHp) {
                        player.hp = player.maxHp;
                    }

                    cout << "\nSystem repaired successfully!\n";
                } else {
                    cout << "\nNot enough CryptoCoins.\n";
                }

                waitForEnter();
                break;

            case 2:
                if (player.money >= 60) {
                    player.money -= 60;
                    player.attack += 5;

                    cout << "\nAttack power upgraded!\n";
                } else {
                    cout << "\nNot enough CryptoCoins.\n";
                }

                waitForEnter();
                break;

            case 3:
                if (player.money >= 50) {
                    player.money -= 50;
                    player.firewall += 2;

                    cout << "\nFirewall upgraded!\n";
                } else {
                    cout << "\nNot enough CryptoCoins.\n";
                }

                waitForEnter();
                break;

            case 4:
                break;

            default:
                cout << "\nInvalid choice.\n";
                waitForEnter();
        }

    } while (choice != 4);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Player player;

    clearScreen();
    title();

    cout << "Initializing terminal...\n";
    cout << "Connecting to the network...\n";
    cout << "Secure connection established.\n\n";

    cout << "Enter your hacker alias: ";
    getline(cin, player.name);

    if (player.name.empty()) {
        player.name = "SyntaxCrash";
    }

    int choice;

    do {
        clearScreen();
        title();

        cout << "Welcome, " << player.name << ".\n";
        cout << "Status: CONNECTED\n";

        cout << "\n=========== MENU ===========\n";
        cout << "1. Launch an attack\n";
        cout << "2. View profile\n";
        cout << "3. Dark Web Shop\n";
        cout << "4. Quit\n";

        cout << "\nroot@" << player.name << ":~$ ";

        cin >> choice;

        switch (choice) {
            case 1:
                fight(player);
                break;

            case 2:
                clearScreen();
                title();
                showStats(player);
                waitForEnter();
                break;

            case 3:
                shop(player);
                break;

            case 4:
                clearScreen();
                title();
                cout << "Disconnecting...\n";
                cout << "Clearing terminal logs...\n";
                cout << "Goodbye, " << player.name << ".\n";
                break;

            default:
                cout << "\nUnknown command.\n";
                waitForEnter();
        }

    } while (choice != 4);

    return 0;
}
