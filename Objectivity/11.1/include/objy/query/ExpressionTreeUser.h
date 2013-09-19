//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ExpressionTreeUser_h 
#define ExpressionTreeUser_h

#include "ExpressionTree.h"

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// The base class for users of expression trees.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionTreeUser
{
   public:

      // Destructor
      virtual ~ExpressionTreeUser() {}

      ExpressionTree& getExpressionTree()
      {return mExpressionTree;}

      const ExpressionTree& getExpressionTree() const
      {return mExpressionTree;}

      // The following set of methods set variable value for different variable types
      void setBoolVarValue(const char* variableName, bool value);
      void setIntVarValue(const char* variableName, int64 value);
      void setUintVarValue(const char* variableName, uint64 value);
      void setFloat32VarValue(const char* variableName, float32 value);
      void setFloat64VarValue(const char* variableName, float64 value);
      void setStringVarValue(const char* variableName, const char* value);
      void setWStringVarValue(const char* variableName, const wchar_t* value);
      void setDateVarValue(const char* variableName, ooDate value);
      void setTimeVarValue(const char* variableName, ooTime value);
      void setDateTimeVarValue(const char* variableName, ooDateTime value);
      void setIntervalVarValue(const char* variableName, ooInterval value);
      void setRefVarValue(const char* variableName, const ooRef(ooObj)& value);
      void setClassVarValueByName(const char* variableName, const char* className);
      void setClassVarValueByType(const char* variableName, ooTypeNumber classType);
 
      // Sets all the literalValueExpression value paired with the specified 
      // variableName.
      // Throws ExpressionSetupException if not found or the literal's 
      // type is not that specified by expectedType.
      void setVariableLiteralValue(const char* variableName, 
        const ExpressionResult& valueResult);

   protected:

      // Constructor
      ExpressionTreeUser() {}

   private:

     ExpressionTree mExpressionTree;

};

}/* end query namespace */} /* end objy namespace */

#endif
