#include "Algo.h"
#include <algorithm>

void::Algo::First_layer_solver(Cube &cube, COLOR color) {
    COLOR_cube current_cube = cube.getCube();

    //if front side is green
    if (current_cube[2][0][2] == COLOR::GREEN && current_cube[2][1][1] == COLOR::GREEN) {
        if (current_cube[0][2][2] == COLOR::ORANGE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[5][0][0] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
        }
    }

    else if (current_cube[2][0][2] == COLOR::WHITE && current_cube[2][1][1] == COLOR::GREEN) {
        if (current_cube[0][2][2] == COLOR::GREEN && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
        }
    }

    else if (current_cube[2][0][2] == COLOR::ORANGE && current_cube[2][1][1] == COLOR::GREEN) {
        if (current_cube[0][2][2] == COLOR::WHITE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[5][0][0] == COLOR::GREEN && current_cube[5][1][1] == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }


        //if front side is red(pink)
    else if (current_cube[3][0][2] == COLOR::RED && current_cube[3][1][1] == COLOR::RED) {
        if (current_cube[0][2][0] == COLOR::GREEN && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[2][0][0] == COLOR::WHITE && current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
        }
    }

    else if (current_cube[3][0][2] == COLOR::WHITE && current_cube[3][1][1] == COLOR::RED) {
        if (current_cube[0][2][0] == COLOR::RED && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[2][0][0] == COLOR::GREEN && current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
        }
    }

    else if (current_cube[3][0][2] == COLOR::GREEN && current_cube[3][1][1] == COLOR::RED) {
        if (current_cube[0][2][0] == COLOR::WHITE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[2][0][0] == COLOR::RED && current_cube[2][1][1] == COLOR::GREEN) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }

        //if front side is blue
    else if (current_cube[4][0][2] == COLOR::BLUE && current_cube[4][1][1] == COLOR::BLUE) {
        if (current_cube[0][0][0] == COLOR::RED && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[3][0][0] == COLOR::WHITE && current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
        }
    }

    else if (current_cube[4][0][2] == COLOR::WHITE && current_cube[4][1][1] == COLOR::BLUE) {
        if (current_cube[0][0][0] == COLOR::BLUE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[3][0][0] == COLOR::RED && current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
            }
        }
    }

    else if (current_cube[4][0][2] == COLOR::RED && current_cube[4][1][1] == COLOR::BLUE) {
        if (current_cube[0][0][0] == COLOR::WHITE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[3][0][0] == COLOR::BLUE && current_cube[3][1][1] == COLOR::RED) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }


        //if front side is orange
    else if (current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][1][1] == COLOR::ORANGE) {
        if (current_cube[0][0][2] == COLOR::BLUE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[4][0][0] == COLOR::WHITE && current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);
            }
        }
    }

    else if (current_cube[5][0][2] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE) {
        if (current_cube[0][0][2] == COLOR::ORANGE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[4][0][0] == COLOR::BLUE && current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }
        }
    }

    else if (current_cube[5][0][2] == COLOR::BLUE && current_cube[5][1][1] == COLOR::ORANGE) {
        if (current_cube[0][0][2] == COLOR::WHITE && current_cube[0][1][1] == COLOR::YELLOW) {
            if (current_cube[4][0][0] == COLOR::ORANGE && current_cube[4][1][1] == COLOR::BLUE) {
                Cube.Rotate(R);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
            }
        }
    }

        //если в верхнем слое не окажется угловых элементов с белым цветом
    else{
        //если углы белой стороны внизу не белые(не на своих местах)
        if(current_cube[1][0][0] != COLOR::WHITE || current_cube[1][0][2] != COLOR::WHITE || current_cube[1][2][0] != COLOR::WHITE|| current_cube[1][2][2] != COLOR::WHITE) {
            //if front is green
            if ((current_cube[5][2][0] == COLOR::WHITE && current_cube[2][1][1] == COLOR::GREEN) ||
                (current_cube[5][2][2] == COLOR::WHITE && current_cube[2][1][1] == COLOR::GREEN)) {
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);

            }
            //if front is orange
            else if ((current_cube[4][2][0] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE) ||
                       (current_cube[4][2][2] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE)) {
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);

            }
            //if front is blue
            else if ((current_cube[3][2][0] == COLOR::WHITE && current_cube[4][1][1] == COLOR::BLUE) ||
                (current_cube[3][2][2] == COLOR::WHITE && current_cube[4][1][1] == COLOR::BLUE)) {
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);

            }
            //if front is res(pink)
            else if ((current_cube[2][2][0] == COLOR::WHITE && current_cube[3][1][1] == COLOR::RED) ||
                (current_cube[2][2][2] == COLOR::WHITE && current_cube[3][1][1] == COLOR::RED)) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);

            }

        }
    }
}

bool Algo::isYellowCross(COLOR color,Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW &&
            current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW) {
            return true;
        }
        return false;
}


void::Algo::Yellow_cross_solver(Cube &cube, COLOR color) {
    COLOR_cube current_cube = cube.getCube();
        while(!isYellowCross(color, cube)) {
            if (current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                } else if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                }
                else {//это типо когда только точка в центре
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                }
            }
        }
}


int::Algo::Max_corners_sum(Cube& cube){
    COLOR_cube current_cube = cube.getCube();
    int counter1, counter2, counter3, counter4 = 0;
    //if front is green
    if(current_cube[2][1][1] == COLOR::GREEN && current_cube[5][1][1] == COLOR::ORANGE && current_cube[4][1][1] == COLOR::BLUE && current_cube[3][1][1] == COLOR::RED){
        if(current_cube[2][0][2] == COLOR::GREEN || current_cube[2][0][0] == COLOR::GREEN){
            counter1+=1;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
            counter1+=2;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE || current_cube[5][0][0] == COLOR::ORANGE){
            counter1+=1;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            counter1+=2;
        }
        if(current_cube[5][0][2] == COLOR::BLUE || current_cube[5][0][0] == COLOR::BLUE){
            counter1+=1;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE && current_cube[5][0][2] == COLOR::BLUE){
            counter1+=2;
        }
        if(current_cube[3][0][2] == COLOR::RED || current_cube[3][0][0] == COLOR::RED){
            counter1+=1;
        }
        else if(current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
            counter1+=2;
        }
        else{
            counter1 = 0;
        }
    }
    Cube.Rotate(U);
    //if front is green
    if(current_cube[2][1][1] == COLOR::GREEN && current_cube[5][1][1] == COLOR::ORANGE && current_cube[4][1][1] == COLOR::BLUE && current_cube[3][1][1] == COLOR::RED){
        if(current_cube[2][0][2] == COLOR::GREEN || current_cube[2][0][0] == COLOR::GREEN){
            counter2+=1;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
            counter2+=2;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE || current_cube[5][0][0] == COLOR::ORANGE){
            counter2+=1;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            counter2+=2;
        }
        if(current_cube[5][0][2] == COLOR::BLUE || current_cube[5][0][0] == COLOR::BLUE){
            counter2+=1;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE && current_cube[5][0][2] == COLOR::BLUE){
            counter2+=2;
        }
        if(current_cube[3][0][2] == COLOR::RED || current_cube[3][0][0] == COLOR::RED){
            counter2+=1;
        }
        else if(current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
            counter2+=2;
        }
        else{
            counter2 = 0;
        }
    }
    Cube.Rotate(U);
    //if front is green
    if(current_cube[2][1][1] == COLOR::GREEN && current_cube[5][1][1] == COLOR::ORANGE && current_cube[4][1][1] == COLOR::BLUE && current_cube[3][1][1] == COLOR::RED){
        if(current_cube[2][0][2] == COLOR::GREEN || current_cube[2][0][0] == COLOR::GREEN){
            counter3+=1;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
            counter3+=2;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE || current_cube[5][0][0] == COLOR::ORANGE){
            counter3+=1;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            counter3+=2;
        }
        if(current_cube[5][0][2] == COLOR::BLUE || current_cube[5][0][0] == COLOR::BLUE){
            counter3+=1;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE && current_cube[5][0][2] == COLOR::BLUE){
            counter3+=2;
        }
        if(current_cube[3][0][2] == COLOR::RED || current_cube[3][0][0] == COLOR::RED){
            counter3+=1;
        }
        else if(current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
            counter3+=2;
        }
        else{
            counter3 = 0;
        }
    }
    Cube.Rotate(U);
    //if front is green
    if(current_cube[2][1][1] == COLOR::GREEN && current_cube[5][1][1] == COLOR::ORANGE && current_cube[4][1][1] == COLOR::BLUE && current_cube[3][1][1] == COLOR::RED){
        if(current_cube[2][0][2] == COLOR::GREEN || current_cube[2][0][0] == COLOR::GREEN){
            counter4+=1;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
            counter4+=2;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE || current_cube[5][0][0] == COLOR::ORANGE){
            counter4+=1;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            counter4+=2;
        }
        if(current_cube[5][0][2] == COLOR::BLUE || current_cube[5][0][0] == COLOR::BLUE){
            counter4+=1;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE && current_cube[5][0][2] == COLOR::BLUE){
            counter4+=2;
        }
        if(current_cube[3][0][2] == COLOR::RED || current_cube[3][0][0] == COLOR::RED){
            counter4+=1;
        }
        else if(current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
            counter4+=2;
        }
        else{
            counter4 = 0;
        }
    }
    int maximum = std::max(std::max(std::max(counter1,counter2), counter3), counter4);
    return maximum;
}
void::Algo::Corner_cubies_solver(Cube& cube){
    COLOR_cube current_cube = cube.getCube();
    int value = -10;
    if(Max_corners_sum(cube) > value){
        COLOR ce = current_cube[2][0][2];//надо ли для всех пар граней смотреть??!?!
        COLOR fe = current_cube[4][0][0];
        COLOR ke = current_cube[5][0][2];
        COLOR ze = current_cube[2][0][0];
        COLOR pe = current_cube[3][0][2];
        if(ce != fe){ //или while.....
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);

        }
        if(fe!=ze || fe!= pe){//или в один а if объединить...
            if(fe!=ze || fe!= pe){
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
        }
    }
}
