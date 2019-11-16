// araxisdiff.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

enum
{
    eDynamicView = 3,
    eSnapshotView = 7
};

int main(int argc, char* argv[])
{
    //Input format for snapshot view - "xcompare -fname %s -fname %s %s %s";
    //Input format for dynamic view -  "xcompare %s %s";
    const char* out_format = "%s /2 /title1:\"[1] %s\" /title2:\"[2] %s\" \"%s\" \"%s\"";
    const char* program_name = "compare.exe";
    string out_str;

    switch(argc)
    {
    case eSnapshotView://snaphot view
        {
         /* example of command line:
         compare.exe xcompare -fname E:\GENSRC\sblconnector_6_5_3_kiev\sblconnector\frmTransferToForm.frm@@\main\6.5.3_kiev\1 
                              -fname E:\GENSRC\sblconnector_6_5_3_kiev\sblconnector\frmTransferToForm.frm 
                              \\miracle\.1\vobstore\sblconnector\c\cdft\27\3b\b560c12cd9db404c9454f0d75472230f.msdos 
                              E:\GENSRC\sblconnector_6_5_3_kiev\sblconnector\frmTransferToForm.frm 
         */
         
          string name_tag = "-FNAME";
          string name1 = argv[1];
          string name2 = argv[3];

          std::transform(name1.begin(), name1.end(), name1.begin(), ::toupper);
          std::transform(name2.begin(), name2.end(), name2.begin(), ::toupper);

          if(name1==name_tag && name2==name_tag)
          {
              char buff[1024] = {0};
              ::sprintf_s(buff, out_format, program_name, argv[2], argv[4], argv[5], argv[6]);
              out_str = buff;
          }
      }
      break;
   case eDynamicView://dynamic view
	   {
          /* example of command line:
          compare.exe xcompare Y:\sosinniy_view2\sblconnector\ActiveMsgsBanner.ctl@@\main\r6.1\r6.5\0 
                               X:\sblconnector\ActiveMsgsBanner.ctl 
          */

           char buff[1024] = {0};
           ::sprintf_s(buff, out_format, program_name, argv[1], argv[2], argv[1], argv[2]);
           out_str = buff;
       }
       break;
   default:
       break;
   }
   
   if(!out_str.empty())
   {
       system(out_str.c_str());
   }
   else
   {
       cout<<
           "AraxisDiff v2.0 - adapter between Rational ClearCase and Araxis Merge.\n\n"
           "Usage : araxisdiff.exe [params]\n"
           "where params:\n"
           " for snapshot view : -name FileName1 -name FileName2 File1 File2\n"
           " for dynamic view  : File1 File2\n\n";
   }

    return 0;
}
