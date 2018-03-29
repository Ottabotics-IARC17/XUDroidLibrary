#include <stdio.h>      // standard input / output functions
#include <iostream>
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions


class Serial {
  private:
    char* dev_desc;
    struct termios tty;
    struct termios tty_old;
    int USB;
  public:
    Serial(char*);
    void open_connection();
    void set_baud(termios*, unsigned int);
    void add_flag(int);
    void mask_flag();
    void set_blocking(bool);
    void write_cmd(char*);
};
