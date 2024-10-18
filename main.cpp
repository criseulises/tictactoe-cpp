#include <format>
#include <iostream>
#include <string>
using namespace std;

void write_tictactoe(string values[3][3]) {
    const string tictactoe =
            format(" {} | {} | {} \n", values[0][0], values[1][1], values[2][2]) +
            format("----------- \n") +
            format(" {} | {} | {} \n", values[0][0], values[1][1], values[2][2]) +
            format("----------- \n") +
            format(" {} | {} | {} \n", values[0][0], values[1][1], values[2][2]);

    cout << tictactoe << endl;
}

bool validate_tictactoe_complete(string values[][]) {

    return true;
}

int main() {
    cout << "Hello, World!" << endl;
    string values[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
    cout << values[0] << endl;
    write_tictactoe(values);

    int x, y = 0;
    while (true) {
        cin >> x;
        cin >> y;
        cin >> values[x][y];

        write_tictactoe(values);
        if(validate_tictactoe_complete(values)) {
            break;
        }
    }
    return 0;
}
