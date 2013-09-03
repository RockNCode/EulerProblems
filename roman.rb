$numbers = {'I' => 1,
  'V' => 5,
  'X' => 10,
  'L' => 50,
  'C' => 100,
  'D' => 500,
  'M' => 1000
}

#need to combine four concecutive Is into IV
#need to combine 2 V's into X
#need to combine 5 

#Only I, X, and C can be used as the leading numeral in part of a subtractive pair.
#I can only be placed before V and X.
#X can only be placed before L and C.
#C can only be placed before D and M.

def ReduceRoman(myroman)
  lesschar = 0;
  newroman = ""
  puts "orig roman = #{myroman}"

  for i in 0...myroman.to_s.length-1 do
    count = 0
    j=i
    basechar = myroman[i]
    
    while ( $numbers[myroman[j]] == $numbers[myroman[j+1]]) do
      count = count + 1
      j = j+1
    end
    
    if(count == 4)
      case basechar
      when 'I'
        
      when 'V'
        
      when 'L'
        
      when 'C'
        
      when 'D'

      when 'M'
 
      end

    else
      for k in 0..count do
        newroman[k]=basechar
      end
    end

  end
  puts "new roman is #{newroman}"
  return lesschar
end


roman = Array.new

file = File.new("roman.txt","r")

while line = file.gets(sep=$/) do
  roman.push(line)
end

file.close

lesschar = 0

for i in 0..roman.length do
  lesschar = lesschar + ReduceRoman(roman[i])
end

puts "Done reduce char is #{lesschar}"
