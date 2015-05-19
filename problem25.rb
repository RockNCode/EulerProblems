#!/usr/bin/env ruby

def  fibonacci_rec (last )
  if( last <=2 )
    return 1
  end
  return ( fibonacci_rec( last - 1) + fibonacci_rec(last -2 ) )
end

def  fibonacci_dyn (last )

end


fibo = fibonacci_rec(10)

puts "The fibo is #{fibo}"

countDigits = 0
index = 3
stage =0
fibo_k1 =1
fibo_k2 =1

while true  do
  fibo = fibo_k1 + fibo_k2#fibonacci(index)
#  puts "fibo is #{fibo}"
  fibo_k2=fibo_k1
  fibo_k1=fibo



  if(fibo.to_s.size == 3 && stage == 0)
    puts "stage 0 cleared fibo =#{fibo}"
    stage =1
  end
  if(fibo.to_s.size == 200 && stage == 1)
    puts "stage 1 cleared"
    stage =2
  end
  if(fibo.to_s.size == 500 && stage == 2)
    puts "stage 2 cleared"
    stage =3
  end
  if(fibo.to_s.size == 900 && stage == 3)
    puts "stage 3 cleared"
    stage =4
  end
  if(fibo.to_s.size >= 1000)
    break
  end
   index = index + 1
end

puts "The index of the first item is #{index} last fibonacci =#{fibo}"
