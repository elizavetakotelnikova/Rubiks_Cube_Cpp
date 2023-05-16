//
// Created by Nastya on 14.05.2023.
//
#include "Algo.h"

void::Algo::phase_one(Cube &cube, Cubie & mini_cube) {
    COLOR_cube current_cube = cube.getCube();

    //if front side is green
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


    //if front side is red(pink)
    else if (mini_cube.getCubieLeft() == COLOR::RED && current_cube[3][0][2] == COLOR::RED &&
        current_cube[3][1][1] == COLOR::RED) {
        if (mini_cube.getCubieTop() == COLOR::GREEN && current_cube[0][2][0] == COLOR::GREEN &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::WHITE && current_cube[2][0][0] == COLOR::WHITE &&
                current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::WHITE && current_cube[3][0][2] == COLOR::WHITE &&
             current_cube[3][1][1] == COLOR::RED) {
        if (mini_cube.getCubieTop() == COLOR::RED && current_cube[0][2][0] == COLOR::RED &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN &&
                current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::GREEN && current_cube[3][0][2] == COLOR::GREEN &&
             current_cube[3][1][1] == COLOR::RED) {
        if (mini_cube.getCubieTop() == COLOR::WHITE && current_cube[0][2][0] == COLOR::WHITE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::RED && current_cube[2][0][0] == COLOR::RED &&
                current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }

    //if front side is blue
    else if (mini_cube.getCubieLeft() == COLOR::BLUE && current_cube[4][0][2] == COLOR::BLUE &&
             current_cube[4][1][1] == COLOR::BLUE) {
        if (mini_cube.getCubieTop() == COLOR::RED && current_cube[0][0][0] == COLOR::RED &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::WHITE && current_cube[3][0][0] == COLOR::WHITE &&
                current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::WHITE && current_cube[4][0][2] == COLOR::WHITE &&
             current_cube[4][1][1] == COLOR::BLUE) {
        if (mini_cube.getCubieTop() == COLOR::BLUE && current_cube[0][0][0] == COLOR::BLUE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::RED && current_cube[3][0][0] == COLOR::RED &&
                current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::RED && current_cube[4][0][2] == COLOR::RED &&
             current_cube[4][1][1] == COLOR::BLUE) {
        if (mini_cube.getCubieTop() == COLOR::WHITE && current_cube[0][0][0] == COLOR::WHITE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::BLUE && current_cube[3][0][0] == COLOR::BLUE &&
                current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }


    //if front side is orange
    else if (mini_cube.getCubieLeft() == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE &&
             current_cube[5][1][1] == COLOR::ORANGE) {
        if (mini_cube.getCubieTop() == COLOR::BLUE && current_cube[0][0][2] == COLOR::BLUE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::WHITE && current_cube[4][0][0] == COLOR::WHITE &&
                current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::WHITE && current_cube[5][0][2] == COLOR::WHITE &&
             current_cube[5][1][1] == COLOR::ORANGE) {
        if (mini_cube.getCubieTop() == COLOR::ORANGE && current_cube[0][0][2] == COLOR::ORANGE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::BLUE && current_cube[4][0][0] == COLOR::BLUE &&
                current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }
        }
    }

    else if (mini_cube.getCubieLeft() == COLOR::BLUE && current_cube[5][0][2] == COLOR::BLUE &&
             current_cube[5][1][1] == COLOR::ORANGE) {
        if (mini_cube.getCubieTop() == COLOR::WHITE && current_cube[0][0][2] == COLOR::WHITE &&
            current_cube[0][1][1] == COLOR::YELLOW) {
            if (mini_cube.getCubieRight() == COLOR::ORANGE && current_cube[4][0][0] == COLOR::ORANGE &&
                current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }

    //если в верхнем слое не окажется угловых элементов с белым цветом
    else{


    }



}



void::Algo::phase_three(Cube &cube, Cubie & mini_cube) {
    COLOR_cube current_cube = cube.getCube();
    if(current_cube[0][1][1] == COLOR::YELLOW){
        while(!(current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW)) {
            if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(R);
            } 
            else if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW) {
                Cube.Rotate(F);
                Cube.Rotate(R);
                Cube.Rotate(U);
            }
            else{//это типо когда только точка в центре
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(R);
            }
        }
    }
}
