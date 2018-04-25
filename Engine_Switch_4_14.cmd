@ECHO OFF
CALL clean_intermediate_files.cmd
SET APP="UnrealEngineVersionChanger\bin\Debug\UnrealEngineVersionChanger.exe"
IF NOT EXIST %APP% ECHO UnrealEngineVersionChanger needs to be compiled!
IF EXIST %APP% CALL "UnrealEngineVersionChanger\bin\Debug\UnrealEngineVersionChanger.exe" 4.14
COPY /Y UE4ChromaSDKRT_4_14.uproject UE4ChromaSDKRT.uproject
CALL SwitchEngineVersion.cmd
IF EXIST "%CD%\ChromaSDKPlugin_4_14.zip" START "" OpenPluginBinaries.cmd
IF EXIST "%CD%\ChromaSDKPlugin_4_14.zip" "C:\Program Files\7-Zip\7zFM.exe" "%CD%\ChromaSDKPlugin_4_14.zip\ChromaSDKPlugin\Binaries\Win64\"
