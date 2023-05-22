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
};
