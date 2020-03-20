#include "Menu_creator.h"

using namespace std;

int main();

void option_2(Menu menu){

    cout << "Option 2 has multiple sub-options:" << endl;
    /// We may also choose a different error message for this submenu if we wish..

    string options[3] = {"Suboption 1", "Suboption 2", "Back"};
    menu_action actions[4] = {[](Menu menu){cout << "Suboption 1" << endl; option_2(menu);}, [](Menu menu){cout << "Suboption 2" << endl; option_2(menu);}, [](Menu menu){main();}};
    menu.deploy(3, options, actions);

    main();
}

int main(){

    Menu menu;
    *menu.error = "Custom error msg for invalid input !";

    string options[4] = {"Option 1", "Option 2", "Option 3", "Quit"};
    menu_action actions[4] = {[](Menu menu){cout << "option 1" << endl;main();}, option_2, [](Menu menu){cout << "option 3" << endl;main();}, [](Menu menu){cout << "Good bye !" << endl;/*Not returning to main !*/}};
    menu.deploy(4, options, actions);

    return 0;
}
