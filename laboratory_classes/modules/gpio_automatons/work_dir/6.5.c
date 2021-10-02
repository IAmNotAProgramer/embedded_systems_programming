#include"main.h"
#include"led.h"
#include"keyboard.h"

enum led_state {RUN_RIGHT, STOP};
enum led_state led_state_var = RUN_RIGHT;

void delay(int time)
{
	time = time * DELAY_COUNT_1MS;
	for (int counter = 0;counter < time;counter++);
}

int main()
{
	keyboard_init();
	led_init();

	while (1) {

		switch (led_state_var) {
		case STOP:
			if (keyboard_read() == BUTTON_1) {
				led_state_var = RUN_RIGHT;
			}
			break;
		case RUN_RIGHT:
			if (keyboard_read() == BUTTON_0) {
				led_state_var = STOP;
			}
			led_step_right();
			delay(500);
			break;
		default:
			break;
		}
	}
}
