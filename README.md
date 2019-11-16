# AraxisDiff
Integrates AraxisMerge and ClearCase

How to install a snap-in (AraxisDiff) for Rational ClearCase to work with Araxis Merge difference viewer.
 
1. You should have Araxis Merge installed.
2. Add path to compare.exe (tool for file comparations, supplied with Araxis Merge) to PATH 
  variable in your environment.
3. Copy araxisdiff.exe to the clearcase\bin directory.
4. Backup clearcase\lib\mgrs\map file.
5. Replace all places, except for directory sections, that contain cleardiff.exe and cleardiffmgr.exe 
 by araxisdiff.exe in clearcase\lib\mgrs\map
 
for example:
 
in original map file:
 
    text_file_delta  compare    ..\..\bin\cleardiff.exe
    text_file_delta  xcompare   ..\..\bin\cleardiff.exe

should be changed to:
 
    text_file_delta  compare    ..\..\bin\araxisdiff.exe
    text_file_delta  xcompare   ..\..\bin\araxisdiff.exe
 
NOTE: Do it only for compare and xcompare actions!

  Or merge content of 'map.araxis' file into clearcase\lib\mgrs\map (make backup of the original map
file before it)