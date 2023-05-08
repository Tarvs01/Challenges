#enter a large number to print it in its comma form.
#example input = 1000000
#output = 1,000,000
#No external/inbuilt function is to be used

a = gets.chomp
puts "Your input is #{a}"
b = -4
begin
     Integer(a)
rescue ArgumentError
    puts "Please enter an integer"
    exit 0
end
while (b >= ((a.length)*-1))
    a.insert(b,',')
    b-=4
end
puts (a)