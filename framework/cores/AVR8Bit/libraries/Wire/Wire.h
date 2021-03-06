/* $Id: Wire.h 1200 2011-06-16 00:42:12Z bhagman $
||
|| @author         Nicholas Zambetti
|| @url            http://wiring.org.co/
|| @contribution   Hernando Barragan <b@wiring.org.co>
|| @contribution   Alexander Brevig <abrevig@wiring.org.co>
|| @contribution   Brett Hagman <bhagman@wiring.org.co>
||
|| @description
|| | TWI Library.
|| |
|| | Wiring Core Library
|| #
||
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "Stream.h"

#define BUFFER_LENGTH 32

class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    void write(uint8_t);
    void write(int data) { write((uint8_t)data); };
    void write(const char *);
    void write(const uint8_t *, size_t);
    int available(void);
    int read(void);
    int peek(void);
    void flush(void);
    void onReceive(void (*)(int));
    void onRequest(void (*)(void));
};

extern TwoWire Wire;

#endif

