list1=[] 
num=int(input("Enter the number of first year student: ")) 
for i in range(0,num): 
    marks=int(input("Enter the marks of student: ")) 
    list1.append(marks) 
print("\nlist of first year Student Marks\n") 
print(list1) 
 
#Qick Sort 
 
def pivot_pos(list1,first,last): 
    pivot=list1[first] 
    left=first+1 
    right=last 
    while True: 
        while left<=right and list1[left]<=pivot: 
            left=left+1 
        while left<=right and list1[right]>=pivot: 
            right=right-1 
        if right<left: 
            break 
        else: 
            list1[left],list1[right]=list1[right],list1[left] 
    list1[first], list1[right] =list1[right], list1[first] 
    return right 
 
def quick_sort(list1, first, last): 
    if first<last: 
        p=pivot_pos(list1, first, last) 
        quick_sort(list1, first, p-1) 
        quick_sort(list1, p+1, last) 
 
quick_sort(list1, 0, len(list1)-1) 
print("\nAfter Quick Sort") 
print("\nSorted list: \n") 
print(list1) 
 
print("\nTOPPERS") 
def top(): 
    n=num-1 
    print("top 5 marks") 
    for i in range(n,num-6,-1): 
        print(list1[i]) 
top()         
