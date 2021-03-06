/* Copyright 2015 Samsung Electronics Co., LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/***************************************************************************
 * Printing Java stacktrace when native crash happens. Using tag gvrf
 ***************************************************************************/

#ifndef GVR_JAVA_STACK_TRACE_H_
#define GVR_JAVA_STACK_TRACE_H_

#include "jni.h"
#include <string>

namespace gvr {
static void printJavaCallStack(JNIEnv *env, const char *msg) {
    jclass exception = env->FindClass(
            "org/gearvrf/utility/GVRJniException");
    jclass global_ex = (jclass) env->NewGlobalRef(exception);
    jmethodID throw_ex = env->GetStaticMethodID(global_ex, "printCallStack",
            "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(global_ex, throw_ex, env->NewStringUTF(msg));
}

static void printJavaCallStack(JNIEnv *env, const std::string &msg) {
    printJavaCallStack(env, msg.c_str());
}

}

#endif
