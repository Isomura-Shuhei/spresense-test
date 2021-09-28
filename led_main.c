#include <sdk/config.h>
#include <stdio.h>

#include <arch/board/board.h>
#include <arch/chip/pin.h>

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    board_gpio_config(97, 0, false, true, 0);
    printf("Hello, GPIO!\n");

    for(int i=0; i<10; i++){
        board_gpio_write(97, 1);
        usleep(1000*1000);
        board_gpio_write(97, 0);
        usleep(1000*1000);
    }
    return 0;
}