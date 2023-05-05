=begin
#challenge

February 2026 will be a "Perfect Month".

A perfect month is a month of exactly 4 weeks (28 days), that starts on a Sunday and ends on a Saturday.

Find as many "Perfect Months" as you can. Make a program that outputs years with a perfect february month.
=end

#a perfect month will only occur in years that aren't leap years
#a perfect month can only be February 
#this program searches from the year 1000 to the year 3000 for the years with a perfect month
#Link to challenge in comments


require 'date'

puts "The years with a perfect month between years 1000 and 3000 are"
Date.new(1000,1,1).upto(Date.new(3000,12,30)) do |date|
    if (date.month==2 && date.year%4 != 0)
        if (date.mday==1 && date.wday==0)
            puts "#{date.year}"
        end
    end
end