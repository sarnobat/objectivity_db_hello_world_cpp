/**************************************************************************
		    Copyright (c) 1989-2002 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_VARRAY_H
#define OO_VARRAY_H

/* "@(#)$Id$" */

/*
This header file contains the generic class definition of variable array.
A variable array (ooVArray) behaves just like a normal array except
that it can grow dynamically in size and subscripts are checked to
make sure they are within bounds.  A variable array can also be truncated
to a smaller size when part of its storage is no longer needed.

Note: 
  The following macro calls were once required by earlier versions,
  but are now unnecessary and no longer supported:

	declare(ooVArray,<typeName>);
	implement(ooVArray,<typeName>);

  Any such macro calls in existing code should be removed.


For example:

	// Declared in a schema file

	typedef int32 Coord;

	struct Point {
	    Coord   x;
	    Coord   y;
	};

	class Polygon : public ooObj {
	  public:
	    ooVArray(Point)  vertex;	     // array of vertices

	    Polygon() { }
	    Polygon(uint32 nVertices) : vertex(nVertices) { }

	    virtual void recompute();
	    virtual void scale(int32);
	    virtual void draw();
	};

	// Code in a C++ source file

	ooHandle(Polygon)  polyH;
	polyH = new(containerHandle) Polygon(7);
	   // create a new polygon with a variable array of Point
	   // whose size is 7 in the database

	deptH = new(containerHandle) Polygon();
	   // create a new polygon without a variable array of Point
	   // in the database

Storage allocated to an array is freed when the user explicitly
resizes the array to zero elements.

Notes: variable arrays are defined in such a way that subscript bounds
checking can be bypassed simply by using the method elem().
For example:

	polyH->vertex[5];	      // will invoke bounds checking
	polyH->vertex.elem(5);	      // will bypass bounds checking
*/


#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#ifndef OO_BASE_H
#include <ooBase.h>
#endif
#ifndef OO_ERROR_H
#include <ooError.h>
#endif

#if defined(OO_GNU_CXX) || defined(OO_INTEL_CXX)
#include <new>
#else
#include <new.h>
#endif

#ifdef OO_DDL_TRANSLATION
// DDL compiler and schema recognize only the old name
#define ooVArrayT opiVArray
#else
#define opiVArray ooVArrayT
#endif

// The ODMG name
#define d_Varray opiVArray


/*************************************************************************
 *									 *
 * Note: The following declarations are only for internal system usage.	 *
 *	 It is subject to change in any future release.			 *
 *	 You are not allowed to use it.					 *
 *									 *
 *************************************************************************/

// "_pers" must be at the same offset as "VCBH._omField" in "oomVCB".
struct opiVAheapHK {	    // housekeeping info for VArray in heap
    uint8	_pers;
    uint32	_size;
};

struct opiVApersHK {	    // housekeeping info for VArray in DB
    uint32	_size;
};

struct opiVApersAligHK {    // housekeeping with alignment for VArray in DB
    uint32	_size;
    uint32	_notUsed;
};


// size of HK for heap VArray
#define opimSizeOfHeapHK	sizeof(opiVAheapHK)

// size of HK for persistent VArray
#define opimSizeOfPersHK	sizeof(opiVApersHK)	

// size of HK (aligned) for persistent VArray
#define opimSizeOfPersAligHK	sizeof(opiVApersAligHK)


#define opimIsVApers(vs)						      \
    ((vs) ? ((opiVAheapHK*)(vs))->_pers : 0 /* false */)

#define opimGetPersVAsize(vm)						      \
    ((vm) ? ((opiVApersHK*)(vm))->_size : 0)

#define opimGetHeapVAsize(vs)						      \
    ((vs) ? ((opiVAheapHK*)(vs))->_size : 0)

#define opimSetPersVAsize(vm, size)					      \
    (((opiVApersHK*)(vm))->_size = size)

#define opimSetHeapVAsize(vs, size)					      \
    (((opiVAheapHK*)(vs))->_size = size)

#define opimSetHeapVApers(vs)						      \
    (((opiVAheapHK*)(vs))->_pers = oocFalse)

#define opimGetHKsize(elemSize)						      \
    ((elemSize <= 4) ? opimSizeOfPersHK : opimSizeOfPersAligHK)

extern OO_STORAGE_SPECIFIER ooBoolean oosvMallocEnabled;
// Signals error, throws exception, and returns address of dummy array.
OO_STORAGE_SPECIFIER void* opiBadArrayIndex(int size, int index);

extern OO_STORAGE_SPECIFIER const ooError  // same as in ociError.h
	opieIteratorPastEnd,
	opieIteratorBeforeBegin,
  opieUpdateVArray,
  opieIteratorOffElement;

OO_STORAGE_SPECIFIER ooStatus opiNewVArray(void *, uint32, size_t);
OO_STORAGE_SPECIFIER ooStatus opiOpenVArray(void*, ocmSession* session = 0);
OO_STORAGE_SPECIFIER ooStatus opiUpdateVArray(void *);
OO_STORAGE_SPECIFIER ooStatus opiResizeVArray(void *, uint32, size_t);
OO_STORAGE_SPECIFIER ooStatus opiDeleteVArray(void *);
OO_STORAGE_SPECIFIER ooStatus opiEnsureVArrayOpen(void*, ooMode, ocmSession*);

OO_STORAGE_SPECIFIER void *opiResizeHeapVArray(void *, uint32, uint32, size_t);

OO_STORAGE_SPECIFIER void *opiMalloc(size_t);
OO_STORAGE_SPECIFIER void opiFree(void *);


#define opimIsVAexist(vs)                                                     \
    (((ooVCB*)vs)->VCBH._SN != oocVArrayNotExist)

#define opimGetVmInVCB(vs)                                                    \
    (((ooVCB*)vs)->VCBH._pObject)

#define opimIsVArrayNotOpen(vs)                                               \
    (((ooVCB*)vs)->VCBH._SN >= oocVArrayNotOpen)

#define opimFreeVArray(vs)                                                    \
    (opiDeleteVArray(vs))

#define opimOpenVArray(vs)                                                    \
    (opiOpenVArray(vs))

#define opimGetVArray(vs)                                                     \
    ((opimIsVArrayNotOpen(vs)) ?                                              \
	(opiOpenVArray(vs), opimGetVmInVCB(vs)) :                             \
	opimGetVmInVCB(vs))

#define opimResizeVArray(vs, numOfElems, elemSize)                            \
     ((opiResizeVArray(vs, numOfElems, elemSize) == oocError) ?               \
      (void *)0 :                                                             \
      (opimGetVmInVCB(vs)))

#define opimGetVArrayOffset(vs, index, elemSize)                              \
    ((void *)((char*)(opimGetVmInVCB(vs)) + opimGetHKsize(elemSize) +         \
		 (index)*(elemSize)))

#define opimUpdateVArray(vs)                                                  \
    ((opiUpdateVArray(vs)) ?  oocSuccess :                                    \
	 (ooSignal(oocUserError, opieUpdateVArray, (ooHandleBase*) 0), oocError))

// Definition for VArray - persistent storage

template<class T>
class opiVArrayTypeWrapperTemplate {
 public:
  class inner {
   public:
    inner()
      {}
    ~inner()
      {}
    void destruct()
      {
	this->~inner();
      }
   private:
    T member;
  };
};
#if defined(OO_HP_CXX) || (defined(OO_GNU_CXX) && OO_GNU_CXX >= 3)
#define opiVArrayTypeWrapper(T)                                               \
    typename opiVArrayTypeWrapperTemplate<T >::inner
#else
#define opiVArrayTypeWrapper(T)                                               \
    opiVArrayTypeWrapperTemplate<T >::inner
#endif
#define opiVArrayTypeWrapperDestruct(T)                                       \
    destruct
#define opiVArrayTypeWrapperDeclare(T)                                        \
    /*empty*/


#define opiVArrayElementDestruct(T,element_ptr)                               \
    ooReinterpretCast(opiVArrayTypeWrapper(T) *,element_ptr)->opiVArrayTypeWrapperDestruct(T)()

// Definition for TVArray - transient VArray only
//     TVArray works the same way as a transient VArray except that element
//     copy constructors all called appropriately.

template<class T>
class opiTVArrayTypeWrapperTemplate {
 public:
  class inner {
   public:
    inner()
      {}
    ~inner()
      {}
    void destruct()
      {
	this->~inner();
      }
   private:
    T member;
  };
};
#if defined(OO_HP_CXX) || (defined(OO_GNU_CXX) && OO_GNU_CXX >= 3)
#define opiTVArrayTypeWrapper(T)                                               \
    typename opiTVArrayTypeWrapperTemplate<T >::inner
#else
#define opiTVArrayTypeWrapper(T)                                               \
    opiTVArrayTypeWrapperTemplate<T >::inner
#endif
#define opiTVArrayTypeWrapperDestruct(T)				      \
    destruct
#define opiTVArrayTypeWrapperDeclare(T)					      \
    /*empty*/

#define opiTVArrayElementDestruct(T,element_ptr)			      \
  ooReinterpretCast(opiTVArrayTypeWrapper(T) *,element_ptr)->opiTVArrayTypeWrapperDestruct(T)()

template <class T>
class d_Varray;

template <class T>
class d_Iterator : protected d_IteratorBase {
	friend class d_Varray<T>;
 public:
  d_Iterator() {
      vector = 0;
      index = -1;
      max_index = 0;
    }
  d_Iterator(const d_Iterator<T> &  from) {
      vector = from.vector;
      index = from.index;
      max_index = from.max_index;
    }
  ~d_Iterator()
    {}
  d_Iterator<T> &
      operator=(const d_Iterator<T> &  from)
	{
	  this->vector = from.vector;
	  this->index = from.index;
	  this->max_index = from.max_index;
	  return *this;
	}
  void
      reset()
	{
	  this->index = -1;
	}
  int
      not_done() const
	{
	  return ((this->index == -1)
		  ? (this->max_index != 0)
		  : (((unsigned int) (this->index)) != this->max_index));
	}
  void
      advance()
	{
	  if (this->index == -1) {
	    this->index = 0;
	  } else {
	    if (this->not_done()) {
	      ++(this->index);
	    } else {
	      ooSignal(oocUserError, opieIteratorPastEnd, 0);
		  ooThrowException();
	    }
	  }
	}
  void
      retreat()
	{
	  if (this->index <= 0) {
	    ooSignal(oocUserError, opieIteratorBeforeBegin, 0);
	    ooThrowException();
	  } else {
	    --(this->index);
	  }
	}
  d_Iterator<T> &
      operator++()
	{
	  this->advance();
	  return *this;
	}
  d_Iterator<T>
      operator++(int)
	{
	  d_Iterator<T> result = *this;
	  ++*this;
	  return result;
	}
  d_Iterator<T> &
      operator--()
	{
	  this->retreat();
	  return *this;
	}
  d_Iterator<T>
      operator--(int)
	{
	  d_Iterator<T> result = *this;
	  --*this;
	  return result;
	}
  T
      get_element() const
	{
	  T *result;
	  int vector_index = this->index;
	  if (vector_index == -1) {
	    vector_index = 0;
	  }
	  if (this->not_done()) {
	    T *typed_vector = ((T *) (this->vector));
	    result = &(typed_vector[vector_index]);
	  } else {
	    ooSignal(oocUserError, opieIteratorOffElement, 0);
	    ooThrowException();
	    result = 0;
	  }
	  return *result;
	}
  int
      next(T &	objRef)
	{
	  if (!(this->not_done())) return 0;
	  objRef =  this->get_element();
	  this->advance();
	  return 1;
	}
  // varray structor
  d_Iterator(void *  the_vector,
	     int     the_index,
	     unsigned     the_max_index) {
      vector = the_vector;
      index = the_index;
      max_index = the_max_index;
    }
  // data
  int		get_index() const { return index; }
  void *	get_vector() const { return vector; }
// From d_IteratorBase in ooBase.h:
// protected:
//  void *       vector;
//  int          index;    // -1 is "before start".
//  unsigned int max_index;
};

/*
Define the ooVArray and related macros to use templates.  Also declare the
templates the macros produce.  The " "s before the final ">"s in the macros
are needed when "T" is a template type, and the " " after the final ">"s in
the macros are needed when the macro is a template parameter.
*/

#define ooVArray(type) opiVArray<type > 

template<class T>
class opiVArray 
{
 private:
  void * _vs;	    /* pointer to varray storage */
 public:
  opiVArray()
    { // In a persistent object, this has already been initialized
      // by the parent object's operator new.
      if ( ! opiIsStorePers(this) )
        _vs = 0; 
    }

  opiVArray(uint32 initSize)
    {
      register T *pElem;
      if (initSize == 0) {
	if (! opiIsStorePers(this)) { _vs = 0; }
	return;
      }
      ooWithErrorContext ec("ooVArray(T)::ooVArray(T)(<initSize>)");
      if (opiIsStorePers(this)) {
	if (!opiNewVArray(_vs, initSize, sizeof(T)))
		return;
	void *storage = opimGetVmInVCB(_vs);
	opimSetPersVAsize(storage, initSize);
	pElem = (T*) ((char*)storage + opimGetHKsize(sizeof(T)));
      }
      else {
	_vs = opiMalloc(initSize*sizeof(T)+opimSizeOfHeapHK);
	if (_vs == 0)
	  return;
	opimSetHeapVApers(_vs);
	opimSetHeapVAsize(_vs, initSize);
	pElem = (T*) ((char*)_vs + opimSizeOfHeapHK);
      }
      for (register uint32 i = 0; i < initSize; i++) {
	::new(pElem) T;
	pElem++;
      }
    }
									      
  opiVArray(const opiVArray<T >& varray)
    {
      register uint32 i;
      register T   *pElem;
      ooWithErrorContext ec("ooVArray(T)::ooVArray(T)(<varray>)"); 
      uint32   _size = varray.size();
      if (_size == 0) { if (! opiIsStorePers(this)) { _vs = 0; } return; }
      if (opiIsStorePers(this)) {
	if (!opiNewVArray(_vs, _size, sizeof(T)))
		return;
	void *storage = opimGetVmInVCB(_vs);
	opimSetPersVAsize(storage, _size);
	pElem = (T*) ((char*)storage + opimGetHKsize(sizeof(T)));
      }
      else {
	_vs = opiMalloc(_size*sizeof(T)+opimSizeOfHeapHK);		      
	if (_vs == 0)
	  return;    
	opimSetHeapVApers(_vs);
	opimSetHeapVAsize(_vs, _size);
	pElem = (T*) ((char*)_vs + opimSizeOfHeapHK);
      }
      for (i = 0; i < _size; i++) {
	::new(pElem) T;
	*pElem = varray.elem(i);
	pElem++;
      }
    }
						    							      
  ~opiVArray()
  {
#ifdef OO_NT
    // On Windows we use a private heap that may have been freed already
    if (!oosvMallocEnabled)
      return;
#endif
    register uint32 i;
    register T *pElem;
    register void *	v;
    uint32 _size;
    if (opimIsVApers(_vs)) {
      if (opimIsVAexist(_vs)) {
        ooWithErrorContext ec("ooVArray(T)::~ooVArray(T)()"); 
        v = opimGetVArray(_vs);
        _size = opimGetPersVAsize(v);
        if (_size) {
          pElem = ((T*)((char*)v + opimGetHKsize(sizeof(T))))     
            + _size - 1;				      
          for (i = 0; i < _size; i++) {				      
            opiVArrayElementDestruct(T,pElem);		     
            pElem--;						      
          }							      
        }								      
        opimFreeVArray(_vs);					      
      }
    }
    else {								      
      if (_vs) {
        _size = opimGetHeapVAsize(_vs);
        if (_size) {
          pElem = ((T*)((char*)_vs + opimSizeOfHeapHK)) + _size - 1; 
          for (i = 0; i < _size; i++) {
            opiVArrayElementDestruct(T,pElem);
            pElem--;						      
          }
        }
        opiFree(_vs);						      
        _vs = 0;							      
      }								      
    }									      
  }

  uint32 size() const
    {
      void * v;
      return (opimIsVApers(_vs)) ?
	((opimIsVAexist(_vs)) ?
	 (v = opimGetVArray(_vs), opimGetPersVAsize(v)) : 0) :
	(opimGetHeapVAsize(_vs));
    }

  ooStatus open(ooMode openMode = oocRead, ocmSession* session = 0) const // session use is Objectivity internal only
    { return opiEnsureVArrayOpen(_vs, openMode, session); }

  ooStatus update()
    {
      return (opimIsVApers(_vs)) ?
	(opimUpdateVArray(_vs)) : (oocSuccess);
    }                                                                     
                                                                              
  T& elem(uint32 index) const                                        
    {                                                                     
      register void * v;
      v = (opimIsVApers(_vs)) ?
	((char*)opimGetVArray(_vs)+opimGetHKsize(sizeof(T))) :
	((char*)_vs + opimSizeOfHeapHK);
      return ((T*)v)[index];
    }
                                                                              
  ooStatus                                                       
    set(uint32 index, const T &newValue) {                         
    return this->iset(index, newValue);                           
  }                                                                 
                                                                              
  /* ODMG methods: */                                                   
  uint32 cardinality() const                                            
    {                                                                   
      return this->size();         
    }                                                                   
  int is_empty() const
    {
      return (this->size() == 0);
    }
  void insert_element(const T &element)
    {
      this->extend(element);
    }                                                                   
  void remove_all()
    {
      this->resize(0);
    }
  uint32	upper_bound() const                                           
    {                                                                   
      return this->size();
    }
  const T &retrieve_element_at(uint32 index) const
    {  
      return this->elem(index);
    }
  void replace_element_at(const T &value,                            
			  uint32	    index)                            
    {                                                                   
      this->set(index, value);                                          
    }   
 
  void replace_element_at(const T &	value,              
			  const d_Iterator<T > &iterator)
    {
      if ((iterator.index == -1) || !(iterator.not_done())) {
				ooSignal(oocUserError, opieIteratorOffElement, 0);
				ooThrowException();
			} 
			else                                                           
				this->head()[iterator.index] = value; 
    }
  d_Iterator<T > create_iterator() const
    {
      return d_Iterator<T >(this->head(),
			       0,
			       this->upper_bound());
    }

  T* head() const					      
    {		      
      if (size()) {
	register void * v;
	v = (opimIsVApers(_vs)) ?
	  ((char*)opimGetVArray(_vs)+opimGetHKsize(sizeof(T))) :
	  ((char*)_vs + opimSizeOfHeapHK);
	return (T*) v;
      }
      else {
	return (T*) 0;
      }
    }

  T& operator[](uint32 index) const
    {
      /* bound checking */
      ooWithErrorContext ec("ooVArray(T)::operator[]");
      uint32 n = index, _size = size();
      if (index >= _size) {
        return *((T*) opiBadArrayIndex(_size, index)); // throws exception
      }
      return elem(n);
    }	      

  ooStatus
    iset(uint32 index, const T& newValue)
    {
      ooWithErrorContext ec("ooVArray(T)::iset()");
      uint32   _size = size();
      if (index >= _size) {
        opiBadArrayIndex(_size, index);
        return oocError;
      }
      if (! update())  return oocError;
      elem(index) = (T&) newValue;
      return oocSuccess;
    }
									      						
  ooStatus extend(const T& newElem)
    {
      ooWithErrorContext ec("ooVArray(T)::extend()");
      // `_persistent' is  used only as a true/false value, but is not
      // `ooBoolean' to avoid conversion from `uint8' field `_pers'.
      unsigned _persistent = opimIsVApers(_vs);
      uint32    _size = size();
      if (! update())  return oocError;
      if (_persistent) {
	void *storage = 0;
	if (opimIsVAexist(_vs))
	  storage = opimResizeVArray(_vs, _size+1, sizeof(T));
	else {
		if (!opiNewVArray(_vs, _size+1, sizeof(T)))
			return oocError;
		storage = opimGetVmInVCB(_vs);
	}
	if (!storage)
		return oocError;
	opimSetPersVAsize(storage, _size+1);
      }
      else {
	_vs = opiResizeHeapVArray(_vs, _size, _size+1, sizeof(T));
	opimSetHeapVAsize(_vs, _size+1);
	opimSetHeapVApers(_vs);						      
      }
      void *storage = (_persistent) ?
	opimGetVArrayOffset(_vs, _size, sizeof(T)) :			      
	(void *)((char*)((T*)_vs + (_size)) + opimSizeOfHeapHK);	      
      ::new(storage) T;
      *((T*)storage) = (T&) newElem;				      
      return oocSuccess;
    }

opiVArray<T >& operator=(const opiVArray<T >& varray)
{
  register uint32 i;
  ooWithErrorContext ec("ooVArray(T)::operator=(<varray>)");
  uint32 _size = varray.size();
  if (! resize(_size) || _size == 0)
	  return *this;
  for (i = 0; i < _size; i++)
	  elem(i) = varray.elem(i);
  return *this;
}

ooStatus resize(uint32 newSize);
}; // end of opiVArray template class defention

template<class T>
ooStatus
ooVArray(T)::resize(uint32 newSize)
{
  register uint32 i;
  register T  *pElem;
  ooWithErrorContext ec("ooVArray(T)::resize()");
  uint32 n, _size = size();
  if (!update())
		return oocError;
  if (newSize == _size)
		return oocSuccess;
  // `_persistent' is  used only as a true/false value, but is not
  // `ooBoolean' to avoid conversion from `uint8' field `_pers'.
  unsigned _persistent = opimIsVApers(_vs);
  if (newSize < _size) {
    void *storage = _persistent ? opimGetVArrayOffset(_vs, newSize, sizeof(T)) : 
		                    (void *)((char*)((T*)_vs + (newSize)) + opimSizeOfHeapHK);
    n = _size - newSize;
    pElem = ((T*) storage) + n - 1;
    for (i = 0; i < n; i++) {
      opiVArrayElementDestruct(T,pElem);
      pElem--;
    }
  }
  if (_persistent) {
    if (newSize == 0) {
      opimFreeVArray(_vs);
      return oocSuccess;
    }								      
	void *storage = 0;
	if (opimIsVAexist(_vs)) {
		if (opiResizeVArray(_vs, newSize, sizeof(T))) {
			ooVCB*& vcbPtr = (ooVCB*&) _vs;
			storage = vcbPtr->VCBH._pObject;
		}
	}
	else {
		if (!opiNewVArray(_vs, newSize, sizeof(T)))
			return oocError;
		storage = opimGetVmInVCB(_vs);
	}
  if (! storage) 
			return oocError;
   opimSetPersVAsize(storage, newSize);
  }	
  else {// not persistent array
    _vs = opiResizeHeapVArray(_vs, _size, newSize, sizeof(T));
    if (newSize == 0)
			return oocSuccess;
    opimSetHeapVAsize(_vs, newSize);
    opimSetHeapVApers(_vs);
  }
  if (newSize > _size) {
    void *storage = _persistent ?
      opimGetVArrayOffset(_vs, _size, sizeof(T)) :
      (void *)((char*)((T*)_vs + _size) + sizeof(opiVAheapHK));
    n = newSize - _size;
    pElem = (T*) storage;
    for (i = 0; i < n; i++) {
      ::new(pElem) T;
      pElem++;
    }
  }
  return oocSuccess;
}

#define ooTVArray(type) ooTVArrayT<type > 

#ifdef OO_DDL_TRANSLATION
// DDL compiler and schema recognize only the old name
#define ooTVArrayT opiTVArray
#else
#define opiTVArray ooTVArrayT
#endif

template<class type>
class opiTVArray 
{
 public:
	opiTVArray()  { _vs = 0; }
	uint32 size() const { return opimGetHeapVAsize(_vs); }
	ooStatus resize(uint32 newSize) { return resize(newSize, oocTrue); }
	ooStatus update()   { return oocSuccess; }			      \
	type* head() const
	{
	    return (size()) ? (type*)((char*)_vs + opimSizeOfHeapHK) : 0;
	}
	type& elem(uint32 index) const
	{
	    return ((type*)((char*)_vs + opimSizeOfHeapHK))[index];
	}
	
	inline ooStatus
	set(uint32 index, const type &newValue) {
	    return this->iset(index, newValue);
	}
    private:
	void * _vs;	    /* pointer to temporary varray storage */

 public:
	opiTVArray(uint32 initSize);
	opiTVArray(const ooTVArray(type)& varray);
	~opiTVArray();
	type& operator[](uint32 index) const;
	ooStatus iset(uint32 index, const type& newValue);
	ooStatus resize(uint32 newSize, ooBoolean copy);
	ooStatus extend(const type& newElem);
	ooTVArray(type)& operator=(const ooTVArray(type)& varray);
};

template<class type>
ooTVArray(type)::opiTVArray(uint32 initSize)
{
    register type *pElem;
    if (initSize == 0) { _vs = 0; return; }
    ooWithErrorContext ec("ooTVArray(T)::ooTVArray(T)(<initSize>)");
    _vs = opiMalloc(initSize*sizeof(type)+opimSizeOfHeapHK);
    if (_vs == 0) {
	return;
    }
    opimSetHeapVApers(_vs);
    opimSetHeapVAsize(_vs, initSize);
    pElem = (type*) ((char*)_vs + opimSizeOfHeapHK);
    for (register uint32 i = 0; i < initSize; i++) {
	::new(pElem) type;
	pElem++;
    }
}

template<class type>
ooTVArray(type)::opiTVArray(const ooTVArray(type)& varray)
{
    register uint32 i;
    register type   *pElem;
    ooWithErrorContext ec("ooTVArray(T)::ooTVArray(T)(<varray>)");
    uint32   _size = varray.size();
    if (_size == 0) { _vs = 0; return; }
    _vs = opiMalloc(_size*sizeof(type) + opimSizeOfHeapHK);
    if (_vs == 0) {
	return;
    }
    opimSetHeapVApers(_vs);
    opimSetHeapVAsize(_vs, _size);
    pElem = (type*) ((char*)_vs + opimSizeOfHeapHK);
    for (i = 0; i < _size; i++) {
	::new(pElem) type;
	*pElem = varray.elem(i);
	pElem++;
    }
}

template<class type>
ooTVArray(type)::~opiTVArray()
{
#ifdef OO_NT
// On Windows we use a private heap that may have been freed already
  if (!oosvMallocEnabled)
    return;
#endif
  register uint32 i;
  register type   *pElem;
  uint32   _size;
  if (_vs) {
    _size = opimGetHeapVAsize(_vs);
    if (_size) {
      pElem = ((type*)((char*)_vs + opimSizeOfHeapHK)) + _size - 1;
      for (i = 0; i < _size; i++) {
        opiTVArrayElementDestruct(type,pElem);
        pElem--;
      }
    }
    opiFree(_vs);
    _vs = 0;
  }
}

template<class type>
type &
ooTVArray(type)::operator[](uint32 index) const
{
    /* bound checking */
    uint32 n = index, _size = size();
    if (index >= _size) {
      ooWithErrorContext ec("ooTVArray(T)::operator[]");
      opiBadArrayIndex(_size, index); // throws exception
      n = 0;
    }
    return elem(n);
}

template<class type>
ooStatus
ooTVArray(type)::iset(uint32 index, const type& newValue)
{
    uint32   _size = size();
    if (index >= _size) {
      ooWithErrorContext ec("ooTVArray(T)::iset()");
      opiBadArrayIndex(_size, index);
      return oocError;
    }
    elem(index) = (type&) newValue;
    return oocSuccess;
}

template<class type>
ooStatus
ooTVArray(type)::resize(uint32 newSize, ooBoolean copy)
{
    register uint32 i;
    register type   *pElem;
    void * ptr;
    ooWithErrorContext ec("ooTVArray(T)::resize()");
    uint32    _size = size();
    if (newSize == _size)  return oocSuccess;
    if (newSize == 0) {
	pElem = ((type*)((char*)_vs + opimSizeOfHeapHK)) + _size - 1;
	for (i = 0; i < _size; i++) {
	    opiTVArrayElementDestruct(type,pElem);
	    pElem--;
	}
	opiFree(_vs);
	_vs = 0;
	return oocSuccess;
    }
    ptr = opiMalloc(newSize*sizeof(type) + opimSizeOfHeapHK);
    if (ptr == 0) {
	return oocError;
    }
    void *storage = (char*)ptr + opimSizeOfHeapHK;
    pElem = (type*) storage;
    for (i = 0; i < newSize; i++) {
	::new(pElem) type;
	pElem++;
    }
    if (_size) {
	if (copy) {
	    uint32 n = (_size < newSize) ? _size : newSize;
	    pElem = (type*) storage;
	    for (i = 0; i < n; i++, pElem++)
		*pElem = elem(i);
	}
	pElem = ((type*)((char*)_vs + opimSizeOfHeapHK)) + _size - 1;
	for (i = 0; i < _size; i++) {
	    opiTVArrayElementDestruct(type,pElem);
	    pElem--;
	}
	opiFree(_vs);
    }
    _vs = ptr;
    opimSetHeapVAsize(_vs, newSize);
    opimSetHeapVApers(_vs);
    return oocSuccess;
}

template<class type>
ooStatus
ooTVArray(type)::extend(const type& newElem)
{
    ooWithErrorContext ec("ooTVArray(T)::extend()");
    uint32    _size = size();
    if (resize(_size + 1)) {
	void *storage = (char*)((type*)_vs + (_size)) + opimSizeOfHeapHK;
	*((type*)storage) = (type&) newElem;
	return oocSuccess;
    }
    return oocError;
}

template<class type>
ooTVArray(type) &
ooTVArray(type)::operator=(const ooTVArray(type)& varray)
{
    register uint32 i;
    ooWithErrorContext ec("ooTVArray(T)::operator=(<varray>)");
    uint32   _size = varray.size();
    if (! resize(_size, oocFalse) || _size == 0) return *this;
    for (i = 0; i < _size; i++)
	elem(i) = varray.elem(i);
    return *this;
}

#define ooVArraydeclare(type) /*empty*/
#define ooVArraysdeclare(type,storage_attribute) template class storage_attribute ooVArray(type);
#define ooVArrayimplement(type) /*empty*/
#define ooTVArraydeclare(type) /*empty*/
#define ooTVArraysdeclare(type,storage_attribute) template class storage_attribute ooTVArray(type);
#define ooTVArrayimplement(type) /*empty*/

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif
