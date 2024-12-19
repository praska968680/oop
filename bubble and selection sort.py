n=int(input("Enter number of students in first year: ")) 
marks=[] 
i=0 
for i in range(n): 
    num=float(input("Enter the percentage of students: ")) 
    marks.append(num) 
print("\nList of Students\n")     
print(marks) 
print("\nAfter Bubble Sort\n") 
def bubblesort(): 
    for i in range(0, n - 1): 
        for j in range(0, n - i - 1): 
            if (marks[j] > marks[j + 1]): 
                temp = marks[j] 
                marks[j] = marks[j + 1] 
                marks[j + 1] = temp 
    print(marks) 
     
bubblesort()     
     
print("\nAfter Selection Sort\n") 
 
def selectionsort(): 
    for i in range(0,n): 
        min = i 
        for j in range(i+1,n): 
            if(marks[min]>marks[j]): 
                min=j 
        temp=marks[i] 
        marks[i]=marks[min] 
        marks[min]=temp 
    print(marks) 
selectionsort()     
 
print("\n") 
def top(): 
    print("Top 5 students are:") 
    for i in range(1,6): 
        print(marks[-i]) 
top()
