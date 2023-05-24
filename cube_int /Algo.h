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
    bool matchCenter(uint8_t a, uint8_t center);
    void SetEdge(uint8_t fc, Cube& Cube, uint8_t ce);
    void SetEdgeFront(uint8_t fc, Cube& Cube, uint8_t ce);
    void makeWhiteCross(Cube& cube);

    //void phase_one(Cube &cube, Cubie &mini_cube);
    //void phase_three(Cube &Cube, Cubie &mini_cube);
    void firstLayerSolver(Cube &Cube);
    bool isSolvedFirstLayer(Cube &cube);
    bool isYellowCross(Cube &cube);
    void yellowCrossSolver(Cube &Cube, COLOR color);
    int maxCornersSum(Cube & Cube);
    void cornerCubiesSolver(Cube& Cube);
    bool highCornersCorrectPos(Cube &Cube);
    void solvedSides(Cube &Cube);

    void MiddleLayer(Cube &Cube);
    void fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube &Cube);
    bool isSolvedMiddleLayer(COLOR_cube &cube);

    void SolveYellowFace(Cube &Cube);
    bool IsSolvedYellow(Cube &Cube);
};
