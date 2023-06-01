#include "Cube.h"
#include <vector>
#include <queue>
class Algo {
private:
    int stage;
public:
    //solving functions
    void Solve(Cube& Cube);

    //White Cross Solver
    bool isCross(COLOR color, int index, Cube& cube);
    bool isRightWhiteCross(Cube& cube);
    bool matchCenter(int a, int center);
    void SetEdge(int fc, Cube& Cube, int ce);
    void SetEdgeFront(int fc, Cube& Cube, int ce);
    void makeWhiteCross(Cube& cube);

    //First layer Solver
    void firstLayerSolver(Cube &Cube);
    bool isSolvedFirstLayer(Cube &cube);

    //Middle layer Solver
    void solveMiddleLayer(Cube &Cube);
    void fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube &Cube);
    bool isSolvedMiddleLayer(COLOR_cube &cube);
    void solveOrange(Cube &Cube);
    void solveRed(Cube &Cube);
    void solveBlue(Cube &Cube);
    void solveGreen(Cube &Cube);

    //Yellow Cross Solver
    bool isYellowCross(Cube &cube);
    void solveYellowCross(Cube &Cube);

    //Yellow face solver
    void solveYellowFace(Cube &Cube);
    bool isSolvedYellow(Cube &Cube);

    //Up face's corner cubies solver
    int maxCornersSum(Cube & Cube);
    void solveCornerCubies(Cube& Cube);
    bool highCornersCorrectPos(Cube &Cube);

    //Up face's edges solver
    void solveEdges(Cube &Cube);
    bool areEdgesSolved(Cube &Cube);
};
