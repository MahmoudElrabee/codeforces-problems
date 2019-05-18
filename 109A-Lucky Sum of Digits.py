n = input()
result = ""
while (n%7!=0 and n>0):
 result+='4'
 n-=4
flg = 0
if (n<0 or n%7!=0):
 flg = 1
if(flg!=1):
 while n>0:
  result+='7'
  n-=7
 print result
else :
 print -1