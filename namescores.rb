$scores = { 'A' => 1, 'B' => 2, 'C' => 3, 'D' => 4, 'E' => 5, 'F' => 6, 'G' => 7,
  'H' => 8, 'I' => 9, 'J' => 10, 'K' => 11, 'L' => 12, 'M' => 13, 'N' => 14, 'O' => 15,
  'P' => 16, 'Q' => 17, 'R' => 18, 'S' => 19, 'T' => 20, 'U' => 21, 'V' => 22,
  'W' => 23, 'X' => 24, 'Y' => 25, 'Z' => 26 }

def bubbleSort myNames
  for i in 0...(myNames.length-1) do
    for j in 0...(myNames.length-1) do
      temp = myNames[j+1]
      index = 0
      while ( myNames[j].to_s[index] == myNames[j+1].to_s[index] ) and
              ( index < myNames[j].length-1 and index < myNames[j+1].length-1) do
        index +=1
      end
      if( $scores[ myNames[j].to_s[index] ] > $scores[ myNames[ j+1].to_s[index] ] )
        myNames[ j+1] = myNames[j]
        myNames[j] = temp
      elsif( myNames[j].length > myNames[j+1].length &&
          $scores[ myNames[j].to_s[index] ] == $scores[ myNames[ j+1].to_s[index] ] )
        myNames[ j+1] = myNames[j]
        myNames[j] = temp
      end
    end
  end
  return myNames
end

names = Array.new

file = File.new("names.txt","r")
while line = file.gets(sep=",") do
  names.push(line.delete '"' ",")
end
file.close

names = bubbleSort(names)

sum = 0
for i in 0..names.length do
  namesum = 0
  for j in 0...names[i].to_s.length do
    namesum += $scores[names[i].to_s[j] ]
  end
  sum += (namesum * (i+1) )
end

puts "Sum of all names is #{sum}"
