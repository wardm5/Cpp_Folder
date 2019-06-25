// ------------------------------------------------ Poly.cpp --------------------------------------------------------
// Misha Ward CSS 343 Section B
// January 11th 2018
// January 14th 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Methods to store, calculate, receive input, and show output of polynomils functions.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//   - Assumptions include: Input is limited to integers. No negative exponets.
// --------------------------------------------------------------------------------------------------------------------
#include "Poly.h"

Poly::Poly(){  // Poly constructor, sets size to 1 and array values to 0
    size = 1;
    array = new int[size] {0};
    array[0] = 0;
}

Poly::Poly(int coefficent) {  // Poly constructor
    size = 1;  // sets size to 1
    array = new int[size] {0};  // sets array values to 0
    array[0] = coefficent;   // sets first array value to coefficent
}

Poly::Poly(int coefficent, int exponet) {  // Poly constructor
    size = exponet + 1;  // sets size to the exponet +1
    array = new int[size] {0};  // sets the array values to 0
    *(array + exponet) = coefficent;  // sets the array value of the exponet to the coefficent
}

Poly::Poly(const Poly& polyNomil) {  // Poly constcuctor
    size = polyNomil.size;  // sets size to the size of the polynomil
    int * newArray = new int[size + 1] {0};  // creates new array with the exponet size + 1, sets values to 0
    for (int i = 0; i < size; i ++) {  //  loops through to fill the new array with all the values from the old array
        newArray[i] = *(polyNomil.array + i);
    }
    array = newArray;  // sets the array equalt to the passed in poly object
}

void Poly::expandArray(int newSize){  //  expand array method
    int * newArray = new int[newSize + 1] {0};  // creates new array with the exponet size + 1, sets values to 0
    for (int i = 0; i < size; i ++) {  //  loops through to fill the new array with all the values from the old array
        newArray[i] = *(array + i);
    }
    array = newArray;  // sets old array to the new array
}

Poly::~Poly(){}  // Poly deconstructor

void Poly::setCoeff(int coefficent, int exponet){  // set Coefficent method
    if (exponet + 1 > size) {  // if the exponet + 1 is greater than the size...
        expandArray(exponet);  // then pass the exponet into expand array method
        *(array + exponet) = coefficent;  // set the value for exponet value to the coefficent
        size = exponet + 1;  // set size to the exponet value + 1
    } else {  // if the exponet is less than the current size...
        *(array + exponet) = coefficent;  // then set the array value to the coefficent
    }
}

int Poly::getCoeff(int exponet){  // get coefficent method
    return *(array + exponet);  // returns the array's exponet coefficent
}

Poly Poly::operator+(Poly const &obj) {  // overloading the + operator
    int max = 0;  // sets max
    int min = 0;  // sets min
    Poly newPoly(0, max);
    if (size == obj.size) {
        max = size;  // set max to size
        for (int i = 0; i < max; i++) {  // loop through the array
            newPoly.array[i] = *(array + i) + *(obj.array + i);  // set values in the new array as the combination of poly and object
        }
        return newPoly;  // return newPoly
    } else if (size > obj.size) {  // if size is larger than the object size
        max = size;  // set max to size
        min = obj.size;  // set min to object size
        Poly newPoly(0, max);   // create new poly and set max as its exponet
        for (int i = 0; i < min; i++) {  // loop through the array
            newPoly.array[i] = *(array + i) + *(obj.array + i);  // set values in the new array as the combination of poly and object
        }
        for (int i = min; i < max; i++){  // set the rest of the values in the new array...
            newPoly.array[i] = *(array + i);  // to the values left in the larger array (the poly object)
        }
        return newPoly;  // return newPoly
    } else {     // same as above except switch which array will be looped through first
        max = obj.size;
        min = size;
        Poly newPoly(0, max);
        for (int i = 0; i < min; i++) {
            newPoly.array[i] = *(array + i) + *(obj.array + i);
        }
        for (int i = min; i < max; i++){
            newPoly.array[i] = *(obj.array + i);
        }
        return newPoly;
    }
}
Poly Poly::operator-(Poly const &obj) {   // overloading the - operator
    int max = 0;  // sets max
    int min = 0;  // sets min
    Poly newPoly(0, max);
    if (size == obj.size) {
        max = size;  // set max to size
        for (int i = 0; i < max; i++) {  // loop through the array
            newPoly.array[i] = *(array + i) - *(obj.array + i);  // set values in the new array as the combination of poly and object
        }
        return newPoly;  // return newPoly
    } else if (size > obj.size) {  // if size is larger than the object size
        max = size;  // set max to size
        min = obj.size;  // set min to object size
        Poly newPoly(0, max);   // create new poly and set max as its exponet
        for (int i = 0; i < min; i++) {  // loop through the array
            newPoly.array[i] = *(array + i) - *(obj.array + i);  // set values in the new array as the combination of poly and object
        }
        for (int i = min; i < max; i++){  // set the rest of the values in the new array...
            newPoly.array[i] = *(array + i);  // to the values left in the larger array (the poly object)
        }
        return newPoly;  // return newPoly
    } else {     // same as above except switch which array will be looped through first
        max = obj.size;
        min = size;
        Poly newPoly(0, max);
        for (int i = 0; i < min; i++) {
            newPoly.array[i] = *(array + i) - *(obj.array + i);
        }
        for (int i = min; i < max; i++){
            newPoly.array[i] = -*(obj.array + i);
        }
        return newPoly;
    }
}

Poly Poly::operator*(Poly const &obj) {   // overloading the * operator
    int size1 = size;   // sets size1 to the size of the polynomil
    int size2 = obj.size;  // sets the size2 to the object's size
    Poly newPoly(0, size1 + size2 + 1);  // creates new polinomil object that has a size of (size1 + size2 + 1)
    for (int i = 0; i < size1; i++){  // loops through the first array
        for (int j = 0; j < size2; j++){  // loops through the second array
            newPoly.array[i+j] += *(array + i) * *(obj.array + j);  // sets the value of the
        }
    }
    return newPoly;  // return the new Poly object
}

Poly Poly::operator=(Poly const &obj) {
    int max = obj.size;  // set max to object's size
    Poly newPoly(0, max);  // create new poly object
    for (int i = 0; i <= max-1; i++) {  // loop through
        newPoly.array[i] =  *(obj.array + i);  // set new poly's values to object's values
    }
    array = newPoly.array;
    size = newPoly.size;
    return newPoly;  // return the new poly.
}

Poly Poly::operator+=(Poly const &obj){   // overloading the += operator
    int max = 0;  // create max variable
    int min = 0;   // create min variable
    if (size > obj.size) {  // check if size is larger than object's size
        max = size;  // set max to size
        min = obj.size;  // set min to object's size
        int * newArray = new int[max + 1] {0};  // creates new array with the exponet max + 1, sets values to 0
        for (int i = 0; i < min; i++) {  // loop through the array
            newArray[i] = *(array + i) + *(obj.array + i);  // set the new array's value to the combination of the poly's
                                                                 // old value plus object's value
        }
        for (int i = min; i < max -1; i++){  // loop through the larger array's values
            newArray[i] = *(array + i);  // add the larger array's values to the new array
        }
        array = newArray;
        size = max;
        return *this;  // return the existing poly.
    } else {   // same as above except switch which array will be looped through first
        max = obj.size;
        min = size;
        int * newArray = new int[max + 1] {0};  // creates new array with the exponet max + 1, sets values to 0
        for (int i = 0; i < min; i++) {
            newArray[i] = *(array + i) + *(obj.array + i);
        }
        for (int i = min; i < max - 1; i++){
            newArray[i] = *(obj.array + i);
        }
        array = newArray;
        size = max;
        return *this;  // return the new poly.
    }
}
Poly Poly::operator-=(Poly const &obj) {    // overloading the -= operator
    int max = 0;  // create max variable
    int min = 0;  // create min variable
    if (size > obj.size) { // check if size is larger than object's size
        max = size;  // set max to size
        min = obj.size;  // set min to object's size
        int * newArray = new int[max + 1] {0};  // creates new array with the exponet max + 1, sets values to 0
        for (int i = 0; i < min; i++) {  // loop through the array
            newArray[i] = *(array + i) - *(obj.array + i);  // set values for the new poly object to
                                                                 // combination of the poly's values and object's values
        }
        for (int i = min; i < max -1; i++){  // loop through the rest of the larger array
            newArray[i] = *(array + i);  // set all values from larger array to new array
        }
        array = newArray;
        size = max;
        return *this;  // return the new poly.
    } else {   // same as above except switch which array will be looped through first
        max = obj.size;
        min = size;
        int * newArray = new int[max + 1] {0};  // creates new array with the exponet max + 1, sets values to 0
        for (int i = 0; i < min; i++) {
            newArray[i] = *(array + i) - *(obj.array + i);
        }
        for (int i = min; i < max - 1; i++){
            newArray[i] = -*(obj.array + i);
        }
        array = newArray;
        size = max;
        return *this;  // return the new poly.
    }
}
Poly Poly::operator*=(Poly const &obj) {    // overloading the *= operator
    int size1 = size;  // set size1 to size
    int size2 = obj.size;  // set size2 to object's size
    int * newArray = new int[size1 + size2 + 1] {0};  // creates new array with the exponet size of size1 + size2 + 1, sets values to 0
    for (int i = 0; i < size1; i++){  // loop through the poly array
        for (int j = 0; j < size2; j++){  // loop through object's array
            newArray[i+j] += *(array + i) * *(obj.array + j);  // set the value to the new object's array values to
                                                                    // multiply poly's value to the object's value and add them
                                                                    // to the new object's array.
        }
    }
    array = newArray;
    size = size1 + size2 + 1;
    return *this;  // return the new poly.
}

bool Poly::operator==(Poly const &obj) const{    // overloading the == operator
    int max = 0;  //  create max variable
    int min = 0;  // create min variable
    bool same = 1;  // create boolean with inital value of true
    if (size > obj.size) {  // if size of poly is greater than object's size
        max = size;  // set max to size of poly
        min = obj.size;  // set min to object's size
        for (int i = 0; i < min; i++) {  //  loop throguh
            if (*(array + i) != *(obj.array + i)) {  // check if array's value is same as object's value
                same = 0;  // if it is not the same, then switch the bool to false.
            }
        }
        for (int i = min; i < max; i++){  // loop through the rest of the bigger array...
            if (*(array + i) != 0) {  // chcek if all values in the bigger array are 0's
                same = 0;  // if they are not, then set same to 0.
            }
        }
        return same;  // return same.
    } else {   // same as above except switch which array will be looped through first
        max = obj.size;
        min = size;
        for (int i = 0; i < min; i++) {
            if (*(array + i) != *(obj.array + i)) {
                same = 0;
            }
        }
        for (int i = min; i < max; i++){
            if (*(array + i) != 0) {
                same = 0;
            }
        }
        return same;
    }
}
bool Poly::operator!=(Poly const &obj) const{   // overloading the != operator
    int max = 0;  // creates ints of max and min
    int min = 0;
    bool same = 1;  // creates bool notsame
    if (size >= obj.size) {  // if size is larger than object size...
        max = size;  // set max to size
        min = obj.size;  // set min to object size
        for (int i = 0; i < min; i++) {  // loop through
            if (*(array + i) == *(obj.array + i)) {  // check to see if the values are the same.
                same = 1;  // if they are not, then set not same to false
            }
        }
        for (int i = min; i < max; i++){  // loop through
            if (*(array + i) != 0) {  // if the rest of the larger sized array is all 0's, then..
                same = 1;  // notSame would be set to 0
            }
        }
        return same; // return notSame
    } else {
        max = obj.size; // same as above except switch which array will be looped through first
        min = size;
        for (int i = 0; i < min; i++) {
            if (*(array + i) == *(obj.array + i)) {
                same = 1;
            }
        }
        for (int i = min; i < max; i++){
            if (*(array + i) != 0) {
                same = 1;
            }
        }
        same = 0;
        return same;
    }
}

std::ostream& operator<<(std::ostream &os, Poly& poly){    // overloading the << operator
    for(int i = poly.size-1; i >= 0; i--) {  //  loop through the poly object
        int coef = poly.getCoeff(i);  // set coef to the poly coefficent
        if (coef == 0 && i == 0 && poly.size == 1) {  // if coef is 0 and the exponet is 0 and the size is 1, then...
            os << 0;  // print out 0
            return os;
        }
        if (coef != 0) {  // if coef is not 0...
            if (coef > 0 && i == 0) {  // if coef is higher than 0 and exponet is 0
                os << " " << "+" << coef;  // set output to look like "+coef "
            } else if ( coef == 1 && i == 1) {
                os << " " << "+" << "x";  // set output to look like "+x "
            } else if (coef > 1 && i == 1){
                os << " " << "+" << coef << "x";  // set output to look like "+coefx "
            } else if (coef == 1 && i > 1){
                os<< " " << "+" << "x^" << i;  // set output to look like "+x^i "
            } else if (coef > 0 && i > 1){
                os << " "  << "+" << coef << "x^" << i;  // set output to look like "+coefx^i "
            } else if (coef == -1 && i == 1){
                os << " " << "-x";  // set output to look like "-x "
            } else if (coef < -1 && i == 0) {
                os << " "  << coef;  // set output to look like "-coef "
            } else {
                os << " " << coef << "x^" << i;  // set output to look like "-coefx^i "
            }
        }
    }
    return os;  // return the os.
}

std::istream& operator>>(istream& cin, Poly& poly){    // overloading the >> operator
    int coef = 0;  // set coefficent to 0
    int exponet = 0;  // set exponet to 0
    cin >> coef >> exponet;  // cin coef and exponet
    while (coef != - 1 && exponet != -1) {  // check to see if the coef and
                                            // exponet are not -1
        poly.setCoeff(coef, exponet);  // if they are not, then pass the coef
                                       // and exponet to the setCoef method.
        cin >> coef >> exponet;   // get input from user for coef and exponet.
    }
    return cin;  // return the cin
}

