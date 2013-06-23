counter = 1
sum = 0
file = File.new("file.txt","r")
while line = file.gets do
puts " #{counter} : #{line}"
counter =  counter +1
sum = sum + line.to_i
end
file.close
puts "Sum = #{sum}"
