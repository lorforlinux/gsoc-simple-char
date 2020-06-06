# gsoc-simple-char
This repo includes a simple charachter driver and testing program, written as part of GSoC warmup task.

---

## To try this out, follow these commands on you BeagleBone
1. Clone this repo: `git clone https://github.com/lorforlinux/gsoc-simple-char.git`
2. Compile the project: `make`
3. Get super user privilages: `su`
4. Open up kernel log on different terminal: `tail -f /var/log/kern.log`
5. Load the LKM: `insmod gsochar.ko`
6. Use the test program to talk to the device you created: `./test`
7. Remove the LKM using: `rm gsochar`
   

References:
- https://github.com/thejinxters/simple_linux_character_driver
- http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/