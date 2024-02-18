#include <stdio.h>

typedef enum 
{
    idle,
    first,
    second
} state;

state transit_state(state current_state) 
{
    switch (current_state) 
    {
        case idle:
            return idle;
        case first:
            return first;
        case second:
            return second;
        default:
            return idle;
    }
}

void process_button(int buttonVal) 
{
    static state current_state = idle;

    current_state = transit_state(buttonVal);

    switch (current_state) 
    {
        case idle:
            printf("Button not pressed.\n");
            break;
        case first:
            printf("Button pressed once.\n");
            break;
        case second:
            printf("Button pressed twice.\n");
            break;
        default:
            printf("Unknown state.\n");
            break;
    }
}

int main() 
{
	process_button(0); // Press 1
	process_button(1); // Press 0
	process_button(2); // Press 1
	process_button(3); // Press 0
	process_button(0); // Press 1
    	return 0;
}

