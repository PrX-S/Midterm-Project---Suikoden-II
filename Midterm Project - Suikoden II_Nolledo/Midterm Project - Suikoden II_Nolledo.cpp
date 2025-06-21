// Midterm Project - Suikoden II_Nolledo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    // Seed
    srand((time)(0));

    // Declaring variables
    string name = "";
    int userHP = 0;
    int userBaseDmg = 0;
    int userMaxDmg = 0;
    int aiHP = 0;
    int aiBaseDmg = 0;
    int aiMaxDmg = 0;
    int turn = 1;
    char move = '.';
    int userRolledDmg = 0;
    int aiRolledDmg;

    cout << "| Midterm Project - Suikoden II |\n" << "The Fight Against Warrior Han\n";
    cout << "Input the name of you character: ";
    cin >> name;

    // Hero's stats

    cout << "Input " << name << "'s health: ";
    cin >> userHP;
    cout << "\n";
    cout << "Input " << name << "'s minimum damage: ";
    cin >> userBaseDmg;
    cout << "\n";
    cout << "Input " << name << "'s maximum damage: ";
    cin >> userMaxDmg;
    cout << "\n\n";

    // Han's stats

    cout << "Input Warrior Han's health: ";
    cin >> aiHP;
    cout << "\n";
    cout << "Input Warrior Han's minimum damage: ";
    cin >> aiBaseDmg;
    cout << "\n";
    cout << "Input Warrior Han's maximum damage: ";
    cin >> aiMaxDmg;
    cout << "\n";

    cout << "Are you ready?\n";
    system("pause");

    cout << "Start!\n";
    while (aiHP > 0 && userHP > 0)
    {
        cout << "=========================================\n";
        cout << "Turn " << turn << "\n";
        cout << "\n";
        cout << name << "'s health: " << userHP << "\n";
        cout << "Han's health: " << aiHP << '\n';
        cout << "\n";
        cout << "Input your action:\n";
        cout << "-------------------\n";
        cout << "          [a] = Attack";
        cout << "          [d] = Defend";
        cout << "          [w] = Wild Attack\n";
        cin >> move;

        // compute damage rolls
        int userRolledDmg = rand() % (userMaxDmg - userBaseDmg + 1) + userBaseDmg;
        int aiRolledDmg = rand() % (aiMaxDmg - aiBaseDmg + 1) + aiBaseDmg;

        // AI MOVE: 1 = a | 2 = d | 3 = w
        int aiMove = rand() % 3 + 1;
        
        cout << "\n";

        // All Possible Matchup Outcomes
        switch (move)
        {
        case 'a':
            cout << name << " Attacks!\n";
            if (aiMove == 1)
            {
                cout << "Warrior Han Attacks!\n";
                cout << name << " takes -" << aiRolledDmg << " damage!\n";
                cout << "Warrior Han takes -" << userRolledDmg << " damage!\n";
                userHP -= aiRolledDmg;
                aiHP -= userRolledDmg;
                cout << "\n";
            }
            if (aiMove == 2)
            {
                cout << "Warrior Han readies his shield!\n";
                cout << "Warrior Han takes -" << (userRolledDmg / 2) << " damage!\n";
                aiHP -= (userRolledDmg / 2);
            }
            if (aiMove == 3)
            {
                cout << "Warrior Han charges in with a Wild Attack!\n";
                cout << name << " takes -" << (aiRolledDmg * 2) << " damage!\n";
                cout << "Warrior Han takes -" << userRolledDmg << " damage!\n";
                userHP -= (aiRolledDmg * 2);
                aiHP -= (userRolledDmg);
            }
            break;

        case 'd':
            cout << name << " Defends!\n";
            if (aiMove == 1)
            {
                cout << "Warrior Han Attacks!\n";
                cout << name << " takes -" << (aiRolledDmg / 2) << " damage!\n";
                userHP -= (aiRolledDmg / 2);
            }
            if (aiMove == 2)
            {
                cout << "Warrior Han readies his shield!\n";
                cout << "You both defended, nothing happened\n";
            }
            if (aiMove == 3)
            {
                cout << "Warrior Han charges in with a Wild Attack!\n";
                cout << "Warrior Han misses and " << name << " lauches a counter attack!\n";
                cout << "Warrior Han takes -" << (userRolledDmg * 2) << " damage!\n";
                aiHP -= (userRolledDmg * 2);
            }
            break;

        case 'w':
            cout << name << " performs a Wild Attack!\n";
            if (aiMove == 1)
            {
                cout << "Warrior Han Attacks!\n";
                cout << name << " takes -" << aiRolledDmg << " damage!\n";
                cout << "Warrior Han takes -" << (userRolledDmg * 2) << " damage!\n";
                userHP -= aiRolledDmg;
                userHP -= aiRolledDmg;
                aiHP -= (userRolledDmg * 2);

            }
            if (aiMove == 2)
            {
                cout << "Warrior Han readies his shield!\n";
                cout << name << " misses and Warrior Han launches a counter attack!\n";
                cout << name << " takes -" << (aiRolledDmg * 2) << " damage!\n";
                userHP -= (aiRolledDmg * 2);
            }
            if (aiMove == 3)
            {
                cout << "Warrior Han charges in with a Wild Attack!\n";
                cout << name << " takes -" << (aiRolledDmg * 2) << " damage!\n";
                cout << "Warrior Han takes -" << (userRolledDmg * 2) << " damage!\n";
                userHP -= aiRolledDmg;
                aiHP -= (userRolledDmg * 2);
                userHP -= (aiRolledDmg * 2);
            }
            break;
        }
        turn += 1;
    }
    // Endings
    cout << "\n";
    if (userHP > 0)
    {
        cout << "Warrior Han has fallen...\n" << "\nYOU WIN!!!\n";
    }
    else if (aiHP > 0)
    {
        cout << name << " has fallen\n" << "\nGAME OVER\n";
    }
    else
    {
        cout << "Who could have seen this coming?!?\n" << "A double knockout!\n" << "\nTIE\n";
    }
    system("pause");
    return(0);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
