#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct timestamp {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

struct timestamp add_timestamps(struct timestamp a, struct timestamp b){
    unsigned int SECONDS_IN_MINUTE = 60;
    unsigned int MINUTES_IN_HOUR = 60;
    unsigned int newSecond = a.second + b.second;
    unsigned int newMinute = a.minute + b.minute + (unsigned int) floor(newSecond / SECONDS_IN_MINUTE);
    newSecond = newSecond % SECONDS_IN_MINUTE;
    unsigned int newHour = a.hour + b.hour + (unsigned int) floor(newMinute / MINUTES_IN_HOUR);
    newMinute = newMinute % MINUTES_IN_HOUR;
    struct timestamp res = {
        newHour, newMinute, newSecond
    };
    return res;
}

int main(int argc, char **argv){
    // Init timestamps
    if (argc < 7){
        printf("Invalid arguments");
        exit(-1);
    }
    
    struct timestamp a = {
        atoi(argv[1]), atoi(argv[2]), atoi(argv[3])
    };
    struct timestamp b = {
        atoi(argv[4]), atoi(argv[5]), atoi(argv[6])
    };
    struct timestamp result = add_timestamps(a, b);
    printf("%d %d %d", result.hour, result.minute, result.second);
    return 0;
}