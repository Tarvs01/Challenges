=begin
#Challenge

(A Cash Flow Problem)

Three Pay Check Months
====================

Thanos works at McThanos™️ flipping McGauntlet™️ burgers. 

He is paid once every two weeks, always on a Thursday.

Knowing that he had his first pay on January 14, 2021, find out which months he will have 3 pay checks so he can plan to party more around that time (as he will have extra money left after he pays his rent and other monthly bills).
=end

#This program checks the years 2021 to 3031 for the months that he will be paid 3 times

require 'date'
a=0
b=0
c=0
Date.new(2021,1,14).upto(Date.new(2031,12,31)) do |date|
    if (date.mday==1)
        a=0
    end
    if (date.wday==4 && b==0)
        a+=1
    end
    if (b==0)
        b=1
    else
        b=0
    end
    if (a==3 && date.wday==4)
        print "He will get paid 3 times on "
        c=date.month
        case c
            when 1
                print "January, "
            when 2
                print "February, "
            when 3
                print "March, "
            when 4
                print "April, "
            when 5
                print "May, "
            when 6
                print "June, "
            when 7
                print "July, "
            when 8
                print "August, "
            when 9
                print "September, "
            when 10
                print "October, "
            when 11
                print "November, "
            when 12
                print "December, "
        end
        puts "#{date.year}."
        puts ""
    end
end