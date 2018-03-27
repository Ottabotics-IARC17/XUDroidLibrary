#include "main.h"
#include "SerialPort.cpp"
#include <stdio.h>

/*
 * "What should I name the library" - Brennan
 * "Name it Daddy" - Someone who regrets what they said
 */
class Daddy {
  private:
  	char* port_name = "\\\\.\\COM2";
    bool connected = false;
    SerialPort arduino;
  public:
  	void tryConnect(){
  		try {
            arduino = new SerialPort(port_name);
            if (arduino.isConnected()) cout << "Connection Established" << endl;
            else throw std::runtime_error("Connection Error");
        } catch(const std::exception& e) {
        	std::cout << "Exception hit attempting to connect to arduino" << std::endl;
        }
  	}

  	
}