//-------------------------------------------------------------------
//  Copyright Objectivity Inc. 2003
//-------------------------------------------------------------------

// Class HelloObject represents the HelloWorld object
class HelloObject : public ooObj
{
   public:

      // constructor
      HelloObject();

      // returns the current helloMsg value
      const char* getHelloMsg() const;

      // sets the helloMsg value to the provided value
      void setHelloMsg(const char* value);

   private:

      ooVString mHelloMsg;
    
};
