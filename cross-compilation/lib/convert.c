char hexToAscii(uint8_t h)
{
  if(h < 10)
    {
      return h + '0';
    }
  else
    {
      return (h - 10) + 'a';
    }
}

uint8_t asciiToHex(char a)
{
  if(a <= '9')
    {
      return a - '0';
    }
  else if(a <= 'F')
    {
      return a - 'A' + 10;
    }
  else if(a <= 'f')
    {
      return a - 'a' + 10;
    }
  else
    {
      return 0;
    }
}