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
     counter = 0;
     COLOR_cube current_cube = cube.getCube();
     while (counter != 4) {
         if (current_cube[0][1][0] == WHITE) {
             ce = current_cube[3][0][1]; //current edge
             std::queue<int> Q = {3, 4, 5, 2};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdge(fc);
             counter++;
         }

         if (current_cube[0][0][1] == WHITE) {
             ce = current_cube[4][0][1];
             std::queue<int> Q = {4, 5, 2, 3};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdge(fc);
             counter++;
         }

         if (current_cube[0][1][2] == WHITE) {
             ce = current_cube[5][0][1]; //current edge
             std::queue<int> Q = {5, 2, 3, 4};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdge(fc);
             counter++;
         }

         if (current_cube[2][0][1] == WHITE) {
             ce = current_cube[0][2][1]; //current edge
             std::queue<int> Q = {2, 3, 4, 5};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdge(fc);
             counter++;
         }
         if (counter == 4) { break; }

         if (current_cube[2][0][1] == WHITE) {
             ce = current_cube[0][2][1]; //current edge
             std::queue<int> Q = {2, 3, 4, 5};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdgeFront(fc);
             counter++;
         }
         if (counter == 4) { break; }

         if (current_cube[3][0][1] == WHITE) {
             ce = current_cube[0][1][0]; //current edge
             std::queue<int> Q = {3, 4, 5, 2};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdgeFront(fc);
             counter++;
         }

         if (counter == 4) { break; }

         if (current_cube[4][0][1] == WHITE) {
             ce = current_cube[0][0][1]; //current edge
             std::queue<int> Q = {4, 5, 2, 3};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdgeFront(fc);
             counter++;
         }

         if (counter == 4) { break; }

         if (current_cube[5][0][1] == WHITE) {
             ce = current_cube[0][1][2]; //current edge
             std::queue<int> Q = {5, 2, 3, 4};
             i = Q.front();
             Q.pop();
             fc = current_cube[i][1][1]; //face color
             while (!matchCenter(ce, fc)) {
                 Cube.Rotate(U);
                 i = Q.front();
                 Q.pop();
                 fc = current_cune[i][1][1];
             }
             SetEdgeFront(fc);
             counter++;
         }

         if (counter == 4) { break; }

         else {
             if (edge[5][1][0] == WHITE) {
                 Cube.Rotate(Fprime);
             }

             if (edge[5][1][2] == WHITE) {
                 Cube.Rotate(Bprime);
             }

             if (edge[3][1][2] == WHITE) {
                 Cube.Rotate(F);
             }

             if (edge[3][1][0] == WHITE) {
                 Cube.Rotate(B);
             }

             if (edge[2][1][2] == WHITE) {
                 Cube.Rotate(R);
             }

             if (edge[2][1][0] == WHITE) {
                 Cube.Rotate(Lprime);
             }

             if (edge[4][1][2] == WHITE) {
                 Cube.Rotate(L);
             }

             if (edge[4][1][0] == WHITE) {
                 Cube.Rotate(Rprime);
             }
         }
     }
}

void Algo::SetEdge(COLOR fc) {
    if (fc == RED) {
        Cube.Rotate(L2);
    }
    else if (fc == BLUE) {
        Cube.Rotate(B2);
    }
    else if (ce == ORANGE) {
        Cube.Rotate(R2);
    }
    else {
        Cube.Rotate(F2);
    }
}

void Algo::SetEdgeFront(COLOR fc) {
    if (fc == GREEN) { //should be checked, I am not sure
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(Fprime);
        Cube.Rotate(Lprime);
    }
    else if (fc == RED) {
        Cube.Rotate(U);
        Cube.Rotate(Backprime); //or back?
        Cube.Rotate(Lprime);
        Cube.Rotate(Back);
    }
    else if (ce == BLUE) {
        Cube.Rotate(U);
        Cube.Rotate(L);
        Cube.Rotate(Back); //check please
        Cube.Rotate(Lprime);
    }
    else {
        Cube.Rotate(U);
        Cube.Rotate(Backprime);
        Cube.Rotate(RightPrime);
        Cube.Rotate(Back);
    }
}




