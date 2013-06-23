def  isGregorianLeapYear (year )
  leap = false
  if (year % 4) == 0
    leap = true
  end
  if (year % 100) == 0
    leap = false
  end
  if (year % 400) == 0
    leap = true
  end
  return leap
end

def daysInGregorianMonth(year,month)
  daysInMonth = [ 31,28,31,30,31,30,31,31,30,31,30,31 ]
  d = daysInMonth[month -1 ]
  if (month == 2 )&&(isGregorianLeapYear (year) )
    d+=1
  end
  return d
end

def dayOfYear (year, month , day)
  c = 0
  for i in 1...month do
    c = c + daysInGregorianMonth(year,i )
  end
c = c + day
return c
end

def dayOfTheWeek(year,month,day)
  w = 1
  year = ( (year - 1 ) % 400 ) + 1
  leapYear = (year -1 ) / 4
  leapYear -= (year - 1) / 100
  leapYear += (year - 1) / 400
  regYears = year - 1 - leapYear
  w += regYears
  w += 2*leapYear
  w += dayOfYear(year,month,day)
  w = (w - 1)%7 +1
  return w
end

sundaycount = 0

for yearcount in 1901..2000 do
  for monthcount in 1..12 do
    numdays = daysInGregorianMonth(yearcount,monthcount)
    for daycount in 1..numdays do
      #puts" #{yearcount}   #{monthcount }  #{daycount}"
      if (daycount == 1) && (dayOfTheWeek( yearcount, monthcount, daycount) == 1 )
        sundaycount +=1
      end
    end
  end
end

puts "The numbers of sundays from 1901 to 2000 is #{sundaycount}"
