//-------------------------------------------------------------------
//  Copyright Objectivity Inc. 2012
//-------------------------------------------------------------------
import com.objy.db.app.ooObj;


// Class HelloObject represents the HelloWorld object
public class HelloObject extends ooObj
{
  /** String to contain the message */
  private String mHelloMsg;

  // constructor
  public HelloObject()
  {
  }

  // sets the helloMsg value to the provided value
  void setHelloMsg(String value)
  {
	markModified();
    mHelloMsg = value;
  }

  // returns the current helloMsg value
  String getHelloMsg()
  {
	fetch();
    return mHelloMsg;
  }
}
;
