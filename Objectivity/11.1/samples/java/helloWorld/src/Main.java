//-----------------------------------------------------------------------------
//Copyright Objectivity Inc. 2012
//-----------------------------------------------------------------------------
import com.objy.db.DatabaseNotFoundException;
import com.objy.db.DatabaseOpenException;
import com.objy.db.ObjyRuntimeException;
import com.objy.db.app.Connection;
import com.objy.db.app.Session;
import com.objy.db.app.oo;
import com.objy.db.app.ooFDObj;
import com.objy.db.app.Iterator;


/**
 * Main driver class
 */
public class Main
{
  /**
   * Objectivity/DB HelloWorld example to store a simple HelloWorld object in
   * the database, and then retrieve it.
   *
   * @param args if specified should be a relative path to the federated
   *        database bootstrap file.
   */
  public static void main(String[] args)
  {
    boolean errors = true;
	
    try
    {
      System.out.println("Welcome to the Objectivity HelloWorld Example");
      // default assumes running from Samples/java/helloWorld/src folder
      String bootfile = "../data/HelloWorld.boot";

      if (args.length == 0)
      {
        System.out.println(
          "No Objectivity FD Bootfile passed as argument; using default: " +
          bootfile);
      }
      else
      {
        bootfile = args[0];
        System.out.println("Using FD Bootfile passed as argument: " + bootfile);
      }

      //Open a read/write Connection to the Objectivity Federated Database
      //and catch the standard exceptions.
      Connection connection;
      try
      {
        connection = Connection.open(bootfile, oo.openReadWrite);
      }
      catch (DatabaseNotFoundException e1)
      {
        System.out.println("Federated database not found " + bootfile +
          "- use objy newfd to create federated database.");
        return;
      }
      catch (DatabaseOpenException e2)
      {
        System.out.println("Federated database already open.");
        return;
      }
      //Create a new Objectivity Session with client side cache
      //dimensions of at most and at least 200 pages
      Session session;
      session = new Session(20, 20);
      session.setOpenMode(oo.openReadWrite);
      session.begin();

      ooFDObj fd = session.getFD();
      
      //
      //  create HelloObject and set message
      //
      System.out.println("Create HelloObject and set message");
      String name = "HelloWorld";
      HelloObject hello;
      hello = new HelloObject();
      hello.persist();
      hello.setHelloMsg(name);
      
      //
      //  commit the transaction
      //
      session.commit();
      //
      //  begin a read transaction
      //
      session.begin();
      System.out.println("Looking for object with name " + name);

      //
      //  scan the federation to lookup the object with name "HelloWorld"
      //
      Iterator itr = fd.scan("HelloObject");
      HelloObject hello2;
      while(itr.hasNext())
      {
		hello2 = (HelloObject)itr.next();
		if((hello2.getHelloMsg()).equals(name))
		{
        	System.out.println("Found it!: " + name);
		//
		//	everything worked so far.
		//
		errors = false;
		}
      }
      //
      //  commit the transaction
      //
      session.commit(); 
     } 
    finally
    {
      System.out.println("");
      if (errors)
      {
        System.out.println("HelloWorld test has FAILED");
      }
      else
      {
        System.out.println("HelloWorld test has PASSED");
      }
    }
  }
}
