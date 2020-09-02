# Write a program that repeatedly prompts a user for integer numbers until the user enters 'done'. 
# Once 'done' is entered, print out the largest and smallest of the numbers. 
# If the user enters anything other than a valid number catch it with a try/except and put out an appropriate message and ignore the number. 

nums = []
while True:
    num = input("Enter a number: ")
    if num == "done" : break	
    try:
        num = int(num)
        nums.append(num)
        
    except ValueError:
        print("Invalid input")
       
print("Maximum is", max(nums))
print("Minimum is", min(nums))
