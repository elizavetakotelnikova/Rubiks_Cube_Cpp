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


