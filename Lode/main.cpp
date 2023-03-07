#include <iostream>
using namespace std;

int main() {

    int hits = 0;
    int turns = 0;
    string result = "Victory";

    int row;
    int colum;
    //skryta lod -2 skryte nic -1
    //odkryta lod 2 odkryte nic 1

    int ships[4][4] = {
      { -1, -2, -2, -1},
      { -1, -1, -1, -1},
      { -1, -1, -2, -1},
      { -1, -1, -2, -1},
    };

    while (hits < 4)
    {
        turns++;

        if (turns >= 10) {
            result = "Defeat";
            break;
        }

        cout << "-------- Turn number " << turns <<" --------" << endl << endl;

        cout << "\t    Map:" << endl <<endl;
        for (int i = 0; i < 4; i++)
        {
            cout <<"\t   ";
            for (int j = 0; j < 4; j++)
            {
                switch (ships[i][j])
                {
                case 1:cout << "0 ";
                    break;

                case 2:cout << "X ";
                    break;

                default:
                    cout << "? ";
                    break;
                }
            }
            cout << endl;
        }

 
        cout << "\nSelect row betwen 1 and 4" << endl;
        cin >> row;
        cout << "You have picked up row " << row <<endl;

        cout << "\nSelect colum betwen 1 and 4" << endl;
        cin >> colum;
        cout << "You have picked up colum " << colum << endl;


        row--;
        colum--;
        if (ships[row][colum] == -2)
        {
            ships[row][colum] = 2;
            cout << "\nHit!\n";
            hits++;
            cout << 4-hits<< " ships and " << 10 - turns << " turns remaining\n\n\n";
        }
        else if (ships[row][colum] == -1)
        {
            ships[row][colum] = 1;
            cout << "\nMiss :(\n\n\n";
            cout << 4 - hits << " ships and " << 10 - turns << " turns remaining\n\n\n";
        }
        else
        {
            cout << endl << "Are you stupid???" <<endl;
            cout << 4 - hits << " ships and " << 10 - turns << " turns remaining\n\n\n";
        }

    }
    cout << "\n \n--------" << result << "--------\n\tin " << turns << " turns\n\n";

}