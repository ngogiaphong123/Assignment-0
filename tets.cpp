int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3) {
    //Complete this function to gain point on task 3
    if (!((E3 >= 200 && E3 <= 299) || (E3 >= 100 && E3 <= 199))) return -999;
    else {
        HP1 = ceil(HP1 * 1.4);
        HP2 = ceil(HP2 * 1.6);
    }
    if (HP1 > 1000) HP1 = 1000;
    if (HP2 > 1000) HP2 = 1000;
    if (ID1 == 1) {
        HP1 = HP1 * 2;
        if (HP1 > 1000) HP1 = 1000;
    }
    if (E3 >= 200 && E3 <= 299) {
        if (ID2 == 0) HP2 = ceil(HP2 * 95.0 / 100);
        return 0;
    }
    else if (ID1 == 1) {
        if (ID2 == 0) {
            HP2 = 0;
            return 1;
        }
        else if (ID2 == 2) return 0;
    }
    else if (ID1 == 0 && ID2 == 2) {
        return -1;
    }
    else if (E3 >= 100 && E3 <= 199) {
        int firstHP1 = HP1;
        if (ID2 == 0) {
            int xHP1 = HP1;
            HP2 = ceil(HP2 * 95.0 / 100);
            int u = ceil((2.0 * HP1 * HP2) / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(xHP1 - u);
            if (HP1 < 0) HP1 = 0;
            if (HP2 < 0) HP2 = 0;
            if (HP1 == HP2) return 0;
            else if (HP1 > HP2) return 1;
            else if (HP1 < HP2) {
                HP1 = firstHP1;
                return -1;
            }

        }
        else if (ID2 == 2) {
            int xHP1 = HP1;
            int u = ceil((2.0 * HP1 * HP2) / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(xHP1 - u);
            if (HP1 < 0) HP1 = 0;
            if (HP2 < 0) HP2 = 0;
            if (HP1 == HP2) return 0;
            else if (HP1 > HP2) return 1;
            else if (HP1 < HP2) {
                HP1 = firstHP1;
                return -1;
            }
        }
    }
    else return -999;
    return -1;
}