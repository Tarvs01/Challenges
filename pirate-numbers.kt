//Input is the range you want to get the pirate numbers from.

//scroll to the bottom to see instructions for the challenge

//sorry for the poor output format. I'm still learning kt.


fun pirate(x: Int): Int {
    var y = 1
    for (i in 1..(x-1))
    {
        if (x%i==0)
        {
            y*=i
        }
    }
    if (y==(x*x))
    {
        print("$x :     ")
        for (i in 1..(x-1))
        {
            if (x%i==0)
            {
                print("$i,")
            }
        }
        var b = x*x
        print("        $b")
        println()
        return (1)
    }
    else
    {
        return (0)
    }
}
fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    println("You entered $n. Pirate numbers in the range 1-$n are")
    println(" Num     factors       square of num")
    for (i in 1..n)
    {
        pirate(i)
    }
}

/*Pirate Number Challenge
Task:
Write a program in any (not the name) language that checks if the number is pirate.
Pirate number is my new term.
Number is pirate if product of its divisors (excluding the number itself, but including 1 anyways) is the square of the number.

How to take part in this challenge:
If the language is supported by SoloLearn Code Playground: make a code, save it in Code Playground and give a link in the comment.
If the language is not supported by SoloLearn Code Playground:
 1) save it with any language set, but you must inform it in the comment, name of the code or comment in the code (using syntax of real language).
 OR
 2) create a web code that shows your challenge code properly (without loss).
You can also do a web code that shows your codes (do not forget to precise languages).

Notes:
You can include multiple codes.
All the codes must be written by yourself.

Bonus:
Make a program that displays/outputs/logs (etc.) pirate numbers in given range.*/