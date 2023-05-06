#This code prints out palindrome dates for different date formats

#input is either w or u. using w prints out palindrome dates in dd/mm/yyyy format. w represents world

#using u prints out palindrome dates in mm/dd/yyyy format. u represents USA.

#USA and the rest of the world use different date formats.

#it checks from 1660 - 3000

require 'date'

def rev(t)
    if t<10
        d = "0"
        d = d + (t.to_s)
        return d
    else
        return t.to_s
    end
end

e = gets.chomp

if (e=='U' || e=='u')
    puts "using mm/dd/yyyy format"
elsif (e=='W' || e=='w')
    puts "using dd/mm/yyyy format"
else
    puts "using default value dd/mm/yyyy format"
end

Date.new(1660,1,1).upto(Date.new(3000,12,30)) do |date|
    a = date.year
    a = a.to_s
    a = a.reverse
    b = rev(date.mday)
    c = rev(date.month)
    if ((b+c)==a && (e=='W' || e=='w'))
        puts "#{b}/#{c}/#{date.year}"
    elsif ((c+b)==a && (e=='U' || e=='u'))
        puts "#{c}/#{b}/#{date.year}"
    elsif (b+c==a)
        puts "#{b}/#{c}/#{date.year}"
    end
end

#while we were celebrating february 12,2021 as our palindrome date, people in USA will celebrate December 2,2021 as their palindrome date.