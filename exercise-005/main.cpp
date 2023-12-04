#include <fmt/chrono.h>
#include <fmt/format.h>


#include "CLI/CLI.hpp"
#include "config.h"



    /* INSERT YOUR CODE HERE */

    

    extern void sleep_ms(int milliseconds);

    extern int getInput(void); typedef enum { 
        DB_STATE_OFF = 0,
        DB_STATE_S1 = 1, 
        DB_STATE_S2 = 2, 
        DB_STATE_ON = 3, 
        DB_STATE_MAX
    } DebounceState_t; 

    DebounceState_t state = DB_STATE_OFF;

    void stateMachine() 
    {
        switch(state) 
        {
            case DB_STATE_OFF: 
                if(1 == getInput()) 
                {
                    state = DB_STATE_S1; 
                }
            break; 
            case DB_STATE_S1: 
                if(1 == getInput()) 
                {
                state = DB_STATE_S2;
                }
                else 
                {
                    state = DB_STATE_OFF; 
                }
            break; 
            case DB_STATE_S2: 
                if(1 == getInput()) 
                {
                    state = DB_STATE_ON; 
                }
                else
                {
                    state = DB_STATE_OFF;
                }
            break;
            case DB_STATE_ON: 
                if(1 == getInput()) 
                {
                    state = DB_STATE_ON; 
                }
                else
                {
                    state = DB_STATE_OFF; 
                }
            
            default: 
                state = DB_STATE_OFF;
            break; 
            
        } 
    }
    int main(void) {






    while( 1==1 ) {
    stateMachine(); 
    sleep_ms(100);
    }
}


