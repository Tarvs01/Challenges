#instructions below

def sumd(x)
    a=sum=0
    b = x
    while (b>0)
        a = b%10
        b /= 10 
        sum += a
    end
    return sum
end

def isprime(x)
    for a in (2...x)
        if (x%a==0)
            return false
        end end
    return true
end

def factors(x)
    if (isprime(x))
        return sumd(x)
    else
        for i in (2...x)
            if (isprime(i) && (x%i==0))
                return sumd(i) + factors(x/i)
            end end end end
puts "The smith numbers upto 1000 are"
for i in (2..1000)
    if (!isprime(i) && (sumd(i) == factors(i)))
        puts i
        end end

=begin
[CHALLENGE]

🔹Write a program that accepts a number from the user and verifies if it's a Smith Number or not.

🔹What is a Smith Number?

️Smith Number is a composite number whose sum of digits is equal to the sum of digits of its prime factors obtained as a result of prime factorization (excluding 1). The first few such numbers are 4, 22, 27, 58, 85, 94, 121.

🔹Bonus : Try to code it in the fewest lines possible or display a range of these numbers.

All languages are welcome!
=end