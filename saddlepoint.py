 
rows = int (input("Enter the no of elements present in row : "))
columns = int(input("Enter number of elements present in columns : "))
matrix = []
for i in range(rows):
    row =[]
    for j in range(columns):
        element = int(input(f"Enter elements present at position({i+1},{j+1}) : "))
        row.append(element)
    matrix.append(row)

print("Matrix is : ")
for row in matrix:
    print(row)

saddlePointFound = False

for i in range (rows):
    rowMin = min(matrix[i])
    colIndex = matrix[i].index(rowMin)

    column_values = [matrix[k][colIndex] for k in range(rows)] 
    if rowMin == max(column_values):
        print(f"Saddle point is found at ({i+1}, {colIndex+1}) with value: {rowMin}")
        saddlePointFound = True
        break
if not saddlePointFound:
    print("Saddle point is not found.")
