#include "Algo.h"

bool Algo::isCross(COLOR color, int index, Cube &cube) {
    face_cube current_face = cube.getFace(index);
    int center = current_face[1][1];
    if (current_face[0][1] == center && current_face[1][2] == center)
        if (current_face[2][1] == center && current_face[1][0] == center) {
            return true;
        }
    return false;
}

bool Algo::isRightWhiteCross(Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
    if (current_cube[5][2][1] == COLOR::ORANGE && current_cube[2][2][1] == COLOR::GREEN)
        if (current_cube[3][2][1] == COLOR::RED && current_cube[4][2][1] == COLOR::BLUE) {
            return true;
        }
    return false;
}


bool Algo::matchCenter(int a, int center) {
    if (a == center) {
        return true;
    }
    return false;
}


void Algo::makeWhiteCross(Cube &cube) {
    int counter = 0;
    COLOR_cube current_cube = cube.getCube();
    while (!isCross(WHITE, 1, cube)) {
        if (current_cube[0][1][0] == COLOR::WHITE) {
            int ce = current_cube[3][0][1]; //current edge
            std::queue<int> Q;
            Q.push(3);
            Q.push(4);
            Q.push(5);
            Q.push(2);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
            //counter++;
        }

        if (current_cube[0][0][1] == COLOR::WHITE) {
            int ce = current_cube[4][0][1];
            //std::queue<int> Q = {4, 5, 2, 3};
            std::queue<int> Q;
            Q.push(4);
            Q.push(5);
            Q.push(2);
            Q.push(3);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
            //counter++;
        }

        if (current_cube[0][1][2] == COLOR::WHITE) {
            int ce = current_cube[5][0][1]; //current edge
            //std::queue<int> Q = {5, 2, 3, 4};
            std::queue<int> Q;
            Q.push(5);
            Q.push(2);
            Q.push(3);
            Q.push(4);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
            //counter++;
        }

        if (current_cube[0][2][1] == COLOR::WHITE) {
            int ce = current_cube[2][0][1]; //current edge
            //std::queue<int> Q = {5, 2, 3, 4};
            std::queue<int> Q;
            Q.push(2);
            Q.push(3);
            Q.push(4);
            Q.push(5);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
            //counter++;
        }

        if (current_cube[2][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][2][1]; //current edge
            //std::queue<int> Q = {2, 3, 4, 5};
            std::queue<int> Q;
            Q.push(2);
            Q.push(3);
            Q.push(4);
            Q.push(5);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce); //когда ставлю SetEdgeFront вместо SetEdge, все ломается, но это правильно..
            //counter++;
        }
        //if (counter == 4) { break; }


        if (current_cube[3][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][1][0]; //current edge
            //std::queue<int> Q = {3, 4, 5, 2};
            std::queue<int> Q;
            Q.push(3);
            Q.push(4);
            Q.push(5);
            Q.push(2);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
            counter++;
        }

        //if (counter == 4) { break; }

        if (current_cube[4][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][0][1]; //current edge
            std::cout << ce;
            //std::queue<int> Q = {4, 5, 2, 3};
            std::queue<int> Q;
            Q.push(4);
            Q.push(5);
            Q.push(2);
            Q.push(3);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            std::cout << fc << " " << ce << " ";
            SetEdgeFront(fc, cube, ce);
            //counter++;
        }

        //if (counter == 4) { break; }

        if (current_cube[5][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][1][2]; //current edge
            //std::queue<int> Q = {5, 2, 3, 4};
            std::queue<int> Q;
            Q.push(5);
            Q.push(2);
            Q.push(3);
            Q.push(4);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
            //counter++;
        }

        //if (counter == 4) { break; }

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

            if (current_cube[2][2][1] == COLOR::WHITE) {
                cube.Rotate(F2);
            }

            if (current_cube[3][2][1] == COLOR::WHITE) {
                cube.Rotate(L2);
            }

            if (current_cube[4][2][1] == COLOR::WHITE) {
                cube.Rotate(B2);
            }

            if (current_cube[5][2][1] == COLOR::WHITE) {
                cube.Rotate(R2);
            }
        }
        cube.printCube();
        //counter++;
        if (counter == 1) {
            break;
        }
    }
}

void Algo::SetEdge(int fc, Cube& Cube, int ce) {
    if (fc == COLOR::RED) {
        Cube.Rotate(L2);
    }
    else if (fc == COLOR::BLUE) {
        Cube.Rotate(B2);
    }
    else if (fc == COLOR::ORANGE) {
        Cube.Rotate(R2);
    }
    else {
        Cube.Rotate(F2);
    }
}

void Algo::SetEdgeFront(int fc, Cube& Cube, int ce) {
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
    else if (fc == COLOR::BLUE) {
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(B); //check please
        Cube.Rotate(Lprime);
    }
    else {
        Cube.Rotate(F);
        Cube.Rotate(Dprime);
        Cube.Rotate(R);
        Cube.Rotate(D);
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
    while (!isSolvedMiddleLayer(current_cube)) {
        int ce = current_cube[0][0][1];
        int fe = current_cube[4][0][1];
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
        if (!isSolvedMiddleLayer(current_cube)) {
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

void Algo::Solve(Cube& Cube) {
    makeWhiteCross(Cube);
    firstLayerSolver(Cube);
    MiddleLayer(Cube);
    yellowCrossSolver(Cube);
    SolveYellowFace(Cube);
    cornerCubiesSolver(Cube);
    highCornersCorrectPos(Cube);
} //переименовать надо все

bool::Algo::isSolvedFirstLayer(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    if(current_cube[1][0][0] == COLOR::WHITE && current_cube[1][0][1] == COLOR::WHITE && current_cube[1][0][2] == COLOR::WHITE && current_cube[1][1][0] == COLOR::WHITE && current_cube[1][1][1] == COLOR::WHITE && current_cube[1][1][2] == COLOR::WHITE && current_cube[1][2][0] == COLOR::WHITE && current_cube[1][2][1] == COLOR::WHITE && current_cube[1][2][2] == COLOR::WHITE){
        if(current_cube[2][1][1] == COLOR::GREEN && current_cube[2][2][0] == COLOR::GREEN && current_cube[2][2][1] == COLOR::GREEN && current_cube[2][2][2] == COLOR::GREEN){
            if(current_cube[4][1][1] == COLOR::BLUE && current_cube[4][2][0] == COLOR::BLUE && current_cube[4][2][1] == COLOR::BLUE && current_cube[4][2][2] == COLOR::BLUE){
                if(current_cube[3][1][1] == COLOR::RED && current_cube[3][2][0] == COLOR::RED && current_cube[3][2][1] == COLOR::RED && current_cube[3][2][2] == COLOR::RED){
                    if(current_cube[5][1][1] == COLOR::ORANGE && current_cube[5][2][0] == COLOR::ORANGE && current_cube[5][2][1] == COLOR::ORANGE && current_cube[5][2][2] == COLOR::ORANGE){
                        return true;
                    }
                }
            }
        }
    }
    return false;

}

void::Algo::firstLayerSolver(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    while (!isSolvedFirstLayer(Cube)) {
        //if front side is green
        if (current_cube[2][0][2] == COLOR::GREEN && current_cube[2][1][1] == COLOR::GREEN) {
            if (current_cube[0][2][2] == COLOR::ORANGE && current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[5][0][0] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE) {
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(Rprime);
                }
            }
        } else if (current_cube[2][0][2] == COLOR::WHITE && current_cube[2][1][1] == COLOR::GREEN) {
            if (current_cube[0][2][2] == COLOR::GREEN && current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][1][1] == COLOR::ORANGE) {
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(F);
                }
            }
        } else if (current_cube[2][0][2] == COLOR::ORANGE && current_cube[2][1][1] == COLOR::GREEN) {
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
        } else if (current_cube[3][0][2] == COLOR::WHITE && current_cube[3][1][1] == COLOR::RED) {
            if (current_cube[0][2][0] == COLOR::RED && current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[2][0][0] == COLOR::GREEN && current_cube[2][1][1] == COLOR::GREEN) {
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(L);
                }
            }
        } else if (current_cube[3][0][2] == COLOR::GREEN && current_cube[3][1][1] == COLOR::RED) {
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
        } else if (current_cube[4][0][2] == COLOR::WHITE && current_cube[4][1][1] == COLOR::BLUE) {
            if (current_cube[0][0][0] == COLOR::BLUE && current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[3][0][0] == COLOR::RED && current_cube[3][1][1] == COLOR::RED) {
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(B);
                }
            }
        } else if (current_cube[4][0][2] == COLOR::RED && current_cube[4][1][1] == COLOR::BLUE) {
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
        } else if (current_cube[5][0][2] == COLOR::WHITE && current_cube[5][1][1] == COLOR::ORANGE) {
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
        else {
            //если углы белой стороны внизу не белые(не на своих местах)
            if (current_cube[1][0][0] != COLOR::WHITE || current_cube[1][0][2] != COLOR::WHITE ||
                current_cube[1][2][0] != COLOR::WHITE || current_cube[1][2][2] != COLOR::WHITE) {
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
    if(!isSolvedFirstLayer(Cube)){
    std::cout << "First layer did not solved clearly!";
    }
}

bool Algo::isYellowCross(Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
    if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW &&
        current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW) {
        return true;
    }
    return false;
}


void::Algo::yellowCrossSolver(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    while(!isYellowCross(Cube)) {
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


int::Algo::maxCornersSum(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    int counter1, counter2, counter3, counter4 = 0;
    //if front is green
        if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
            counter1+=2;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
            counter1+=1;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
            counter1+=2;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
            counter1+=1;
        }
        if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
            counter1+=2;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
            counter1+=1;
        }
        if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
            counter1+=2;
        }
        else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
            counter1+=1;
        }
        else{
            counter1 = 0;
        }

    Cube.Rotate(U);
    //if front is green
        if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
            counter2+=2;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
            counter2+=1;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
            counter2+=2;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
            counter2+=1;
        }
        if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
            counter2+=2;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
            counter2+=1;
        }
        if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
            counter2+=2;
        }
        else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
            counter2+=1;
        }
        else{
            counter2 = 0;
        }

    Cube.Rotate(U);
    //if front is green

        if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
            counter3+=2;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
            counter3+=1;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
            counter3+=2;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
            counter3+=1;
        }
        if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
            counter3+=2;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
            counter3+=1;
        }
        if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
            counter3+=2;
        }
        else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
            counter3+=1;
        }
        else{
            counter3 = 0;
        }

    Cube.Rotate(U);
    //if front is green
        if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
            counter4+=2;
        }
        else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
            counter4+=1;
        }
        if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
            counter4+=2;
        }
        else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
            counter4+=1;
        }
        if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
            counter4+=2;
        }
        else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
            counter4+=1;
        }
        if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
            counter4+=2;
        }
        else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
            counter4+=1;
        }
        else{
            counter4 = 0;
        }
    Cube.Rotate(U);
    int maximum = std::max(std::max(std::max(counter1,counter2), counter3), counter4);
    if(maximum == counter1){
        return 1;
    }
    else if(maximum == counter2){
        return 2;
    }
    else if(maximum == counter3){
        return 3;
    }
    else if(maximum == counter4){
        return 4;
    }
}

bool::Algo::highCornersCorrectPos(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    if(current_cube[2][1][1] == COLOR::GREEN &&current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
        if(current_cube[5][1][1] == COLOR::ORANGE &&current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            if(current_cube[3][1][1] == COLOR::RED &&current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
                if(current_cube[4][1][1] == COLOR::BLUE &&current_cube[4][0][0] == COLOR::BLUE && current_cube[4][0][2] == COLOR::BLUE){
                     return true;
                }
            }
        }
    }
    return false;
}

void::Algo::cornerCubiesSolver(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    //if(Max_corners_sum(Cube) == 1){
     //   Cube.Rotate(U);
    //}
    if(maxCornersSum(Cube) == 2){
        Cube.Rotate(U);
    }
    else if(maxCornersSum(Cube) == 3){
        Cube.Rotate(U);
        Cube.Rotate(U);
    }
    else if(maxCornersSum(Cube) == 4){
        Cube.Rotate(U);
        Cube.Rotate(U);
        Cube.Rotate(U);
    }
    else{//не знаю надо ли в случае 1 типо писать эти 4 поворота, что в целом бесмысленно, лучше вообще может это else не писать?
        Cube.Rotate(U);
        Cube.Rotate(U);
        Cube.Rotate(U);
        Cube.Rotate(U);
    }
    while(!highCornersCorrectPos(Cube)){
        if (current_cube[2][1][1] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN && current_cube[4][0][0] == COLOR::BLUE){//а не зел, гол, зел? тогда может еще противополож центр в условие дописать(ту то есть про голубой)
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);
        }
        else if (current_cube[5][1][1] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE && current_cube[3][0][0] == COLOR::RED){//ор,кр,ор
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(U);
        }
        else if (current_cube[4][1][1] == COLOR::BLUE && current_cube[4][0][2] == COLOR::BLUE && current_cube[2][0][0] == COLOR::GREEN){//гол,зел,гол
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(U);
        }
        else if (current_cube[3][1][1] == COLOR::RED && current_cube[3][0][2] == COLOR::RED && current_cube[5][0][0] == COLOR::ORANGE){//кр,ор,кр
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(U);
        }
    }

}

void::Algo::solvedSides(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    if(current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW){//не уверена, что это надо?!?!
        if(current_cube[3][0][1] == COLOR::ORANGE && current_cube[2][0][1] == COLOR::RED && current_cube[5][0][1] == COLOR::GREEN){
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(R);
        }
        else if(current_cube[3][0][1] == COLOR::GREEN && current_cube[2][0][1] == COLOR::ORANGE && current_cube[5][0][1] == COLOR::RED){
            Cube.Rotate(R);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
        }
        else if(current_cube[3][0][1] == COLOR::BLUE && current_cube[4][0][1] == COLOR::RED && current_cube[2][0][1] == COLOR::ORANGE && current_cube[5][0][1] == COLOR::GREEN){
            Cube.Rotate(R);
            Cube.Rotate(Bprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(B);
            Cube.Rotate(F);
            Cube.Rotate(Rprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(F);
            Cube.Rotate(Rprime);
            Cube.Rotate(B);
            Cube.Rotate(R);
            Cube.Rotate(F);
            Cube.Rotate(F);
            Cube.Rotate(U);
        }
        else if(current_cube[3][0][1] == COLOR::ORANGE && current_cube[5][0][1] == COLOR::RED && current_cube[2][0][1] == COLOR::BLUE && current_cube[4][0][1] == COLOR::GREEN){
            Cube.Rotate(R);
            Cube.Rotate(R);
            Cube.Rotate(L);
            Cube.Rotate(L);
            Cube.Rotate(D);
            Cube.Rotate(R);
            Cube.Rotate(R);
            Cube.Rotate(L);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(R);
            Cube.Rotate(L);
            Cube.Rotate(L);
            Cube.Rotate(D);
            Cube.Rotate(R);
            Cube.Rotate(R);
            Cube.Rotate(L);
            Cube.Rotate(L);
        }
    }

}


