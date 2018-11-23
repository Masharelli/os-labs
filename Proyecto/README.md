 # The CODE

So we know the theory, and we have our tools ready. What now? Code? Well... before putting finger to keyboard, it's a good idea for us to take a step back and think about what we have to work with.

##Freestanding - What Does This Mean?

I've already mentioned that we're running our code 'freestanding'. But what does this mean, and how will it affect us? It's important you know. Normally when you write C code in a hosted environment, you have a plethora or interfaces available to you. You can read from files, you can output messages, you can get user input... All with just a few lines of code. Sadly, we don't have that. Those things are provided by an operating system. And right now, we don't have one since we ARE the operating system.

What we DO have access to however is a few useful headers GCC automatically provides us with (they give us things like fixed-width integers) and the hardware of the x86. We'd like to output text, so for that we're going to write ourselves a very simple driver that interacts with the x86's VGA buffer and allows us to display text on the screen. In doing this, we'll have to avoid using anything like the C standard library, because it simply isn't available when we're compiling for a freestanding target like we are now.


So without further ado... Let's start programming!
##The Project Structure

Please remember, this is a minimal setup. A more advanced kernel project will have a more complex code structure, as well as an automated build system.

For now, we'll be creating 3 files in our project directory. They are: 
///
start.s     - This file will contain our x86 assembly code that starts our kernel and sets up the x86
kernel.c    - This file will contain the majority of our kernel, written in C
linker.ld   - This file will give the compiler information about how it should construct our kernel executable by linking the previous files together
///
