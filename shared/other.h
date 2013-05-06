// See the file COPYRIGHT.txt for authors and copyright information.
// See the file LICENSE.txt for copying conditions.

#ifndef OTHER_H
#define OTHER_H

// Miscellaneous functions and classes can go in here

typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long long llong;
typedef unsigned long long ullong;
typedef unsigned int EID;

//enum class Direction {Up, Down, Left, Right};

namespace Errors
{
    enum ErrorCode
    {
        Unknown = -1,
        Ok,
        Graphics,
        Audio,
        Font = 10
    };
}

#endif // OTHER_H
