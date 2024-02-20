
#include <stdio.h>

typedef enum {
    Jan, Feb, Mar, Apr, May, Jun, Jul,
    Aug, Sep, Oct, Nov, Dec
} year;

int main() {
    year i;
    for (i = Jan; i <= Dec; i++)
        printf("%d ", i);
    return 0;
}
