# Igh system RTC HAL driver
## 
The module should has the following public APIs
module name igh_time
```bash
void rtc_init(void); //initializes the rtc module
bool igh_time_is_valid( void ); // returns true if current time is after January 1st 2021
uint32_t igh_time_now( void ); // returns the current unix time
bool igh_time_set( uint32_t unix_time ); // sets the current RTC time and returns true if 
successful
DateTime igh_datetime(void);//returns a DateTime object of the current time
```
## Flashing to device over serial
```bash 
$ make flash
```
This will build the firmware and put the device i dfu mode and flash the firmware binary ontu the device via USB.
### Expected output
```bash
daniel@dan:~/Desktop/synnefa/firmware/rtc_test$ make flash
particle compile boron . --saveTo rtc-test-boron.bin

Compiling code for boron

Including:
    src/include/igh_time.h
    src/include/RTClib.h
    src/rtc_test.cpp
    src/src/igh_time.cpp
    src/src/RTClib.cpp
    project.properties

attempting to compile firmware
downloading binary from: /v1/binaries/62207b69f4cfff43a2628b01
saving to: rtc-test-boron.bin
Memory use:
   text    data     bss     dec     hex filename
   5788     200     616    6604    19cc /workspace/target/workspace.elf

Compile succeeded.
Saved firmware to: /home/daniel/Desktop/synnefa/firmware/rtc_test/rtc-test-boron.bin
particle usb dfu
Done.
particle flash --usb rtc-test-boron.bin

Flash success!
```
## Serial monitor
```bash
$ make serial
```

### Expected Output
```bash
$ daniel@dan:~/Desktop/synnefa/firmware/rtc_test$ make serial 
particle serial monitor
Opening serial monitor for com port: "/dev/ttyACM0"
Serial monitor opened successfully:
Current DATETIME: 2022/3/3 (Thursday) 11:26:26
Unix epoch time: 1646306786
Is the time valid: Yes!
Current DATETIME: 2022/3/3 (Thursday) 11:26:28
Unix epoch time: 1646306788
Is the time valid: Yes!
Current DATETIME: 2022/3/3 (Thursday) 11:26:30
Unix epoch time: 1646306790
Is the time valid: Yes!
```

ToDo
- [ ] Add unit tests sigh...