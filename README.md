# Platform GPIO skel for raspberry pi

This is minimal working example of a device driver on *platform_device* bus.
It handles device driver binding to a particular device. In this example, 
device is defined by device tree overlay (file *skel.dts*).   

You should check out following resources:
* <linux_source_root>/Documentation/driver-api/driver-model/platform.rst
* <linux_source_root>/Documentation/devicetree/usage-model.rst
* <linux_source_root>/Documentation/devicetree/overlay-notes.rst
* [https://www.raspberrypi.org/documentation/configuration/device-tree.md]

# Build and run

Following instructions are for raspbian 10 (buster).  

Dependencies:
```bash
$ sudo apt-get install raspberrypi-kernel-headers build-essential bc git wget bison flex libssl-dev make libncurses-dev
$ sudo apt install device-tree-compiler
```

To build kernel module, run:
```bash
$ make
```
To build device tree overlay, run:
```bash
$ make overlay
```
To test it, insert device tree overlay by running:
```bash
$ sudo dtoverlay skel.dtbo
```

Insert kernel module:
```bash
$ sudo insmod gpio.ko
```

Then check out dmesg output by running:
```bash
$ dmesg | tail
```
To remove device tree overlay, run:
```bash
$ sudo dtoverlay -r skel
```
