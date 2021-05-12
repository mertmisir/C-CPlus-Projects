#include <iostream>
#include"Header.h"
#include<time.h>
#include<cmath>

using namespace std;

void startGame(Grid& g, int size) {
    int a = 0;
    char c=NULL;
    srand(time_t(NULL));
    if (size >= 5) {
        FullBodyBone fb1;
        SkullBone sb1;
        OrdinaryBone ob1;
        BurgerFood bf1;
        NuggetFood nf1;
        ChipsFood cf1;
        Water w1;
        MedicalSupplies ms1;
        Trap t1;
        int NeighborIndex1;
        int NeighborIndex2;
        a = floor((size * size) / 25);

        g.boardPlay[0][0].setResourceType('P');  // in order to prevent player's location to have resource
        g.boardPlay[size-1][size-1].setResourceType('K');

        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            NeighborIndex1 = -1 + rand() % 2;
            NeighborIndex2 = -1 + rand() % 2;
            if (NeighborIndex2 == 0 && NeighborIndex1 == 0) {
                c = 'x';
            }
            else
                c = 'y';
            if ((g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL && g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2].getResourceType() == NULL) && ((RandIndex1 + 1) < size && (RandIndex2 + 1) < size) && ((RandIndex1 - 1) >= 0 && (RandIndex2 - 1) >= 0) && c != 'x') {
                g.boardPlay[RandIndex1][RandIndex2] = fb1;
                 g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2] = fb1;
            }
            else
                i--;
            

        }
        for (int i = 0;i <a;i++) {

            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            NeighborIndex1 = -1 + rand() % 2;
            NeighborIndex2 = -1 + rand() % 2;
            if (NeighborIndex2 == 0 && NeighborIndex1 == 0) {
                c = 'x';
            }
            else
                c = 'y';
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL && g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2].getResourceType() == NULL && (RandIndex1 + 1) < size && (RandIndex2 + 1) < size && (RandIndex1 - 1) >= 0 && (RandIndex2 - 1) >= 0 && c!='x') {
                g.boardPlay[RandIndex1][RandIndex2] = bf1;
                g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2] = bf1;
            }
            else
                i--;
            

        }
        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            NeighborIndex1 = -1 + rand() % 2;
            NeighborIndex2 = -1 + rand() % 2;
            if (NeighborIndex2 == 0 && NeighborIndex1 == 0) {
                c = 'x';
            }
            else
                c = 'y';
            if ((g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL && g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2].getResourceType() == NULL) && ((RandIndex1 + 1) < size && (RandIndex2 + 1) < size) && ((RandIndex1 - 1) >= 0 && (RandIndex2 - 1) >= 0) && c != 'x') {
                g.boardPlay[RandIndex1][RandIndex2] = nf1;
                g.boardPlay[RandIndex1 + NeighborIndex1][RandIndex2 + NeighborIndex2] = nf1;
            }
            else
                i--;
            


        }
        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = sb1;
            else
                i--;
            
            
        }
        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = ob1;
            else
                i--;
           
        }


        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = cf1;
            else
                i--;
            
        }
        for (int i = 0;i < (a+1);i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = w1;
            else
                i--;
            

        }
        for (int i = 0;i < (a+1);i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = t1;
            else
                i--;
            
        }
        for (int i = 0;i < a;i++) {
            int RandIndex1 = rand() % size;
            int RandIndex2 = rand() % size;
            if (g.boardPlay[RandIndex1][RandIndex2].getResourceType() == NULL)
                g.boardPlay[RandIndex1][RandIndex2] = ms1;
            else
                i--;
            
        }
        /*for (int o = 0;o < size;o++) {
            cout << endl;
            for (int m = 0;m < size;m++) {                //////////////////////////CHEATING THE GAME !!!!!!!!!!!!!!!!
                cout << g.boardPlay[o][m].getResourceType();
            }
        }*/
    }
    else
        cout << "WRONG SIZE";
}


int rollDice() {
    int dice;
    dice = 1+rand() % 6;
    return dice;
}


void play(Archeologist& player1,Grid& g,int size) {
    player1.setPlayerEnegery(player1.getPlayerEnergy() - 1);
    int x1, x2, flag1=0;
    cout << "Enter coordinate1 : ";
    cin >> x1;
    cout << "Enter coordinate2 : ";
    cin >> x2;
    if (x1 == 0 && x2 == 0) {
        cout << "WRONG COORDINATE";
        flag1 = 1;
    }
    if (x1 == (size-1) && x2 == (size-1)) {
        cout << "WRONG COORDINATE";
        flag1 = 1;
    }
    while (flag1 == 1) {
        cout << "Enter coordinate1 : ";
        cin >> x1;
        cout << "Enter coordinate2 : ";
        cin >> x2;
        if (x1 == 0 && x2 == 0) {
            cout << "WRONG COORDINATE";
            flag1 = 1;
        }
        else if (x1 == (size - 1) && x2 == (size - 1)) {
            cout << "WRONG COORDINATE";
            flag1 = 1;
        }
        else {
            flag1 = 0;
            break;
        }      
    }
    int dic;
    dic = rollDice();
    cout << "YOUR NEW DICE IS : " << dic << endl;
    
    player1.setDiceValue(dic);
    player1.setListOfGatheredResources(g.boardPlay[x1][x2]);
    g.boardPlay[x1][x2].setResourceType(NULL);
    if (dic == 6) {
        if ((x1 - 1) >= 0) {
            player1.setListOfGatheredResources(g.boardPlay[x1 - 1][x2]);
            g.boardPlay[x1 - 1][x2].setResourceType(NULL);
        }
        if ((x1 - 1) >= 0 && (x2 - 1) >= 0) {
            player1.setListOfGatheredResources(g.boardPlay[x1 - 1][x2-1]);
            g.boardPlay[x1 - 1][x2-1].setResourceType(NULL);
        }
        if ((x1 + 1) < size) {
            player1.setListOfGatheredResources(g.boardPlay[x1 + 1][x2]);
            g.boardPlay[x1 + 1][x2].setResourceType(NULL);
        }
        if ((x1 + 1) < size && (x2 + 1) < size) {
            player1.setListOfGatheredResources(g.boardPlay[x1 + 1][x2+1]);
            g.boardPlay[x1 + 1][x2+1].setResourceType(NULL);
        }
        if ((x1 - 1) >= 0 && (x2 + 1) < size) {
            player1.setListOfGatheredResources(g.boardPlay[x1 - 1][x2+1]);
            g.boardPlay[x1 - 1][x2+1].setResourceType(NULL);
        }
        if ((x1 + 1) < size && (x2 - 1) >= 0) {
            player1.setListOfGatheredResources(g.boardPlay[x1 + 1][x2-1]);
            g.boardPlay[x1 + 1][x2-1].setResourceType(NULL);
        }
        if ((x2 + 1) < size) {
            player1.setListOfGatheredResources(g.boardPlay[x1][x2+1]);
            g.boardPlay[x1][x2+1].setResourceType(NULL);
        }
        if ((x2 - 1) >= 0) {
            player1.setListOfGatheredResources(g.boardPlay[x1][x2-1]);
            g.boardPlay[x1][x2-1].setResourceType(NULL);
        }
    }

}

int main()
{
    char dic1;
    int dic3, dic4;
    srand(time_t(NULL));
    int s = 0;
    cout << "Please enter the size of game table : ";
    cin >> s;
    Grid g(s);
    startGame(g, s);
    int dice=0;
    Archeologist player1;
    Archeologist player2;
    player1.setPlayerEnegery(10);
    player2.setPlayerEnegery(10);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Please press R to  roll a dice to start : " ;
    cin >> dic1;
    dic3 = rollDice();
    cout << "YOUR DICE IS : " << dic3 << endl;
    cout << "Please press R to  roll a dice to start : ";
    cin >> dic1;
    dic4 = rollDice();
    cout << "YOUR DICE IS : " << dic4 << endl;

    

   while (player1.getTotalScore() < 135 && player2.getTotalScore() < 135) {
       
       if (dic3 >= dic4) {
           if (player1.getPlayerEnergy() != 0) {
               cout << "PLAYER 1 TURN !!! " << endl;
               play(player1, g,s);
               cout << "YOUR ENERGY IS : " << player1.getPlayerEnergy() << "YOUR SCORE IS : " << player1.getTotalScore() << endl;
           }
           if (player2.getPlayerEnergy() != 0) {
               cout << "PLAYER 2 TURN !!! " << endl;
               play(player2, g,s);
               cout << "YOUR ENERGY IS : " << player2.getPlayerEnergy() << "YOUR SCORE IS : " << player2.getTotalScore() << endl;
           }
       }
       else {
           if (player2.getPlayerEnergy() != 0) {
               cout << "PLAYER 2 TURN !!! " << endl;
               play(player1, g,s);
               cout << "YOUR ENERGY IS : " << player2.getPlayerEnergy() << "YOUR SCORE IS : " << player2.getTotalScore() << endl;
           }
           if (player1.getPlayerEnergy() != 0) {
               cout << "PLAYER 1 TURN !!! " << endl;
               play(player2, g,s);
               cout << "YOUR ENERGY IS : " << player1.getPlayerEnergy() << "YOUR SCORE IS : " << player1.getTotalScore() << endl;
           }
       }
    
   }
   if (player1.getTotalScore() > player2.getTotalScore())
       cout << "PLAYER 1 WON THE GAME !!!!";
   else if (player1.getTotalScore() == player2.getTotalScore())
       cout << "DRAW !!!!!!!!!!";
   else
       cout << "PLAYER 2 WON THE GAME !!!!";

   
   return 0;
}


