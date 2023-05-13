#include "Algo.h"

bool Algo::isCross(COLOR color, int index, Cube &cube) {
    face_cube current_face = cube.getFace(index);
    COLOR center = current_face[1][1];
    if (current_face[0][1] == center && current_face[1][2] == center)
        if (current_face[2][1] == center && current_face[1][0] == center) {
        return true;
    }
    return false;
}

bool Algo::isRightWhiteCross(COLOR color, int index, Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
    if (current_cube[5][2][1] == COLOR::ORANGE && current_cube[2][2][1] == COLOR::GREEN)
        if (current_cube[3][2][1] == COLOR::RED && current_cube[4][2][1] == COLOR::BLUE) {
            return true;
        }
    return false;
}




