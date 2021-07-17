/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
bool KTSNT(int socuoi)
{
    if (socuoi < 2)
        return false;
    for (int i = 2; i <= socuoi / 2; i++)
        if (socuoi % i == 0)
            return false;
    return true;
}
int getReady(int& HP, const int& ID, int& M, const int& E1) {
    if (HP > 1000) HP = 1000;
    if (HP < 0) HP = 0;
    if (M > 1000) M = 1000;
    if (M < 0) M = 0;
    if (E1 < 100 || E1 > 500) return -999;
    // truong hop 1 
    if (E1 >= 100 && E1 <= 199)
    {
        if (ID == 1)
            return (HP + 75) + M;
        if (ID == 2)
            return HP + M;
        if (ID == 0)
        {
            int j, h;
            j = HP % 100;
            h = (E1 - 100) % 64;
            if (j > h)
            {
                if (HP >= 500 && M % 2 != 0)
                {
                    if (M >= 300)
                    {
                        HP = HP + 50;
                        M = M - 300;
                    }
                    else return HP + M;
                }
                else  if (M % 2 == 0)
                {
                    if (M >= 200)
                    {
                        HP = HP + 25;
                        M = M - 200;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            return HP + M;
        }
    }

    // truong hop 2
    if (E1 >= 200 && E1 <= 299)
    {
        int x;
        x = E1 % 4 + 1;
        if (ID == 1 || ID == 2)
        {
            if (x == 1)
            {
                if (M >= 190)
                {
                    HP = HP + 5;
                    M = M - 190;
                }
                else return HP + M;
            }


            else if (x == 2)
            {
                if (M >= 195)
                {
                    HP = HP + 7;
                    M = M - 195;
                }
                else return HP + M;
            }
            else if (x == 3)
            {
                if (M >= 200)
                {
                    HP = HP + 9;
                    M = M - 200;
                }
                else return HP + M;
            }
            else if (x == 4)
            {
                if (M >= 205)
                {

                    HP = HP + 11;
                    M = M - 205;
                }
                else return HP + M;
            }
            else
            {
                HP = HP;
                M = M;
            }
            return HP + M;

        }
        if (ID == 0)
        {
            if (M % 2 != 0)
            {
                if (x == 1)
                {
                    if (M >= 190)
                    {
                        HP += 5;
                        M -= 190;
                    }
                    else return HP + M;
                }
                else if (x == 3)
                {
                    if (M >= 200)
                    {
                        HP += 9;
                        M -= 200;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            if (M % 2 == 0)
            {
                if (x == 2)
                {
                    if (M >= 195)
                    {
                        HP = HP + 7;
                        M = M - 195;
                    }
                }
                else if (x == 4)
                {
                    if (M >= 205)
                    {
                        HP = HP + 11;
                        M = M - 205;
                    }
                }
                else return HP + M;
            }
            return HP + M;
        }
    }


    // truong hop 3

    if (E1 >= 300 && E1 <= 399)
    {
        int a,socuoi,socuoi2;
        socuoi = E1   % 10;
        socuoi2 = HP % 10;
        if (1)
        {
            if (KTSNT(socuoi) == true)
            {
                a = socuoi * 2;
            }
            else
            {
                a = 1;
            }
        }
        if (HP >= 600)
        {


            if (KTSNT(socuoi2) == true)
            {
                if (M >= 500)
                {
                    HP = HP + ceil(HP * 2 * a / 100);
                    if (ID == 1) HP = HP + 200;
                    M = M - 500;
                }
                else return HP + M;
            }
            else
            {
                if (M >= 300)
                {
                    HP = HP + ceil(HP * a / 100);
                    M = M - 300;
                }
                else
                    return HP + M;
            }

            return HP + M;

        }
        else return HP + M;
        
       
    }

    // truong hop 4

    if (E1 >= 400 && E1 <= 499)
    {
        if (E1 % 5 == 0)
            return ceil(HP * 0.9 + M);
        else return HP + M;
    }

    // truong hop 5     
    if (E1 == 500)
    {
        return ceil(HP * 0.75 + M * 0.75);
    }
    return -1;
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2) {
    if (E2 < 100 || E2>499) return -999;


    // TRUONG HOP 1;
    if (E2 >= 100 && E2 <= 199)
    {
        HP1 = ceil(double(HP1) * 110 / 100);
        HP2 = ceil(double(HP2) * 130 / 100);
        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
    }
    // TRUONG HOP 2;
    if (E2 >= 200 && E2 <= 299)
    {
        HP1 = ceil(double(HP1) * 170 / 100);
        HP2 = ceil(double(HP2) * 120 / 100);
        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
    }
    // TRUONG HOP 3;
    if (E2 >= 300 && E2 <= 399)
    {
        if (E2 < 350)HP1 = HP1 + 30;
        else HP1 += E2 % 100;
        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
    }
    // TRUONG HOP 4;
    if (E2 >= 400 && E2 <= 499)
    {
        HP1 = ceil(double(HP1) * 130 / 100);
        HP2 = ceil(double(HP2) * 80 / 100);
        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
        if (1)
        {
            HP1 = ceil(double(HP1) * 50 / 100);
        }
    }
    if (ID1 == 0 && ID2 == 0)
    {
        int num = HP1;
        int u = ceil((2 * double(HP1) * HP2) / (HP1 + HP2));
        HP1 = HP1 - abs(HP2 - u);
        HP2 = HP2 - abs(num - u);
        if (HP1 < 0)
            HP1 = 0;
        if (HP2 < 0)
            HP2 = 0;
        if (HP1 > HP2)
        {
            HP1 =  ceil(double(HP1) *80 / 100);
            return 1;
        }
        if (HP1 == HP2)
        {
            HP1 = ceil(double(HP1) * 80 / 100);
            return 0;
        }
        if (HP2 > HP1)
        {
            HP1 =  ceil(double(HP1) * 80 / 100);
            return -1;
        }

    }
    if (ID1 == 1 && ID2 == 0)
    {
        HP1 = ceil(HP1 * 0.8);
        HP2 = 0;
        return 1;
    }
    if (ID1 == 1 && ID2 == 2)
    {
        HP1 = ceil(HP1 * 0.8);
        return 0;
    }
    if (ID1 == 0 && ID2 == 2)
    {
        HP1 = 0;
        return -1;
    }
    return -1;

}
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3) {
    if (E3 < 100 || E3>299) return -999;
    else {
        if (HP1 > 1000)
            HP1 = 1000;
        if (HP1 < 0)
            HP1 = 0;
        if (HP2 > 1000)
            HP2 = 1000;
        if (HP2 < 0)
            HP2 = 0;
        HP1 = ceil(double(HP1) * 140 / 100);
        HP2 = ceil(double(HP2) * 160 / 100);
        if (HP1 > 1000)
            HP1 = 1000;
        if (HP2 > 1000)
            HP2 = 1000;
        if (ID1 == 1)
            HP1 = 2 * HP1;
        if (HP1 > 1000)
            HP1 = 1000;
        if (E3 >= 100 && E3 <= 199)
        {
            if (ID2 == 0)   HP2 = ceil(double(HP2) * 95 / 100);
            if (ID1 == 0 && ID2 == 0)
            {
                int num = HP1;
                int u = ceil(2 * double(HP1) * HP2 / double(HP1 + HP2));
                HP1 = HP1 - abs(HP2 - u);
                HP2 = HP2 - abs(num - u);
                if (HP1 < 0)HP1 = 0;
                if (HP2 < 0)HP2 = 0;
                if (HP2 < HP1) return 1;
                if (HP2 == HP1) return 0;
                if (HP2 > HP1)
                {
                    HP1 = num;
                    return -1;
                }
            }
            if (ID1 == 0 && ID2 == 2)
            {
                int num = HP1;
                int u = ceil(2 * float(HP1) * HP2 / float(HP1 + HP2));
                HP1 = HP1 - abs(HP2 - u);
                HP2 = HP2 - abs(num - u);
                if (HP1 < 0)HP1 = 0;
                if (HP2 < 0)HP2 = 0;
                return -1;
            }
            if (ID1 == 1 && ID2 == 0)
            {
                int num = HP1;
                int u = ceil(2 * float(HP1) * HP2 / float(HP1 + HP2));
                HP1 = HP1 - abs(HP2 - u);
                HP2 = HP2 - abs(num - u);
                if (HP1 < 0)HP1 = 0;
                if (HP2 < 0)HP2 = 0;
                HP2 == 0;
                return 1;
            }
            if (ID1 == 1 && ID2 == 2)
            {
                return 0;
            }
        }
        if (E3 >= 200 && E3 <= 299)
        {
            if (ID2 == 0)
            {
                HP2 = ceil(double(HP2) * 95 / 100);
            }
            return 0;
        }
    }
    return -1;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4) {
    if (E4 < 100 || E4>299) return -999;

    /* truong hop 1  */
    if (E4 >= 100 && E4 <= 199)
    {
        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
        if (1)
        {
            if (ID2 == 0)   HP2 = ceil(double(HP2) * 10 / 100);
            else if (ID2 == 2)   HP2 = ceil(double(HP2) * 30 / 100);
        }
        return 0;

    }
    if (E4 >= 200 && E4 <= 299)
    {

        if (HP1 > 1000)HP1 = 1000;
        if (HP1 < 0)HP1 = 0;
        if (HP2 > 1000)HP2 = 1000;
        if (HP2 < 0)HP2 = 0;
        HP2 = 0;
        return 1;
    }
    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */