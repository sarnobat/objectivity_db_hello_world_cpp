/******************************************************************************

Class Truck

Truck defines a persistence-capable Truck object.

The file was originally auto-generated from an Objectivity Schema.
If you have any questions, please contact Objectivity support.

******************************************************************************/
#include "Vehicle.h"

class Truck :    public ::Vehicle
{
   public:

      uint16 getLoadCapacity() const
      {return loadCapacity;}

      void setLoadCapacity(uint16 value);

      ooBoolean getHasFourWheelDrive() const
      {return hasFourWheelDrive;}

      void setHasFourWheelDrive(ooBoolean value);

   protected:

   private:
      uint16 loadCapacity;
      ooBoolean hasFourWheelDrive;

};
