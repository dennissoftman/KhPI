#!/usr/bin/python3
from random import randint as rand

f = open('test.bin', 'wb')
for i in range(0, 10):
  num = rand(0, 2**31)
  print(num)
  f.write(num.to_bytes(4, byteorder='little'))
f.close()
