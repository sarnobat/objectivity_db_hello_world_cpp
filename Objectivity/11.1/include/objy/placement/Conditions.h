//***************************************************************************//
//                                                                           //
//                   Copyright © 2011 Objectivity Inc, USA.                  //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#if _MSC_VER > 1000
  #pragma once
#endif 

#ifndef objy_placement_Conditions_h
#define objy_placement_Conditions_h

#ifndef OO_H
#include "oo.h"
#endif

namespace objy {namespace placement
{

//-----------------------------------------------------------------------------
/**
* Conditions captures values that are to be considered when determining an 
* object's placement.
*/
class OO_STORAGE_SPECIFIER Conditions
{
  public:

    /**
    * Constructor taking an optional purpose.
    *
    * @param purpose The purpose of the placement.
    */
    explicit Conditions(const char* purpose = 0);

    /**
    * Constructor taking a related object as an ID and an optional purpose.
    *
    * @param relatedObject The ooId of the related object.
    * @param purpose The purpose of the placement.
    */
    explicit Conditions(const ooId& relatedObject, 
                        const char* purpose = 0);

    /**
    * Constructor taking a related object as an ID, its type number and an 
    * optional purpose.
    *
    * Providing a type number prevents the Placement Manager from opening the 
    * related object just to obtain its type in those circumstances where it 
    * needs its type, which can reduce the number of containers needing to be
    * opened to perform a placement as well as reduce lock contention.
    *
    * @warning There is no check that the provided type number is correct for the object
    * indicated by the provided ID.
    *
    * @param relatedObject The ooId of the related object.
    * @param relatedObjectTypeNumber The type number of the the related object.
    * @param purpose The purpose of the placement.
    */
    explicit Conditions(const ooId& relatedObject,
                        uint32 relatedObjectTypeNumber,
                        const char* purpose = 0);

    /**
    * Constructor taking a related object as a handle and an optional purpose.
    *
    * @param relatedObject The ooHandle(ooObj) of the related object.
    * @param purpose The purpose of the placement.
    */
    explicit Conditions(const ooHandle(ooObj)& relatedObject, 
                        const char* purpose = 0);

    /**
    * Constructor taking a related object as a handle, its type number and an 
    * optional purpose.
    *
    * Providing a type number prevents the Placement Manager from opening the 
    * related object just to obtain its type in those circumstances where it 
    * needs its type, which can reduce the number of containers needing to be
    * opened to perform a placement as well as reduce lock contention.
    *
    * @warning There is no check that the provided type number is correct for the object
    * indicated by the provided ID.
    *
    * @param relatedObject The ooHandle(ooObj) of the related object.
    * @param relatedObjectTypeNumber The type number of the the related object.
    * @param purpose The purpose of the placement.
    */
    explicit Conditions(const ooHandle(ooObj)& relatedObject,
                        uint32 relatedObjectTypeNumber,
                        const char* purpose = 0);

    /**
    * Copy constructor.
    *
    * @param other The other Conditions to be a copy of.
    */
    Conditions(const Conditions& other);

    /**
    * Destructor.
    */
    ~Conditions();

    bool operator== (const Conditions& other) const;

    bool operator!= (const Conditions& other) const
    {return ! operator==(other);}

    /**
    * Assignment operator.
    *
    * @param other The other Conditions whose values to copy.
    */
    Conditions& operator=(const Conditions& other);

    /**
    * Sets the related object and optionally its type number.
    *
    * Providing a type number prevents the Placement Manager from opening the 
    * related object just to obtain its type in those circumstances where it 
    * needs its type, which can reduce the number of containers needing to be
    * opened to perform a placement as well as reduce lock contention.
    *
    * @warning There is no check that the provided type number is correct for the object
    * indicated by the provided ID.
    *
    * @param relatedObject The ooId of the related object.
    * @param relatedObjectTypeNumber The type number of the the related object.
    */
    void setRelatedObject(const ooId& relatedObject,
                          uint32 relatedObjectTypeNumber = 0)
    {
      mRelatedObject = relatedObject;
      mRelatedObjectTypeNumber = relatedObjectTypeNumber;
    }

    /**
    * Returns the related object's OID.
    *
    * @return The ooId of the related object.
    */
    const ooId& getRelatedObjectId() const
    {return mRelatedObject;}

    /**
    * Obtains the type number of the related object.
    *
    * @param relatedObjectTypeNumber The related object's type number.
    *
    * @return <code>oocSuccess</code> if successful; <code>oocError</code> 
    *  otherwise.
    */
    ooStatus getRelatedObjectTypeNumber(uint32& relatedObjectTypeNumber /*out*/) const;

    /**
    * Sets the purpose of the placement.
    *
    * @param purpose The purpose of the placement.
    */
    void setPurpose(const char* purpose);

    /**
    * Returns the purpose of the placement.
    *
    * @return The purpose of the placement.
    */
    const char* getPurpose() const
    {return mPurpose;}

    /**
    * Returns the session requesting the placement.
    * 
    * @note Internal use only.
    *
    * @return The ocmSession requesting the placement.
    */
    ocmSession* session() const
    {return mSession;}

  private:

    ooId mRelatedObject;
    mutable uint32 mRelatedObjectTypeNumber;
    char* mPurpose;
    mutable  ocmSession* mSession; 

};

}  /* end placement namespace */} /* end objy namespace */

#endif
