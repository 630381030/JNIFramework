#pragma once

#include <jni.h>
#include "JNI_Example.h"

extern "C" {
    //这里定义需要注册的Java层的native方法
    //例如我的包 xyz.sziit.test 下有个 Example 类
    //Example类下有两个native的方法 add() 和 sub()
    //Java的native方法对应c++的函数定义在 JNI_Example.h, Example_Add() 和 Example_Sub()
    #define JC_Example  "xyz/sziit/test/Example"
    JNINativeMethod methods_Example[] =
    {
        {"add", "(II)I", (void*) Example_Add},
        {"sub", "(II)I", (void*) Example_Sub}
    };
}