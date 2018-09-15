import matplotlib

fptr = open("TimeTaken.csv", 'r')

BubbleSortCoordinates = []
SelectSortCoordinates = []

count = 0
temp = []
inputVar = 0
bubbleSort = []
selectSort = []

for line in fptr.readlines():
    for char in line:
        if char == ',':
            if (count == 0):
                inputVar = int(''.join(temp))
                count += 1
                temp = []
            else:
                bubbleSort.append(tuple([inputVar, int(''.join(temp))]))
                count += 1
                temp = []
        elif char == '\n':
            selectSort.append(tuple([inputVar, int(''.join(temp))]))
            temp = []
            count = 0
        else:
            temp.append(char)

fptr.close()
