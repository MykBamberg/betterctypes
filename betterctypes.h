#ifndef BETTERCTYPES_H
#define BETTERCTYPES_H

#define ptr(T) typeof(typeof(T)*)
#define arr(T, n) typeof(typeof(T)[n])
#define arrptr(T, n) ptr(arr(T, n))
#define fn(out, ...) typeof(typeof(out) (*)(__VA_ARGS__))

#endif
