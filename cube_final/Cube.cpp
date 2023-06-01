#include "cube.h"

Cube::Cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = i;
            }
        }
    }
}

uint8_t Cube::inputToInt(char x) {
    switch(x) {
        case 'Y': return 0;
        case 'W': return 1;
        case 'G': return 2;
        case 'R': return 3;
        case 'B': return 4;
        case 'O': return 5;
    }
}

char Cube::outputToChar(int x) {
    switch(x) {
        case 0: return 'Y';
        case 1: return 'W';
        case 2: return 'G';
        case 3: return 'R';
        case 4: return 'B';
        case 5: return 'O';
    }
}

std::string Cube::printColor(int x) {
    switch(x) {
        case 0: return "Yellow face";
        case 1: return "White face";
        case 2: return "Green face";
        case 3: return "Red face";
        case 4: return "Back face";
        case 5: return "Orange face";
    }
}

void Cube::Shuffle() {
    history.clear();
    for (int i = 0; i < 101; i++) {
        int random_value = abs(rand() % 18);
        Rotate(static_cast<COMMANDS>(random_value));
    }
    history.clear();
}

void Cube::printCube() {
    for (int i = 0; i < 6; i++) {
        std::cout << printColor(i) << "\n";
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                std::cout << outputToChar(cube[i][j][k]);
            }
            std::cout << "\n";
        }
        std::cout << '\n';
    }
}

void Cube::printRotations() {
    for (int i = 0; i < history.size(); i++) {
        if (i % 10 == 9)
            std::cout << '\n';
        std::cout << history[i] << ' ';
    }
}

void Cube::Write(const std::string& filename) {
    std::ofstream File;
    File.open(filename);
    if (File.is_open()) {
        for (int i = 0; i < 6; i++) {
            File << "---\n";
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    File << outputToChar(cube[i][j][k]);
                }
                File << '\n';
            }
        }
        File << "---\n";
    }
    File.close();
};

void Cube::Read(const std::string& filename) {
    std::ifstream file;
    file.open(filename);
    std::string str;
    if (file.is_open()) {
        int face = 0;
        int row = 0;
        while (std::getline(file, str)) {
            if (str == "---") {
                continue;
            }
            cube[face][row][0] = inputToInt(str[0]);
            cube[face][row][1] = inputToInt(str[1]);
            cube[face][row][2] = inputToInt(str[2]);
            row = (row + 1) % 3;
            if (row == 0) {
                face = (face + 1) % 6;
            }
        }
    }
    file.close();
}

/*void Cube::Read(const std::string& filename) {
    std::ifstream File(filename);
    File.open(filename);
    std::string str;
    if (File.is_open()) {
        File.seekg(0);
        int row = 0;
        while (std::getline(File, str)) {
            if (str == "---") {
                continue;
            }
            for (int j = 0; j < 3;j++) {
                cube[row][j][0] = inputToInt(str[0]);
                cube[row][j][1] = inputToInt(str[1]);
                cube[row][j][2] = inputToInt(str[2]);
            }
            row++;
        }
    }
    std::cout << "Cube's state was successfully read from the file" << std::endl;
    File.close();
}*/

bool Cube::isSolved() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (cube[i][j][k] != i) {
                    return false;
                }
            }
        }
    }
    return true;
}


bool Cube::operator==(const Cube& a){
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (this->cube[i][j][k] != a.cube[i][j][k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Cube::Up(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[0][2 - i][0];
            cube[0][2 - i][0] = cube[0][2][2-i]; //first column
            cube[0][2][2-i] = cube[0][i][2]; //top row
            cube[0][i][2] = cube[0][0][i];
            cube[0][0][i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[3][0][0];
        int temp2 = cube[3][0][1];
        int temp3 = cube[3][0][2];
        cube[3][0][0] = cube[2][0][0];
        cube[3][0][1] = cube[2][0][1];
        cube[3][0][2] = cube[2][0][2];
        cube[2][0][0] = cube[5][0][0];
        cube[2][0][1] = cube[5][0][1];
        cube[2][0][2] = cube[5][0][2];
        cube[5][0][0] = cube[4][0][0];
        cube[5][0][1] = cube[4][0][1];
        cube[5][0][2] = cube[4][0][2];
        cube[4][0][0] = temp1;
        cube[4][0][1] = temp2;
        cube[4][0][2] = temp3;
    }
}

void Cube::UpPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[0][2 - i][0];
            cube[0][2 - i][0] = cube[0][0][i]; //first column
            cube[0][0][i] = cube[0][i][2]; //top row
            cube[0][i][2] = cube[0][2][2 - i];
            cube[0][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[3][0][0];
        int temp2 = cube[3][0][1];
        int temp3 = cube[3][0][2];
        cube[3][0][0] = cube[4][0][0];
        cube[3][0][1] = cube[4][0][1];
        cube[3][0][2] = cube[4][0][2];
        cube[4][0][0] = cube[5][0][0];
        cube[4][0][1] = cube[5][0][1];
        cube[4][0][2] = cube[5][0][2];
        cube[5][0][0] = cube[2][0][0];
        cube[5][0][1] = cube[2][0][1];
        cube[5][0][2] = cube[2][0][2];
        cube[2][0][0] = temp1;
        cube[2][0][1] = temp2;
        cube[2][0][2] = temp3;
    }
}


void Cube::Left(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[3][2 - i][0];
            cube[3][2 - i][0] = cube[3][2][2-i]; //first column
            cube[3][2][2-i] = cube[3][i][2]; //top row
            cube[3][i][2] = cube[3][0][i];
            cube[3][0][i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][0][0];
        int temp2 = cube[0][1][0];
        int temp3 = cube[0][2][0];
        cube[0][0][0] = cube[4][2][2];
        cube[0][1][0] = cube[4][1][2];
        cube[0][2][0] = cube[4][0][2];
        cube[4][2][2] = cube[1][0][0];
        cube[4][1][2] = cube[1][1][0];
        cube[4][0][2] = cube[1][2][0];
        cube[1][0][0] = cube[2][0][0];
        cube[1][1][0] = cube[2][1][0];
        cube[1][2][0] = cube[2][2][0];
        cube[2][0][0] = temp1;
        cube[2][1][0] = temp2;
        cube[2][2][0] = temp3;
    }
}

void Cube::LeftPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[3][2 - i][0];
            cube[3][2 - i][0] = cube[3][0][i]; //first column
            cube[3][0][i] = cube[3][i][2]; //top row
            cube[3][i][2] = cube[3][2][2 - i];
            cube[3][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][0][0];
        int temp2 = cube[0][1][0];
        int temp3 = cube[0][2][0];
        cube[0][0][0] = cube[2][0][0];
        cube[0][1][0] = cube[2][1][0];
        cube[0][2][0] = cube[2][2][0];
        cube[2][0][0] = cube[1][0][0];
        cube[2][1][0] = cube[1][1][0];
        cube[2][2][0] = cube[1][2][0];
        cube[1][0][0] = cube[4][2][2];
        cube[1][1][0] = cube[4][1][2];
        cube[1][2][0] = cube[4][0][2];
        cube[4][2][2] = temp1;
        cube[4][1][2] = temp2;
        cube[4][0][2] = temp3;
    }
}

void Cube::Front(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[2][2 - i][0];
            cube[2][2 - i][0] = cube[2][2][2-i]; //first column
            cube[2][2][2-i] = cube[2][i][2]; //top row
            cube[2][i][2] = cube[2][0][i];
            cube[2][0][i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][2][0];
        int temp2 = cube[0][2][1];
        int temp3 = cube[0][2][2];
        cube[0][2][0] = cube[3][2][2];
        cube[0][2][1] = cube[3][1][2];
        cube[0][2][2] = cube[3][0][2];
        cube[3][2][2] = cube[1][0][2];
        cube[3][1][2] = cube[1][0][1];
        cube[3][0][2] = cube[1][0][0];
        cube[1][0][2] = cube[5][0][0];
        cube[1][0][1] = cube[5][1][0];
        cube[1][0][0] = cube[5][2][0];
        cube[5][0][0] = temp1;
        cube[5][1][0] = temp2;
        cube[5][2][0] = temp3;
    }
}

void Cube::FrontPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[2][2 - i][0];
            cube[2][2 - i][0] = cube[2][0][i]; //first column
            cube[2][0][i] = cube[2][i][2]; //top row
            cube[2][i][2] = cube[2][2][2 - i];
            cube[2][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][2][0];
        int temp2 = cube[0][2][1];
        int temp3 = cube[0][2][2];
        cube[0][2][0] = cube[5][0][0];
        cube[0][2][1] = cube[5][1][0];
        cube[0][2][2] = cube[5][2][0];
        cube[5][0][0] = cube[1][0][2];
        cube[5][1][0] = cube[1][0][1];
        cube[5][2][0] = cube[1][0][0];
        cube[1][0][2] = cube[3][2][2];
        cube[1][0][1] = cube[3][1][2];
        cube[1][0][0] = cube[3][0][2];
        cube[3][2][2] = temp1;
        cube[3][1][2] = temp2;
        cube[3][0][2] = temp3;
    }
}

void Cube::Right(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = cube[5][2][2-i]; //first column
            cube[5][2][2-i] = cube[5][i][2]; //top row
            cube[5][i][2] = cube[5][0][i];
            cube[5][0][i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][0][2];
        int temp2 = cube[0][1][2];
        int temp3 = cube[0][2][2];
        cube[0][0][2] = cube[2][0][2];
        cube[0][1][2] = cube[2][1][2];
        cube[0][2][2] = cube[2][2][2];
        cube[2][0][2] = cube[1][0][2];
        cube[2][1][2] = cube[1][1][2];
        cube[2][2][2] = cube[1][2][2];
        cube[1][0][2] = cube[4][2][0];
        cube[1][1][2] = cube[4][1][0];
        cube[1][2][2] = cube[4][0][0];
        cube[4][2][0] = temp1;
        cube[4][1][0] = temp2;
        cube[4][0][0] = temp3;
    }
}

void Cube::RightPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = cube[5][0][i]; //first column
            cube[5][0][i] = cube[5][i][2]; //top row
            cube[5][i][2] = cube[5][2][2 - i];
            cube[5][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][0][2];
        int temp2 = cube[0][1][2];
        int temp3 = cube[0][2][2];
        cube[0][0][2] = cube[4][2][0];
        cube[0][1][2] = cube[4][1][0];
        cube[0][2][2] = cube[4][0][0];
        cube[4][2][0] = cube[1][0][2];
        cube[4][1][0] = cube[1][1][2];
        cube[4][0][0] = cube[1][2][2];
        cube[1][0][2] = cube[2][0][2];
        cube[1][1][2] = cube[2][1][2];
        cube[1][2][2] = cube[2][2][2];
        cube[2][0][2] = temp1;
        cube[2][1][2] = temp2;
        cube[2][2][2] = temp3;
    }
}


void Cube::Back(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[4][2 - i][0];
            cube[4][2 - i][0] = cube[4][2][2-i]; //first column
            cube[4][2][2-i] = cube[4][i][2]; //top row
            cube[4][i][2] = cube[4][0][i];
            cube[4][0][i] = temp[i];
        }

        // Rotate adjacent edges
        int temp1 = cube[0][0][0];
        int temp2 = cube[0][0][1];
        int temp3 = cube[0][0][2];
        cube[0][0][0] = cube[5][0][2];
        cube[0][0][1] = cube[5][1][2];
        cube[0][0][2] = cube[5][2][2];
        cube[5][0][2] = cube[1][2][2];
        cube[5][1][2] = cube[1][2][1];
        cube[5][2][2] = cube[1][2][0];
        cube[1][2][2] = cube[3][2][0];
        cube[1][2][1] = cube[3][1][0];
        cube[1][2][0] = cube[3][0][0];
        cube[3][2][0] = temp1;
        cube[3][1][0] = temp2;
        cube[3][0][0] = temp3;

    }
}


void Cube::BackPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[4][2 - i][0];
            cube[4][2 - i][0] = cube[4][0][i]; //first column
            cube[4][0][i] = cube[4][i][2]; //top row
            cube[4][i][2] = cube[4][2][2 - i];
            cube[4][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[0][0][0];
        int temp2 = cube[0][0][1];
        int temp3 = cube[0][0][2];
        cube[0][0][0] = cube[3][2][0];
        cube[0][0][1] = cube[3][1][0];
        cube[0][0][2] = cube[3][0][0];
        cube[3][2][0] = cube[1][2][2];
        cube[3][1][0] = cube[1][2][1];
        cube[3][0][0] = cube[1][2][0];
        cube[1][2][2] = cube[5][0][2];
        cube[1][2][1] = cube[5][1][2];
        cube[1][2][0] = cube[5][2][2];
        cube[5][0][2] = temp1;
        cube[5][1][2] = temp2;
        cube[5][2][2] = temp3;
    }
}

void Cube::Down(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = cube[1][2][2-i]; //first column
            cube[1][2][2-i] = cube[1][i][2]; //top row
            cube[1][i][2] = cube[1][0][i];
            cube[1][0][i] = temp[i];
        }

        // Rotate adjacent edges
        int temp1 = cube[3][2][0];
        int temp2 = cube[3][2][1];
        int temp3 = cube[3][2][2];
        cube[3][2][0] = cube[4][2][0];
        cube[3][2][1] = cube[4][2][1];
        cube[3][2][2] = cube[4][2][2];
        cube[4][2][0] = cube[5][2][0];
        cube[4][2][1] = cube[5][2][1];
        cube[4][2][2] = cube[5][2][2];
        cube[5][2][0] = cube[2][2][0];
        cube[5][2][1] = cube[2][2][1];
        cube[5][2][2] = cube[2][2][2];
        cube[2][2][0] = temp1;
        cube[2][2][1] = temp2;
        cube[2][2][2] = temp3;
    }
}

void Cube::DownPrime(int amount) {
    int temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 2; i++) {
            temp[i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = cube[1][0][i]; //first column
            cube[1][0][i] = cube[1][i][2]; //top row
            cube[1][i][2] = cube[1][2][2 - i];
            cube[1][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        int temp1 = cube[3][2][0];
        int temp2 = cube[3][2][1];
        int temp3 = cube[3][2][2];
        cube[3][2][0] = cube[2][2][0];
        cube[3][2][1] = cube[2][2][1];
        cube[3][2][2] = cube[2][2][2];
        cube[2][2][0] = cube[5][2][0];
        cube[2][2][1] = cube[5][2][1];
        cube[2][2][2] = cube[5][2][2];
        cube[5][2][0] = cube[4][2][0];
        cube[5][2][1] = cube[4][2][1];
        cube[5][2][2] = cube[4][2][2];
        cube[4][2][0] = temp1;
        cube[4][2][1] = temp2;
        cube[4][2][2] = temp3;
    }
}


void Cube::Rotate(COMMANDS  command){
    switch (command) {
        case COMMANDS::F:
            history.push_back("F");
            Front(1);
            break;
        case COMMANDS::Fprime:
            history.push_back("Fprime");
            FrontPrime(1);
            break;
        case COMMANDS::F2:
            history.push_back("F2");
            Front(2);
            break;
        case COMMANDS::R:
            history.push_back("R");
            Right(1);
            break;
        case COMMANDS::Rprime:
            history.push_back("Rprime");
            RightPrime(1);
            break;
        case COMMANDS::R2:
            history.push_back("R2");
            Right(2);
            break;
        case COMMANDS::L:
            history.push_back("L");
            Left(1);
            break;
        case COMMANDS::Lprime:
            history.push_back("Lprime");
            LeftPrime(1);
            break;
        case COMMANDS::L2:
            history.push_back("L2");
            Left(2);
            break;
        case COMMANDS::B:
            history.push_back("B");
            Back(1);
            break;
        case COMMANDS::Bprime:
            history.push_back("Bprime");
            BackPrime(1);
            break;
        case COMMANDS::B2:
            history.push_back("B2");
            Back(2);
            break;
        case COMMANDS::D:
            history.push_back("D");
            Down(1);
            break;
        case COMMANDS::Dprime:
            history.push_back("Dprime");
            DownPrime(1);
            break;
        case COMMANDS::D2:
            history.push_back("D2");
            Down(2);
            break;
        case COMMANDS::U:
            history.push_back("U");
            Up(1);
            break;
        case COMMANDS::Uprime:
            history.push_back("Uprime");
            UpPrime(1);
            break;
        case COMMANDS::U2:
            history.push_back("U2");
            Up(2);
            break;
    }
}

COLOR_cube Cube::getCube() {
    return cube;
}

face_cube Cube::getFace(int index) {
    return cube[index];
}

std::vector<std::string> Cube::getHistory() {
    return history;
}
