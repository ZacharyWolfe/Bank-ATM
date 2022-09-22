/*
Author: Zachary Wolfe
Date: 9/20/2022 
Purpose: Create a C++ program to practice implementing flow control using if-else,switch, and looping
         statements. The program will simulate a simple bank account that you can make deposits to or withdraw from.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SET INITIAL VARIABLE OF BALANCE = $2300

SET A PIN NUMBER (3579) WHERE IF ENTERED INCORRECTLY 3 TIMES WILL KILL THE PROGRAM

CREATE A SWITCH MENU

-OPTION 1: SEE BALANCE.

-OPTION 2: DEPOSIT (MUST ENTER CORRECT PIN NUMBER) | OUTPUT "INCORRECT PIN" IF FALSE. OUTPUT NEW BALANCE IF TRUE

-OPTION 3: WITHDRAW. ONLY SHOULD BE ALLOWED TO DO THIS OPTION IF CORRECT PIN AND BALANCE IS SUFFICIENT ENOUGH | 
           OUTPUT "INCORRECT PIN", THE NEW BALANCE, OR "INSUFFICIENT FUNDS".

-OPTION 4: QUIT. MENU SHOULD BE IN LOOP UNTIL OPTION 4 IS SELECTED.
                 AMOUNTS TO TWO DECIMALS.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
 
    //VARIABLES
    double bal = 2300;
    const int PIN = 3579;
    double dep_amnt;
    double wtd_amnt;
    int user_pin;
    int inc_pin_atmpt = 0;
    int menu_opt;
 
    do{
    
        //DISPLAYS MENU
        cout << "-------------" << endl;
        cout << "1: Balance." << endl;
        cout << "2: Deposit." << endl;
        cout << "3: Withdraw: " << endl;
        cout << "4: QUIT. " << endl;
 
        //MENU OPTION INPUT FROM USER
        cin >> menu_opt;
        
        switch(menu_opt)
        {
            case 1:
            
                //OUTPUT BALANCE
                cout << "\nYour balance is: $" << setprecision(2) << bal << endl;
                break;
            
            case 2:
            
            if (inc_pin_atmpt == 3)
            {
                //ERROR - PIN ENTRY FAILED ATTEMPTS == 3
                cout << "You have entered the incorrect PIN too many times. \n" << endl;
                exit(true);
            }else 
                {
                //ENTER PIN TO MAKE A DEPOSIT
                cout << "Please enter your pin to make a deposit: ";
                cin >> user_pin;

                //CHECKING VALIDITY OF USER PIN
                if (user_pin != PIN)
                {
                    //ERROR - INCORRECT PIN
                    inc_pin_atmpt += 1;
                    cout << "Incorrect PIN. #" << inc_pin_atmpt << endl;
                    break;
                }else
                    {
                    //REQUEST DEPOSIT AMOUNT
                    cout << "How much would you like to deposit? ";
                    cin >> dep_amnt;

                    //UPDATE BALANCE AMOUNT
                    bal = bal + dep_amnt;
                    
                    //OUTPUT NEW BALANCE
                    cout << "\nYour new balance is: $" << setprecision(2) << bal << endl;
                    break; 
                    }
                }
            
            case 3:
            
            //ERROR - PIN ENTRY FAILED ATTEMPTS == 3
            if (inc_pin_atmpt == 3)
            {
                cout << "You have entered the incorrect PIN too many times. \n" << endl;
                exit(true);
            }
            
            cout << "Please enter your pin to make a withdrawal: ";
            cin >> user_pin;
            //INCORRECT PIN ERROR
            if (user_pin != PIN)
            {
                inc_pin_atmpt += 1;
                cout << "Incorrect PIN. #" << inc_pin_atmpt << endl;
                break;
            }else
                {
                    //USER ENTERS WITHDRAW AMOUNT
                    cout << "\nHow much would you like to withdraw? ($" << setprecision(2) << bal << ")" << endl;
                    cin >> wtd_amnt;
                    
                    //IF THE WITHDRAWAL AMOUNT THE USER IS TRYING TO TAKE FROM THE ACCOUNT IS GREATER THAN THE BALANCE IN THE ACCOUNT, 
                    THE TRANSACTION WILL NOT HAPPEN.
                    
                    //ERROR WITHDRAWAL AMOUNT GREATER THAN BALANCE OF ACCOUNT
                    if (wtd_amnt > bal) 
                    {
                    cout << "\nYou do not have the funds to make this transaction. ";
                    cout << "\nYour balance is: $" << setprecision(2) << bal << endl;\
                    break;
                    }else   
                        {
                        //WITHDRAWS AMOUNT USER DECLARED AS THE AMOUNT THEY WANT TO TAKE
                        bal = bal - wtd_amnt;
                        cout << "\nYour new balance is: $" << setprecision(2) << bal << endl;
                        break;
                        }
                }
            case 4:

                //EXITS ACCOUNT && KILLS PROGRAM
                cout << "\nThanks for updating your account! Goodbye.\n" << endl;            
                exit(true);           
            default: 
                //COULDN'T READ INPUT OF USER (NOT A SELECTION FOR THE SWITCH CASES)
                cout << "We couldn't quite get your input. \n";
        }
        }while(true);
        
        return 0;
}
