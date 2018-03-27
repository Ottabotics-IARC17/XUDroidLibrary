#ifndef MAIN_H
#define MAIN_H

#define BAUD 2000000

class Daddy
{
private:
	char* port_name;
    bool connected;
    SerialPort arduino(port_name);
public:
    Daddy(char *portName);
    ~Daddy();

    void tryConnect()
};

#endif // SERIALPORT_H