# Function for the representation of the matrix
def matrix_representation(m, n):
    matrix = []
    for i in range(m):
        row = []
        for j in range(n):
            element = int(input("Enter the elements as per the row column wise: "))
            row.append(element)
        matrix.append(row)
    return matrix

# Function for the addition of the matrix
def add_matrix(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("Matrix addition is not possible.")
        return None
    result = [[mat1[i][j] + mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]
    return result

# Function for the subtraction of the matrix
def sub_matrix(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("Subtraction of the matrix is not possible.")
        return None
    result = [[mat1[i][j] - mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]
    return result

# Function for the multiplication of the matrix
def mult_matrix(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        print("Matrix multiplication is not possible.")
        return None
    result = [[sum(mat1[i][k] * mat2[k][j] for k in range(len(mat2))) for j in range(len(mat2[0]))] for i in range(len(mat1))]
    return result

# Function for the transpose of the matrix
def transpose_matrix(mat1):
    transposed = [[mat1[i][j] for i in range(len(mat1))] for j in range(len(mat1[0]))]
    return transposed

# For the first matrix mat1:
m = int(input("Enter the number of rows of the first matrix: "))
n = int(input("Enter the number of columns of the first matrix: "))
mat1 = matrix_representation(m, n)
print("The first matrix is:")
print(mat1)

# For the second matrix mat2:
m = int(input("Enter the number of rows of the second matrix: "))
n = int(input("Enter the number of columns of the second matrix: "))
mat2 = matrix_representation(m, n)
print("The second matrix is:")
print(mat2)

# Printing addition of the matrix:
addition = add_matrix(mat1, mat2)
print("The addition of the matrices is:")
print(addition)

# Printing subtraction of the matrix:
subtraction = sub_matrix(mat1, mat2)
print("The subtraction of the matrices is:")
print(subtraction)

# Printing multiplication of the matrix:
multiplication = mult_matrix(mat1, mat2)
print("The multiplication of the matrices is:")
print(multiplication)

# Printing the transpose of the matrix:
transpose1 = transpose_matrix(mat1)
print("The transpose of the first matrix is:")
print(transpose1)

print("THANK YOU")
