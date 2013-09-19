******************************************************************************
*                                                                            *
*             Objectivity for Java Sample: Hello World                       *
*                                                                            *
*                  ===============================                           *
*                  COPYRIGHT AND DISCLAIMER NOTICE                           *
*                  ===============================                           *
*                                                                            *
* The following copyright and disclaimer notice applies to all files         *
* included in this application.                                              *
*                                                                            *
* Objectivity, Inc. grants you a nonexclusive copyright license to use all   *
* programming code examples from which you can generate similar function     *
* tailored to your own specific needs.                                       *
*                                                                            *
* All sample code is provided by Objectivity, Inc. for illustrative          *
* purposes only. These examples have not been thoroughly tested under all    *
* conditions. Objectivity, Inc., therefore, cannot guarantee or imply        *
* reliability, serviceability, or function of these programs.                *
*                                                                            *
* All programs contained herein are provided to you "AS IS" without any      *
* warranties or indemnities of any kind. The implied warranties of           *
* non-infringement, merchantability and fitness for a particular purpose     *
* are expressly disclaimed.                                                  *
*                                                                            *
******************************************************************************

Welcome to the HelloWorld Java sample. If you are using this sample to verify 
the installation and configuration of Objectivity for Java, please continue 
to follow the installation and configuration documentation found on the 
Objectivity Developer Network:

    http://support.objectivity.com/docs
    
Overview
--------
The HelloWorld Java sample is an efficient introduction to Objectivity/DB 
placement-managed federated databases.  

By going through the sample, you will:
* Create an Objectivity/DB placement-managed federated database using the
  'Objy CreateFd' administrative tool.
* Compile and run a simple java application.

Running the application persists a single instance of a HelloObject, then
scans (queries) the federation for that particular object.

At the end of the sample, you have a placement-managed federation
configured using the default placement strategy.

Prerequisites
-------------
If you have not already done so:
* Set up an Objectivity license file.
* Make sure the lock server is running.
* Depending on your installation choices, you might need to set 
  environment variables; see the installDir/setup script for an example.

See the installation and configuration documentation on the Objectivity 
Developer Network for more information:

    http://support.objectivity.com/docs

Compiling and Running
---------------------

Windows Platforms
-----------------
1. From a command prompt, create a new federated database in the 
   helloWorld\data directory:
   
   cd installDir\samples\java\helloWorld\data
   objy CreateFd -fdname HelloWorld 
   
2. From the directory containing the source files, build the sample    
   application:
   
   cd ..\src
   javac *.java
   
3. Run the application:

   java Main ..\data\HelloWorld.boot

When successful, the sample application outputs a message that includes: 
    
    HelloWorld test has PASSED

If the HelloWorld test does not pass:

- Verify your environment-variable settings and default Objectivity 
  license file.
- Correct any errors.
- Rebuild and rerun the application.


UNIX and Macintosh Platforms
----------------------------
1. Create a copy of installDir/samples/java/helloWorld and give yourself 
   read, write, and execute permissions. For example:
   
   cp -r installDir/samples/java/helloWorld homeDir
   chmod 777 homeDir/helloWorld
   cd homeDir/helloWorld

2. From a command shell, create a new federated database in the 
   helloWorld/data directory:
   
   cd data
   objy CreateFd -fdname HelloWorld 
   
3. From the directory containing the source files, build the sample    
   application:
   
   cd ../src
   javac *.java
   
4. Run the application:

   java Main ../data/HelloWorld.boot

When successful, the sample application outputs a message that includes: 
    
    HelloWorld test has PASSED

If the HelloWorld test does not pass:

- Verify your environment-variable settings and default Objectivity 
  license file.
- Correct any errors.
- Rebuild and rerun the application.

If you need help, contact Objectivity Customer Support:

    http://support.objectivity.com/contact




