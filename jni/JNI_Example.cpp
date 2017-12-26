#include "JNI_Example.h"

JNIEXPORT jint JNICALL Example_Add(JNIEnv *env, jobject obj, jint a, jint b)
{
    return a + b;
}

JNIEXPORT jint JNICALL Example_Sub(JNIEnv *env, jobject obj, jint a, jint b)
{
    return a - b;
}