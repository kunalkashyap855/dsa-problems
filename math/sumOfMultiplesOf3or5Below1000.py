"""
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9. The sum of these multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.
"""

def sum3(num_multiples):
    ans = 0
    for i in range(num_multiples + 1):
        ans += 3*i
    return ans
    
def sum5(num_multiples):
    ans = 0
    for i in range(num_multiples + 1):
        ans += 5*i
    return ans
    
def sum15(num_multiples):
    ans = 0
    for i in range(num_multiples + 1):
        ans += 15*i
    return ans

    
# FIND SUM OF ALL MULTIPLES 3 OR 5 BELOW 1000

num_multiples_3 = int((1000 - (1000 % 3)) / 3)
num_multiples_5 = int((1000 - 5) / 5)
num_multiples_15 = int((1000 - (1000 % 15)) / 15)
print(f"Number of multiples of 3 below 1000 = {num_multiples_3}")
print(f"Number of multiples of 5 below 1000 = {num_multiples_5}")
print(f"Number of multiples of 15 below 1000 = {num_multiples_15}")

# Add sum of all multiples of 3 and 5 below 1000, subtract sum of multiples of 15 below 1000
# because they are duplicate in the preceding sum
print(sum3(num_multiples_3) + sum5(num_multiples_5) - sum15(num_multiples_15))
