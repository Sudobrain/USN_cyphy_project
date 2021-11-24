#include "Coms.h"
#include "database.h"

int main(int argc, char *argv[])
{

    Database DB; // SQL database
    DB.create_table();// Create the table in database
    Coms user_comms; // Input / Output / Error Messages
    int m = 1; // Meny option holder 
    int um = 0; // User meny choice

   
    //test data start -------------------
    
    DB.write_user("user1", 180);
    DB.view_database();
    
    //test data slutt -------------------


    user_comms.intro();

    while (m >= 0) {
        if (m == 1) { // Main menu
            user_comms.menu_main();
            um = user_comms.get_menu_int(2);
            if (um == 1) { // go to m2, menu for new user
                m = 2;
                um = 0;
            }
            else if (um == 2) { // go to m3, menu for exicting user
                m = 3;
                um = 0;
            }
            else if (um == 0) {// go to m0, end programm
                m = 0;
                um = 0;
            }
            else if (um == -1) {//redo m1, user input not valid
                m = 1;
                um = 0;
            }
            else {
                user_comms.error_message("user input(um) out of range");
            }
        }
        else if (m == 2) { // Menu for new user 
            user_comms.menu_new();
            um = user_comms.get_menu_int(1);
            if (um == 1) {// new user
                m = 2;//----temp---loop meny---- 
                um = 0;
                
                std::string user = "";
                int hight = 0;
                // --------------------------TO DO---------------------------------------
                //Get goes here:
                //hight = get_hight();
                // --------------------------TO DO---------------------------------------
                 
                std::cout << "Ditt navn: ";
                std::cin >>user;
                DB.write_user(user, hight);

            }
            else if (um == 0) {//return to main
                m = 1;
                um = 0;
            }
            else if (um == -1) {//wrong input, return to meny
                m = 2;
                um = 0;
            }
            else {//error, um out of range
                user_comms.error_message("user input(um) out of range");
            }

        }
        else if (m == 3) {// menu for getting exicting user data
            user_comms.menu_existing();
            um = user_comms.get_menu_int(2);
            if (um == 1) {
                m = 3;//---loop back to existing meny----
                um = 0;

                std::string user = "";
                std::cout << "Ditt navn: ";
                std::cin >> user;
                DB.read_user(user);

            }
            else if (um == 2) {
                m = 3;//---loop back to existing meny----
                um = 0;
                DB.view_database();
            }
            else if (um == 0) {//return to main
                m = 1;
                um = 0;
            }
            else if (um == -1) {//wrong input, return to meny
                m = 3;
                um = 0;
            }
            else {// error, um out of range
                user_comms.error_message("user input(um) out of range");
            }

        }
        else if (m == 0) {// exit programm
            user_comms.end();
            DB.clear_database(); // Clear data from database
            m = -1;
        }
        else {// Error, m out of range
            user_comms.error_message("user input(m) out of range");
        }

    }

}
