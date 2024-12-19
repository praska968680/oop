def average(l):
    sum=0
    for i in l:
        sum=sum+i
    avg=sum/len(l)
    return avg
########################################################################
def highest(l):
    max=l[0]
    for i in l:
        if(i>max):
            max=i
    return max
def lowest(l):
    min=l[0]
    for i in l:
        if(min>i):
            min=i
    return min
########################################################################
def frequency(l):
    count=0
    a=l[0]
    for i in l:
        f=l.count(i)
        if(f>count):
            count=f
            a=i
    print("Marks with highest frequency is :",a)
#########################################################################
SE_comp=[]
n=int(input("Enter total number of students :"))
Ab=0
for i in range(n):
    mark=int(input("Enter marks of student (Enter -1 if absent) :"))
    if(mark != -1):
        SE_comp.append(mark)
    else:
        Ab=Ab+1
        n=n-1
print("List you entered ",SE_comp)
while(True):
    print("--------------------MENU---------------------")
    print("1.The average score of class")
    print("2.Highest score and lowest score of class")
    print("3.Count of students who were absent for the test")
    print("4.Display mark with highest frequency")
    print("5.EXIT")
    n=int(input("Enter the option :"))
    if(n==1):
        print("The average of given students is",average(SE_comp))
    if(n==2):
        print("The highest mark is ",highest(SE_comp))
        print("The lowest mark is ",lowest(SE_comp))
    if(n==3):
        print("Number of absent student/s",Ab)
    if(n==4):
        print(frequency(SE_comp))
    if(n==5):
        print("Thank you")
        break
