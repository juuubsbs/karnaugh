#include <iostream>
#include "correctPair.hpp"

int main(){

    // inicialize a new matrix
    int matrix[4][4] = 
    { 
        { 1, 0, 0, 1},
        { 1, 0, 0, 1},
        { 0, 0, 0, 0},
        { 0, 0, 0, 0}
    };

    // counters 
    int pair = 0; int quatrain = 0; int octet = 0;

    // atribute the numbers based on the kind of pairs (2) they make
    for ( int i = 0; i < 4; i++){
        for ( int j = 0; j < 4; j++){

            //pair at the same line (they become '2')
            if(matrix[i][j] == 1 && matrix[i][j+1] == 1 && j+1 < 4){
                matrix[i][j] = 2; // the 1 that has been tested
                matrix[i][j+1] = 2; // the 'neighbor' of the tested
                pair++;
            }
            //pair at the same column (they also become '2')
            if(matrix[i][j] == 1 && matrix[i+1][j] == 1 && i+1 < 4){
                matrix[i][j] = 2; // the 1 that has been tested
                matrix[i+1][j] = 2; // the 'neighbor' of the tested
                pair++;
            }
            //check when there's a 1 wich already is '2' but also completes a pair with a '1' that doesen't
            else if(matrix[i][j] == 1){
                if(matrix[i+1][j] == 2 && i+1 < 4){ // the 1 that's on top is '2' already
                    matrix[i][j] = 2;
                    pair++;
                }
                if(matrix[i-1][j] == 2 && i-1 > 0){ // the 1 that's above is '2' already
                    matrix[i][j] = 2;
                    pair++;
                }
                if(matrix[i][j-1] == 2 && j-1 > 0){ // the 1 that's at left is '2' already
                    matrix[i][j] = 2;
                    pair++;
                }
            }
        }
    }

    // atribute the numbers based on the kind of quatrains (4) they make
    for ( int i = 0; i < 4; i++){
        for ( int j = 0; j < 4; j++){
            // checks if any possibility doesen't go out of the matrix
            if ( i-1 > 0 && j+1 < 4){ 
                if ( matrix[i][j] == 2 && matrix[i][j+1] == 2 && matrix[i-1][j+1] == 2 && matrix[i-1][j] == 2 ){ // tests if the above is a '2' and if the diagonal is '2'
                    matrix[i][j] = 4;
                    matrix[i][j+1] = 4;
                    matrix[i-1][j+1] = 4;
                    matrix[i-1][j] = 4;
                    quatrain++;
                }
            }  

            // checks if any possibility doesen't go out of the matrix
            if ( i+1 < 4 && i+2 < 4 && i+3 < 4){ 
                // checks if the column makes a quatrain
                if ( matrix[i][j] == 2 && matrix[i+1][j] == 2 && matrix[i+2][j] == 2 && matrix[i+3][j] == 2){
                    matrix[i][j] = 4;
                    matrix[i+1][j] = 4;
                    matrix[i+2][j] = 4;
                    matrix[i+3][j] = 4;
                    quatrain++;
                }
            }

            // checks if any possibility doesen't go out of the matrix
            if(j+1 < 4 && j+2 < 4 && j+3 < 4){ 
                // checks if the line makes a quatrain
                if ( matrix[i][j] == 2 && matrix[i][j+1] == 2 && matrix[i][j+2] == 2 && matrix[i][j+3] == 2){
                    matrix[i][j] = 4; 
                    matrix[i][j+1] = 4;
                    matrix[i][j+2] = 4;
                    matrix[i][j+3] = 4;
                    quatrain++;
                }
            }
        }
    }

    // atribute the numbers based on the kind of octets (8) they make
    for ( int i = 0; i < 4; i++){
        for ( int j = 0; j < 4; j++){
            if ( matrix[i][j] == 4 && matrix[i+1][j+1] == 4 && matrix[i][j+2] == 4 && matrix[i+1][j+3] == 4){
                for (int ifour = i; ifour < i + 2; ifour++){
                    for (int jfour = j; jfour < j + 4; jfour++){
                        if (matrix[ifour][jfour]== 4){
                            matrix[ifour][jfour] = 8;
                        }
                    }
                }
                octet++;
            }
            if (matrix[i+2][j] == 4 && matrix[i+3][j+1] == 4){
                matrix[i+2][j] = 8;
                matrix[i+2][j+1] = 8;
                matrix[i+3][j] = 8;
                matrix[i+3][j+1] = 8;
                octet++;
            }
        }
    }

    // loop to show the matrix after the attribution 
    for ( int i = 0; i < 4; i++){
        for( int j = 0; j < 4; j++){

            std:: string colorCode = "\e[0;32m"; // a variable to change de color according to the type
            std:: cout << colorCode << matrix[i][j] << "\e[0m " ;
        }

        std:: cout << "\n";
    }



    correctPair(pair, quatrain, octet); // this function reduces the numers of the small groupings

    // a feedback of all the different kind of pairs found
    std:: cout << "The number of \e[0;32mpairs\e[0m found is: "<< pair;
    std:: cout << "\nThe number of \e[0;33mquatrains\e[0m found is: "<< quatrain;
    std:: cout << "\nThe number of \e[0;35moctets\e[0m found is: "<< octet;

    return 0;
}
// IDEIA: usar essa coisa de sair da matriz pra puxar o portal lateral, 
//não sei de funciona pra cima e pra baixo também
