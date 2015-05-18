
int charToDigit(char mychar){
  return mychar - 0x40;
}

char digitToChar(int digit)
{
    return (char)(digit + 0x40);
}
