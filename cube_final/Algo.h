#include "Cube.h"
#include <vector>
#include <queue>
class Algo {
private:
    int stage;
public:
    void Solve(Cube& Cube);

    bool isCross(COLOR color, int index, Cube& cube);
    bool isRightWhiteCross(Cube& cube);
    bool matchCenter(int a, int center);
    void SetEdge(int fc, Cube& Cube, int ce);
    void SetEdgeFront(int fc, Cube& Cube, int ce);
    void makeWhiteCross(Cube& cube);

    void firstLayerSolver(Cube &Cube);
    bool isSolvedFirstLayer(Cube &cube);

    void middleLayer(Cube &Cube);
    void fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube &Cube);
    bool isSolvedMiddleLayer(COLOR_cube &cube);

    bool isYellowCross(Cube &cube);
    void yellowCrossSolver(Cube &Cube);

    void solveYellowFace(Cube &Cube);
    bool isSolvedYellow(Cube &Cube);

    int maxCornersSum(Cube & Cube);
    void cornerCubiesSolver(Cube& Cube);
    bool highCornersCorrectPos(Cube &Cube);

    void solveCorners(Cube &Cube);
    bool areCornersSolved(Cube &Cube);

    void solveOrange(Cube &Cube);
    void solveRed(Cube &Cube);
    void solveBlue(Cube &Cube);
    void solveGreen(Cube &Cube);
};
