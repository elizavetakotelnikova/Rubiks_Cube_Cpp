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
 *
 *
 * indexes of edges will be like this (observing from the top face)
 *     *-*-*-*
 *     | |1| |
 *     *-*-*-*
 *     |0| |2|
 *     *-*-*-*
 *     | |3| |
 *     *-*-*-*
 *       face
 *
 *   the way we are holding rubics cube: white face if at the bottom (1), yellow face is top (0), green face is front (2),
 *   red face is left (3), blue face is back (4) and orange face is right (5)
*/

struct Block {
	int8_t top, bottom, front, back, left, right;
};

//using block_info_t = std::pair<const int8_t*, const int8_t*>;

enum class FACE: uint8_t {UP, LEFT, FRONT, RIGHT, BACK, DOWN};
enum class COLOR : unsigned char {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
enum CORNER {ULB, URB, URF, ULF, DLF, DLB, DRB, DRF}; //position is a solved state
enum CORNERS_COLOR {YRB, YOB, YOG, YRG, WRG, WRB, WOB, WOG};
enum EDGE {UB, UR, UF, UL, FR, FL, BL, BR, DF, DL, DB, DR}; // position in s solved state
enum EDGES_COLOR {YB, YO, YG, YR, GO, GR, BLUERED, BO, WG, WR, WB, WO};
int FRONT[4] = {0, 2, 3, 4};
class Cubie {
private:
    COLOR right_color;
    COLOR left_color;
    COLOR top_color;
public:
    COLOR getCubieRight();
    COLOR getCubieLeft();
    COLOR getCubieTop();
};

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

//in this implementation rotating a face means updating indexes and orientations
class Cube {
private:
    COLOR cube[6][3][3];
    //Cubie corners[8];
    //Cubie edges[12];
    //Cubie centers[6];
    //Face[6] faces[6];

    /*int8_t co[8]; //corners orientation, {0, 1, 2} - oriented, rotated once, rotated twice
    int8_t cp[8]; //corners position
    int8_t ep[12]; //edges position
    int8_t eo[12]; //edges orientation, {0, 1) - oriented or flipped
    COLOR centers[6];*/
    //std::string cornerNames[8] = {"URF", "UBR", "DLF", "DFR", "ULB", "UFL", "DRB", "DBL"};
    //std::string edgeNames[12] = {"UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "BR", "BL", "FL"};
public:
    Cube();
    void Read(const char* filename);
    //bool IsSolved();
    /*COLOR getCubieRight(int side, int row, int column);
    COLOR getCubieLeft(int side, int row, int column);
    COLOR getCubieTop(int side, int row, int column);*/
    bool checkWhiteCross();
    void Generate();
    void PrintCube();
    void Write();
    Cube& operator=(const Cube &a);
    bool operator==(const Cube &a);
    bool Check();
    //Solve();
    void Rotate(FACE command, int move);
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
    COLOR getColor(FACE face, unsigned row, unsigned col);
    int8_t* getCO();
    int8_t* getCP();
    int8_t* getEO();
    int8_t* getEP();
};
#endif
