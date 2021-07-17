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
// Ham kiem tra snt

bool checksnt (int n)
{
    if (n < 2) 
    {
        return false;
    }
    if (n==2)
    {
        return true;
    }
    if (n%2==0)
    {
        return false;
    }
    for ( int i =3 ; i < (n -1); i = i +2 )
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true ;
}
int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    if(M > 1000) M=1000;
    if(M< 0)      M=0;
    if(HP > 1000) HP=1000;
    if(HP < 0)  HP=0;
    // Truong hop 1
    if (E1 <= 199 && E1 >=100)
    {
        int h=(E1-100)%64;
        int J=HP%100;
        // No king && No commander
        if(ID==0)
        {
            if (J>h)
            {
                if(M >= 300 && HP >= 500 && M%2==1)
                {
                    HP=HP+50;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-300;
                    return HP + M;
                }
                else if (M >= 200 && M %2==0)
                {
                    HP=HP+25;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-200;
                    return HP + M;
                }
                else return HP + M ;
            }
            else return HP + M;
        }
        // King && No commander
        else if (ID==1)
        {
            HP=HP+75;
            if(HP > 1000) HP=1000;
            if(HP < 0) HP=0;
            return HP + M;
        }
        // No king && commander
        else if (ID==2)
        {
            return HP + M;
        }
    }
    // Truong hop 2
    else if (E1 >= 200 && E1 <= 299)
    {
        int x = E1%4 +1 ;
        // No King && No commander
        if ( ID ==0 )
        {
            if (M%2==0)
            {
                if ( M >= 195 && x==2)
                {
                    HP=HP + 7;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-195;
                    return HP + M;
                }
                else if (M >= 205 && x==4)
                {
                    HP= HP + 11;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-205;
                    return HP + M;
                }
                else return HP + M;
            }
        
            
            if (M%2==1)
            {
                if ( M >= 190 && x==1)
                {
                    HP=HP +5;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-190;
                    return HP + M;
                }
                else if (M >=200 && x==3)
                {
                    HP=HP+9;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    M=M-200;
                    return HP + M;
                }
                else return HP + M;
            }
        }
        // King && commander
        if ( ID ==1 || ID ==2)
        {
            if ( x== 1 && M >= 190)
            {
                HP=HP +5;
                if(HP > 1000) HP=1000;
                if(HP < 0) HP=0;
                return HP + (M-190);
            }
            else if (x==2 && M >= 195)
            {
                HP=HP+7;
                if(HP > 1000) HP=1000;
                if(HP < 0) HP=0;
                return HP + (M-195);
            }
            else if (x==3 && M >= 200)
            {
                HP = HP + 9;
                if(HP > 1000) HP=1000;
                if(HP < 0) HP=0;
                return HP + (M-200);
            }
            else if (x==4 && M>= 205)
            {
                HP=HP+11;
                if(HP > 1000) HP=1000;
                if(HP < 0) HP=0;
                return HP + (M-205);
            }
            else return HP + M;
        }
    }
    
    // Truong hop 3
    else if (E1>= 300 && E1<= 399)
    {
        int a;
        int lastNumOfE1 = E1 % 10;
        int lastNumOfHP = HP % 10;
        if (checksnt(lastNumOfE1))
        {
            a=2*lastNumOfE1;
        }
        else
        {
            a=1;
        }
        if ( ID == 0 || ID == 2)
        {
            if (HP >= 600 )
            {
                if ( checksnt(lastNumOfHP) == true && M >= 500 )
                {
                    HP= ceil (HP + HP*2*a/100.0);
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    return HP + (M-500);
                }
                else if (checksnt(lastNumOfHP) == false && M >= 300)
                {
                    HP=ceil(HP + HP*a/100.0);
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    return HP + (M-300);
                }
                else return HP + M;
            }
            else return HP + M;
        }
        else if(ID == 1)
        {
            if (HP >= 600 )
            {
                if ( checksnt(lastNumOfHP) == true && M >= 500 )
                {
                    HP= HP +200;
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    return HP + (M-500);
                }
                else if (checksnt(lastNumOfHP) == false && M >= 300)
                {
                    HP=ceil (HP + HP*a/100.0);
                    if(HP > 1000) HP=1000;
                    if(HP < 0) HP=0;
                    return HP + (M-300);
                }
                else return HP + M;
            }
            else return HP + M;
        }
        else return HP + M;
    }
    // Truong hop 4
    else if (E1 >= 400 && E1 <= 499)
    {
        if (E1 % 5==0)
        {
            HP= ceil(HP*9/10.0);
            if(HP > 1000) HP=1000;
            if(HP < 0) HP=0;
            return HP + M;
        }
        else return HP + M;
    }
    // Truong hop 5
    else if (E1==500)
    {   
        HP=ceil(HP*75/100.0);
        if(HP > 1000) HP=1000;
        if(HP < 0) HP=0;
        M =ceil(M*75/100.0);
        return HP + M;
    }
    else return -999;
    return -1;
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2)
{
    // Complete this function to gain point on task 2
    // Tính HP 
    if (E2 > 499 || E2 < 100)
    {
        return -999;
    }
    
    else if ( E2 >= 100 && E2 <= 199)
    {
        HP1=ceil(HP1*11/10.0);
        HP2=ceil(HP2*13/10.0);
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
    }
    
    
    /* ------------------------- */
    else if ( E2 >= 200 && E2 <=299)
    {
        HP1=ceil(HP1*17/10.0);
        HP2=ceil(HP2*12/10.0);
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
    }


    /* ------------------------- */
    else if (E2 >= 300 && E2 <= 399)
    {
        if(E2 <350)
        {
            HP1=HP1+30;
        }    
        else HP1 = HP1 + E2%100;
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
    }


    /* ------------------------- */
    else if (E2 >= 400 && E2 <= 499)
    {
        HP1=ceil(HP1*13/10.0);
        HP2=ceil(HP2*8/10.0);
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        HP1=ceil(HP1*5/10.0);
    }

    //Hinh thuc chien dau
    if (ID1==0 && ID2==0 )
    {
        int temp = HP2;
        int u = ceil ((2*HP1*HP2)/(double(HP1+HP2)));
        HP2=HP2 - abs(HP1-u);
        HP1=HP1 - abs(temp-u);
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        if (HP1 > HP2 )
        {
            HP1=ceil(HP1*8/10.0);
            return 1;
        }
        if (HP1 == HP2)
        {
            HP1 =ceil(HP1*8/10.0);
            return 0;
        }
        if (HP1 < HP2)
        {
            HP1=ceil(HP1*8/10.0);
            return -1;
        }
    }
    else if(ID1==1 && ID2 ==2)
    {
        HP1=ceil(HP1*8/10.0);
        return 0;
    }
    else if(ID1==1 && ID2 ==0)
    {
        HP2=0;
        HP1=ceil(HP1*8/10.0);
        return 1;
    }
    else if (ID1==0 && ID2==2)
    {
        HP1=0;
        return -1;
    }
    return -1;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    if(E3 < 100 || E3 >299)
    {
        return -999;
    }
    else if(E3 >= 100 && E3 <=299)
    {
    HP1=ceil(HP1*14/10.0);
    HP2=ceil(HP2*16/10.0);
    if(ID1==1) HP1=HP1*2;
    }
    if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
    if ( HP1 < 0)
        {
            HP1 = 0;
        }
    if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
    if ( HP2 < 0)
        {
            HP2 = 0;
        }
    int v=HP1;
    // Tinh HP 
    if (E3 >= 100 && E3 <= 199)
    {
        if(ID2!=2)
        {
            HP2=ceil(HP2*95/100.0);
        }
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
    }

    /* ------------------------- */
    else if (E3 >= 200 && E3 <= 299)
    {
        if(ID2!=2)
        {
            HP2=ceil(HP2*95/100.0);
        }
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        return 0;
    }

    //Hinh thuc chien dau
    if (ID1==0 && ID2==0 )
    {
        int temp = HP2;
        int u = ceil((2*HP1*HP2)/(double(HP1+HP2)));
        HP2=HP2 - abs(HP1-u);
        HP1=HP1 - abs(temp-u);
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        if (HP1 > HP2 )
        {
            return 1;
        }
        if (HP1 == HP2)
        {
            return 0;
        }
        if (HP1 < HP2)
        {
            HP1=v;
            return -1;
        }
    }
    else if(ID1==1 && ID2 ==2)
    {
        return 0;
    }
    else if(ID1==1 && ID2 ==0)
    {
        HP2=0;
        return 1;
    }
    else if (ID1==0 && ID2==2)
    {
        HP1=v;
        return -1;
    }
    return -1;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    // Tinh HP
    if (E4 < 100 || E4 > 299)
    {
        return -999;
    }
    
    else if(E4 >= 100 && E4 <= 199)
    {
        if(ID2==2)
        {
            HP2=ceil(HP2*3/10.0);
        }
        if(ID2==0) 
        {
            HP2=ceil(HP2*1/10.0);
        }
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        return 0;
    }


    /* ------------------------- */
    else if(E4 >=200 && E4 <= 299)
    {
        if ( HP1 > 1000) 
        {
            HP1 = 1000;
        }
        if ( HP1 < 0)
        {
            HP1 = 0;
        }
        if ( HP2 > 1000) 
        {
            HP2 = 1000;
        }
        if ( HP2 < 0)
        {
            HP2 = 0;
        }
        HP2=0;
        return 1;
    }
    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */