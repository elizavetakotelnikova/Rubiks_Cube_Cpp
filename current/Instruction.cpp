#include "Algo.h"

void::Algo::phase_one(Cube &cube, Cubie & mini_cube) {
    COLOR_cube current_cube = cube.getCube();
    if (mini_cube.getCubieLeft() == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN &&
        current_cube[2][1][1] == COLOR::GREEN) {
        if (mini_cube.getCubieTop() == COLOR::ORANGE && current_cube[0][2][2] == COLOR::ORANGE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::WHITE && current_cube[5][0][0] == COLOR::WHITE &&
                current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::WHITE && current_cube[2][0][2] == COLOR::WHITE &&
               current_cube[2][1][1] == COLOR::GREEN) {
        if (mini_cube.getCubieTop() == COLOR::GREEN && current_cube[0][2][2] == COLOR::GREEN &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE &&
                current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::ORANGE && current_cube[2][0][2] == COLOR::ORANGE &&
             current_cube[2][1][1] == COLOR::GREEN) {
        if (mini_cube.getCubieTop() == COLOR::WHITE && current_cube[0][2][2] == COLOR::WHITE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::GREEN && current_cube[5][0][0] == COLOR::GREEN &&
                current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }


}
