#include "AmisStepperMotor.h"
#include "mbed.h"

AmisStepperMotor::AmisStepperMotor(Pin& step, Pin& dir, Pin& en)
	:StepperMotor(step, dir, en)
{
	mbed::SPI spi(P0_18,NC,P0_15);
    spi.frequency(1000000);
    en.as_output();
    en.set(0);
	uint8_t write_cmd = 1<<5;
	uint8_t read_cmd = 0;
	spi.write(write_cmd | 0x01);
	spi.write(14 | 1<<5);
	//spi.write(write_cmd | 0x01);
	//spi.write(1<<5); // 1/16 microstep
	spi.write(write_cmd | 0x03);
	spi.write(1<<7); // enable motor
	en.set(1);
}