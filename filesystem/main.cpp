#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct PlayerStat
{
    string name;
    string hp;
    string def;
    // string dice;
};

bool
loadFile(const string &file, PlayerStat &player)
{
    string temp;
    ifstream MyReadFile(file);

    if (!MyReadFile.is_open())
    {
        cout << "Error, file not found." << file << endl;
        return false;
    };

    if (!(MyReadFile >> temp) || temp != "Player:{")
    {
        cerr << "Error: File format error - Expected 'Player:{'" << endl;
        return false;
    }

    if (!player.name.empty() && player.name.back() == ',')
    {
        player.name.pop_back();
    }
    

    if (!(MyReadFile >> temp >> player.name))
    {
        cerr << "Error: File format error - Could not read 'name'" << endl;
        return false;
    }

    if (!(MyReadFile >> temp >> temp >> player.hp))
    {
        cerr << "Error: File format error - Could not read 'hp'" << endl;
        return false;
    }

    if (!(MyReadFile >> temp >> temp >> player.def))
    {
        cerr << "Error: File format error - Could not read 'def'" << endl;
        return false;
    }

    // if (!(MyReadFile >> temp >> temp >> player.dice))
    // {
    //     cerr << "Error: File format error - Could not read 'dice'" << endl;
    //     return false;
    // }

    if (!(MyReadFile >> temp) || temp != "};")
    {
        cerr << "Error: File format error - Expected '};'" << endl;
        return false;
    }

    MyReadFile.close();
    return true;
}



int main()
{
    PlayerStat myPlayer;

    if (loadFile("data.txt", myPlayer))
    {
        cout << "\n✅ Data loaded successfully!" << endl;
        cout << "--- Player Stats ---" << endl;
        cout << "Name: " << myPlayer.name << endl;
        cout << "HP:   " << myPlayer.hp << endl;
        cout << "DEF:  " << myPlayer.def << endl;
        // cout << "Dice: " << myPlayer.dice << endl;
        cout << "--------------------" << endl;
    }
    else
    {
        cout << "\n❌ Failed to load data." << endl;
    };
    return 0;
}