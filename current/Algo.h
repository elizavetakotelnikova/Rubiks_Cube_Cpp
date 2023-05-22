#include "Cube.h"
#include <vector>
#include <queue>
class Algo {
private:
    int stage;
public:
    bool isCross(COLOR color, int index, Cube& cube);
    bool isRightWhiteCross(COLOR color, int index, Cube& cube);
    bool matchCenter(COLOR a, COLOR center);
    void SetEdge(COLOR fc, Cube& Cube, COLOR ce);
    void SetEdgeFront(COLOR fc, Cube& Cube, COLOR ce);
    void makeWhiteCross(Cube& cube);

    //void phase_one(Cube &cube, Cubie &mini_cube);
    //void phase_three(Cube &Cube, Cubie &mini_cube);
    void First_layer_solver(Cube &Cube, COLOR color);
    bool isYellowCross(COLOR color,Cube &Cube);
    void Yellow_cross_solver(Cube &Cube, COLOR color);
    int Max_corners_sum(Cube & Cube);
    void Corner_cubies_solver(Cube& Cube);

    void MiddleLayer(Cube &Cube);
    void fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube &Cube);
    bool isSolvedMiddleLayer(COLOR_cube &cube);

    void SolveYellowFace(Cube &Cube);
    bool IsSolvedYellow(Cube &Cube);
};
