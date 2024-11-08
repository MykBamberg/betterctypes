#ifndef BETTERCTYPES_H
#define BETTERCTYPES_H

#define arr(T, ...) typeof(typeof(T)[__VA_ARGS__])
#define fn(out, ...) typeof(typeof(out) (*)(__VA_ARGS__))

#endif
