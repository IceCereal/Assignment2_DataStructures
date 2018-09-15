import matplotlib.pyplot as plt

fptr = open("TimeTaken.csv", 'r')

BubbleSortCoordinates = []
SelectSortCoordinates = []

count = 0
inputVar = 0
temp = []

for line in fptr.readlines():
    for char in line:
        if char == ',':
            if (count == 0):
                inputVar = int(''.join(temp))
                count += 1
                temp = []
            else:
                BubbleSortCoordinates.append(tuple([inputVar, int(''.join(temp))]))
                count += 1
                temp = []
        elif char == '\n':
            SelectSortCoordinates.append(tuple([inputVar, int(''.join(temp))]))
            temp = []
            count = 0
        else:
            temp.append(char)

fptr.close()

plt.scatter(*zip(*BubbleSortCoordinates), s=1)
plt.scatter(*zip(*SelectSortCoordinates), s=1)
plt.show()
