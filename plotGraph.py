import matplotlib.patches as mpatches
import matplotlib.pyplot as plt

BubbleSortCoordinates = []
SelectSortCoordinates = []

overCount = 1

count = 0
inputVar = 0
temp = []

fptr = open("TimeTaken.csv", 'r')
lines = fptr.readlines()
fptr.close()

for line in lines:
    if overCount%10 != 0:
        overCount += 1
        continue

    overCount += 1

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

plt.scatter(*zip(*BubbleSortCoordinates), s=1, c='red')
plt.scatter(*zip(*SelectSortCoordinates), s=1, c='blue')

plt.title("Sorting Algo's - Number vs. Time (IceCereal)")
bubblePatch = mpatches.Patch(color='red', label="Bubble Sort")
selectPatch = mpatches.Patch(color='blue', label="Selection Sort")
plt.legend(handles=[bubblePatch, selectPatch])

plt.xlabel("Number of Variables")
plt.ylabel("Time Taken (μS)")

plt.show()
