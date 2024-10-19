#include <algorithm>
#include <format>
#include <iostream>
#include <string>
using namespace std;

void write_tictactoe(string values[3][3]);

bool validate_tictactoe_complete(string values[3][3]);

void insert_value(string values[3][3]);

int main() {
    string values[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
    int counter = 0;
    string turn = "1 (x): ";
    for (int i = 0; i < 9; i++) {
        string value;
        string player;
        write_tictactoe(values);
        player.append("Player ").append(turn);

        if (validate_tictactoe_complete(values)) {
            const string winner = value == "o" ? "2nd Player" : "1st Player";
            system("Color 02");
            cout << "The " << winner << " is the winner" << endl;
            break;
        }

        do {
            int x, y = 0;
            cout << player << endl;
            cout << "--> Please select the column:";
            cin >> x;
            cout << "--> Please select the row:";
            cin >> y;

            if (values[x][y] == " ") {
                cout << "--> Please, enter the value (x or o):";
                cin >> value;

                if ("x" != value && "o" != value) {
                    cout << "\n";
                    cout << "|--------------------------------|" << endl;
                    cout << "| Select a valid option (x or o) |" << endl;
                    cout << "|--------------------------------|" << endl;
                    continue;
                } else {
                    values[x][y] = value;
                    turn = turn == "1 (x): " ? "2 (o): " : "1 (x): ";
                    counter++;
                    break;
                }
            } else {
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  This position is already taken, please try again  |" << endl;
                cout << "|----------------------------------------------------|" << endl;
            }

            if (cin.fail()) {
                system("Color 04");
                cout << "\n\n\n\n" << "An error occurred when you enter an invalid value" << endl;
                break;
            }
        } while (true);
    }

    if (counter == 9) {
        cout << "\n\n There was a tie!";
    }
    return 0;
}

void write_tictactoe(string values[3][3]) {
    const string tictactoe =
            format("\n\n\n\n\n\n\n\n\n\n\n") +
            format(" {} | {} | {} \n", values[0][0], values[0][1], values[0][2]) +
            format("----------- \n") +
            format(" {} | {} | {} \n", values[1][0], values[1][1], values[1][2]) +
            format("----------- \n") +
            format(" {} | {} | {} \n", values[2][0], values[2][1], values[2][2]);
    cout << tictactoe << endl;
}

bool validate_tictactoe_complete(string values[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (values[i][0] + values[i][1] == values[i][1] + values[i][2]) return values[i][0] != " ";

        if (values[0][i] + values[1][i] == values[1][i] + values[2][i]) return values[0][i] != " ";
        if (values[0][0] + values[1][1] == values[1][1] + values[2][2] ||
            values[0][2] + values[1][1] == values[1][1] + values[2][0]) {
            return values[1][1] != " ";
        }
    }
    return false;
}
