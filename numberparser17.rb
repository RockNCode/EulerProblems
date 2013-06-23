units = {
        0 => "",
        1 => "one",
        2 => "two",
        3  => "three",
        4 => "four",
        5 => "five",
        6 => "six",
        7 => "seven",
        8 => "eight",
        9 => "nine",
        10 => "ten",
        11 => "eleven",
        12 => "twelve",
        13 => "thirteen",
        14 =>"fourteen",
        15 =>"fifteen",
        16 => "sixteen",
        17 =>"seventeen",
        18 =>"eighteen",
        19 =>"nineteen",
    }

    decimal = {

      2 => "twenty",
      3=> "thirty",
      4 => "forty",
      5 => "fifty",
      6 => "sixty",
      7 => "seventy",
      8 => "eighty",
      9 => "ninety"

    }

sum = 0

    for counter in 1..999 do
        size = counter.to_s.size
        str = ""
        decimalplaces = counter.to_s[(size-2)..(size-1)].to_i

        if size >= 3
            index = counter.to_s[size-3].to_i
            str += units[index] +" " + "hundred "
            sum+=units[index].size
            sum+="hundred".size

            if counter.to_s[(size-2)..(size-1)] != "00"
                sum+="and".size
                str += "and "
            end

        end

        if  decimalplaces < 20
            sum += units[ decimalplaces ].size
            str +=units[ decimalplaces ]
        end

        if decimalplaces >= 20 and decimalplaces <= 99
            second = counter.to_s[size -2 ].to_i
            first =counter.to_s[size -1].to_i
            sum +=  decimal[ second ].size + units[first].size
            str += decimal[ second ] + " " + units[first]
        end

        puts str
    end

    sum += "onethousand".size

    puts "The final sum is #{sum}"

