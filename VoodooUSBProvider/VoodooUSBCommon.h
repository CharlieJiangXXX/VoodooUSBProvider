//
//  VoodooUSBCommon.h
//  VoodooUSBProvider
//
//  Copyright © 2021 cjiang. All rights reserved.
//
//-----------------------------------------------------------------------------
/*
 *  Released under "The GNU General Public License (GPL-2.0)"
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef VoodooUSBCommom_H
#define VoodooUSBCommon_H

#include "VoodooHCI.h"
#include <IOKit/usb/USB.h>

#if defined(TARGET_ELCAPITAN) || defined(TARGET_CATALINA)

#include <IOKit/usb/IOUSBHostInterface.h>
#include <sys/utfconv.h>

#define USBDevice                       IOUSBHostDevice
#define USBInterface                    IOUSBHostInterface
#define USBPipe                         IOUSBHostPipe

#define USBCompletion                   IOUSBHostCompletion
#define USBConfigurationDescriptor      StandardUSB::ConfigurationDescriptor
#define USBEndpointDescriptor           StandardUSB::EndpointDescriptor
#define USBStatus                       UInt16

#else

#include <IOKit/usb/IOUSBInterface.h>

#define USBDevice                       IOUSBDevice
#define USBInterface                    IOUSBInterface
#define USBPipe                         IOUSBPipe

#define USBCompletion                   IOUSBCompletion
#define USBConfigurationDescriptor      IOUSBConfigurationDescriptor
#define USBEndpointDescriptor           IOUSBEndpointDescriptor

#endif

#define VoodooUSBSafeDeleteNULL(x) do { if (x) { delete x; x = NULL; } } while (0)
#define VoodooUSBSafeDeleteArrayNULL(x) do { if (x) { delete[] x; x = NULL; } } while (0)

#define VOODOO_USB_DRIVER_NAME "VoodooUSBProvider"

#ifdef DEBUG
#define VoodooUSBDebugLog(args...) do { IOLog(VOODOO_USB_DRIVER_NAME ": " args); } while (0)
#else
#define VoodooUSBDebugLog(args...) do { } while (0)
#endif /* DEBUG */

#define VoodooUSBAlwaysLog(args...) do { IOLog(VOODOO_USB_DRIVER_NAME ": " args); } while (0)

#define VoodooUSBErrorLog(args...) VoodooUSBAlwaysLog("Error! " args)
#define VoodooUSBInfoLog(args...) VoodooUSBAlwaysLog(args)
#define VoodooUSBWarningLog(args...) VoodooUSBDebugLog("Warning! " args)
#define VoodooUSBFuncLog(args...) VoodooUSBDebugLog(args "()\n")

#endif /* VoodooUSBCommon_H */
