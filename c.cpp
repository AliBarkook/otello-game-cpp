#include <iostream>
using namespace std;

int turns(int entry);
int printMap();
int changes( int positionX, int positionY, int counter);

int  position[10][10] ={0};

int main() {
    // initialize map:
    position[4][4] = 1;
    position[5][4] = 2;
    position[4][5] = 2;
    position[5][5] = 1;
    int counter = 0, positionY, positionX;



    printMap();

    while(counter<5) {

        turns(counter);


        cin >> positionX;
        cin >> positionY;

        if (positionX<9 && positionX>0 && positionY<9 && positionY>0) {
            if((position[positionX][positionY]==0) &&
                (position[positionX+1][positionY]!=0 ||
                position[positionX+1][positionY+1]!=0 ||
                position[positionX+1][positionY-1]!=0 ||
                position[positionX][positionY+1]!=0 ||
                position[positionX][positionY-1]!=0 ||
                position[positionX-1][positionY+1]!=0 ||
                position[positionX-1][positionY-1]!=0 ||
                position[positionX-1][positionY]!=0)) {
                // for black:
                if (counter%2==0)
                    position[positionX][positionY] = 1;
                // for white:
                else
                    position[positionX][positionY] = 2;


                changes( positionX,  positionY, counter);
                if (changes( positionX,  positionY, counter)==0) {
                    if (counter%2==0)
                        position[positionX][positionY] = 0;
                    // for white:
                    else
                        position[positionX][positionY] = 0;

                    cout << "cordinate is wrong!\n";
                }
                else {
                    counter++;
                    printMap();
                }
                //cout << changes(  positionX,  positionY, counter);

            }
            else
                cout << "cordinate is wrong!\n";
        }
        else
            cout << "cordinate is wrong!\n";

    }


    return 0;
}

int changes( int positionX, int positionY, int counter){
    bool checkForAction;
    int k, m;
    // for x+:
    int i=positionX+1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][positionY]==1 && position[i-1][positionY]==2) {
                    for (int j=positionX+1; j<i; j++) {
                            position[j][positionY]=1;
                    }
                    checkForAction = true;
                    break ;
            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][positionY]==2 && position[i-1][positionY]==1) {
                    for (int j=positionX+1; j<i; j++) {
                            position[j][positionY]=2;
                    }
                    checkForAction = true;
                    break ;
            }

        }
        if (i==10) {
            break ;

        }

    i++;
    }

    // for x-:
    i=positionX-1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][positionY]==1 && position[i+1][positionY]==2) {
                    for (int j=positionX-1; j>i; j--) {
                            position[j][positionY]=1;
                    }
                    checkForAction = true;
                    break;
            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][positionY]==2 && position[i+1][positionY]==1) {
                    for (int j=positionX-1; j>i; j--) {
                            position[j][positionY]=2;
                    }
                    checkForAction = true;
                    break;
            }

        }
        if (i==0) {
            break;

        }

    i--;
    }

    // for y+:
    i=positionY+1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[positionX][i]==1 && position[positionX][i-1]==2) {
                    for (int j=positionY+1; j<i; j++) {
                            position[positionX][j]=1;
                    }
                    checkForAction = true;
                    break;
            }
        }

         // for white:
        if (counter%2==1) {
            if (position[positionX][i]==2 && position[positionX][i-1]==1) {
                    for (int j=positionY+1; j<i; j++) {
                            position[positionX][j]=2;
                    }
                    checkForAction = true;
                    break;
            }
        }
        if (i==10) {
            break;

        }

    i++;
    }

    // for y-:
    i=positionY-1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[positionX][i]==1 && position[positionX][i+1]==2) {
                    for (int j=positionY-1; j>i; j--) {
                            position[positionX][j]=1;
                    }
                    checkForAction = true;
                    break;
            }
        }

         // for white:
        if (counter%2==1) {
            if (position[positionX][i]==2 && position[positionX][i+1]==1) {
                    for (int j=positionY-1; j>i; j--) {
                            position[positionX][j]=2;
                    }
                    checkForAction = true;
                    break;
            }
        }
        if (i==0) {
            break;

        }

    i--;
    }

     // for x+y+:
    i=positionX+1;
    k=positionY+1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][k]==1 && position[i-1][k-1]==2) {
                    m=positionY+1;
                    for (int j=positionX+1; j<i; j++) {
                            position[j][m]=1;
                            m++;
                    }
                    checkForAction = true;
                    break ;

            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][k]==2 && position[i-1][k-1]==1) {
                    m=positionY+1;
                    for (int j=positionX+1; j<i; j++) {
                            position[j][m]=2;
                            m++;
                    }
                    checkForAction = true;
                    break ;
            }
        }
        if (i==10) {
            break ;

        }

    i++;
    k++;
    }

     // for x-y-:
    i=positionX-1;
    k=positionY-1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][k]==1 && position[i+1][k+1]==2) {
                    m=positionY-1;
                    for (int j=positionX-1; j>i; j--) {
                            position[j][m]=1;
                            m--;
                    }
                    checkForAction = true;
                    break ;
            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][k]==2 && position[i+1][k+1]==1) {
                    m=positionY-1;
                    for (int j=positionX-1; j>i; j--) {
                            position[j][m]=2;
                            m--;
                    }
                    checkForAction = true;
                    break ;
            }
        }
        if (i==0) {
            break ;

        }

    i--;
    k--;
    }

     // for x+y-:
    i=positionX+1;
    k=positionY-1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][k]==1 && position[i-1][k+1]==2) {
                    m=positionY-1;
                    for (int j=positionX+1; j<i; j++) {
                            position[j][m]=1;
                            m--;
                    }
                    checkForAction = true;
                    break ;

            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][k]==2 && position[i-1][k+1]==1) {
                    m=positionY-1;
                    for (int j=positionX+1; j<i; j++) {
                            position[j][m]=2;
                            m--;
                    }
                    checkForAction = true;
                    break ;
            }
        }
        if (i==10) {
            break ;

        }

    i++;
    k--;
    }


     // for x-y+:
    i=positionX-1;
    k=positionY+1;
    while ( i!=0) {

         // for black:
        if (counter%2==0) {
            if (position[i][k]==1 && position[i+1][k-1]==2) {
                    m=positionY+1;
                    for (int j=positionX-1; j>i; j--) {
                            position[j][m]=1;
                            m++;
                    }
                    checkForAction = true;
                    break ;

            }
        }

         // for white:
        if (counter%2==1) {
            if (position[i][k]==2 && position[i+1][k-1]==1) {
                    m=positionY+1;
                    for (int j=positionX-1; j>i; j--) {
                            position[j][m]=2;
                            m++;
                    }
                    checkForAction = true;
                    break ;
            }
        }
        if (i==0) {
            break ;

        }

    i--;
    k++;
    }

    if (checkForAction)
        return 1;
    else
        return 0;


}

int turns(int entry) {
    // cout << "enter the Cordinates:\n";
    if (entry%2==0)
        cout << "black turn:\n";
    else
        cout << "white turn:\n";
    return 0;
}

int printMap() {

       for(int counter = 1; counter<9; counter++) {
            cout << "---------------------------------\n";
            for (int i = 1; i<9;i++) {
                    switch(position[i][counter]) {
                        case 0:
                            cout << "| . ";
                            break;

                        case 1:
                            cout << "| B ";
                            break;

                        case 2:
                            cout << "| W ";
                            break;
                    }

            }
            cout << "|\n";

    }
    cout << "---------------------------------\n";
        return 0;
}
