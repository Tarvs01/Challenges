#An alexandrian number N is one which can be represented by N = pqr and 1/N = 1/p + 1/q + 1/r
#This program generates all alexandrian numbers less than 20k

def alex(a,b,c,d)
    if ((a**-1)==((b**-1)+(c**-1)+(d**-1)))
        return true
    end
    return false end

def place(a,b,c,d)
    if alex(a,b,c,d)
        return b,c,d
    elsif alex(a,-b,-c,d)
        return -b,-c,d
    elsif alex(a,-b,c,-d)
        return -b,c,-d
    elsif alex(a,b,-c,-d)
        return b,-c,-d
    else
        return false end end

puts"A.numbers\t\t\tfactors"
for i in (1..20000)
    a=0
    for j in (1..i/2)
        if (i%j==0)
            if a==1
                break end
            b = i/j
            for k in (1..b/2)
                if (b%k==0)
                    bodi = place(i,j,k,b/k)
                    if (bodi != false) 
                        a = 1
                        puts "#{i}\t\t\t\t#{bodi[0]}, #{bodi[1]}, #{bodi[2]}"
                        break
end end end end end end