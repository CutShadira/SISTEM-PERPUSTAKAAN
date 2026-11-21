#include <ctype.h>
#include "pembanding.h"

int bandingkanTeks(const char *a, const char *b) {
    while (*a != '\0' && *b != '\0') {
        int x = tolower((unsigned char) *a);
        int y = tolower((unsigned char) *b);

        if (x != y) {
            return x - y;
        }
        a++;
        b++;
    }
    return tolower((unsigned char) *a) - tolower((unsigned char) *b);
}