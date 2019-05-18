def derminat(number):
    if number >= -128 and number <= 127: return "byte"
    elif number >= -32768 and number <= 32767: return "short"
    elif number >= -2147483648 and number <= 2147483647: return "int"
    elif number >= -9223372036854775808 and number <= 9223372036854775807: return "long "
    else : return "BigInteger"
print(derminat(int(input())))