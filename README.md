# Collatz-Conjecture
An Arduino sketch that produces Collatz sequences

I was between projects and decided to revisit an old mathematical problem - the Collatz Conjecture. As I do not possess any other C++ development environment than Arduino IDE, the choice of platform was easy - Arduino IDE and an Arduino microcontroller. The coding is straight forward and I did not need any other components than my pc and microcontroller - no wires, LEDs, relays, buzzers, servos, etc.

If you have an interest in mathematics, even at a rudimentary level, then you may find this article interesting.

# What is the Collatz Conjecture?
The Collatz Conjecture is a very simple to follow set of rules concerning positive integers (whole numbers). The conjecture says that if you take any positive integer and apply the following rules:

1. if the integer is odd then multiply it by 3 and add 1, otherwise
2. if the integer is even then divide it by 2 and
3. if the result from either step is greater than 1 repeat the above two steps.
then the sequence produced eventually converges (collapses) to 1, irrespective of the starting choice of positive integer, however small or large.

For example, lets select the integer 11 as our starting value. Then if we apply the above rules we generate the sequence:

11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
Let's try another number, say 3412. The sequence generated is:

3412, 1706, 853, 2560, 1280, 640, 320, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
It will work like this for any positive integer you select! Remarkable.

At this point in time the Collatz Conjecture has not been proven for all positive integers. At the surface, the conjecture appears simple enough, but it has very deep roots into number theory and has challenged many great mathematicians since it was first proposed by Lothar Collatz in 1937. There is much on the internet about Lothar Collatz and his conjecture and if your interest is sparked then do a little research - you will soon discover its hidden complexities!

For this article, though, we are simply concerned with using an Arduino microcontroller to run a short program that produces the Collatz sequence for any given user provided positive integer. Other than plugging in a microcontroller to a pc running your IDE and opening the serial monitor that is all there is to configure. Any Arduino microcontroller should be suitable.

So load up and try a few positive integers, small or large. I think you will be surprised how some small numbers produce long sequences and how some large numbers short one. After you have tried a few you will notice something common to all sequences in how the converge to produce 1.

# Set Up
Set up couldn't be simpler:

select your Arduino microcontroller and connect to your pc running IDE
download the Collatz sketch, compile and upload to your microcontroller
open the serial monitor (make sure it is set 9600 baud) and enter a positive integer into the input field, then either press return or hit the send button
note the sequence of integers in the Collatz sequence for your number. Run several examples and see that there appears to be no correlation between the number and how many values are in its Collatz sequence. What else do you notice?
The program runs in a loop and further numbers can be entered in the same way.

# The Shape of Collatz Sequences
When you have explored many examples and satisfied yourself that the conjecture does indeed collapse all of your example sequences to 1, explore the serial plotter rather than the serial monitor.

If you select the serial plotter (from the IDE tools menu) rather than the serial monitor then what this produces is a graph showing the 'shape' of Collatz sequences. Unfortunately the serial plotter does not have a clear button/function and so you will need to close it and reopen it between each sequence, but it does provide another interesting observation about the conjecture.
