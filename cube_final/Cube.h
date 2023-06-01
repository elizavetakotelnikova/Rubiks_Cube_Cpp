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
enum COMMANDS: int {U, Uprime, U2, F, Fprime, F2, L, Lprime, L2, R, Rprime, R2, B, Bprime, B2, D, Dprime, D2};
enum COLOR : int {YELLOW, WHITE, GREEN, RED, BLUE, ORANGE};

typedef int (*COLOR_cube)[3][3];
typedef int (*face_cube)[3];

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
    
    //invariants
    bool isCubecorrect(Cube &Cube);
    
    //illustrating cube's state
    uint8_t inputToInt(char x);
    char outputToChar(int x);
    std::string printColor(int x);

    //get methods
    COLOR_cube getCube();
    face_cube getFace(int index);
    std::vector<std::string> getHistory();

    //rotations
    void rotateQuery(int amount);
    COMMANDS inputQueryToRotation(const std::string& x);
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
