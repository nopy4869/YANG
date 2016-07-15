# Yet ANother Gameboy

Yep, you guessed it! It's another Gameboy Emulator.

This work of art might actually play games some day.

# Usage
Arguments are as follows:


		    -d#       Sets debug level, # is between 0 and 3 inclusive


		               When no number is given, this defaults to level 1


		              Debug levels are as follows:


		                1:Logs and prints everything, breaks on every command, has a menu.


		                2:Logs and prints everything, doesn't stop after commands.


		                3:Logs everything, skips printing.


		                4:Prints everything, skips instruction logging, doesn't stop after commands.


		                5:Prints everything, skips instruction logging, breaks on every command.


		               WARNING: Logs with instruction logging get Very Big Very Fast...


		    -W#       Sets the level of execution bounds warning on address spaces


		               1 warns on execution from echo ram, 2 warns on


		               execution from IO and the undefined memory area.


		    -B#       Sets the level of execution limits on address spaces


		               1 exits on execution from echo ram, 2 exits on


		               execution from IO and the undefined memory area.


		              NOTE: In order to do anything, this must be at least


		                equal to the warn level (default is 1)


		    -s        Sets debug level to 3


		    -c        Force color mode


		    -g        Force original gameboy mode


		    -w -b -o  Turn on viewing tiledata for Window, Background,


		               and OAM respectively.


		Is your refridgerator running?Then you'd better catch it!




