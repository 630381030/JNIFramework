#include <jni.h>
#include <stdint.h>
#include "JNI_NativeMethods.h"

extern "C" {

    #define REGISTERCLASSMETHODS(sig, method)   JniRegisterNativeMethods(env, sig, method, sizeof(method) / sizeof(method[0]))

    void RegisterClassesMethods(JNIEnv *env);

    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
    {
        JNIEnv *pEnv = NULL;
        if(vm->GetEnv((void**)&pEnv, JNI_VERSION_1_4) != JNI_OK)
        {
            return JNI_ERR;
        }

        RegisterClassesMethods(pEnv);

        return JNI_VERSION_1_4;
    }

    int JniRegisterNativeMethods(JNIEnv *env, const char *className, const JNINativeMethod *gMethods, int numMethods)
    {
        jclass clazz = env->FindClass(className);
        if(clazz == NULL)
        {
            return false;
        }

        int result = true;
        if(env->RegisterNatives(clazz, gMethods, numMethods) < 0)
        {
            result = false;
        }
        env->DeleteLocalRef(clazz);
        return result;
    }

    void RegisterClassesMethods(JNIEnv *env)
    {
        //将Java的native方法注册到JNI，native相关信息定义在 JNI_NativeMethods.h 中
        REGISTERCLASSMETHODS(JC_Example, methods_Example);
    }
}