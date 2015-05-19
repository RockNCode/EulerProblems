#!/usr/bin/env ruby

index =1
result =0
while true  do
  result = result + index**index
  if (index == 100)
    puts "Stage 0 cleared"
  end
  if (index == 500)
    puts "Stage 1 cleared"
  end

  if (index == 700)
    puts "Stage 2 cleared"
  end

  index = index+1
  if(index == 1001)
    break
  end

end

puts "Result is #{result}"
