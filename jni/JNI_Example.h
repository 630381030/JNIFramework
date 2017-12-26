#pragma once

#include <jni.h>

JNIEXPORT jint JNICALL Example_Add(JNIEnv *env, jobject obj, jint a, jint b);

JNIEXPORT jint JNICALL Example_Sub(JNIEnv *env, jobject obj, jint a, jint b);