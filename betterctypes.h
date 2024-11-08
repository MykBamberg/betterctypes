#ifndef BETTERCTYPES_H
#define BETTERCTYPES_H

#define arr(T, n) typeof(typeof(T)[n])
#define fn(out, ...) typeof(typeof(out) (*)(__VA_ARGS__))

#endif
