#include "cube.h"

Cube::Cube() {
    std::memset(co, 0, sizeof(co));
    std::memset(eo, 0, sizeof(eo));
    for (int i = 0; i < 8; i++) {
        cp[i] = i;
    }
    for (int i = 0; i < 12; i++) {
        ep[i] = i;
    }
    centers[0] = COLOR::RED;
    centers[1] = COLOR::BLUE;
    centers[2] = COLOR::WHITE;
    centers[3] = COLOR::GREEN;
    centers[4] = COLOR::YELLOW;
    centers[5] = COLOR::ORANGE;
}

void Cube::Read(const char* filename) {
    std::ifstream File;
    File.open(filename, std::ios::in);
    for (int i = 0; i < 8; i++) {
        File >> cp[i] >> co[i];
    }
    for (int i = 0; i < 12; i++) {
        File >> ep[i] >> eo[i];
    }
    std::cout << "Cube's state was successfully read from the file " << std::endl;
}

void Cube::Generate() {
    for (int i = 0; i++; i < 6) {
        for (int j = 0; j++; j < 3) {
            for (int k = 0; k++; k < 3) {
                sides[i][j][k] = rand() % 6;
            }
        }
    }
}

bool Cube::Check() {
    for (int i = 0; i < 8; i++) {
        if ((cp[i] != i) or (co[i] != 0))
            return false;
    }
    for (int i = 0; i < 12; i++) {
        if ((ep[i] != i) or (eo[i] != 0))
            return false;
    }
    return true;
}

void Cube::PrintCube() {
    std::cout << "Corners' position and orientation:\n";
    for (int i = 0; i < 8; i++)
        std::cout << cp[i] << ' ' << co[i] << std::endl;
    std::cout << "Edges' position and orientation:\n";
    for (int i = 0; i < 12; ++i)
        std::cout << ep[i] << ' ' << eo[i] << std::endl;
}

void Cube::Write() {
    std::string filename = "Current_state.txt";
    std::ofstream File;
    File.open(filename, std::ios::out);
    for (int i = 0; i < 8; i++)
        File << cp[i] << ' ' << co[i] << std::endl;
    for (int i = 0; i < 12; i++)
        File << ep[i] << ' ' << eo[i] << std::endl;
    std::cout << "Cube's state was successfully wrote to the file " << filename << std::endl;
}

Cube& Cube::operator=(const Cube& a){
    for (int i = 0; i < 8; i++){
        cp[i] = a.cp[i];
        co[i] = a.co[i];
    }
    for (int i = 0; i < 12; i++){
        ep[i] = a.ep[i];
        eo[i] = a.eo[i];
    }
    return *this;
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0][2 - i][0];
            cube[0][2 - i][0] = cube[0][2][2-i]; //first column
            cube[0][2][2-i] = cube[0][i][2]; //top row
            cube[0][i][2] = cube[0][0][i];
            cube[0][0][i] = temp[i];
        }
        // Rotate adjacent edges
        COLOR temp1 = cube[3][0][0];
        COLOR temp2 = cube[3][0][1];
        COLOR temp3 = cube[3][0][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0][2 - i][0];
            cube[0][2 - i][0] = cube[0][0][i]; //first column
            cube[0][0][i] = cube[0][i][2]; //top row
            cube[0][i][2] = cube[0][2][2 - i];
            cube[0][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        COLOR temp1 = cube[3][0][0];
        COLOR temp2 = cube[3][0][1];
        COLOR temp3 = cube[3][0][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[3][2 - i][0];
            cube[3][2 - i][0] = cube[3][2][2-i]; //first column
            cube[3][2][2-i] = cube[3][i][2]; //top row
            cube[3][i][2] = cube[3][0][i];
            cube[3][0][i] = temp[i];
        }
        // Rotate adjacent edges
        //should be checked - I guess I might have done a mistake
        //have been checked by nastya, it is clear!
        COLOR temp1 = cube[0][0][0];
        COLOR temp2 = cube[0][1][0];
        COLOR temp3 = cube[0][2][0];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[3][2 - i][0];
            cube[3][2 - i][0] = cube[3][0][i]; //first column
            cube[3][0][i] = cube[3][i][2]; //top row
            cube[3][i][2] = cube[3][2][2 - i];
            cube[3][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        //should be checked
        //have been checked and changed by nastya
        COLOR temp1 = cube[0][0][0];
        COLOR temp2 = cube[0][1][0];
        COLOR temp3 = cube[0][2][0];
        cube[0][0][0] = cube[2][0][0];
        cube[0][1][0] = cube[2][1][0];
        cube[0][2][0] = cube[2][2][0];
        cube[2][0][0] = cube[1][0][0];
        cube[2][1][0] = cube[1][1][0];
        cube[2][2][0] = cube[1][2][0];
        cube[1][0][0] = cube[4][2][2];
        cube[1][1][0] = cube[4][1][2];
        cube[1][2][0] = cube[4][0][2];//change 422 to 402!
        cube[4][2][2] = temp1;
        cube[4][1][2] = temp2;
        cube[4][0][2] = temp3;//change 422 to 402!
    }
}

void Cube::Front(int amount) {
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][2 - i][0];
            cube[2][2 - i][0] = cube[2][2][2-i]; //first column
            cube[2][2][2-i] = cube[2][i][2]; //top row
            cube[2][i][2] = cube[2][0][i];
            cube[2][0][i] = temp[i];
        }
        // Rotate adjacent edges
        //it was fixed
        //have been checked and changed by nastya
        COLOR temp1 = cube[0][2][0];
        COLOR temp2 = cube[0][2][1];
        COLOR temp3 = cube[0][2][2];
        cube[0][2][0] = cube[3][2][2];//why you add back, if we do front rotate?)
        cube[0][2][1] = cube[3][1][2];//changed 4 to 3
        cube[0][2][2] = cube[3][0][2];
        cube[3][2][2] = cube[1][0][2];
        cube[3][1][2] = cube[1][0][1];
        cube[3][0][2] = cube[1][0][0];
        cube[1][0][2] = cube[5][0][0];//changed 2 to 5
        cube[1][0][1] = cube[5][1][0];//01 to 10
        cube[1][0][0] = cube[5][2][0];//02 to 20
        cube[5][0][0] = temp1;//changed 4 to 5 and
        cube[5][1][0] = temp2;
        cube[5][2][0] = temp3;
    }
}

void Cube::FrontPrime(int amount) {
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][2 - i][0];
            cube[2][2 - i][0] = cube[2][0][i]; //first column
            cube[2][0][i] = cube[2][i][2]; //top row
            cube[2][i][2] = cube[2][2][2 - i];
            cube[2][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        //should be checked
        //have been checked and changed by nastya
        COLOR temp1 = cube[0][2][0];
        COLOR temp2 = cube[0][2][1];
        COLOR temp3 = cube[0][2][2];
        cube[0][2][0] = cube[5][0][0];
        cube[0][2][1] = cube[5][1][0];
        cube[0][2][2] = cube[5][2][0];
        cube[5][0][0] = cube[1][0][2];// 100 to 102
        cube[5][1][0] = cube[1][0][1];//110 to 101
        cube[5][2][0] = cube[1][0][0];//120 to 100
        cube[1][0][2] = cube[3][2][2];//302 to 322
        cube[1][0][1] = cube[3][1][2];
        cube[1][0][0] = cube[3][0][2];//322 to 302
        cube[3][2][2] = temp1;
        cube[3][1][2] = temp2;
        cube[3][0][2] = temp3;
    }
}

void Cube::Right(int amount) {
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = cube[5][2][2-i]; //first column
            cube[5][2][2-i] = cube[5][i][2]; //top row
            cube[5][i][2] = cube[5][0][i];
            cube[5][0][i] = temp[i];
        }
        // Rotate adjacent edges
        //have been checked and it is clear
        COLOR temp1 = cube[0][0][2];
        COLOR temp2 = cube[0][1][2];
        COLOR temp3 = cube[0][2][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = cube[5][0][i]; //first column
            cube[5][0][i] = cube[5][i][2]; //top row
            cube[5][i][2] = cube[5][2][2 - i];
            cube[5][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        //have been checked and changed by nastya
        COLOR temp1 = cube[0][0][2];
        COLOR temp2 = cube[0][1][2];
        COLOR temp3 = cube[0][2][2];
        cube[0][0][2] = cube[4][2][0];//422 to 420...
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[4][2 - i][0];
            cube[4][2 - i][0] = cube[4][2][2-i]; //first column
            cube[4][2][2-i] = cube[4][i][2]; //top row
            cube[4][i][2] = cube[4][0][i];
            cube[4][0][i] = temp[i];
        }

        // Rotate adjacent edges
        //writen by nastya, please check!
        COLOR temp1 = cube[0][0][0];
        COLOR temp2 = cube[0][0][1];
        COLOR temp3 = cube[0][0][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[4][2 - i][0];
            cube[4][2 - i][0] = cube[4][0][i]; //first column
            cube[4][0][i] = cube[4][i][2]; //top row
            cube[4][i][2] = cube[4][2][2 - i];
            cube[4][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        //writen by nastya, please check!
        COLOR temp1 = cube[0][0][0];
        COLOR temp2 = cube[0][0][1];
        COLOR temp3 = cube[0][0][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = cube[1][2][2-i]; //first column
            cube[1][2][2-i] = cube[1][i][2]; //top row
            cube[1][i][2] = cube[1][0][i];
            cube[1][0][i] = temp[i];
        }

        // Rotate adjacent edges
        //writen by nastya, please check!
        COLOR temp1 = cube[3][2][0];
        COLOR temp2 = cube[3][2][1];
        COLOR temp3 = cube[3][2][2];
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
    COLOR temp[3];
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = cube[1][0][i]; //first column
            cube[1][0][i] = cube[1][i][2]; //top row
            cube[1][i][2] = cube[1][2][2 - i];
            cube[1][2][2 - i] = temp[i];
        }
        // Rotate adjacent edges
        //writen by nastya, please check!
        COLOR temp1 = cube[3][2][0];
        COLOR temp2 = cube[3][2][1];
        COLOR temp3 = cube[3][2][2];
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


int8_t* Cube::getCO() {
    return this->co;
}

int8_t* Cube::getCP() {
    return this->cp;
}

int8_t* Cube::getEO() {
    return this->eo;
}

int8_t* Cube::getEP() {
    return this->ep;
}


COLOR Cube::getColor(FACE face, unsigned int row, unsigned int col) {
    return COLOR::RED;
}

void Cube::Rotate(commands command){
    switch (command) {
        case COMMANDS::F:
            Front(1);
            break;
        case COMMANDS::Fprime:
            FrontPrime(1);
            break;
        case COMMANDS::F2:
            Front(2);
            break;
        case COMMANDS::R:
            Right(1);
            break;
        case COMMANDS::Rprime:
            RightPrime(1);
            break;
        case COMMANDS::R2:
            Right(2);
            break;
        case COMMANDS::L:
            Left(1);
            break;
        case COMMANDS::Lprime:
            LeftPrime(1);
            break;
        case COMMANDS::L2:
            Left(2);
            break;
        case COMMANDS::B:
            Back(1);
            break;
        case COMMANDS::Bprime:
            BackPrime(1);
            break;
        case COMMANDS::B2:
            Back(2);
            break;
        case COMMANDS::D:
            Down(1);
            break;
        case COMMANDS::Dprime:
            DownPrime(1);
            break;
        case COMMANDS::D2:
            Down(2);
            break;
        case COMMANDS::U:
            Up(1);
            break;
        case COMMANDS::Uprime:
            UpPrime(1);
            break;
        case COMMANDS::U2:
            Up(2);
            break;
    }
}

bool Cube::checkWhiteCross() {
    for (int i = 0; i < 6; i++) {
        if (centers[i] == COLOR::WHITE) {
            if (sides[i][0][1].getCubieTop() != COLOR::WHITE) {
                return false;
            }
            if (sides[i][1][0].getCubieTop() != COLOR::WHITE) {
                return false;
            }
            if (sides[i][1][2].getCubieTop() != COLOR::WHITE) {
                return false;
            }
            if (sides[i][2][1].getCubieTop() != COLOR::WHITE) {
                return false;
            }
        }
    }
    return true;
}

COLOR_cube Cube::getCube() {
    return cube;
}

face_cube Cube::getFace(int index) {
    return cube[index];
}

//if needed, change to Face::FACE_TYPE
