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


bool Algo::matchCenter(COLOR a, COLOR center) {
    if (a == center) {
        return true;
    }
    return false;
}


void Algo::makeWhiteCross(Cube &cube) {
     int counter = 0;
     COLOR_cube current_cube = cube.getCube();
     while (counter != 4) {
         if (current_cube[0][1][0] == COLOR::WHITE) {
             COLOR ce = current_cube[3][0][1]; //current edge
             std::queue<int> Q;
             Q.push(3);
             Q.push(4);
             Q.push(5);
             Q.push(2);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdge(fc, cube, ce);
             counter++;
         }

         if (current_cube[0][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[4][0][1];
             //std::queue<int> Q = {4, 5, 2, 3};
             std::queue<int> Q;
             Q.push(4);
             Q.push(5);
             Q.push(2);
             Q.push(3);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdge(fc, cube, ce);
             counter++;
         }

         if (current_cube[0][1][2] == COLOR::WHITE) {
             COLOR ce = current_cube[5][0][1]; //current edge
             //std::queue<int> Q = {5, 2, 3, 4};
             std::queue<int> Q;
             Q.push(5);
             Q.push(2);
             Q.push(3);
             Q.push(4);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdge(fc, cube, ce);
             counter++;
         }

         if (current_cube[2][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[0][2][1]; //current edge
             //std::queue<int> Q = {2, 3, 4, 5};
             std::queue<int> Q;
             Q.push(2);
             Q.push(3);
             Q.push(4);
             Q.push(5);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdge(fc, cube, ce);
             counter++;
         }
         if (counter == 4) { break; }

         if (current_cube[2][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[0][2][1]; //current edge
             //std::queue<int> Q = {2, 3, 4, 5};
             std::queue<int> Q;
             Q.push(2);
             Q.push(3);
             Q.push(4);
             Q.push(5);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdgeFront(fc, cube, ce);
             counter++;
         }
         if (counter == 4) { break; }

         if (current_cube[3][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[0][1][0]; //current edge
             //std::queue<int> Q = {3, 4, 5, 2};
             std::queue<int> Q;
             Q.push(3);
             Q.push(4);
             Q.push(5);
             Q.push(2);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdgeFront(fc, cube, ce);
             counter++;
         }

         if (counter == 4) { break; }

         if (current_cube[4][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[0][0][1]; //current edge
             //std::queue<int> Q = {4, 5, 2, 3};
             std::queue<int> Q;
             Q.push(4);
             Q.push(5);
             Q.push(2);
             Q.push(3);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdgeFront(fc, cube, ce);
             counter++;
         }

         if (counter == 4) { break; }

         if (current_cube[5][0][1] == COLOR::WHITE) {
             COLOR ce = current_cube[0][1][2]; //current edge
             //std::queue<int> Q = {5, 2, 3, 4};
             std::queue<int> Q;
             Q.push(5);
             Q.push(2);
             Q.push(3);
             Q.push(4);
             int i = Q.front();
             Q.pop();
             COLOR fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cube[i][1][1];
             }
             SetEdgeFront(fc, cube, ce);
             counter++;
         }

         if (counter == 4) { break; }

         else {
             if (current_cube[5][1][0] == COLOR::WHITE) {
                 cube.Rotate(Fprime);
             }

             if (current_cube[5][1][2] == COLOR::WHITE) {
                 cube.Rotate(Bprime);
             }

             if (current_cube[3][1][2] == COLOR::WHITE) {
                 cube.Rotate(F);
             }

             if (current_cube[3][1][0] == COLOR::WHITE) {
                 cube.Rotate(B);
             }

             if (current_cube[2][1][2] == COLOR::WHITE) {
                 cube.Rotate(R);
             }

             if (current_cube[2][1][0] == COLOR::WHITE) {
                 cube.Rotate(Lprime);
             }

             if (current_cube[4][1][2] == COLOR::WHITE) {
                 cube.Rotate(L);
             }

             if (current_cube[4][1][0] == COLOR::WHITE) {
                 cube.Rotate(Rprime);
             }
         }
     }
}

void Algo::SetEdge(COLOR fc, Cube& Cube, COLOR ce) {
    if (fc == COLOR::RED) {
        Cube.Rotate(L2);
    }
    else if (fc == COLOR::BLUE) {
        Cube.Rotate(B2);
    }
    else if (ce == COLOR::ORANGE) {
        Cube.Rotate(R2);
    }
    else {
        Cube.Rotate(F2);
    }
}

void Algo::SetEdgeFront(COLOR fc, Cube& Cube, COLOR ce) {
    if (fc == COLOR::GREEN) { //should be checked, I am not sure
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(Fprime);
        Cube.Rotate(Lprime);
    }
    else if (fc == COLOR::RED) {
        Cube.Rotate(U);
        Cube.Rotate(Bprime); //or back?
        Cube.Rotate(Lprime);
        Cube.Rotate(B);
    }
    else if (ce == COLOR::BLUE) {
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(B); //check please
        Cube.Rotate(Lprime);
    }
    else {
        Cube.Rotate(U);
        Cube.Rotate(Bprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(B);
    }
}

void Algo::phase_one(Cube &Cube, Cubie & mini_cube) {
    COLOR_cube current_cube = Cube.getCube();

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

/*void TransferRight(Cube& Cube) {
    Cube.Rotate()
}*/

bool Algo::isSolvedMiddleLayer(COLOR_cube &cube) {
    for (int i = 2; i < 6; i++) {
        if (!(cube[i][1][0] == cube[i][1][1] && cube[i][1][1] == cube[i][1][2])) {
            return false;
        }
        if (!(cube[i][2][0] == cube[i][2][1] && cube[i][2][1] == cube[i][2][2])) {
            return false;
        }
    }
    return true;
}

void Algo::fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube& Cube) {
    if (current_cube[2][1][2] != COLOR::YELLOW && current_cube[5][1][0] != COLOR::YELLOW) {
        Cube.Rotate(F);
        Cube.Rotate(U);
        Cube.Rotate(F);
        Cube.Rotate(U);
        Cube.Rotate(F);
        Cube.Rotate(Uprime);
        Cube.Rotate(Fprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Fprime);
    }
    if (current_cube[5][1][2] != COLOR::YELLOW && current_cube[4][1][0] != COLOR::YELLOW) {
        Cube.Rotate(Lprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Lprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Lprime);
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(U);
        Cube.Rotate(L);
    }
    if (current_cube[4][1][2] != COLOR::YELLOW && current_cube[3][1][0] != COLOR::YELLOW) {
        Cube.Rotate(B);
        Cube.Rotate(Uprime);
        Cube.Rotate(B);
        Cube.Rotate(Uprime);
        Cube.Rotate(B);
        Cube.Rotate(U);
        Cube.Rotate(B);
        Cube.Rotate(U);
        Cube.Rotate(B);
    }
    if (current_cube[3][1][2] != COLOR::YELLOW && current_cube[2][1][0] != COLOR::YELLOW) {
        Cube.Rotate(Rprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(U);
        Cube.Rotate(R);
    }
}

void Algo::MiddleLayer(Cube& Cube) {
    COLOR_cube current_cube = Cube.getCube();
    std::queue<int> Q;
    while (!isSolvedSecondLayer(current_cube)) {
        COLOR ce = current_cube[0][0][1];
        COLOR fe = current_cube[4][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::RED && fe == COLOR::BLUE) {
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
            }
            else if (ce == COLOR::ORANGE && fe == COLOR::BLUE) {
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
            }
            else {
                if (fe == COLOR::RED) {
                    Cube.Rotate(Uprime);
                }
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(U2);
                }
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(U);
                }
            }
        }
        ce = current_cube[0][1][0];
        fe = current_cube[3][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::GREEN && fe == COLOR::RED) {
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime); //check Lprime or L
                Cube.Rotate(Lprime);
            }
            else if (ce == COLOR::BLUE && fe == COLOR::RED) {
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(L);
            }
            else {
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(U2);
                }
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(Uprime);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U);
                }
            }
        }
        ce = current_cube[0][2][1];
        fe = current_cube[2][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::ORANGE && fe == COLOR::GREEN) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
            }
            else if (ce == COLOR::RED && fe == COLOR::GREEN) {
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
            }
            else {
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(Uprime);
                }
                if (fe == COLOR::RED) {
                    Cube.Rotate(U);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U2);
                }
            }
        }
        ce = current_cube[0][1][1];
        fe = current_cube[5][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::BLUE && fe == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
            }
            else if (ce == COLOR::GREEN && fe == COLOR::ORANGE) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
            }
            else {
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(Uprime);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U);
                }
                if (fe == COLOR::RED) {
                    Cube.Rotate(U2);
                }
            }
        }
        if (!isSolvedSecondLayer(current_cube)) {
            if (current_cube[0][0][1] != COLOR::YELLOW && current_cube[4][0][1] != COLOR::YELLOW) {
                continue;
            }
            if (current_cube[0][1][1] != COLOR::YELLOW && current_cube[5][0][1] != COLOR::YELLOW) {
                continue;
            }
            if (current_cube[0][2][1] != COLOR::YELLOW && current_cube[2][0][1] != COLOR::YELLOW) {
                continue;
            }
            if (current_cube[0][1][0] != COLOR::YELLOW && current_cube[3][0][1] != COLOR::YELLOW) {
                continue;
            }
            else {
                fixWrongSecondLayerEdges(current_cube, Cube);
            }
        }
    }
}

void Algo::phase_three(Cube &Cube, Cubie & mini_cube) {
    COLOR_cube current_cube = Cube.getCube();
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

bool Algo::IsSolvedYellow(Cube & Cube) {
    COLOR_cube current_cube = Cube.getCube();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (current_cube[0][i][j] != COLOR::YELLOW) {
                return false;
            }
        }
    }
    return true;
}

void Algo::SolveYellowFace(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    if (IsSolvedYellow(Cube)) {
        return;
    }
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW &&
            current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[2][0][1] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) { //здесь же пофиг на передние ребра?
                Cube.Rotate(R2);
                Cube.Rotate(B);
                Cube.Rotate(Rprime);
                Cube.Rotate(U2);
                Cube.Rotate(R);
                Cube.Rotate(Bprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
            }
        }
    }
    else if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(L);
                Cube.Rotate(F);
                Cube.Rotate(R);
                Cube.Rotate(Fprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(F);
            }
        }
    }
    else if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
                if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(F);
                    Cube.Rotate(R);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(L);
                    Cube.Rotate(F);
                }
            }
        }
    }
    else if (current_cube[0][0][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                    Cube.Rotate(U2);
                    Cube.Rotate(Rprime);
                }
            }
        }
    }
    else if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[3][0][0] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(R);
                    Cube.Rotate(U2);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(R);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Rprime);
                }
            }
        }
    }
    else if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[0][0][2] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW) {
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(R2);
            Cube.Rotate(Uprime);
            Cube.Rotate(R2);
            Cube.Rotate(Uprime);
            Cube.Rotate(R2);
            Cube.Rotate(U2);
            Cube.Rotate(R);
        }
    }
    else if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
        }
    }
}



