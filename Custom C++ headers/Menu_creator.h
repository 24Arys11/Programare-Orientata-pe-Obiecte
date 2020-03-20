#include <iostream>
#include <string>

using namespace std;

class Menu; /// menu_action uses the class "Menu" and the class "Menu" also uses menu_action :))

typedef void(*menu_action)(Menu); /// It’s a function pointer

class Menu{
private:

    int read_input(){

        string input;
        cin >> input;

        if(input == "0"){       /// Maximul nr. of entries is 50 ! No sane person creates a bigger menu !
            return 0;           /// Even if we scale this exponentially, time will not be wasted !
        }else if(input == "1"){ /// It will not iterate through all 50 options, unless your input is invalid !
            return 1;
        }else if(input == "2"){
            return 2;
        }else if(input == "3"){
            return 3;
        }else if(input == "4"){
            return 4;
        }else if(input == "5"){
            return 5;
        }else if(input == "6"){
            return 6;
        }else if(input == "7"){
            return 7;
        }else if(input == "8"){
            return 8;
        }else if(input == "9"){
            return 9;
        }else if(input == "10"){
            return 10;
        }else if(input == "11"){
            return 11;
        }else if(input == "12"){
            return 12;
        }else if(input == "13"){
            return 13;
        }else if(input == "14"){
            return 14;
        }else if(input == "15"){
            return 15;
        }else if(input == "16"){
            return 16;
        }else if(input == "17"){
            return 17;
        }else if(input == "18"){
            return 18;
        }else if(input == "19"){
            return 19;
        }else if(input == "20"){
            return 20;
        }else if(input == "21"){
            return 21;
        }else if(input == "22"){
            return 22;
        }else if(input == "23"){
            return 23;
        }else if(input == "24"){
            return 24;
        }else if(input == "25"){
            return 25;
        }else if(input == "26"){
            return 26;
        }else if(input == "27"){
            return 27;
        }else if(input == "28"){
            return 28;
        }else if(input == "29"){
            return 29;
        }else if(input == "30"){
            return 30;
        }else if(input == "31"){
            return 31;
        }else if(input == "32"){
            return 32;
        }else if(input == "33"){
            return 33;
        }else if(input == "34"){
            return 34;
        }else if(input == "35"){
            return 35;
        }else if(input == "36"){
            return 36;
        }else if(input == "37"){
            return 37;
        }else if(input == "38"){
            return 38;
        }else if(input == "39"){
            return 39;
        }else if(input == "40"){
            return 40;
        }else if(input == "41"){
            return 41;
        }else if(input == "42"){
            return 42;
        }else if(input == "43"){
            return 43;
        }else if(input == "44"){
            return 44;
        }else if(input == "45"){
            return 45;
        }else if(input == "46"){
            return 46;
        }else if(input == "47"){
            return 47;
        }else if(input == "48"){
            return 48;
        }else if(input == "49"){
            return 49;
        }else if(input == "50"){
            return 50;
        }else{
            return -1;
        }
    }

public:

    string *error;      /// We want to be able to change the eror message if needed !

    Menu(){

        this->error = new string ("Invalid input !");
    }

    ~Menu(){

        delete[] error;

    }

    void deploy(int no_of_entries, string options[], menu_action actions[]){

        for(int i = 0; i < no_of_entries; i++){
            cout << (i + 1) << ". " << options[i] << endl;
        }

        int selected = read_input();

        while((selected < 1) || (selected > no_of_entries)){
            cout << *error << endl;
            selected = read_input();
        }

        actions[selected - 1](*this);
    }
};
