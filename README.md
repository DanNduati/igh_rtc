# Igh system RTC HAL driver
The module should have the following public APIs
module name igh_time
```bash
bool igh_time_is_valid( void ); // returns true if current time is after January 1st 2021
uint32_t igh_time_now( void ); // returns the current unix time
bool igh_time_set( uint32_t unix_time ); // sets the current RTC time and returns true if successful
```