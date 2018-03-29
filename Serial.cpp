#include "Serial.h"


Serial::Serial(char* device_descriptor){
  memset (&tty, 0, sizeof tty);

  if ( tcgetattr ( USB, &tty ) != 0 ) {
     std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
  }
}

void Serial::open_connection(){
  USB = open(dev_desc, O_RDWR| O_NOCTTY);
}

void Serial::set_baud(termios* tty, unsigned int baud){
  cfsetospeed(tty, baud);
  cfsetispeed(tty, baud);
}

void Serial::add_flag(int flag) {
  tty.c_cflag &= ~flag;
}

void Serial::mask_flag() {
  tty.c_cflag |=  CS8;
}

void Serial::set_blocking(bool enabled) {
  if(enabled) {
    tty.c_cc[VMIN] = 1;
  } else {
    tty.c_cc[VMIN] = 0;
  }
}

void Serial::write_cmd(char cmd[]) {
  int n_written = 0,
    spot = 0;
  do {
      n_written = write( USB, &cmd[spot], 1 );
      spot += n_written;
  } while (cmd[spot-1] != '\r' && n_written > 0);
}
