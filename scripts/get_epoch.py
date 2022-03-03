import time
import calendar

# get current epoch time
print(F"Current epoch/unix time: {time.time()}")
# convert human readable date to epoch/unix time -> 1st january 2021
print(
    f"2022-01-01 to unix time: {calendar.timegm(time.strptime('2021-01-01', '%Y-%m-%d'))}")
# convert from epoch to human readable date
print(time.strftime("%a, %d %b %Y %H:%M:%S +0000", time.localtime(time.time())))
