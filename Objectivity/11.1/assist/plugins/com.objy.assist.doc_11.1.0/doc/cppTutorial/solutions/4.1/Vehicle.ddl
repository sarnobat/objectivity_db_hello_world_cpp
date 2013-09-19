/******************************************************************************

Class Vehicle

Vehicle defines a persistence-capable Vehicle object.

The file was originally auto-generated from an Objectivity Schema.
If you have any questions, please contact Objectivity support.

******************************************************************************/

class Vehicle :    public ::ooObj
{
   public:
      uint32 getLicense() const
      {return license;}
	  
	  void setLicense(uint32 value);

      ooBoolean getAvailable() const
      {return available;}

      void setAvailable(ooBoolean value);

      uint8 getSeatingCapacity() const
      {return seatingCapacity;}

      void setSeatingCapacity(uint8 value);

   protected:

   private:
      uint32 license;
      ooBoolean available;
      uint8 seatingCapacity;

};
