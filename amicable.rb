def getsumofproperdiv( num )
  sum=0
  for i in 1..(num/2)
    if (num % i ) == 0
      sum+=i
    end
  end
  return sum
end

amicalist = Array.new
for i in 1..10000 do
  amica = getsumofproperdiv(i)
  if ( (amica != i ) && !amicalist.include?(i) )
    if ( getsumofproperdiv(amica) == i )
      amicalist.push(amica)
      amicalist.push(i)
    end
  end
end

amicasum = 0
for i in 0...amicalist.length
  amicasum+=amicalist[i]
end
puts "Sum is #{amicasum}"
