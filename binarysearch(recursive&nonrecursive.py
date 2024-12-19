def recursive_binary_search(list, ele, low, high):
    if low <= high:
        mid = (high + low) // 2
        if list[mid][0] == ele:
            return mid
        elif list[mid][0] > ele:
            return recursive_binary_search(list, ele, low, mid - 1)
        elif list[mid][0] < ele:
            return recursive_binary_search(list, ele, mid + 1, high)

    return -1

def non_recursive_binary_search(list, ele):
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = (high + low) // 2
        if list[mid][0] == ele:  # Compare the name at mid
            return mid
        elif list[mid][0] < ele:  # Move to the right half
            low = mid + 1
        else:  # Move to the left half
            high = mid - 1
    return -1

def get_name(item):
    return item[0]

def insert_friend(list, ele, mobile):
    if not list:
        list.append((ele, mobile))
        return
    index = non_recursive_binary_search(list, ele)
    if index != -1:
        print("The name already exists.")
    else:
        list.append((ele, mobile))
        list.sort(key=get_name)
        print(f"Friend {ele} is inserted successfully.")

def display_menu():
    print("\nPhonebook Menu:")
    print("1. Add Friend")
    print("2. Search Friend")
    print("3. Display All Friends")
    print("4. Exit")

def main():
    phoneBook = []
    while True:
        display_menu()
        choice = input("Enter your choice from 1 to 4: ")
        if choice == '1':
            name = input("Enter name of your friend: ")
            mobile_number = input("Enter mobile number: ")
            insert_friend(phoneBook, name, mobile_number)

        elif choice == '2':
            name = input("Enter name to search: ")
            index = non_recursive_binary_search(phoneBook, name)
            if index != -1:
                print(f"Friend found: Name = {phoneBook[index][0]}, Mobile Number = {phoneBook[index][1]}")
            else:
                print("Friend not found!")

        elif choice == '3':
            if not phoneBook:
                print("Phonebook is empty.")
            else:
                print("PhoneBook:")
                for friend in phoneBook:
                    print(f"Name = {friend[0]}, Mobile Number = {friend[1]}")

        elif choice == '4':
            print("Exiting the program.")
            break

        else:
            print("Invalid choice. Please enter a valid option.")

main()
