#Please for your input, input the year first then the day.and input them on seperate lines
#also, please make the day all small letters. sorry for the inconvenience
#format for input is this. The year first. Then the day on a NEWLINE. don't leave a space between the year and day. write input the day on a NEWLINE. thanks.

=begin
Time for [Weekend Challenge]
Let the user input a year and a weekday.

Output: The sum of all days of that year falling on that day

Example:

User chooses 2021 and Sunday
The result is the sum of all red numbers on the picture below.
=end
#Link to Challenge in comments
#please for your input, input the year first then the day. and input them on seperate lines.

require 'date'

#The below function checks if the year is a leap year
def isleapyear(x)
    if (x%4==0)
        if (x%100==0 && x%400==0)
            return 1
        else
            return 0
        end
    else
        return 0
    end
end

a = gets.to_i
b = gets.chomp
puts "You entered year #{a}"
puts "You entered day #{b}\n"

if (b == "sunday")
    c=0
elsif (b == "monday")
    c=1
elsif (b == "tuesday")
    c=2
elsif (b == "wednesday")
    c=3
elsif (b == "thursday")
    c=4
elsif (b == "friday")
    c=5
elsif (b == "saturday")
    c=6
else
    puts "Enter the day in small letters"
    puts ""
    exit(0)
end

#The block of code below is unnecessary for the challenge. I was just testing something. This calculates the total number of that day in that year
t = Time.new(a,1,1)
d = isleapyear(a)
e = t.wday
if (d == 0)
    if (c==e)
        f=53
    else
        f=52
    end
else
    if (c==e || c==e+1)
        f=53
    else
        f=52
    end
end

#The block below calculates the sum of the dates
g=0
Date.new(a,1,1).upto(Date.new(a,12,30)) do |date|
    if (date.wday==c)
        g+=date.mday
    end
end
puts "There are #{f} #{b}'s in #{a}"
puts "The sum of #{b}'s dates in #{a} is #{g}"