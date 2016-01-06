#ifdef _MSC_VER
#error Not supported yet
#elif __GNUC__ >= 3

typedef void Void;
typedef bool Boolean;
typedef signed char SByte;
typedef short Int16;
typedef int Int32;
typedef long long Int64;
typedef unsigned char Byte;
typedef unsigned short Char;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
typedef unsigned long long UInt64;
typedef float Single;
typedef double Double;

#define compare_and_swap __sync_val_compare_and_swap 
#define compare_and_swap_bool __sync_bool_compare_and_swap 
#define sync_synchronize __sync_synchronize
#define fetch_and_add __sync_fetch_and_add
#define fetch_and_sub __sync_fetch_and_sub
#define add_and_fetch __sync_add_and_fetch
#define sub_and_fetch __sync_sub_and_fetch
#define swap __sync_lock_test_and_set
#define alloca __builtin_alloca

extern void *__builtin_memset(Void*,Int32,UInt32);
#define Memset __builtin_memset

extern void *__builtin_memcpy(Void*,const Void*,UInt32);

#endif

#define GC_MALLOC __alloc
#define GC_MALLOC_ATOMIC __alloc
#define GC_MALLOC_IGNORE_OFF_PAGE __alloc
#define GC_MALLOC_ATOMIC_IGNORE_OFF_PAGE __alloc
#define GC_PTHREAD_CREATE pthread_create
#define GC_PTHREAD_SIGMASK pthread_sigmask
#define GC_PTHREAD_JOIN pthread_join
#define GC_PTHREAD_DETACH pthread_detach
#define GC_PTHREAD_CANCEL pthread_cancel
#define GC_PTHREAD_KILL pthread_kill
#define GC_PTHREAD_EXIT pthread_exit

extern "C" Void* calloc(UInt32, UInt32);
extern "C" Void exit(Int32 status);

// Float
extern "C" Double fmod (Double, Double);

// misc
extern "C" Void __pure_virtual();
extern "C" Void* Memcpy(Byte* dst, Byte* src, Int32 size);
extern "C" Void __Memmove(Byte* dst, Byte* src, UInt32 size);
extern "C" Byte* __get_full_path(Byte* partial, Byte* full);

inline Void* __alloc(UInt32 size)
{
	return (Void*) calloc(1, size);
}

inline Void* __get_mutex_address(Void* _object)
{
	return (Void*) ((Void**)_object - 1);
}

inline Void* __get_cond_address(Void* _object)
{
	return (Void*) ((Void**)_object - 2);
}

inline Void* __null_address(Void* _object)
{
	_object;
	return (Void*)0;
}

template < typename T > struct __static_data
{
#if __MULTI_THREADING
	Byte* __mutex;
	Byte* __cond;
#endif
	T data;
};

#if __MULTI_THREADING || __ANDROID__
template < int N > struct __static_str
#else
template < int N > const struct __static_str
#endif
{
#if __MULTI_THREADING
	Byte* __mutex;
	Byte* __cond;
#endif
    Void** __vtbl;
    Int32 length;
	wchar_t data[N];
};

struct __interface_data
{
	Void* __vtbl;
	Void* __this;
};

Void* __new_interface(Void* _object, Void** _vtbl);
Void* __new_interface_debug(Void* _object, Void** _vtbl, SByte* __file, Int32 __line);
inline Void* __this_from_interface(Void* _object) 
{
	return (Void*) (_object ? (((__interface_data*)_object)->__this) : 0);
}

class System_Object;
extern "C" Int32 pthread_key_create(Int32* key, Void* destructor);
extern "C" Int32 pthread_key_delete(Int32 key);
extern "C" System_Object* pthread_getspecific(Int32 key);
extern "C" Int32 pthread_setspecific(Int32 key, System_Object* value);

struct System_DivideByZeroException;
Void Void_System_DivideByZeroException__ctorFN(System_DivideByZeroException* __this);
#ifdef __GC_MEMORY_DEBUG
System_DivideByZeroException* System_DivideByZeroException_System_DivideByZeroException__newFSByteP__Int32N(SByte* __file, Int32 __line);
#else
System_DivideByZeroException* System_DivideByZeroException_System_DivideByZeroException__newFN();
#endif
template < typename T > T __check_divide(T div)
{
	if (!div)
	{
		System_DivideByZeroException* _new;
#ifdef __GC_MEMORY_DEBUG
		_new = System_DivideByZeroException_System_DivideByZeroException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
		_new = System_DivideByZeroException_System_DivideByZeroException__newFN();
#endif
		Void_System_DivideByZeroException__ctorFN(_new);
		throw (::Void*) _new;
	}

	return div;
}

struct System_NullReferenceException;
Void Void_System_NullReferenceException__ctorFN(System_NullReferenceException* __this);
#ifdef __GC_MEMORY_DEBUG
System_NullReferenceException* System_NullReferenceException_System_NullReferenceException__newFSByteP__Int32N(SByte* __file, Int32 __line);
#else
System_NullReferenceException* System_NullReferenceException_System_NullReferenceException__newFN();
#endif
inline Void __check_this(Void* __this)
{
	if (__this)
	{
		return;
	}

	System_NullReferenceException* _new;
#ifdef __GC_MEMORY_DEBUG
	_new = System_NullReferenceException_System_NullReferenceException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
	_new = System_NullReferenceException_System_NullReferenceException__newFN();
#endif

	Void_System_NullReferenceException__ctorFN(_new);
	throw (Void*) _new;
}

struct System_NotSupportedException;
Void Void_System_NotSupportedException__ctorFN(System_NotSupportedException* __this);
#ifdef __GC_MEMORY_DEBUG
System_NotSupportedException* System_NotSupportedException_System_NotSupportedException__newFSByteP__Int32N(SByte* __file, Int32 __line);
#else
System_NotSupportedException* System_NotSupportedException_System_NotSupportedException__newFN();
#endif
inline Void* __throw_not_supported()
{
	System_NotSupportedException* _new;
#ifdef __GC_MEMORY_DEBUG
	_new = System_NotSupportedException_System_NotSupportedException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
	_new = System_NotSupportedException_System_NotSupportedException__newFN();
#endif
	Void_System_NotSupportedException__ctorFN(_new);
	throw (Void*) _new;
}

struct System_InvalidOperationException;
Void Void_System_InvalidOperationException__ctorFN(System_InvalidOperationException* __this);
#ifdef __GC_MEMORY_DEBUG
System_InvalidOperationException* System_InvalidOperationException_System_InvalidOperationException__newFSByteP__Int32N(SByte* __file, Int32 __line);
#else
System_InvalidOperationException* System_InvalidOperationException_System_InvalidOperationException__newFN();
#endif
inline Void* __throw_invalid_operation()
{
	System_InvalidOperationException* _new;
#ifdef __GC_MEMORY_DEBUG
	_new = System_InvalidOperationException_System_InvalidOperationException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
	_new = System_InvalidOperationException_System_InvalidOperationException__newFN();
#endif
	Void_System_InvalidOperationException__ctorFN(_new);
	throw (Void*) _new;
}

struct System_OverflowException;
Void Void_System_OverflowException__ctorFN(System_OverflowException* __this);
#ifdef __GC_MEMORY_DEBUG
System_OverflowException* System_OverflowException_System_OverflowException__newFSByteP__Int32N(SByte* __file, Int32 __line);
#else
System_OverflowException* System_OverflowException_System_OverflowException__newFN();
#endif
inline Void* __throw_overflow()
{
	System_OverflowException* _new;
#ifdef __GC_MEMORY_DEBUG
	_new = System_OverflowException_System_OverflowException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
	_new = System_OverflowException_System_OverflowException__newFN();
#endif
	Void_System_OverflowException__ctorFN(_new);
	throw (Void*) _new;
}

inline Int32 __create_thread_static(Int32* key, Void* destructor)
{
	return pthread_key_create(key, destructor);
}

inline Int32 __delete_thread_static(Int32 key)
{
	return pthread_key_delete(key);
}

inline System_Object* __get_thread_static(Int32 key)
{
	System_Object** memoryBox = (System_Object**) pthread_getspecific(key);
	if (memoryBox)
	{
		return *memoryBox;
	}

	return (System_Object*)0;
}

inline System_Object** __get_thread_static_addr(Int32 key)
{
	System_Object** memoryBox = (System_Object**) pthread_getspecific(key);
	if (memoryBox)
	{
		return memoryBox;
	}

	memoryBox = (System_Object**) GC_MALLOC(sizeof(System_Object**));
	if (!memoryBox)
	{
		System_NullReferenceException* _new;
#ifdef __GC_MEMORY_DEBUG
		_new = System_NullReferenceException_System_NullReferenceException__newFSByteP__Int32N((SByte*)__FILE__, __LINE__);
#else
		_new = System_NullReferenceException_System_NullReferenceException__newFN();
#endif

		Void_System_NullReferenceException__ctorFN(_new);
		throw (Void*) _new;
	}

	pthread_setspecific(key, (System_Object*)memoryBox);

	return memoryBox;
}

inline Void __set_thread_static(Int32 key, System_Object* _object)
{
	*__get_thread_static_addr(key) = _object;
}

extern "C" Byte* __get_full_path(Byte* partial, Byte* full);

inline SByte __add_ovf(SByte a, SByte b)
{
	SByte s = (Byte) a + (Byte) b;
	if (b >= 0)
	{
		if (s < a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s >= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Int16 __add_ovf(Int16 a, Int16 b)
{
	Int16 s = (UInt16) a + (UInt16) b;
	if (b >= 0)
	{
		if (s < a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s >= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Int32 __add_ovf(Int32 a, Int32 b)
{
	Int32 s = (UInt32) a + (UInt32) b;
	if (b >= 0)
	{
		if (s < a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s >= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Int64 __add_ovf(Int64 a, Int64 b)
{
	Int64 s = (UInt64) a + (UInt64) b;
	if (b >= 0)
	{
		if (s < a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s >= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

template < typename T > inline T __add_ovf_un(T a, T b)
{
	if ((T)-1 - (T)a <= (T) b)
	{
		__throw_overflow();
	}

	return a + b;
}

inline SByte __sub_ovf(SByte a, SByte b)
{
	SByte s = (Byte) a - (Byte) b;
	if (b >= 0)
	{
		if (s > a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s <= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Byte __sub_ovf(Byte a, Byte b)
{
	if (a < b)
	{
		__throw_overflow();
	}

	return a - b;
}

inline Int16 __sub_ovf(Int16 a, Int16 b)
{
	Int16 s = (UInt16) a - (UInt16) b;
	if (b >= 0)
	{
		if (s > a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s <= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Char __sub_ovf(Char a, Char b)
{
	if (a < b)
	{
		__throw_overflow();
	}

	return a - b;
}

inline Int32 __sub_ovf(Int32 a, Int32 b)
{
	Int32 s = (UInt32) a - (UInt32) b;
	if (b >= 0)
	{
		if (s > a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s <= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

inline Int64 __sub_ovf(Int64 a, Int64 b)
{
	Int64 s = (UInt64) a - (UInt64) b;
	if (b >= 0)
	{
		if (s > a)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (s <= a)
		{
			__throw_overflow();
		}
	}

	return s;
}

template < typename T > inline T __sub_ovf_un(T a, T b)
{
	if ((T)a < (T) b)
	{
		__throw_overflow();
	}

	return a - b;
}

#define CHAR_BIT 8
template < typename T > inline T __mul_ovf(T a, T b)
{
	const int N = (int)(sizeof(T) * CHAR_BIT);
	const T MIN = (T)1 << (N-1);
	const T MAX = ~MIN;
	if (a == MIN)
	{
		if (b == 0 || b == 1)
		{
			return a * b;
		}

		__throw_overflow();
	}
	if (b == MIN)
	{
		if (a == 0 || a == 1)
		{
			return a * b;
		}

		__throw_overflow();
	}

	T sa = a >> (N - 1);
	T abs_a = (a ^ sa) - sa;
	T sb = b >> (N - 1);
	T abs_b = (b ^ sb) - sb;
	if (abs_a < 2 || abs_b < 2)
		return a * b;
	if (sa == sb)
	{
		if (abs_a > MAX / abs_b)
		{
			__throw_overflow();
		}
	}
	else
	{
		if (abs_a > MIN / -abs_b)
		{
			__throw_overflow();
		}
	}

	return a * b;
}

inline Byte __mul_ovf_un(Byte a, Byte b)
{
	if (a != 0 && b > ((Byte)-1) / a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline UInt16 __mul_ovf_un(UInt16 a, UInt16 b)
{
	if (a != 0 && b > ((UInt16)-1) / a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline UInt32 __mul_ovf_un(UInt32 a, UInt32 b)
{
	if (a != 0 && b > ((UInt32)-1) / a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline UInt64 __mul_ovf_un(UInt64 a, UInt64 b)
{
	if (a != 0 && b > ((UInt64)-1) / a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline SByte __mul_ovf_un(SByte a, SByte b)
{
	if ((Byte)a != 0 && (Byte)b > ((Byte)-1) / (Byte)a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline Int16 __mul_ovf_un(Int16 a, UInt16 b)
{
	if ((UInt16)a != 0 && (UInt16)b > ((UInt16)-1) / (UInt16)a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline Int32 __mul_ovf_un(Int32 a, Int32 b)
{
	if ((UInt32)a != 0 && (UInt32)b > ((UInt32)-1) / (UInt32)a)
	{
		__throw_overflow();
	}

	return a * b;
}

inline Int64 __mul_ovf_un(Int64 a, Int64 b)
{
	if ((UInt64)a != 0 && (UInt64)b > ((UInt64)-1) / (UInt64)a)
	{
		__throw_overflow();
	}

	return a * b;
}