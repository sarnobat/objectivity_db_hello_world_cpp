/******************************************************************************

Class RentalCompany

RentalCompany defines a persistence-capable RentalCompany object.

The file was originally auto-generated from an Objectivity Schema.
If you have any questions, please contact Objectivity support.

******************************************************************************/

class RentalCompany :    public ::ooObj
{
   public:
      const char* getName() const
      {return (name.head() == 0)? "" : name.head();}
      void setName(const char* value);

   protected:

   private:
      ooVString name;

};
