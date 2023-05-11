=begin
Challenge - Digit powers

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1⁴ + 6⁴ + 3⁴ + 4⁴
8208 = 8⁴ + 2⁴ + 0⁴ + 8⁴
9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴

As 1 = 1⁴ is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

Bonus => Do for powers 2,3 and 4.
=end

def power(x,y)
    a = 1
    b = x
    sum = 0
    while (b>0)
        a = b%10
        b = (b/10)
        sum += (a**y)
    end
    if (sum==x)
        return true
    else
        return false
    end
end

for a in (2..5)
    sum = 0
    puts "The numbers for #{a} are"
    for b in (2..200000)
        if power(b,a)
            puts "#{b}"
            sum += b
        end
    end
    puts "Their sum is #{sum}"
    puts ""
end
