#ifndef JML_CONSTANTS_H
#define JML_CONSTANTS_H

#include <JML/dependencies.h>

#define JML_EPSILON 0.000001L
#define JML_CUT     0.0000001L
#define JML_PI_     0x1.882p+1L
#define JML_PI      0x1.921fb54442d18469898cc51701b8p+1L
#define JML_PIO2    0x1.921fb54442d18469898cc51701b8p+0L
#define JML_TAU     0x1.921fb54442d18469898cc51701b8p+2L
#define JML_E       0x1.5bf0a8b1457695355fb8ac404e7ap+1L
#define JML_PHI     0x1.9E3779B97F4A7C15F39p+0L
#define SQRT2       0x1.6A09E66p+0L

enum {
    JML_LESS = -1,
    JML_EQUAL,
    JML_GREATER
};

enum {
    JML_ROUND_UP,
    JML_ROUND_DOWN
};

enum {
    JML_INTEGER_PART,
    JML_DECIMAL_PART
};

enum {
    JML_CLOCKWISE = -1,
    JML_COLLINEAR,
    JML_COUNTERCLOCKWISE
};

enum {
    JML_TRIG_ODD = -1,
    JML_TRIG_EVEN = 1
};

#endif // JML_CONSTANTS_H
