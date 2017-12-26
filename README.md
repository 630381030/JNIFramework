# 动态注册JNI

使用`JNI_OnLoad()`动态注册JNI函数。

Github:[https://github.com/630381030/JNIFramework](https://github.com/630381030/JNIFramework)



## 添加CPP文件

添加实现你的c++文件到目录中（例如**JNI_Example.cpp**）。

## 添加CPP映射Java的Native信息

在**JNI_NativeMehtods.h**中添加你的Java的Native方法对应的信息。

例如**JNI_Example.cpp**对应Java包下**Example.java**的信息

```cpp
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
```

## 将映射信息注册到JNI中

在JNI_Init.cpp文件中的void RegisterClassesMethods(JNIEnv *env);函数注册你的映射信息。

```cpp
    void RegisterClassesMethods(JNIEnv *env)
    {
        //将Java的native方法注册到JNI，native相关信息定义在 JNI_NativeMethods.h 中
        REGISTERCLASSMETHODS(JC_Example, methods_Example);
    }
```

## 完成

至此已完成，执行`ndk-build`即可编译。详细编译规则请修改**Android.mk**文件