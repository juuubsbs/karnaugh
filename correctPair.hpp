

int correctPair (int& x, int& y, int& z){

    x = x - (y * 2);
    y = y - (z * 2);

    if ( x < 0){
        x = 0;
    }

    if ( y < 0){
        y = 0;
    }

    return 0;
}