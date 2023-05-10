#input is the number of digits the fibonacci number should have
#It prints out the first fibonacci term with that number of digits and the term

x = gets.to_i
a,b,c,f = 0,1,0,2
e = true

while (e)
    c = b + a
    a,b,d = b,c,c
    if (d.to_s.length >= x)
        e = false
    end
    f=f+1
end

puts ("The first fibonacci number with #{x} digits is the #{f}th term")

puts ("\nThat fibonacci number is\n")
puts(d)