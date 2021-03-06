/******************************************************************************

Class Customer

Customer defines a persistence-capable Customer object.

The file was originally auto-generated from an Objectivity Schema.
If you have any questions, please contact Objectivity support.

******************************************************************************/

class RentalCompany;
#pragma ooclassref RentalCompany "RentalCompany_ref.h"

class Customer :    public ::ooObj
{
   public:
      const char* getFirstName() const
      {return (firstName.head() == 0)? "" : firstName.head();}
      void setFirstName(const char* value);
      const char* getLastName() const
      {return (lastName.head() == 0)? "" : lastName.head();}
      void setLastName(const char* value);
      ooRef(::RentalCompany) getCompany() const
      {return mCompany();}
      void setCompany(const ooRef(::RentalCompany)& obj);

   protected:

   private:
      ooVString firstName;
      ooVString lastName;
      inline ooRef(::RentalCompany) mCompany <-> mCustomers[]
         : copy(drop);

};
