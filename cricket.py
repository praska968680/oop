
n1=int(input("No. of students play cricket :"))
cricket = []
for i in range(n1):
    roll = int(input("enter roll_ no play cricket:"))
    cricket.append(roll)
print("List of students play cricket :", cricket)    

n2=int(input("No. of students play football :"))
football = []
for i in range(n2):
    roll1= int(input("enter roll_ no play football:"))
    football.append(roll1)
print("List of students play football :", football)

n3=int(input("No. of students play badminton :"))
badminton = []
for i in range(n3):
    roll2= int(input("enter roll_ no play badminton:"))
    badminton.append(roll2)
print("List of students play badminton :", badminton)


def intersection( l1, l2):
    res= []
    for i in l1:
        if i in l2:
            res.append(i)
    return res

def union(l1, l2):
    res = l1[:]  # Start with all elements of l1
    for i in l2:  # Add elements from l2 that are not already in res
        if i not in res:
            res.append(i)
    return res
5
def diff( l1, l2):
    res = []
    for i in l1:
        if i not in l2:
            res.append(i)
    return res
i=intersection(cricket,badminton)
u=union(cricket,badminton)
d=diff(football,u)

print (" List of students play both cricket and badminton ",i)
print (" List of students who play either cricket or badminton  but not both ",diff(u,i))
print (" List of students plays neither cricket nor badminton ",d)
print (" List of students who play cricket and football but not badminton ",diff(union(cricket,football),badminton))

 
