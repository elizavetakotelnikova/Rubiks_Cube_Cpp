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
    for (int i = 0; i < 12; i++ {
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
        co[ULF] = co[URB];
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
   void Cube::UPrime(int amount) {
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
          co[DLB] = (co[DLF] + 2) % 3;
          co[DLF] = (co[ULF] + 1) % 3;
          co[ULF] = (co[ULB] + 2) % 3;
          co[ULB] = (tmp + 1) % 3;
          
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
  void Cube::LeftPrime() {
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
  RubiksCube& RubiksCubeIndexModel::f()
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
  }

  /**
   * Front prime.
   */
  RubiksCube& RubiksCubeIndexModel::fPrime()
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
  }

  /**
   * Front 2.
   */
  RubiksCube& RubiksCubeIndexModel::f2()
  {
    swap(this->corners[(unsigned)CORNER::ULF], this->corners[(unsigned)CORNER::DRF]);
    swap(this->corners[(unsigned)CORNER::URF], this->corners[(unsigned)CORNER::DLF]);

    swap(this->edges[(unsigned)EDGE::UF],      this->edges[(unsigned)EDGE::DF]);
    swap(this->edges[(unsigned)EDGE::FL],      this->edges[(unsigned)EDGE::FR]);

    return *this;
  }

  /**
   * Right.
   */
  RubiksCube& RubiksCubeIndexModel::r()
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
  }

  /**
   * Right prime.
   */
  RubiksCube& RubiksCubeIndexModel::rPrime()
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
  }

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
  RubiksCube& RubiksCubeIndexModel::b()
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
  }

  /**
   * Back prime.
   */
  RubiksCube& RubiksCubeIndexModel::bPrime()
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
  }

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
  RubiksCube& RubiksCubeIndexModel::d()
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
  }

  /**
   * Down prime.
   */
  RubiksCube& RubiksCubeIndexModel::dPrime()
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
  }

  /**
   * Down 2.
   */
  RubiksCube& RubiksCubeIndexModel::d2()
  {
    swap(this->corners[(unsigned)CORNER::DLB], this->corners[(unsigned)CORNER::DRF]);
    swap(this->corners[(unsigned)CORNER::DRB], this->corners[(unsigned)CORNER::DLF]);

    swap(this->edges[(unsigned)EDGE::DB],      this->edges[(unsigned)EDGE::DF]);
    swap(this->edges[(unsigned)EDGE::DR],      this->edges[(unsigned)EDGE::DL]);

    return *this;
  }
  
void Cube::RotateUp (int amount){
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp_cp = cp[URF];
        cp[urf] = cp[ubr];
        cp[ubr] = cp[ulb];
        cp[ulb] = cp[ufl];
        cp[ufl] = tmp_cp;

        int8_t tmp_co = co[urf];
        co[urf] = co[ubr];
        co[ubr] = co[ulb];
        co[ulb] = co[ufl];
        co[ufl] = tmp_co;

        int8_t tmp_eo = eo[ub];
        eo[ub] = eo[ul];
        eo[ul] = eo[uf];
        eo[uf] = eo[ur];
        eo[ur] = tmp_eo;

        int tmp_edge = ep[ub];
        ep[ub] = ep[ul];
        ep[ul] = ep[uf];
        ep[uf] = ep[ur];
        ep[ur] = tmp_edge;
    }
}

void Cube::RotateDown(int amount){
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp_cp = cp[dfr];
        cp[dfr] = cp[dlf];
        cp[dlf] = cp[dbl];
        cp[dbl] = cp[drb];
        cp[drb] = tmp_cp;

        int8_t tmp_co = co[dfr];
        co[dfr] = co[dlf];
        co[dlf] = co[dbl];
        co[dbl] = co[drb];
        co[drb] = tmp_co;

        int8_t tmp_eo = eo[df];
        eo[df] = eo[dl];
        eo[dl] = eo[db];
        eo[db] = eo[dr];
        eo[dr] = tmp_eo;

        int tmp_ep = ep[df];
        ep[df] = ep[dl];
        ep[dl] = ep[db];
        ep[db] = ep[dr];
        ep[dr] = tmp_ep;
    }
}

void Cube::RotateLeft(int amount) {
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp_cp = cp[dlf];
        cp[dlf] = cp[ufl];
        cp[ufl] = cp[ulb];
        cp[ulb] = cp[dbl];
        cp[dbl] = tmp_cp;

        int8_t tmp_co = co[dlf];
        co[dlf] = (1 + co[ufl]) % 3;
        co[ufl] = (2 + co[ulb]) % 3;
        co[ulb] = (1 + co[dbl]) % 3;
        co[dbl] = (2 + tmp_co) % 3;

        int8_t tmp_eo = eo[bl];
        eo[bl] = eo[dl];
        eo[dl] = eo[fl];
        eo[fl] = eo[ul];
        eo[ul] = tmp_eo;

        int tmp_ep = ep[bl];
        ep[bl] = ep[dl];
        ep[dl] = ep[fl];
        ep[fl] = ep[ul];
        ep[ul] = tmp_ep;
    }
}

void Cube::RotateRight(int amount) {
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp_cp = cp[urf];
        cp[urf] = cp[dfr];
        cp[dfr] = cp[drb];
        cp[drb] = cp[ubr];
        cp[ubr] = tmp_cp;

        int8_t tmp_co = co[urf];
        co[urf] = (1 + co[dfr]) % 3;
        co[dfr] = (2 + co[drb]) % 3;
        co[drb] = (1 + co[ubr]) % 3;
        co[ubr] = (2 + tmp_co) % 3;

        int8_t tmp_eo = eo[fr];
        eo[fr] = eo[dr];
        eo[dr] = eo[br];
        eo[br] = eo[ur];
        eo[ur] = tmp_eo;

        int tmp_ep = ep[fr];
        ep[fr] = ep[dr];
        ep[dr] = ep[br];
        ep[br] = ep[ur];
        ep[ur] = tmp_ep;
    }
}

void Cube::RotateFront(int amount) {
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp = cp[urf];
        cp[urf] = cp[ufl];
        cp[ufl] = cp[dlf];
        cp[dlf] = cp[dfr];
        cp[dfr] = tmp;

        int8_t tmp_co = co[urf];
        co[urf] = (2 + co[ufl]) % 3;
        co[ufl] = (1 + co[dlf]) % 3;
        co[dlf] = (2 + co[dfr]) % 3;
        co[dfr] = (1 + tmp_co) % 3;

        int8_t tmp_eo = eo[uf];
        eo[uf] = 1 - eo[fl];
        eo[fl] = 1 - eo[df];
        eo[df] = 1 - eo[fr];
        eo[fr] = 1 - tmp_eo;

        int tmp_ep = ep[uf];
        ep[uf] = ep[fl];
        ep[fl] = ep[df];
        ep[df] = ep[fr];
        ep[fr] = tmp_ep;
    }
}

void Cube::RotateBack(int amount) {
    if (amount == -1)
        amount = 3;
    for (int i = 0; i < amount; i++){
        int tmp = cp[ulb];
        cp[ulb] = cp[ubr];
        cp[ubr] = cp[drb];
        cp[drb] = cp[dbl];
        cp[dbl] = tmp;

        int8_t tmp_co = co[ulb];
        co[ulb] = (2 + co[ubr]) % 3;
        co[ubr] = (1 + co[drb]) % 3;
        co[drb] = (2 + co[dbl]) % 3;
        co[dbl] = (1 + tmp_co) % 3;

        int8_t tmp_eo = eo[br];
        eo[br] = 1 - eo[db];
        eo[db] = 1 - eo[bl];
        eo[bl] = 1 - eo[ub];
        eo[ub] = 1 - tmp_eo;

        int tmp_ep = ep[br];
        ep[br] = ep[db];
        ep[db] = ep[bl];
        ep[bl] = ep[ub];
        ep[ub] = tmp_ep;
    }
}

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

