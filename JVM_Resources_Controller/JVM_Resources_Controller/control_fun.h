#include<stdlib.h>
#include "jni.h"

/*
enum Library_Status{Loaded,Loadding,Unload,Unknow};
struct _Library_Loaded{
enum Library_Status status;
char *const name;
void *const Binary_Library;
};*/


typedef struct _JNI_Class_Stack JNI_Class_Stack;
struct _JNI_Class_Stack{
	const int id;
	int len;
	char *const ClassName;
	JNINativeMethod **Methods_List;
	int(*add_Methods)(JNI_Class_Stack *, JNINativeMethod);
	int(*Remove_Methods)(JNI_Class_Stack *, JNINativeMethod);//未写
	int(*Clean_all_Methods)(JNI_Class_Stack *);//未写
};

typedef struct _VM_stack{
	void * JVM_Handle;
	int(*Add_Class_Stack)(void * JVM_Handle, JNI_Class_Stack *);
	Receipt *(*Run_main_method)(void * JVM_Handle);
	int(*Run_Jni_Onload)(void * JVM_Handle);
	int(*Stop_vm)(void * JVM_Handle);
	int(*Recycling_resources)(void * JVM_Handle);//未写
}VM_stack;


Receipt * Create_JVM_Management(void);
JNI_Class_Stack *alloc_JNI_Class_Stack(char * ClassName);