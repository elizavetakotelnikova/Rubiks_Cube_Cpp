#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

/*F, B, U, D, L, R - 90-degree turns of the front, back, up, down, left, and right faces, respectively.
 * An apostrophe (’) designates a 90-degree counterclockwise “prime” twist
 * “2” suffix indicates a 180-degree twist*/

/*
 * indexes of corners (observing from the top face)
 *     *-*-*-*        *-*-*-*
 *     |0| |1|        |4| |5|
 *     *-*-*-*        *-*-*-*
 *     | | | |        | | | |
 *     *-*-*-*        *-*-*-*
 *     |3| |2|        |7| |6|
 *     *-*-*-*        *-*-*-*
 *    bottom face,   top face
 *
 * indexes of edges will be like this (observing from the top face)
 *     *-*-*-*          *-*-*-*         *-*-*-*
 *     | |8| |          |0| |1|         | |4| |
 *     *-*-*-*          *-*-*-*         *-*-*-*
 *     |B| |9|          | | | |         |7| |5|
 *     *-*-*-*          *-*-*-*         *-*-*-*
 *     | |A| |          |3| |2|         | |6| |
 *     *-*-*-*          *-*-*-*         *-*-*-*
 *    bottom face,    middle layer,     top face
 *
 */

struct Face {
    enum FACE_TYPE {
        top,
        bottom,
        front,
        back,
        left,
        right,
    };
    int8_t C[9];
};

struct Block {
	int8_t top, bottom, front, back, left, right;
};
//using block_info_t = std::pair<const int8_t*, const int8_t*>;

enum class FACE: uint8_t {UP, LEFT, FRONT, RIGHT, BACK, DOWN};
enum class COLOR : unsigned char {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
enum CORNER {ULB, URB, URF, ULF, DLF, DLB, DRB, DRF}; //position is a solved state
enum EDGE {UB, UR, UF, UL, FR, FL, BL, BR, DF, DL, DB, DR}; // position in s solved state

//in this implementation rotating a face means updating indexes and orientations
class Cube {
private:
    int sides[6][3][3];
    int8_t co[8]; //corners orientation, {0, 1, 2} - oriented, rotated once, rotated twice
    int8_t cp[8]; //corners position
    int8_t ep[12]; //edges position
    int8_t eo[12]; //edges orientation, {0, 1) - oriented or flipped
    COLOR centers[6];
public:
    Cube();
    void Read(const char* filename);
    bool IsSolved();
    void Generate();
    void PrintCube();
    void Write();
    Cube& operator=(const Cube &a);
    bool operator==(const Cube &a);
    Check();
    Solve();
    void Front(int amount);
    void Down(int amount);
    void Up(int amount);
    void UpPrime(int amount);
    void Left(int amount);
    void Right(int amount);
    void LeftPrime(int amount);
    void Back(int amount);
    COLOR getColor(FACE face, unsigned row, unsigned col);

    int8_t* getCO();
    int8_t* getCP();
    int8_t* getEO();
    int8_t* getEP();
};
#endif
