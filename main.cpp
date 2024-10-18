#include <algorithm>
#include <format>
#include <iostream>
#include <string>
using namespace std;


void write_tictactoe(string values[3][3]);

bool validate_tictactoe_complete(string values[3][3]);

void insert_value(string values[3][3]);

int main() {
    cout << "Hello, World!" << endl;
    string values[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };

    int x, y = 0;
    for (int i = 0; i < 10; i++) {
        write_tictactoe(values);

        if (validate_tictactoe_complete(values)) {
            break;
        }

        cout << "Please select the column: " << endl;
        cin >> x;
        cout << "Please select the row: " << endl;
        cin >> y;
        cout << "Please, enter the value: " << endl;
        if (values[x][y] == " ") {
            cin >> values[x][y];
        } else {
            cout << "This position is already taken, please try again" << endl;
        }

        cout << validate_tictactoe_complete(values) << endl;
    }

    return 0;
}

void insert_value(string values[3][3]) {
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
    cout << "--------------< " << endl;
    return false;
}
