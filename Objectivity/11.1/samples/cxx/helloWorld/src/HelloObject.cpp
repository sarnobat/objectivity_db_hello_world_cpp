//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2003
//-----------------------------------------------------------------------------
#include <iostream>
#include <ooMap.h>
#include "../ddlFiles/HelloObject.h"

//-----------------------------------------------------------------------------
HelloObject::HelloObject()
   :mHelloMsg(0)
{
}

//-----------------------------------------------------------------------------
const char* 
HelloObject::getHelloMsg() const
{
  return mHelloMsg.head()? mHelloMsg.head() : "";
}

//-----------------------------------------------------------------------------
void 
HelloObject::setHelloMsg(const char* value)
{
  mHelloMsg = value;
}


