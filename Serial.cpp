#include "Serial.h"


class Serial {
  private:
    char* dev_desc;
    struct termios tty;
    struct termios tty_old;
    int USB;
}

Serial::Serial(char* device_descriptor){
  dev_desc = device_descriptor;
  memset (&tty, 0, sizeof tty);

  if ( tcgetattr ( USB, &tty ) != 0 ) {
     std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
  }
}

Serial::open(){
  USB = open(dev_desc, O_RDWR| O_NOCTTY);
}

Serial::set_baud(unsigned int baud){
  cfsetospeed(baud);
  cfsetispeed(baud);
}

Serial::addflag(int flag) {
  tty.c_cflag &= ~flag;
}

Serial::maskflag() {
  tty.c_cflag |=  CS8;
}

Serial::set_blocking(bool enabled) {
  if(enabled) {
    tty.c_cc[VMIN] = 1;
  } else {
    tty.c_cc[VMIN] = 0;
  }
}

Serial::make_raw(struct in_struct) {
  cfmakeraw(&in_struct);
}

Serial::write(char* cmd) {
  int n_written = 0,
    spot = 0;
  do {
      n_written = write( USB, &cmd[spot], 1 );
      spot += n_written;
  } while (cmd[spot-1] != '\r' && n_written > 0);
}
