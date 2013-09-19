/**************************************************************************
	      Copyright (c) 1992-2000 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

// "@(#)$Id$"

#ifndef OO_STRING_H
#define OO_STRING_H

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#include <string.h>
#include <ooVArray.h>
#if !defined(OO_NT) && !defined(OO_IBM_RS6000)
#include <wchar.h>
#endif

OO_STORAGE_SPECIFIER size_t opiString16Len(const ooChar16* p);
OO_STORAGE_SPECIFIER int opiString16Cmp(const ooChar16* s1, const ooChar16* s2);
OO_STORAGE_SPECIFIER ooChar16* opiString16Cpy(ooChar16* target, const ooChar16* source);
OO_STORAGE_SPECIFIER size_t opiString32Len(const ooChar32* p);
OO_STORAGE_SPECIFIER int opiString32Cmp(const ooChar32* s1, const ooChar32* s2);
OO_STORAGE_SPECIFIER ooChar32* opiString32Cpy(ooChar32* target, const ooChar32* source);

#ifdef OO_H

inline
ooBoolean
ooStrSame(const char* p1, const char* p2)
{
  return (p1 && p2) ? ((strcmp(p1, p2)) ? oocFalse : oocTrue) : oocFalse;
}


inline
ooBoolean
ooStrDiff(const char* p1, const char* p2)
{
  return ! ooStrSame(p1, p2);
}


// Make ooVArray(char) the same as ooVArray(ooChar) for name mangling.
#define char_ooVArray ooChar_ooVArray


#define OO_VARRAY_CHAR
ooStorageDeclare(ooVArray,ooChar)

// Class definition of an Objectivity/DB string
//   - A VArray of character is used to support the C string
OO_CLI_PUBLIC class OO_STORAGE_SPECIFIER ooVString : public ooVArray(ooChar) {
  public:
    ooVString() {}
    ooVString(const char* p);
    ooVString(const ooVString& s);
    ~ooVString() {}
    ooVString& operator=(const char* p);
    ooVString& assign(const char* c , size_t n);
    ooVString& operator+=(const char* p);
    ooStatus resize(uint32 newLength);
    char* head() const { return ooVArray(ooChar)::head(); }
    operator const char*() const { return head(); }
    uint32 length() const {
      char *p = head();
      return (p) ? ((uint32) strlen(p)) : 0;
    }
    char& operator[](int index) const {
      return ooVArray(ooChar)::operator[](index);
    }
    char& operator[](unsigned int index) const
    {
      return ooVArray(ooChar)::operator[](index);
    }
    char& operator[](long index) const
    {
      return ooVArray(ooChar)::operator[]((uint32)index);
    }
    char& operator[](unsigned long index) const
    {
      return ooVArray(ooChar)::operator[]((uint32)index);
    }
 private:
    inline ooStatus resize_internal(uint32 newLength);
};

// ooVString compatible C style string operations
inline
ooVString&
strcat(ooVString& vs, const char* s)
{
  vs += s;
  return vs;
}

inline
ooVString&
strcpy(ooVString& vs, const char* s)
{
  vs = s;
  return vs;
}

inline
uint32
strlen(ooVString& vs)
{
  return vs.length();
}

// Omit these undocumented functions if the compiler will complain. (SPR 17775)
#if !defined(_MSC_VER) || defined(_CRT_SECURE_NO_DEPRECATE) || (_MSC_VER < 1400)
inline
ooVString&
strncat(ooVString& vs, const char* s, size_t size)
{
  vs.resize(vs.length()+(uint32)size+1);
  strncat(vs.head(), s,	 size);
  return vs;
}

inline
ooVString&
strncpy(ooVString& vs, const char* s, size_t size)
{
  vs.resize((uint32) size+1);
  strncpy(vs.head(), s, size);
  vs.set((uint32) size,'\0');
  return vs;
}

inline
char*
strtok(ooVString& vs, const char* s)
{
  return strtok(vs.head(),s);
}
#endif

inline
ooVString& opiReallocName(ooVString& vs, size_t size)
{
  vs.resize((uint32) size);
  return vs;
}

inline
int
opiFreeName(ooVString& vs)
{
  return vs.resize(0);
}


///////////////////////////////////////////////////////////////////////////////
// string relational operators

inline
int
operator==(const ooVString &left,
	   const ooVString &right)
{
  char *left_ptr = left.head();
  char *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (strcmp(left_ptr, right_ptr) == 0)
				: 0)
		   : !right_ptr);
}

inline
int
operator==(const ooVString &left,
	   const char *right)
{
  char *left_ptr = left.head();
  return (left_ptr ? (right ? (strcmp(left_ptr, right) == 0)
			    : 0)
		   : !right);
}

inline
int
operator==(const char *left,
	   const ooVString &right)
{
  return (right == left);
}

inline
int
operator!=(const ooVString &left,
	   const ooVString &right)
{
  return !(left == right);
}

inline
int
operator!=(const ooVString &left,
	   const char *right)
{
  return !(left == right);
}

inline
int
operator!=(const char *left,
	   const ooVString &right)
{
  return !(left == right);
}

inline
int
operator<(const ooVString &left,
	  const ooVString &right)
{
  char *left_ptr = left.head();
  char *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (strcmp(left_ptr, right_ptr) < 0)
				: 0)
		   : 1);
}

inline
int
operator<(const ooVString &left,
	  const char *right)
{
  char *left_ptr = left.head();
  return (left_ptr ? (right ? (strcmp(left_ptr, right) < 0)
			    : 0)
		   : 1);
}

inline
int
operator<(const char *left,
	  const ooVString &right)
{
  return (right < left);
}

inline
int
operator>(const ooVString &left,
	  const ooVString &right)
{
  return (right < left);
}

inline
int
operator>(const ooVString &left,
	  const char *right)
{
  return (right < left);
}

inline
int
operator>(const char *left,
	  const ooVString &right)
{
  return (right < left);
}

inline
int
operator<=(const ooVString &left,
	   const ooVString &right)
{
  return !(right < left);
}

inline
int
operator<=(const ooVString &left,
	   const char *right)
{
  return !(right < left);
}

inline
int
operator<=(const char *left,
	   const ooVString &right)
{
  return !(right < left);
}

inline
int
operator>=(const ooVString &left,
	   const ooVString &right)
{
  return (right <= left);
}

inline
int
operator>=(const ooVString &left,
	   const char *right)
{
  return (right <= left);
}

inline
int
operator>=(const char *left,
	   const ooVString &right)
{
  return (right <= left);
}


//////////////////////////
//  class ooUtf8String  //
//////////////////////////

OO_CLI_PUBLIC class OO_STORAGE_SPECIFIER ooUtf8String: public ooVArray(ooChar)
{
      public:

        ooUtf8String() { }

        ooUtf8String(const char* p);

        ooUtf8String(const wchar_t* p) { init(p); }

#ifndef OO_WCHAR_16
        ooUtf8String(const ooChar16* p){ init(p); }
#else
        ooUtf8String(const ooChar32* p){ init(p); }
#endif

        ~ooUtf8String() {}

	char* head() const { return ooVArray(ooChar)::head(); }

        operator const char*() const { return head(); }

        size_t length() const { return strlen(head()); }

        void setFromUtf8(const char* utf8string) { *this = utf8string; }

        // Removed. Just call 'open' directly.
        // ooStatus openVar() { return ooVArray(ooChar)::open(); }

        ooUtf8String& operator=(const char* p);

        ooUtf8String& operator+=(const char* p);

        // Public Methods that take ooChar16
        ooUtf8String& operator=(const ooChar16* p);

        ooUtf8String& operator+=(const ooChar16* p);

        // Public Methods that take ooChar32
        ooUtf8String& operator=(const ooChar32* p);

        ooUtf8String& operator+=(const ooChar32* p);

	ooStatus resize(uint32 newLength);

        ooChar& operator[](int index) const
        { return ooVArray(ooChar)::operator[](index); }

        ooChar& operator[](unsigned int index) const
        { return ooVArray(ooChar)::operator[](index); }

        ooChar& operator[](long index) const
        { return ooVArray(ooChar)::operator[]((uint32)index); }

        ooChar& operator[](unsigned long index) const
        { return ooVArray(ooChar)::operator[]((uint32)index); }

      private:
	inline ooStatus resize_internal(uint32 newLength);
        void init(const ooChar16* p);
        void init(const ooChar32* p);

};

/////////////////////////////////////////
//  ooUtf8String relational operators  //
/////////////////////////////////////////

inline int operator==(const ooUtf8String &left, const ooUtf8String &right)
{
  char *left_ptr = left.head();
  char *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (strcmp(left_ptr, right_ptr) == 0)
				: 0)
		  : !right_ptr);
}

inline int operator==(const ooUtf8String &left, const char *right)
{
  char *left_ptr = left.head();
  return (left_ptr ? (right ? (strcmp(left_ptr, right) == 0)
			    : 0)
		  : !right);
}

inline int operator==(const char *left, const ooUtf8String &right)
{
  char *right_ptr = right.head();
  return (left ? (right_ptr ? (strcmp(left, right_ptr) == 0)
          : 0)
      : !right_ptr);
}

inline int operator!=(const ooUtf8String &left, const ooUtf8String &right)
{
  return !(left == right);
}

inline int operator!=(const ooUtf8String &left, const char *right)
{
  return !(left == right);
}

inline int operator!=(const char *left, const ooUtf8String &right)
{
  return !(left == right);
}

inline int operator<(const ooUtf8String &left, const ooUtf8String &right)
{
  char *left_ptr = left.head();
  char *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (strcmp(left_ptr, right_ptr) < 0)
				: 0)
		  : 1);
}

inline int operator<(const ooUtf8String &left, const char *right)
{
  char *left_ptr = left.head();
  return (left_ptr ? (right ? (strcmp(left_ptr, right) < 0)
			    : 0)
		  : 1);
}

inline int operator<(const char *left, const ooUtf8String &right)
{
  char *right_ptr = right.head();
  return (left ? (right_ptr ? (strcmp(left, right_ptr) < 0)
			    : 0)
		  : 1);
}

inline int operator>(const ooUtf8String &left, const ooUtf8String &right)
{
  return (right < left);
}

inline int operator>(const ooUtf8String &left, const char *right)
{
  return (right < left);
}

inline int operator>(const char *left, const ooUtf8String &right)
{
  return (right < left);
}

inline int operator<=(const ooUtf8String &left, const ooUtf8String &right)
{
  return !(right < left);
}

inline int operator<=(const ooUtf8String &left, const char *right)
{
  return !(right < left);
}

inline int operator<=(const char *left, const ooUtf8String &right)
{
  return !(right < left);
}

inline int operator>=(const ooUtf8String &left, const ooUtf8String &right)
{
  return (right <= left);
}

inline int operator>=(const ooUtf8String &left, const char *right)
{
  return (right <= left);
}

inline int operator>=(const char *left, const ooUtf8String &right)
{
  return (right <= left);
}

////////////////////////////
//  class ooUtf8Iterator  //
////////////////////////////

class OO_STORAGE_SPECIFIER ooUtf8Iterator
{
private:

  const char* ptr;
  ooBoolean isSurrogate;

public:

  ooUtf8Iterator() 
    { ptr = NULL; isSurrogate = 0; }

  ooUtf8Iterator( const char* s ) 
    { ptr = s; isSurrogate = 0; }

  ooUtf8Iterator( const ooUtf8String & s ) 
    { ptr = s.head(); isSurrogate = 0; }

  ooUtf8Iterator & operator = ( const ooUtf8String & s )
    { ptr = s.head(); return *this; }

  ooUtf8Iterator & operator = ( const ooUtf8Iterator & s )
    { ptr = s.ptr; return *this; }

  wchar_t operator *() const;

  // prefix version
  ooUtf8Iterator& operator ++();

  // postfix version. (int) used only to differentiate the signature with the one above
  ooUtf8Iterator operator ++(int)
  {
    ooUtf8Iterator cur = *this;
    ++*this;
    return cur;
  }

  ooBoolean isSurrogateValue()
    { return isSurrogate; }

  ooBoolean operator == (const ooUtf8Iterator& other)const
    { return ptr==other.ptr; }

  ooBoolean operator != (const ooUtf8Iterator& other)const
    { return ptr!=other.ptr; }
};

//  class ooUtf8CharacterIterator
//  Similar to ooUtf8Iterator, dereference operator
//  returns ooChar32 instead of wchar_t.
#ifdef OO_WCHAR_16
class OO_STORAGE_SPECIFIER ooUtf8CharacterIterator
{
private:

  const char* ptr;

public:

  ooUtf8CharacterIterator() 
    { ptr = NULL; }

  ooUtf8CharacterIterator( const char* s ) 
    { ptr = s; }

  ooUtf8CharacterIterator( const ooUtf8String & s ) 
    { ptr = s.head(); }

  ooUtf8CharacterIterator & operator = ( const ooUtf8String & s )
    { ptr = s.head(); return *this; }

  ooUtf8CharacterIterator & operator = ( const ooUtf8CharacterIterator & s )
    { ptr = s.ptr; return *this; }

  ooChar32 operator *() const;

  // prefix version
  ooUtf8CharacterIterator& operator ++();

  // postfix version. (int) used only to differentiate the signature with the one above
  ooUtf8CharacterIterator operator ++(int)
  {
    ooUtf8CharacterIterator cur = *this;
    ++*this;
    return cur;
  }

  ooBoolean operator == (const ooUtf8CharacterIterator& other)const
    { return ptr==other.ptr; }

  ooBoolean operator != (const ooUtf8CharacterIterator& other)const
    { return ptr!=other.ptr; }
};
#else
typedef ooUtf8Iterator ooUtf8CharacterIterator;
#endif

class OO_STORAGE_SPECIFIER ooUtf32String;

///////////////////////////
//  class ooUtf16String  //
///////////////////////////

#ifndef OO_DDL_TRANSLATION 
ooStorageDeclare(ooVArray,ooChar16)
#endif

OO_CLI_PUBLIC class OO_STORAGE_SPECIFIER ooUtf16String : public ooVArray(ooChar16)
{
  public:
    ooUtf16String() {}

    ooUtf16String(const ooUtf8String& s) {
      ooChar *p = s.head();
      init(p);
    }

    ooUtf16String(const wchar_t* p) { init(p); }

    ~ooUtf16String() {}

    ooUtf16String& operator=(const wchar_t* p) {
      init(p);
      return *this;
    }

    // assign from the first n characters of string c
    ooUtf16String& assign(const char* c , size_t n);
    ooUtf16String& assign(const ooChar16* c , size_t n);

    ooUtf16String& operator+=(const wchar_t* p);

#ifndef OO_WCHAR_16

    ooUtf16String(const ooChar16* p) { init(p); }

    ooUtf16String& operator=(const ooChar16* p) {
      init(p);
      return *this;
    }

    ooUtf16String& operator+=(const ooChar16* p);

#else

    ooUtf16String(const ooChar32* p) { init(p); }

    ooUtf16String& operator=(const ooChar32* p) {
      init(p);
      return *this;
    }

    ooUtf16String& operator+=(const ooChar32* p);

#endif

    ooUtf16String& operator=(const ooUtf8String& s) {
      ooChar *p = s.head();
      init(p);
      return *this;
    }

    ooUtf16String& operator=(const char* p) { 
      initAsIs(p);
      return *this;
    }

    ooUtf16String(const char* s) { initAsIs(s); }

    ooUtf16String& operator+=(const char* s);

    ooUtf16String& operator+=(const ooUtf8String& s);

    ooStatus resize(uint32 newLength);

    ooChar16* head() const { return ooVArray(ooChar16)::head(); }

    operator const ooChar16*() const { return head(); }

    size_t length() const { return opiString16Len(head()); }

    void setFromUtf8(const char* utf8string) { init(utf8string); }

    ooChar16& operator[](int index) const
    { return ooVArray(ooChar16)::operator[](index); }

    ooChar16& operator[](unsigned int index) const
    { return ooVArray(ooChar16)::operator[](index); }

    ooChar16& operator[](long index) const
        { return ooVArray(ooChar16)::operator[]((uint32)index); }

    ooChar16& operator[](unsigned long index) const
        { return ooVArray(ooChar16)::operator[]((uint32)index); }

 private:
    inline ooStatus resize_internal(uint32 newLength);
    void init(const wchar_t* p);
    void init(const char* p);
    void initAsIs(const char* p);
#ifndef OO_WCHAR_16
    void init(const ooChar16 *p);
#else
    void init(const ooChar32 *p);
#endif
};

//////////////////////////////////////////
//  ooUtf16String relational operators  //
//////////////////////////////////////////

inline int operator==(const ooUtf16String &left, const ooUtf16String &right)
{
  ooChar16 *left_ptr = left.head();
  ooChar16 *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (opiString16Cmp(left_ptr, right_ptr) == 0)
				: 0)
		   : !right_ptr);
}

inline int operator==(const ooUtf16String &left, const ooChar16 *right)
{
  ooChar16 *left_ptr = left.head();
  return (left_ptr ? (right ? (opiString16Cmp(left_ptr, right) == 0)
			    : 0)
		   : !right);
}

inline int operator==(const ooChar16 *left, const ooUtf16String &right)
{
  return (right == left);
}

inline int operator!=(const ooUtf16String &left,
	   const ooUtf16String &right)
{
  return !(left == right);
}

inline int operator!=(const ooUtf16String &left, const ooChar16 *right)
{
  return !(left == right);
}

inline int operator!=(const ooChar16 *left, const ooUtf16String &right)
{
  return !(left == right);
}

inline int operator<(const ooUtf16String &left, const ooUtf16String &right)
{
  ooChar16 *left_ptr = left.head();
  ooChar16 *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (opiString16Cmp(left_ptr, right_ptr) < 0)
				: 0)
		   : 1);
}

inline int operator<(const ooUtf16String &left, const ooChar16 *right)
{
  ooChar16 *left_ptr = left.head();
  return (left_ptr ? (right ? (opiString16Cmp(left_ptr, right) < 0)
			    : 0)
		   : 1);
}

inline int operator<(const ooChar16 *left, const ooUtf16String &right)
{
  ooChar16 *right_ptr = right.head();
  return (left ? (right_ptr ? (opiString16Cmp(left, right_ptr) < 0)
			    : 0)
		   : 1);
}

inline int operator>(const ooUtf16String &left, const ooUtf16String &right)
{
  return (right < left);
}

inline int operator>(const ooUtf16String &left, const ooChar16 *right)
{
  return (right < left);
}

inline int operator>(const ooChar16 *left, const ooUtf16String &right)
{
  return (right < left);
}

inline int operator<=(const ooUtf16String &left, const ooUtf16String &right)
{
  return !(right < left);
}

inline int operator<=(const ooUtf16String &left, const ooChar16 *right)
{
  return !(right < left);
}

inline int operator<=(const ooChar16 *left, const ooUtf16String &right)
{
  return !(right < left);
}

inline int operator>=(const ooUtf16String &left, const ooUtf16String &right)
{
  return (right <= left);
}

inline int operator>=(const ooUtf16String &left, const ooChar16 *right)
{
  return (right <= left);
}

inline int operator>=(const ooChar16 *left, const ooUtf16String &right)
{
  return (right <= left);
}

/////////////////////////////
//  class ooUtf16Iterator  //
/////////////////////////////

#ifdef OO_WCHAR_16
typedef const ooChar16* ooUtf16Iterator;
#else
class OO_STORAGE_SPECIFIER ooUtf16Iterator
{
private:

  const ooChar16* ptr;

public:

  ooUtf16Iterator() { ptr = NULL; }

  ooUtf16Iterator( const ooChar16* s ) { ptr = s; }

  ooUtf16Iterator( const ooUtf16String & s ) { ptr = s.head(); }

  ooUtf16Iterator & operator = ( const ooUtf16String & s )
    { ptr = s.head(); return *this; }

  ooUtf16Iterator & operator = ( const ooUtf16Iterator & s )
    { ptr = s.ptr; return *this; }

  wchar_t operator *() const;

  // prefix version
  ooUtf16Iterator& operator ++();

  // postfix version. (int) used only to differentiate the signature with the one above
  ooUtf16Iterator operator ++(int)
  {
    ooUtf16Iterator cur = *this;
    ++*this;
    return cur;
  }

  ooBoolean operator == (const ooUtf16Iterator& other)const
  {
    return ptr==other.ptr;
  }

  ooBoolean operator != (const ooUtf16Iterator& other)const
  {
    return ptr!=other.ptr;
  }
};
#endif

//  class ooUtf16CharacterIterator
//  Similar to ooUtf16Iterator, dereference operator
//  returns ooChar32 instead of wchar_t.
#ifdef OO_WCHAR_16
class OO_STORAGE_SPECIFIER ooUtf16CharacterIterator
{
private:

  const ooChar16* ptr;

public:

  ooUtf16CharacterIterator() { ptr = NULL; }

  ooUtf16CharacterIterator( const ooChar16* s ) { ptr = s; }

  ooUtf16CharacterIterator( const ooUtf16String & s ) { ptr = s.head(); }

  ooUtf16CharacterIterator & operator = ( const ooUtf16String & s )
    { ptr = s.head(); return *this; }

  ooUtf16CharacterIterator & operator = ( const ooUtf16CharacterIterator & s )
    { ptr = s.ptr; return *this; }

  ooChar32 operator *() const;

  // prefix version
  ooUtf16CharacterIterator& operator ++();

  // postfix version. (int) used only to differentiate the signature with the one above
  ooUtf16CharacterIterator operator ++(int)
  {
    ooUtf16CharacterIterator cur = *this;
    ++*this;
    return cur;
  }

  ooBoolean operator == (const ooUtf16CharacterIterator& other)const
  {
    return ptr==other.ptr;
  }

  ooBoolean operator != (const ooUtf16CharacterIterator& other)const
  {
    return ptr!=other.ptr;
  }
};
#else
typedef ooUtf16Iterator ooUtf16CharacterIterator;
#endif

///////////////////////////
//  class ooUtf32String  //
///////////////////////////

ooStorageDeclare(ooVArray,ooChar32)

OO_CLI_PUBLIC class OO_STORAGE_SPECIFIER ooUtf32String : public ooVArray(ooChar32)
{
  public:
    ooUtf32String() {}

    ooUtf32String(const ooUtf8String& s) {
      ooChar *p = s.head();
      init(p);
    }

    ooUtf32String(const wchar_t* p) { init(p); }

    ~ooUtf32String() {}

    ooUtf32String& operator=(const wchar_t* p) {
		  init(p);
		  return *this;
	  }

    // assign from the first n characters of string c
    ooUtf32String& assign(const char* c , size_t n);
    ooUtf32String& assign(const ooChar16* c , size_t n);
    ooUtf32String& assign(const ooChar32* c , size_t n);

    ooUtf32String& operator+=(const wchar_t* p);

#ifndef OO_WCHAR_16

    ooUtf32String(const ooChar16* p) { init(p); }

    ooUtf32String& operator=(const ooChar16* p) {
		  init(p);
		  return *this;
	  }

    ooUtf32String& operator+=(const ooChar16* p);

#else

    ooUtf32String(const ooChar32* p) { init(p); }

    ooUtf32String& operator=(const ooChar32* p) {
		  init(p);
		  return *this;
	  }

    ooUtf32String& operator+=(const ooChar32* p);

#endif

    ooUtf32String& operator=(const ooUtf8String& s) {
      ooChar *p = s.head();
      init(p);
      return *this;
    }
    
    ooUtf32String& operator=(const char* s) {
      initAsIs(s);
      return *this;
    }

    ooUtf32String(const char* s) { initAsIs(s); }

    ooUtf32String& operator+=(const char* s);

    ooUtf32String& operator+=(const ooUtf8String& s);

    ooStatus resize(uint32 newLength);

    ooChar32* head() const { return ooVArray(ooChar32)::head(); }

    operator const ooChar32*() const { return head(); }

    size_t length() const { return opiString32Len(head()); }

    void setFromUtf8(const char* utf8string) { init(utf8string); }

    ooChar32& operator[](int index) const
        { return ooVArray(ooChar32)::operator[](index); }

    ooChar32& operator[](unsigned int index) const
        { return ooVArray(ooChar32)::operator[](index); }

    ooChar32& operator[](long index) const
        { return ooVArray(ooChar32)::operator[]((uint32)index); }

    ooChar32& operator[](unsigned long index) const
        { return ooVArray(ooChar32)::operator[]((uint32)index); }

 private:

    inline ooStatus resize_internal(uint32 newLength);
    void init(const wchar_t *p);
    void init(const char *p);
    void initAsIs(const char *p);
#ifndef OO_WCHAR_16
    void init(const ooChar16 *p);
#else
    void init(const ooChar32 *p);
#endif
};

#ifndef OO_WCHAR_16 
typedef const ooChar32* ooUtf32Iterator;
#else
class OO_STORAGE_SPECIFIER ooUtf32Iterator
{
private:

  const ooChar32* ptr;
  ooBoolean isSurrogate;

public:

  ooUtf32Iterator() { ptr = NULL; isSurrogate = 0; }

  ooUtf32Iterator( const ooChar32* s ) { ptr = s; isSurrogate = 0; }

  ooUtf32Iterator( const ooUtf32String & s ) { ptr = s.head(); isSurrogate = 0; }

  ooUtf32Iterator & operator = ( const ooUtf32String & s )
    { ptr = s.head(); return *this; }

  ooUtf32Iterator & operator = ( const ooUtf32Iterator & s )
    { ptr = s.ptr; return *this; }

  wchar_t operator *() const;

  // prefix version
  ooUtf32Iterator& operator ++();

  // postfix version. (int) used only to differentiate the signature with the one above
  ooUtf32Iterator operator ++(int)
  {
    ooUtf32Iterator cur = *this;
    ++*this;
    return cur;
  }

  ooBoolean isSurrogateValue()
    { return isSurrogate; }

  ooBoolean operator == (const ooUtf32Iterator& other)const
  {
    return ptr==other.ptr;
  }

  ooBoolean operator != (const ooUtf32Iterator& other)const
  {
    return ptr!=other.ptr;
  }
};

#endif

//  class ooUtf32CharacterIterator
//  Similar to ooUtf32Iterator, dereference operator
//  returns ooChar32 instead of wchar_t.
typedef const ooChar32* ooUtf32CharacterIterator;

//////////////////////////////////////////
//  ooUtf32String relational operators  //
//////////////////////////////////////////

inline int operator==(const ooUtf32String &left, const ooUtf32String &right)
{
  ooChar32 *left_ptr = left.head();
  ooChar32 *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (opiString32Cmp(left_ptr, right_ptr) == 0)
				: 0)
		   : !right_ptr);
}

inline int operator==(const ooUtf32String &left, const ooChar32 *right)
{
  ooChar32 *left_ptr = left.head();
  return (left_ptr ? (right ? (opiString32Cmp(left_ptr, right) == 0)
			    : 0)
		   : !right);
}

inline int operator==(const ooChar32 *left, const ooUtf32String &right)
{
  return (right == left);
}

inline int operator!=(const ooUtf32String &left, const ooUtf32String &right)
{
  return !(left == right);
}

inline int operator!=(const ooUtf32String &left, const ooChar32 *right)
{
  return !(left == right);
}

inline int operator!=(const ooChar32 *left, const ooUtf32String &right)
{
  return !(left == right);
}

inline int operator<(const ooUtf32String &left, const ooUtf32String &right)
{
  ooChar32 *left_ptr = left.head();
  ooChar32 *right_ptr = right.head();
  return (left_ptr ? (right_ptr ? (opiString32Cmp(left_ptr, right_ptr) < 0)
				: 0)
		   : 1);
}

inline int operator<(const ooUtf32String &left, const ooChar32 *right)
{
  ooChar32 *left_ptr = left.head();
  return (left_ptr ? (right ? (opiString32Cmp(left_ptr, right) < 0)
			    : 0)
		   : 1);
}

inline int operator<(const ooChar32 *left, const ooUtf32String &right)
{
  ooChar32 *right_ptr = right.head();
  return (left ? (right_ptr ? (opiString32Cmp(left, right_ptr) < 0)
			    : 0)
		   : 1);
}

inline int operator>(const ooUtf32String &left, const ooUtf32String &right)
{
  return (right < left);
}

inline int operator>(const ooUtf32String &left, const ooChar32 *right)
{
  return (right < left);
}

inline int operator>(const ooChar32 *left, const ooUtf32String &right)
{
  return (right < left);
}

inline int operator<=(const ooUtf32String &left, const ooUtf32String &right)
{
  return !(right < left);
}

inline int operator<=(const ooUtf32String &left, const ooChar32 *right)
{
  return !(right < left);
}

inline int operator<=(const ooChar32 *left, const ooUtf32String &right)
{
  return !(right < left);
}

inline int operator>=(const ooUtf32String &left, const ooUtf32String &right)
{
  return (right <= left);
}

inline int operator>=(const ooUtf32String &left, const ooChar32 *right)
{
  return (right <= left);
}

inline int operator>=(const ooChar32 *left, const ooUtf32String &right)
{
  return (right <= left);
}

#if defined(OO_DDL_TRANSLATION)
// Retrofit type numbers for FDs created before R93.  (SPR 18301)
#pragma ooassign ooVArray(ooChar16) oocChar16_ooVArrayTypeN
#pragma ooassign ooVArray(ooChar32) oocChar32_ooVArrayTypeN
#pragma ooassign ooUtf16String      oocUtf16StringTypeN
#pragma ooassign ooUtf32String      oocUtf32StringTypeN
#endif

/*****************************************************************************/

// Class definition of an Objectivity/DB string
//   - use fixed character array and VArray of character
/*
The following template defines the generic class definition of an
Objectivity/DB string.
It consists of two parts - fixed character array and VArray of character.
If a C string can be put into the fixed part, then it will be in the fixed
part.  Otherwise, it will be put in the VArray.
You can define the length of the fixed part to optimize the performance.

An Objectivity/DB string behaves just like a normal C string, which is
NULL terminated.
To use a string whose length for the fixed part is N, where N > 0,
simply use ooString(N) as a data type.

The following macro calls were required by previous versions,
but should be removed now:

	declare(ooString,N);
	implement(ooString,N);

For example, ooString(8) is a class which has a length of 8 for the fixed
character array.

*/


// Macro ooString is defined in oo.h.

#define ooStringdeclare(N)

#define ooStringsdeclare(N,storage_attribute)				      \
template class storage_attribute ooString(N)

#ifdef OO_DDL_TRANSLATION
// DDL compiler and schema recognize only the old name
#define ooStringT opiString
#else
#define opiString ooStringT
#endif

template<int N>
class opiString
{
  private:
    enum {N_minus_1 = N - 1};
    ooBoolean isVArray() const { return _fix[N_minus_1]; }
    void markFix()	       { _fix[N_minus_1] = 0; }
    void markVArray()	       { _fix[N_minus_1] = 1; }
    void clear()
    {
	if (isVArray()) _v.resize(0);
	_fix[0] = 0;
	markFix();
    }
    void init(const char* s);

  public:
    opiString() { _fix[0] = 0; markFix(); }
    opiString(const char* s) { init(s); }
    opiString(const ooString(N)& s) { init(s.head()); }
    opiString(const ooVString& s) { init(s.head()); }

    ~opiString() { }

    ooString(N)& operator=(const char* s);
    ooString(N)& operator+=(const char* s2);

    char* head() const { return (isVArray() ? _v.head() : (char*)_fix); }
    uint32 length() const { return strlen((isVArray()) ? _v.head() : _fix); }
    ooStatus resize(uint32 newLength);

    operator const char*() const { return head(); }
    operator ooVString() const { return ooVString(head()); }

    ooStatus update() { return isVArray() ? _v.update() : oocSuccess; }

    char& operator[](uint32 index) const;

#ifdef OO_MSC_VISUAL_CXX
    /* For SPR 6517 */
    char &operator[](int32 index) const
	{ return operator[]((uint32)index); }
#elif defined(OO_IBM_CXXSET)
    /* Work around non-standard overload resolution in the IBM AIX 4.3
       compiler version 3.6 (SPR 15257) -- explicitly define all argument
       types to avoid automatic conversions. */
    char& operator[](int index) const
	{ return operator[]((uint32)index); }
    char& operator[](unsigned long index) const
	{ return operator[]((uint32)index); }
#endif

    ooBoolean operator==(const char* p) const
    {
	char *ps = head();
	return ooStrSame(ps, p);
    }
    ooBoolean operator==(const ooString(N)& s) const
    {
	char *ps = head(), *p = s.head();
	return ooStrSame(ps, p);
    }
    ooBoolean operator==(const ooVString& s) const
    {
	char *ps = head(), *p = s.head();
	return ooStrSame(ps, p);
    }

    ooBoolean operator!=(const char* p) const
    {
	char *ps = head();
	return ooStrDiff(ps, p);
    }
    ooBoolean operator!=(const ooString(N)& s) const
    {
	char *ps = head(), *p = s.head();
	return ooStrDiff(ps, p);
    }
    ooBoolean operator!=(const ooVString& s) const
    {
	char *ps = head(), *p = s.head();
	return ooStrDiff(ps, p);
    }

  private:
    ooVArray(ooChar) _v;
    char	     _fix[N];

  public:
    // (Note: The following functions are not friends because they need any
    //     special access permissions, but just because we are using this
    //     syntax to declare global functions as part of the class template.)

    friend ooString(N)& strcat(ooString(N)& vs, const char* s)
      { vs += s; return vs; }

    friend ooString(N)& strncat(ooString(N)& vs, const char* s, size_t size)
      {
	vs.resize((uint32)vs.length()+size+1);
	strncat(vs.head(),s,size);
	return vs;
      }

    friend inline
      ooString(N)& strcpy(ooString(N)& vs, const char* s)
      { vs = s; return vs; }

    friend
      ooString(N)& strncpy(ooString(N)& vs, const char* s, size_t size)
      {
	vs.resize((uint32)size+1);
	strncpy(vs.head(),s,size);
	vs[size]=0;
	return vs;
      }

    friend inline
      uint32 strlen(ooString(N)& vs) { return vs.length(); }

    friend inline
      char* strtok(ooString(N)& vs, const char* s)
      { return strtok(vs.head(),s); }

    friend inline
      ooString(N)& opiReallocName(ooString(N)& vs, size_t size)
      { vs.resize((uint32)size); return vs; }

    friend inline
      int opiFreeName(ooString(N)& vs) { return vs.resize(0); }
};


#define ooStringimplement(N)


template <int N>
void ooString(N)::init(const char* s)
{
    if (s == 0) {
	_fix[0] = 0;
	markFix();
	return;
    }
    int length = (int)strlen(s);
    if (length > N_minus_1) {
	_v.resize(length + 1);
	strcpy(_v.head(), s);
	markVArray();
    }
    else {
	strcpy(_fix, s);
	markFix();
    }
}

template <int N>
ooString(N)& ooString(N)::operator=(const char* s)
{
    if (s == 0) {
	clear();
	return *this;
    }
    int length = (int)strlen(s);
    if (length > N_minus_1) {
	_v.resize(length + 1);
	strcpy(_v.head(), s);
	markVArray();
    }
    else {
	if (isVArray()) _v.resize(0);
	strcpy(_fix, s);
	markFix();
    }
    return *this;
}

template <int N>
char& ooString(N)::operator[](uint32 index) const
{
    uint32 length = isVArray() ? _v.size() : N;
    if (index >= length) {
      ooWithErrorContext ec("ooString(N)::operator[]");
      return *(char*)opiBadArrayIndex(length, index); // throws exception
    }
    return (head())[index];
}

template <int N>
ooString(N)& ooString(N)::operator+=(const char* s2)
{
    int oldLength, newLength;
    if (s2 == 0) return *this;
    oldLength = length();
    newLength = oldLength + (int)strlen(s2);
    if (newLength > N_minus_1) {
	_v.resize(newLength + 1);
	if (oldLength <= N_minus_1) {
	    strcpy(_v.head(), _fix);
	}
	strcpy(&(_v.elem(oldLength)), s2);
	markVArray();
    }
    else {
	strcpy(&(_fix[oldLength]), s2);
    }
    return *this;
}

template <int N>
ooStatus ooString(N)::resize(uint32 newLength)
{
    if (newLength == 0) {
	clear();
	return oocSuccess;
    }
    if (newLength > N_minus_1) {
	ooWithErrorContext ec("ooString(N)::resize");
	ooStatus status =  _v.resize(newLength + 1);
	if (isVArray()) {
	    _v[newLength] = '\0';
	} else {
	    strcpy(_v.head(), _fix);
	    markVArray();
	}
	return status;
    }
    else {
	ooStatus status =  oocSuccess;
	if (isVArray()) {
	    ooWithErrorContext ec("ooString(N)::resize");
	    _v[newLength] = '\0';
	    strcpy(_fix, _v.head());
	    markFix();
	    status =_v.resize(0);
	} else {
	    _fix[newLength] = '\0';
	}
	return status;
    }
}

#else  /*!(defined(OO_H) */

/* Alternate definitions for files not using the C++ API */

typedef struct ooVString {
    void * _vs;
} ooVString;

#define ooStringdeclare(N)						      \
    struct ooString(N) {						      \
	void *  _vs;							      \
	char	   _fix[N];						      \
    };

#define ooStringimplement(N)


#endif /*!(defined(OO_H))*/

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_STRING_H */
