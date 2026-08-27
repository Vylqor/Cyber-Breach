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
    cout << "\nAppuie sur ENTREE pour continuer...";
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
    cout << "\n=========== TON PROFIL ===========\n";
    cout << " Hacker      : " << player.name << endl;
    cout << " Niveau      : " << player.level << endl;
    cout << " XP          : " << player.xp << "/" << player.xpNeeded << endl;
    cout << " HP          : " << player.hp << "/" << player.maxHp << endl;
    cout << " Puissance   : " << player.attack << endl;
    cout << " Firewall    : " << player.firewall << endl;
    cout << " CryptoCoins : " << player.money << endl;
    cout << "==================================\n";
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
        cout << "      Tu es maintenant niveau " << player.level << " !\n";
        cout << "==================================\n";

        cout << "+20 HP max\n";
        cout << "+5 puissance\n";
        cout << "HP entierement restaure\n";
    }
}

Enemy generateEnemy(int level) {
    int type = rand() % 5;

    Enemy enemy;

    switch (type) {
        case 0:
            enemy.name = "Firewall basique";
            break;
        case 1:
            enemy.name = "Antivirus Sentinel";
            break;
        case 2:
            enemy.name = "Systeme IDS";
            break;
        case 3:
            enemy.name = "Agent de securite";
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

    cout << "ALERTE : Systeme detecte !\n\n";
    cout << "Cible : " << enemy.name << endl;
    cout << "Integrite systeme : " << enemy.hp << endl;
    cout << "Puissance defensive : " << enemy.attack << endl;

    waitForEnter();

    while (player.hp > 0 && enemy.hp > 0) {
        clearScreen();
        title();

        cout << "=== COMBAT ===\n\n";

        cout << player.name << " HP: " << player.hp << "/" << player.maxHp << endl;
        cout << enemy.name << " HP: " << enemy.hp << endl;

        cout << "\n1. Attaque SQL Injection\n";
        cout << "2. DDoS\n";
        cout << "3. Exploit zero-day\n";
        cout << "4. Fuir\n";

        cout << "\nCommande > ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int damage = player.attack + rand() % 10;
            cout << "\nInjection reussie ! -" << damage << " HP\n";
            enemy.hp -= damage;
        }
        else if (choice == 2) {
            int damage = player.attack + 10 + rand() % 15;
            cout << "\nDDoS lance ! -" << damage << " HP\n";
            enemy.hp -= damage;
        }
        else if (choice == 3) {
            int chance = rand() % 100;

            if (chance < 40) {
                int damage = player.attack * 3;
                cout << "\n!!! ZERO-DAY TROUVE !!!\n";
                cout << "CRITICAL HIT ! -" << damage << " HP\n";
                enemy.hp -= damage;
            } else {
                cout << "\nExploit bloque par le systeme...\n";
            }
        }
        else if (choice == 4) {
            int chance = rand() % 100;

            if (chance < 50) {
                cout << "\nTu as reussi a disparaitre du reseau !\n";
                waitForEnter();
                return;
            } else {
                cout << "\nImpossible de fuir ! Ton IP est tracee !\n";
            }
        }
        else {
            cout << "\nCommande invalide !\n";
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
            cout << "\n!!! CONTRE-ATTAQUE CRITIQUE !!!\n";
        }

        cout << enemy.name << " attaque ton systeme !\n";
        cout << "Tu perds " << realDamage << " HP.\n";

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
        cout << "\nTon systeme a ete compromis...\n";
        cout << "Tes donnees ont ete chiffrees.\n";
        cout << "Connexion perdue.\n";

        player.hp = player.maxHp;
        player.money /= 2;

        cout << "\nTu as perdu la moitie de tes CryptoCoins.\n";
    }
    else {
        cout << "\n====================================\n";
        cout << "         SYSTEME COMPROMIS !\n";
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
        cout << "CryptoCoins disponibles : " << player.money << "\n\n";

        cout << "1. Restaurer 30 HP        [20 coins]\n";
        cout << "2. +5 Puissance           [60 coins]\n";
        cout << "3. +2 Firewall            [50 coins]\n";
        cout << "4. Retour\n";

        cout << "\nChoix > ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (player.money >= 20) {
                    player.money -= 20;
                    player.hp += 30;

                    if (player.hp > player.maxHp) {
                        player.hp = player.maxHp;
                    }

                    cout << "\nSysteme repare !\n";
                } else {
                    cout << "\nPas assez de CryptoCoins.\n";
                }
                waitForEnter();
                break;

            case 2:
                if (player.money >= 60) {
                    player.money -= 60;
                    player.attack += 5;

                    cout << "\nPuissance augmentee !\n";
                } else {
                    cout << "\nPas assez de CryptoCoins.\n";
                }
                waitForEnter();
                break;

            case 3:
                if (player.money >= 50) {
                    player.money -= 50;
                    player.firewall += 2;

                    cout << "\nFirewall ameliore !\n";
                } else {
                    cout << "\nPas assez de CryptoCoins.\n";
                }
                waitForEnter();
                break;

            case 4:
                break;

            default:
                cout << "\nChoix invalide.\n";
                waitForEnter();
        }

    } while (choice != 4);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Player player;

    clearScreen();
    title();

    cout << "Initialisation du terminal...\n";
    cout << "Connexion au reseau Tor...\n";
    cout << "VPN actif...\n";
    cout << "Proxy chain active...\n\n";

    cout << "Entre ton pseudo de hacker : ";
    getline(cin, player.name);

    if (player.name.empty()) {
        player.name = "SyntaxCrash";
    }

    int choice;

    do {
        clearScreen();
        title();

        cout << "Bienvenue, " << player.name << ".\n";
        cout << "Statut : CONNECTED\n";

        cout << "\n=========== MENU ===========\n";
        cout << "1. Lancer une attaque\n";
        cout << "2. Voir mon profil\n";
        cout << "3. Dark Web Shop\n";
        cout << "4. Quitter\n";

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
                cout << "Deconnexion en cours...\n";
                cout << "Effacement des logs...\n";
                cout << "Goodbye, " << player.name << ".\n";
                break;

            default:
                cout << "\nCommande inconnue.\n";
                waitForEnter();
        }

    } while (choice != 4);

    return 0;
}
