/******************************************************************************

Class RentalCompany

RentalCompany defines a persistence-capable RentalCompany object.

The file was originally auto-generated from an Objectivity Schema.
If you have any questions, please contact Objectivity support.

******************************************************************************/

class Vehicle;
#pragma ooclassref Vehicle "Vehicle_ref.h"
class Customer;
#pragma ooclassref Customer "Customer_ref.h"

class RentalCompany :    public ::ooObj
{
   public:
      const char* getName() const
      {return (name.head() == 0)? "" : name.head();}
      void setName(const char* value);
      void getVehicles(ooItr(::Vehicle)& itr, const char* predicate = 0) const
      {mVehicles(itr, predicate);}
      void addToVehicles(const ooRef(::Vehicle)& obj);
      void removeFromVehicles(const ooRef(::Vehicle)& obj);
      void clearVehicles();
      void getCustomers(ooItr(::Customer)& itr, const char* predicate = 0) const
      {mCustomers(itr, predicate);}
      void addToCustomers(const ooRef(::Customer)& obj);
      void removeFromCustomers(const ooRef(::Customer)& obj);
      void clearCustomers();

   protected:

   private:
      ooVString name;
      inline ooRef(::Vehicle) mVehicles[]
         : copy(drop);
      inline ooRef(::Customer) mCustomers[] <-> mCompany
         : copy(drop);

};
