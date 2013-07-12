#ifndef __mstring_h__
#define __mstring_h__

typedef struct mstring {
	int length;
	char *str;
} mstring;

#define mlen(s) (s).length
#define cstr(s) (s).str

#endif
