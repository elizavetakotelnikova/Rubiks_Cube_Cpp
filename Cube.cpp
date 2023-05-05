#include "Cube.h"

Cube::Cube() {
    std::memset(co, 0, sizeof(co));
    std::memset(eo, 0, sizeof(eo));
    for (int i = 0; i < 8; i++) {
        cp[i] = i;
    }
    for (int i = 0; i < 12; i++) {
        ep[i] = i;
    }
    centers[0] = COLOR::RED;
    centers[1] = COLOR::BLUE;
    centers[2] = COLOR::WHITE;
    centers[3] = COLOR::GREEN;
    centers[4] = COLOR::YELLOW;
    centers[5] = COLOR::ORANGE;
}

void Cube::Read(const char* filename) {
    std::ifstream File;
    File.open(filename, std::ios::in);
    for (int i = 0; i < 8; i++) {
        File >> cp[i] >> co[i];
    }
    for (int i = 0; i < 12; i++) {
        File >> ep[i] >> eo[i];
    }
    std::cout << "Cube's state was successfully read from the file " << std::endl;
}

void Cube::Generate() {
    for (int i = 0; i++; i < 6) {
        for (int j = 0; j++; j < 3) {
            for (int k = 0; k++; k < 3) {
                sides[i][j][k] = rand() % 6;
            }
        }
    }
}

bool Cube::Check() {
    for (int i = 0; i < 8; i++) {
        if ((cp[i] != i) or (co[i] != 0))
            return false;
    }
    for (int i = 0; i < 12; i++) {
        if ((ep[i] != i) or (eo[i] != 0))
            return false;
    }
    return true;
}

void Cube::PrintCube() {
    std::cout << "Corners' position and orientation:\n";
    for (int i = 0; i < 8; i++)
        std::cout << cp[i] << ' ' << co[i] << std::endl;
    std::cout << "Edges' position and orientation:\n";
    for (int i = 0; i < 12; ++i)
        std::cout << ep[i] << ' ' << eo[i] << std::endl;
}

void Cube::Write() {
    std::string filename = "Current_state.txt";
    std::ofstream File;
    File.open(filename, std::ios::out);
    for (int i = 0; i < 8; i++)
        File << cp[i] << ' ' << co[i] << std::endl;
    for (int i = 0; i < 12; i++)
        File << ep[i] << ' ' << eo[i] << std::endl;
    std::cout << "Cube's state was successfully wrote to the file " << filename << std::endl;
}

Cube& Cube::operator=(const Cube& a){
    for (int i = 0; i < 8; i++){
        cp[i] = a.cp[i];
        co[i] = a.co[i];
    }
    for (int i = 0; i < 12; i++){
        ep[i] = a.ep[i];
        eo[i] = a.eo[i];
    }
    return *this;
}

bool Cube::operator==(const Cube& a){
    for (int i = 0; i < 8; i++) {
        if (cp[i] != a.cp[i] || co[i] != a.co[i])
            return false;
    }
    for (int i = 0; i < 12; i++) {
        if (ep[i] != a.ep[i] || eo[i] != a.eo[i])
            return false;
    }
    return true;
}

void Cube::Up(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[ULF];
        cp[ULF] = cp[URF];
        cp[URF] = cp[URB];
        cp[URB] = cp[ULB];
        cp[ULB] = tmp;

        tmp = co[ULF];
        co[ULF] = co[URF];
        co[URF] = co[URB];
        co[URB] = co[ULB];
        co[ULB] = tmp;

        tmp = ep[UL];
        ep[UL] = ep[UF];
        ep[UF] = ep[UR];
        ep[UR] = ep[UB];
        ep[UB] = tmp;

        tmp = eo[UL];
        eo[UL] = eo[UF];
        eo[UF] = eo[UR];
        eo[UR] = eo[UB];
        eo[UB] = tmp;
    }

    //return *this;
}

/**
 * Up prime.
 */
void Cube::UpPrime(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[ULB];
        cp[ULB] = cp[URB];
        cp[URB] = cp[URF];
        cp[URF] = cp[ULF];
        cp[ULF] = tmp;

        tmp = co[ULB];
        co[ULB] = co[URB];
        co[URB] = co[URF];
        co[URF] = co[ULF];
        co[ULF] = tmp;

        tmp = ep[UB];
        ep[UB] = ep[UR];
        ep[UR] = ep[UF];
        ep[UF] = ep[UL];
        ep[UL] = tmp;

        tmp = eo[UB];
        eo[UB] = eo[UR];
        eo[UR] = eo[UF];
        eo[UF] = eo[UL];
        eo[UL] = tmp;

    }
}

/**
 * Up 2.
 */
/*  RubiksCube& RubiksCubeIndexModel::u2()
  {
    swap(this->corners[(unsigned)CORNER::ULB], this->corners[(unsigned)CORNER::URF]);
    swap(this->corners[(unsigned)CORNER::URB], this->corners[(unsigned)CORNER::ULF]);
    swap(this->edges[(unsigned)EDGE::UB],      this->edges[(unsigned)EDGE::UF]);
    swap(this->edges[(unsigned)EDGE::UR],      this->edges[(unsigned)EDGE::UL]);
    return *this;
  }
*/
/**
 * Left.
 */
void Cube::Left(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DLB];
        cp[DLB] = cp[DLF];
        cp[DLF] = cp[ULF];
        cp[ULF] = cp[ULB];
        cp[ULB] = tmp;

        tmp = co[DLB];
        co[DLB] = (co[DLF] + 1) % 3;
        co[DLF] = (co[ULF] + 2) % 3;
        co[ULF] = (co[ULB] + 1) % 3;
        co[ULB] = (tmp + 2) % 3;

        tmp = ep[BL];
        ep[BL] = ep[DL];
        ep[DL] = ep[FL];
        ep[FL] = ep[UL];
        ep[UL] = tmp;

        tmp = eo[BL];
        eo[BL] = eo[DL];
        eo[DL] = eo[FL];
        eo[FL] = eo[UL];
        eo[UL] = tmp;
    }
}

/*this->updateCornerOrientation(CORNER::DLB, 1);
this->updateCornerOrientation(CORNER::DLF, 2);
this->updateCornerOrientation(CORNER::ULF, 1);
this->updateCornerOrientation(CORNER::ULB, 2); ???/
return *this;
}
/**
* Left prime.
*/
void Cube::LeftPrime(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DLB];
        cp[DLB] = cp[ULB];
        cp[ULB] = cp[ULF];
        cp[ULF] = cp[DLF];
        cp[DLF] = tmp;

        tmp = co[DLB];
        co[DLB] = (co[DLF] + 1) % 3;
        co[DLF] = (co[ULF] + 2) % 3;
        co[ULF] = (co[ULB] + 1) % 3;
        co[ULB] = (tmp + 2) % 3;

        tmp = ep[BL];
        ep[BL] = ep[UL];
        ep[UL] = ep[FL];
        ep[FL] = ep[DL];
        ep[DL] = tmp;

        tmp = eo[BL];
        eo[BL] = eo[UL];
        eo[UL] = eo[FL];
        eo[FL] = eo[DL];
        eo[DL] = tmp;

        /*this->updateCornerOrientation(CORNER::DLB, 1);
        this->updateCornerOrientation(CORNER::DLF, 2);
        this->updateCornerOrientation(CORNER::ULF, 1);
        this->updateCornerOrientation(CORNER::ULB, 2);
        return *this;*/
    }
}

/**
 * Left 2.
 */
/*RubiksCube& RubiksCubeIndexModel::l2()
{
  swap(this->corners[(unsigned)CORNER::DLB], this->corners[(unsigned)CORNER::ULF]);
  swap(this->corners[(unsigned)CORNER::ULB], this->corners[(unsigned)CORNER::DLF]);
  swap(this->edges[(unsigned)EDGE::BL],      this->edges[(unsigned)EDGE::FL]);
  swap(this->edges[(unsigned)EDGE::UL],      this->edges[(unsigned)EDGE::DL]);
  return *this;
}*/

/**
 * Front.
 */

void Cube::Front(int amount) {
    for(int i = 0; i < amount; i++){
        int8_t  tmp = cp[ULF];
        cp[ULF] = cp[DLF];
        cp[DLF] = cp[DRF];
        cp[DRF] = cp[URF];
        cp[URF] = tmp;


        tmp = co[ULF];
        co[ULF] = (co[URF] + 2) % 3;
        co[URF] = (co[DRF] + 1) % 3;
        co[DRF] = (co[DLF] + 2) % 3;
        co[DLF] = (tmp + 1) % 3;

        tmp = ep[UF];
        ep[UF] = ep[FL];
        ep[FL] = ep[DF];
        ep[DF] = ep[FR];
        ep[FR] = tmp;

        tmp = eo[UF];
        eo[UF] =  1 - eo[FL];
        eo[FL] =  1 - eo[DF];
        eo[DF] =  1 - eo[FR];
        eo[FR] =  1 - tmp;

    }
}
/*RubiksCube& RubiksCubeIndexModel::f()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = hold;

    this->updateCornerOrientation(CORNER::ULF, 2);
    this->updateCornerOrientation(CORNER::URF, 1);
    this->updateCornerOrientation(CORNER::DRF, 2);
    this->updateCornerOrientation(CORNER::DLF, 1);

    this->updateEdgeOrientationZ(EDGE::UF);
    this->updateEdgeOrientationZ(EDGE::FL);
    this->updateEdgeOrientationZ(EDGE::DF);
    this->updateEdgeOrientationZ(EDGE::FR);

    return *this;
}*/

/**
 * Front prime.
 */

void Cube::FrontPrime(int amount) {
    for(int i = 0; i < amount; i++){
        int8_t  tmp = cp[ULF];
        cp[ULF] = cp[URF];
        cp[URF] = cp[DRF];
        cp[DRF] = cp[DLF];
        cp[DLF] = tmp;

        tmp = co[ULF];
        co[ULF] = (co[URF] + 2) % 3;
        co[URF] = (co[DRF] + 1) % 3;
        co[DRF] = (co[DLF] + 2) % 3;
        co[DLF] = (tmp + 1) % 3;

        tmp = ep[UF];
        ep[UF] = ep[FL];
        ep[FL] = ep[DF];
        ep[DF] = ep[FR];
        ep[FR] = tmp;

        tmp = ep[UF];
        ep[UF] =  1 - ep[FL];
        ep[FL] =  1 - ep[DF];
        ep[DF] =  1 - ep[FR];
        ep[FR] =  1 - tmp;
    }
}
/*RubiksCube& RubiksCubeIndexModel::fPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = hold;

    this->updateCornerOrientation(CORNER::ULF, 2);
    this->updateCornerOrientation(CORNER::URF, 1);
    this->updateCornerOrientation(CORNER::DRF, 2);
    this->updateCornerOrientation(CORNER::DLF, 1);

    this->updateEdgeOrientationZ(EDGE::UF);
    this->updateEdgeOrientationZ(EDGE::FL);
    this->updateEdgeOrientationZ(EDGE::DF);
    this->updateEdgeOrientationZ(EDGE::FR);

    return *this;
}*/

/**
 * Front 2.
 */
/*RubiksCube& RubiksCubeIndexModel::f2()
{
    swap(this->corners[(unsigned)CORNER::ULF], this->corners[(unsigned)CORNER::DRF]);
    swap(this->corners[(unsigned)CORNER::URF], this->corners[(unsigned)CORNER::DLF]);

    swap(this->edges[(unsigned)EDGE::UF],      this->edges[(unsigned)EDGE::DF]);
    swap(this->edges[(unsigned)EDGE::FL],      this->edges[(unsigned)EDGE::FR]);

    return *this;
}*/

/**
 * Right.
 */

void Cube::Right(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DRB];
        cp[DRB] = cp[URB];
        cp[URB] = cp[URF];
        cp[URF] = cp[DRF];
        cp[DRF] = tmp;

        tmp = co[DRB];
        co[DRB] = (co[DRF] + 2) % 3;
        co[DRF] = (co[URF] + 1) % 3;
        co[URF] = (co[URB] + 2) % 3;
        co[URB] = (tmp + 1) % 3;

        tmp = ep[BR];
        ep[BR] = ep[UR];
        ep[UR] = ep[FR];
        ep[FR] = ep[DR];
        ep[DR] = tmp;

        tmp = ep[BR];
        ep[BR] = ep[UR];
        ep[UR] = ep[FR];
        ep[FR] = ep[DR];
        ep[DR] = tmp;
    }
}
/*RubiksCube& RubiksCubeIndexModel::r()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = hold;

    this->updateCornerOrientation(CORNER::DRB, 2);
    this->updateCornerOrientation(CORNER::DRF, 1);
    this->updateCornerOrientation(CORNER::URF, 2);
    this->updateCornerOrientation(CORNER::URB, 1);

    return *this;
}*/

/**
 * Right prime.
 */


void Cube::RightPrime(int amount){
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DRB];
        cp[DRB] = cp[DRF];
        cp[DRF] = cp[URF];
        cp[URF] = cp[URB];
        cp[URB] = tmp;

        tmp = co[DRB];
        co[DRB] = (co[DRF] + 2) % 3;
        co[DRF] = (co[URF] + 1) % 3;
        co[URF] = (co[URB] + 2) % 3;
        co[URB] = (tmp + 1) % 3;

        tmp = ep[BR];
        ep[BR] = ep[DR];
        ep[DR] = ep[FR];
        ep[FR] = ep[UR];
        ep[UR] = tmp;

        tmp = ep[BR];
        ep[BR] = ep[DR];
        ep[DR] = ep[FR];
        ep[FR] = ep[UR];
        ep[UR] = tmp;

    }
}


/*RubiksCube& RubiksCubeIndexModel::rPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = hold;

    this->updateCornerOrientation(CORNER::DRB, 2);
    this->updateCornerOrientation(CORNER::DRF, 1);
    this->updateCornerOrientation(CORNER::URF, 2);
    this->updateCornerOrientation(CORNER::URB, 1);

    return *this;
}*/

/**
 * Right 2.
 */
/*RubiksCube& RubiksCubeIndexModel::r2()
{
  swap(this->corners[(unsigned)CORNER::DRB], this->corners[(unsigned)CORNER::URF]);
  swap(this->corners[(unsigned)CORNER::URB], this->corners[(unsigned)CORNER::DRF]);
  swap(this->edges[(unsigned)EDGE::BR],      this->edges[(unsigned)EDGE::FR]);
  swap(this->edges[(unsigned)EDGE::UR],      this->edges[(unsigned)EDGE::DR]);
  return *this;
}*/

/**
 * Back.
 */

void Cube::Back(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[ULB];
        cp[ULB] = cp[URB];
        cp[URB] = cp[DRB];
        cp[DRB] = cp[DLB];
        cp[DLB] = tmp;

        tmp = co[ULB];
        co[ULB] = (co[URB] + 1) % 3;
        co[URB] = (co[DRB] + 2) % 3;
        co[DRB] = (co[DLB] + 1) % 3;
        co[DLB] = (tmp + 2) % 3;

        tmp = ep[UB];
        ep[UB] = ep[BR];
        ep[BR] = ep[DB];
        ep[DB] = ep[BL];
        ep[BL] = tmp;

        tmp = eo[UB];
        eo[UB] =  1 - eo[BL];
        eo[BL] =  1 - eo[DB];
        eo[DB] =  1 - eo[BR];
        eo[BR] =  1 - tmp;

    }
}
/*RubiksCube& RubiksCubeIndexModel::b()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = hold;

    this->updateCornerOrientation(CORNER::ULB, 1);
    this->updateCornerOrientation(CORNER::URB, 2);
    this->updateCornerOrientation(CORNER::DRB, 1);
    this->updateCornerOrientation(CORNER::DLB, 2);

    this->updateEdgeOrientationZ(EDGE::UB);
    this->updateEdgeOrientationZ(EDGE::BL);
    this->updateEdgeOrientationZ(EDGE::DB);
    this->updateEdgeOrientationZ(EDGE::BR);

    return *this;
}*/

/**
 * Back prime.
 */

void Cube::BackPrime(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[ULB];
        cp[ULB] = cp[DLB];
        cp[DLB] = cp[DRB];
        cp[DRB] = cp[URB];
        cp[URB] = tmp;

        tmp = co[ULB];
        co[ULB] = (co[URB] + 1) % 3;
        co[URB] = (co[DRB] + 2) % 3;
        co[DRB] = (co[DLB] + 1) % 3;
        co[DLB] = (tmp + 2) % 3;

        tmp = ep[UB];
        ep[UB] = ep[BL];
        ep[BL] = ep[DB];
        ep[DB] = ep[BR];
        ep[BR] = tmp;

        tmp = eo[UB];
        eo[UB] = 1 - eo[BL];
        eo[BL] = 1 - eo[DB];
        eo[DB] = 1 - eo[BR];
        eo[BR] = 1 - tmp;

    }
}

/*RubiksCube& RubiksCubeIndexModel::bPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = hold;

    this->updateCornerOrientation(CORNER::ULB, 1);
    this->updateCornerOrientation(CORNER::URB, 2);
    this->updateCornerOrientation(CORNER::DRB, 1);
    this->updateCornerOrientation(CORNER::DLB, 2);

    this->updateEdgeOrientationZ(EDGE::UB);
    this->updateEdgeOrientationZ(EDGE::BL);
    this->updateEdgeOrientationZ(EDGE::DB);
    this->updateEdgeOrientationZ(EDGE::BR);

    return *this;
}*/

/**
 * Back 2.
 */
/* RubiksCube& RubiksCubeIndexModel::b2()
 {
   swap(this->corners[(unsigned)CORNER::ULB], this->corners[(unsigned)CORNER::DRB]);
   swap(this->corners[(unsigned)CORNER::URB], this->corners[(unsigned)CORNER::DLB]);
   swap(this->edges[(unsigned)EDGE::UB],      this->edges[(unsigned)EDGE::DB]);
   swap(this->edges[(unsigned)EDGE::BL],      this->edges[(unsigned)EDGE::BR]);
   return *this;
 }*/

/**
 * Down.
 */

void Cube::Down(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DLB];
        cp[DLB] = cp[DRB];
        cp[DRB] = cp[DRF];
        cp[DRF] = cp[DLF];
        cp[DLF] = tmp;

        tmp = co[DLB];
        co[DLB] = co[DRB];
        co[DRB] = co[DRF];
        co[DRF] = co[DLF];
        co[DLF] = tmp;


        tmp = ep[DB];
        ep[DB] = ep[DR];
        ep[DR] = ep[DF];
        ep[DF] = ep[DL];
        ep[DL] = tmp;

        tmp = eo[DB];
        eo[DB] = eo[DR];
        eo[DR] = eo[DF];
        eo[DF] = eo[DL];
        eo[DL] = tmp;

    }
}
/*RubiksCube& RubiksCubeIndexModel::d()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = hold;

    return *this;
}*/

/**
 * Down prime.
 */

void Cube::DownPrime(int amount) {
    for (int i = 0; i < amount; i++) {
        int8_t tmp = cp[DLF];
        cp[DLF] = cp[DRF];
        cp[DRF] = cp[DRB];
        cp[DRB] = cp[DLB];
        cp[DLB] = tmp;

        tmp = co[DLF];
        co[DLF] = co[DRF];
        co[DRF] = co[DRB];
        co[DRB] = co[DLB];
        co[DLB] = tmp;


        tmp = ep[DL];
        ep[DL] = ep[DF];
        ep[DF] = ep[DR];
        ep[DR] = ep[DB];
        ep[DB] = tmp;

        tmp = eo[DL];
        eo[DL] = eo[DF];
        eo[DF] = eo[DR];
        eo[DR] = eo[DB];
        eo[DB] = tmp;

    }
}
/*RubiksCube& RubiksCubeIndexModel::dPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = hold;

    return *this;
}*/

/**
 * Down 2.
 */
/*RubiksCube& RubiksCubeIndexModel::d2()
{
    swap(this->corners[(unsigned)CORNER::DLB], this->corners[(unsigned)CORNER::DRF]);
    swap(this->corners[(unsigned)CORNER::DRB], this->corners[(unsigned)CORNER::DLF]);

    swap(this->edges[(unsigned)EDGE::DB],      this->edges[(unsigned)EDGE::DF]);
    swap(this->edges[(unsigned)EDGE::DR],      this->edges[(unsigned)EDGE::DL]);

    return *this;
}*/


COLOR Cube::getColor(FACE face, unsigned int row, unsigned int col) {
    return COLOR::RED;
}

/*void Cube::rotateCube(char command, int amount){
    switch (command){
        case 'F':
            rotFront(amount);
            break;
        case 'R':
            rotRight(amount);
            break;
        case 'U':
            rotUp(amount);
            break;
        case 'B':
            rotBack(amount);
            break;
        case 'L':
            rotLeft(amount);
            break;
        case 'D':
            rotDown(amount);
    }
}*/
