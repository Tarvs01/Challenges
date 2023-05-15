=begin
[CHALLENGE]

The Euler Number e is used as the base of natural logarithm.

It can be approximated using the formula:
e = 1 + 1 / 1! + 1 / 2! + 1 / 3! + … 1 / n!

Write a program in any language that approximates e using a loop that terminates when the difference between two successive values of e differ by less than 0.00000001.
=end

def fact(x)
    if (x==1)
        return 1
    end
    return x * fact(x-1)
end

a = 1.0
d = 1
b = 0.0
c = a-b
while(c>=0.00000001)
    a = a + (1.0/fact(d))
    d = d + 1
    c=a-b
    b = a
end
puts '%.50f' % a
