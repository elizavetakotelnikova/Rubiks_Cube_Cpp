#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdint.h>

/*F, B, U, D, L, R - 90-degree turns of the front, back, up, down, left, and right faces, respectively.
 * An apostrophe (’) designates a 90-degree counterclockwise “prime” twist
 * “2” suffix indicates a 180-degree twist*/

/*
 *
 *     *-*-*-*
 *     |00|01|02|
 *     *-*-*-*-*
 *     |10|11|12|
 *     *-*-*-*-*
 *     |20|21|22|
 *     *-*-*-*-*
 *       face
 *
 *   the way we are holding rubics cube: white face if at the bottom (1), yellow face is top (0), green face is front (2),
 *   red face is left (3), blue face is back (4) and orange face is right (5)
*/
enum class FACE: int {UP, LEFT, FRONT, RIGHT, BACK, DOWN};
enum COMMANDS: int {U, Uprime, U2, F, Fprime, F2, L, Lprime, L2, R, Rprime, R2, B, Bprime, B2, D, Dprime, D2};
enum COLOR : int {YELLOW, WHITE, GREEN, RED, BLUE, ORANGE};
enum CORNER {ULB, URB, URF, ULF, DLF, DLB, DRB, DRF}; //position is a solved state
enum CORNERS_COLOR {YRB, YOB, YOG, YRG, WRG, WRB, WOB, WOG};
enum EDGE {UB, UR, UF, UL, FR, FL, BL, BR, DF, DL, DB, DR}; // position in s solved state
enum EDGES_COLOR {YB, YO, YG, YR, GO, GR, BLUERED, BO, WG, WR, WB, WO};

typedef int (*COLOR_cube)[3][3];
typedef int (*face_cube)[3];


struct Face {
    enum FACE_TYPE {
        top,
        bottom,
        front,
        back,
        left,
        right,
    };
    COLOR C[9];
};

class Cube {
private:
    int cube[6][3][3]; //array of cubies
    std::vector<std::string> history;
public:
    Cube();
    void Read(const std::string& filename);
    void Shuffle();
    void Write(const std::string& filename);
    void printCube();
    void printRotations();

    //illustrating cube's state
    uint8_t inputToInt(char x);
    char outputToChar(int x);
    std::string printColor(int x);

    //get methods
    COLOR_cube getCube();
    face_cube getFace(int index);
    std::vector<std::string> getHistory();

    //rotations
    void Rotate(COMMANDS command);
    void Front(int amount);
    void FrontPrime(int amount);
    void Down(int amount);
    void DownPrime(int amount);
    void Up(int amount);
    void UpPrime(int amount);
    void Left(int amount);
    void LeftPrime(int amount);
    void Right(int amount);
    void RightPrime(int amount);
    void Back(int amount);
    void BackPrime(int amount);

    //other
    bool operator==(const Cube &a);
    bool isSolved();
};
#endif
