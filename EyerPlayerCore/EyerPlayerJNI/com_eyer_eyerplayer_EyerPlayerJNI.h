/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_eyer_eyerplayer_EyerPlayerJNI */

#ifndef _Included_com_eyer_eyerplayer_EyerPlayerJNI
#define _Included_com_eyer_eyerplayer_EyerPlayerJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_init
 * Signature: (Landroid/view/Surface;)J
 */
JNIEXPORT jlong JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1init
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_change
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1change
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1init
  (JNIEnv *, jclass);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_open
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1open
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_set_gl_ctx
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1set_1gl_1ctx
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_unset_gl_ctx
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1unset_1gl_1ctx
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
