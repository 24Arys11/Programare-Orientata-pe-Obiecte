#ifndef TYPECAST_H_INCLUDED
#define TYPECAST_H_INCLUDED

#include <string>
#include <sstream>

namespace dtk{  /// Darius The King ;)

int strToInt(std::string s, int err = -1){

    int number;
    bool negative = false;

    number = 0;
    int i = 0;

    if(s[i] == '-'){

        negative = true;
        i++;
    }

    if((s.length() == 1) && (negative == true)){

            return err;
    }

    while(s[i] != '\0'){    /// verificam daca stringul contine doar cifre.

        if(!((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9'))){

            return err;

        }else{

            number = number * 10 + ((int)s[i] - 48);    /// pentru ca: '0' = 48, '1' = 49 ...
        }
        i++;
    }

    if(negative == false){
        return number;
    }else{
        return (-number);
    }
}

double strToDouble(std::string s, double err = -1){

    double number;
    double dotDivision;
    bool dotFound = false;
    bool negative = false;

    number = 0;
    dotDivision = 1;

    int i = 0;

    if(s[i] == '-'){

        negative = true;
        i++;
    }

    if((s.length() == 1) && (negative == true)){

            return err;
    }

    while(s[i] != '\0'){    /// verificam daca stringul contine doar cifre.

        if(!((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9') || (s[i] == '.'))){

            return err;

        }else{

            if(s[i] == '.'){

                if(dotFound == true){

                    return err;
                }else{

                    dotFound = true;
                }
            }

            if(dotFound == true){

                dotDivision *= 10;
            }

            if(s[i] != '.'){
                number = number * 10 + (double)((int)s[i] - 48);    /// pentru ca: '0' = 48, '1' = 49 ...
            }
        }
        i++;
    }

    if(dotFound == true){

        return ((number * 10) / dotDivision);

    }else{

        if(negative == false){
            return number;
        }else{
            return (-number);
        }
    }
}

std::string intToString(int x){

    std::stringstream s;
    s << x;

    return s.str();
}

std::string doubleToString(double d){

    std::stringstream s;
    s << d;

    return s.str();
}

}   /// End of namespace

#endif /// TYPECAST_H_INCLUDED
