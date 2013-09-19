#!/usr/bin/perl
print "\n"; 
print "Objectivity/DB (TM) WebSphere CMP Deployer, Version: 9.4\n";
print "Copyright (c) Objectivity, Inc 2007. All rights reserved.\n";
print "\n"; 
if (scalar @ARGV == 0) {
  print "Usage:\n";
  print "wsDeployer.pl ejbName.jar deployableEjbName.jar [pathToWebSphere]\n";
  exit 1;
}
if ($^O eq 'MSWin32') {
  $WS_HOME = "C:/Program Files/IBM/WebSphere/AppServer";
  $DELIM = ";";
}
else {
  $WS_HOME = "/opt/IBM/WebSphere/AppServer";
  $DELIM = ":";
}
if ($ARGV[2]) {
  $WS_HOME = $ARGV[2];
}
$WS_LIB = "$WS_HOME/lib";
$WS_BIN = "$WS_HOME/bin";
if ($^O eq 'MSWin32') {
  $EJB_DEPLOY = "$WS_BIN/ejbdeploy";
}
else {
  $EJB_DEPLOY = "$WS_BIN/ejbdeploy.sh";
}
mkdir "tmp";
system ($EJB_DEPLOY, "-dbvendor", "DB2UDB_V81", $ARGV[0], "tmp", $ARGV[1]);
$NEW_NAME = (split (/\./, $ARGV[1]))[0];
opendir (DIR, "tmp");
readdir (DIR);
readdir (DIR);
$NUMBER = readdir (DIR);
closedir (DIR);
$JAR = (split (/\.jar/, $ARGV[0]))[0];
$SEARCH_FILE = "tmp/$NUMBER/$JAR/ejbModule/META-INF/backends/DB2UDBNT_V8_1/ibm_pmbab.properties";
open (RESULT, $SEARCH_FILE);
read (RESULT, $buffer, 200);
$HASHCODE = (split (/_/, $buffer))[4];
$HASHCODE =~ s/[\s]//;
close (RESULT);
mkdir "tmp/lib";
$CP = "$ENV{'CLASSPATH'}$DELIM$NEW_NAME.jar";
system ("java -classpath \"$CP\" com.objy.ejb.websphere.ObjyCMPCodeGenerator $HASHCODE $ARGV[0]");
$CP = "$ENV{'CLASSPATH'}$DELIM$WS_LIB/../plugins/com.ibm.ws.runtime_6.1.0.jar$DELIM$NEW_NAME.jar";
opendir (DIR, "tmp");
while ($JAVA_FILE = readdir (DIR))
{
  if ($JAVA_FILE =~ m/java$/)
  {
    $filelist[++$#filelist] = "tmp/$JAVA_FILE" ;
  }
}
closedir (DIR);
system ("javac -d tmp/lib -classpath \"$CP\" @filelist");
chdir "tmp/lib";
system ("jar uvf ../../$NEW_NAME.jar .");
chdir "../..";
use File::Path;
rmtree("tmp", 0, 1);
