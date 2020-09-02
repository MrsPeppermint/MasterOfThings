# Write a program to prompt the user for hours and rate per hour using input to compute gross pay. 
# Pay the hourly rate for the hours up to 40 and 1.5 times the hourly rate for all hours worked above 40 hours. 
# You should use input to read a string and float() to convert the string to a number. Do not worry about error checking.

hrs = float(input("Enter Hours:"))
rate = float(input("Enter rate: "))
if hrs > 40.0:
    pay = 40 * rate + (hrs-40) * 1.5 * rate
else:
    pay = hrs * rate
print(pay)
