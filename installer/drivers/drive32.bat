@echo off
setLocal Enabledelayedexpansion


FOR %%d IN (c d e f g h i j k l m n o p q r s t u v w x y z) DO (
  IF EXIST %%d:\ResetCD.exe (
    ECHO Device Found : %%d
  )
)

%%d:\ResetCD.exe %%d