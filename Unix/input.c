#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int get_key_board_from_termios()
{
    int key_value;
    struct termios new_config;
    struct termios old_config;

    tcgetattr(0, &old_config);
    new_config = old_config;
    new_config.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_config);

    key_value = getchar();

    tcsetattr(0, TCSANOW, &old_config);

    printf("key_value: %d\n", key_value);
    return 0;
}

int main() {
	get_key_board_from_termios();
		return 0;
}
