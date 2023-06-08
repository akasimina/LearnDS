
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double FindSquare(double number){

    double start = 0, end = number, square;
    for(  square = (start + end)/2 ; abs((square * square) - number ) > 0.0001 ; square = (start + end)/2 ){
        if( square * square > number ) end = square;
        else start = square;
    }
    return square;
}

void Solution(){

    int times;
    cin >> times;

    double number;
    while( times-- ){
        cin >> number;
        cout << std::fixed << std::setprecision(3) << FindSquare(number) << endl;
    }

}












