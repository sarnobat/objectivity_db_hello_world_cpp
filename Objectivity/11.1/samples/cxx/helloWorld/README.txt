******************************************************************************
*                                                                            *
*                Objectivity/C++ Sample: Hello World                         *
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

Welcome to the HelloWorld C++ sample. If you are using this sample to verify 
the installation and configuration of Objectivity/C++ and Objectivity/DDL, 
please continue to follow the installation and configuration documentation 
found on the Objectivity Developer Network:

    http://support.objectivity.com/docs

Overview
--------
The HelloWorld C++ sample is an efficient introduction to Objectivity/DB 
placement-managed federated databases. 
  
When you build the project, you will:

* Create an Objectivity/DB placement-managed federated database using the
  'Objy CreateFd' administrative tool.
* Load the schema of a simple HelloObject, whose only data member is a 
  string, using the 'ooddlx' administrative tool.
* Compile a simple c++ application.

Running the application persists a single instance of a HelloObject, then
scans (queries) the federation for that particular object.

At the end of the sample, you have a placement-managed federation
configured using the default placement strategy.

Prerequisites
-------------
If you have not already done so:
* Set up an Objectivity license file.
* Make sure the lock server is running.
* Depending on your installation choices, you might need to set environment
  variables; see the installDir/setup script for an example.

See the installation and configuration documentation on the Objectivity 
Developer Network for more information:

    http://support.objectivity.com/docs

Compiling and Running
---------------------

Windows Platforms
-----------------
You can use your Visual C++ IDE to build and run the HelloWorld sample:

1. Set up your Visual Studio search paths as follows:

   Include files: installDir\include
   Executable files: installDir\bin
   Library files: installDir\lib

2. Choose 'File > Open Project/Solution' and open the helloWorld solution
   in installDir\samples\cxx\helloWorld.

3. Choose 'Build > Build helloWorld'.

4. Choose 'Debug > Start Without Debugging'.

When successful, the sample application outputs a message that includes: 
    
    HelloWorld test has PASSED

If the HelloWorld test does not pass:

- Verify your environment-variable settings, Visual C++ IDE search paths, and
  default Objectivity license file.
- Correct any errors, choose 'Build > Clean' or 'Build > Clean helloWorld', 
  then build the application again.

UNIX and Macintosh Platforms
----------------------------
1. Create a copy of installDir/samples/cxx and give yourself read, write, 
   and execute permissions. For example:
   
   cp -r installDir/samples/cxx homeDir
   chmod 777 homeDir/cxx

2. Create the demo federated database and build the sample application
   (helloWorld):
   
   cd homeDir/cxx/helloWorld
   make -e

   The -e flag causes make to use the environment variables you set.

3. Run the sample application. Enter:

   ./helloWorld data/HelloWorld.boot

When successful, the sample application outputs a message that includes: 
    
    HelloWorld test has PASSED

If the HelloWorld test does not pass:

Check the compiler, the lock server, and the settings of the environment
variables. Correct any errors and run the sample applications again.

If you need help, contact Objectivity Customer Support:

    http://support.objectivity.com/contact



