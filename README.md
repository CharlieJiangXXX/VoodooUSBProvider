# VoodooUSBProvider

## Introduction
Developing a Qualcomm Bluetooth kernel extension for macOS recently, I realized how "terrible" the original bluetooth provider (IOUSBHostController) is - it has barely any compatibility for systems older than El Captain and many functions require wrapping up (AKA it is leaving too much space for developers, which is inconvenient). The purpose of this project is to provide an enhanced macOS bluetooth provider based on the apple one, in order to avoid certain trivial works being redone repeatedly.

## Requirements
1. Compile with Xcode. </br>
2. Use MacKernelSDK. See its README for more info. </br>

## How to use?
1. Copy the VoodooUSBProvider folder to the directory of your repository. </br>
2. Add the files to your project in Xcode. </br>
3. (Optional) In your project's Header Search Paths, add this folder. </br>
4. Make sure you have 3 IOKit driver targets with Deployment Targets 10.8, 10.11, and 10.15 respectively. </br>
5. Add Preprocessor Macros in the targets. </br>
In the 10.8 one, make sure you add TARGET_MAVERICKS=1. </br>

![TARGET_MAVERICKS](https://github.com/AppleBluetooth/VoodooUSBProvider/raw/master/Resources/TARGET_MAVERICKS.png)  

Add TARGET_ELCAPTAIN=1 in the 10.11 one. </br>

![TARGET_ELCAPTAIN](https://github.com/AppleBluetooth/VoodooUSBProvider/raw/master/Resources/TARGET_ELCAPTAIN.png)  

Add TARGET_CATALINA=1 in the 10.15 one. </br>

![TARGET_CATALINA](https://github.com/AppleBluetooth/VoodooUSBProvider/raw/master/Resources/TARGET_CATALINA.png)  

6. Include the codes of this project with 

        #include <VoodooUSBProvider.h>
or with

       #include "VoodooUSBProvider.h"
depending on whether you have completed step 3 or not. </br>
7. In places where you would originally use IOUSBHostDevice * or IOUSBDevice *, use VoodooUSBDevice * instead. Similarly for VoodooUSBInterface * and VoodooUSBPipe *. </br>
8. Enjoy 😎 </br>

## TO-DO
1. Add more HCI commands </br>
2. Add more vendor requests </br>
3. Add documentations </br>

## Acknowledgements
[Apple](https://www.apple.com) for macOS </br>
[Acidanthera](https://www.github.com/acidanthera) for BrcmPatchRam and MacKernelSDK </br>
[cjiang](https://www.github.com/CharlieJiangXXX) for developing this project </br>
