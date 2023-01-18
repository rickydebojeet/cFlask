import sys
import matplotlib.pyplot as plt

if len(sys.argv) < 3:
    print("Error: too few arguments!")
    print(
        "Usage: ./plot.py input_data_filename1 input_data_filename2 input_data_filename3 output_filename [plot_title] [y_axis_label1] [y_axis_label2]"
    )
    exit()

# Read command line arguments
datafile1 = sys.argv[1]
datafile2 = sys.argv[2]
datafile3 = sys.argv[3]
outfile = sys.argv[4]

plottitle = ""
ylabel1 = ""
ylabel2 = ""
if len(sys.argv) >= 6:
    plottitle = sys.argv[5]
    if len(sys.argv) >= 7:
        ylabel1 = sys.argv[6]
        ylabel2 = sys.argv[7]

# Read input data file
labels = []
data1 = []

with open(datafile1) as f:
    content = f.read().splitlines()
    # First row is assumed to contain labels for each column
    labels = [l.strip() for l in content[0].split("\t")]

    # Use the number of labels to determine the number of data columns
    data1 = [[] for _ in range(len(labels))]
    for line in content[1:]:
        i = 0
        for num in line.split():
            data1[i].append(float(num))
            i += 1

if ylabel1 == "" and len(labels) == 2:
    ylabel1 = labels[1]
if ylabel2 == "" and len(labels) == 3:
    ylabel2 = labels[2]

# Read input data file
labels = []
data2 = []

with open(datafile2) as f:
    content = f.read().splitlines()
    # First row is assumed to contain labels for each column
    labels = [l.strip() for l in content[0].split("\t")]

    # Use the number of labels to determine the number of data columns
    data2 = [[] for _ in range(len(labels))]
    for line in content[1:]:
        i = 0
        for num in line.split():
            data2[i].append(float(num))
            i += 1

if ylabel1 == "" and len(labels) == 2:
    ylabel1 = labels[1]
if ylabel2 == "" and len(labels) == 3:
    ylabel2 = labels[2]

# Read input data file
labels = []
data3 = []

with open(datafile3) as f:
    content = f.read().splitlines()
    # First row is assumed to contain labels for each column
    labels = [l.strip() for l in content[0].split("\t")]

    # Use the number of labels to determine the number of data columns
    data3 = [[] for _ in range(len(labels))]
    for line in content[1:]:
        i = 0
        for num in line.split():
            data3[i].append(float(num))
            i += 1

if ylabel1 == "" and len(labels) == 2:
    ylabel1 = labels[1]
if ylabel2 == "" and len(labels) == 3:
    ylabel2 = labels[2]

# Initialize plot
fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)


# Plot each data set, using first column as x-axis data
# for i in range(1, len(labels)):
ax1.plot(data1[0], data1[1], 'r', label='Single Thread')
ax1.plot(data2[0], data2[1], 'g', label='Dual Thread')
ax1.plot(data3[0], data3[1], 'b', label='Quad Thread')
ax2.plot(data1[0], data1[2], 'r', label='Single Thread')
ax2.plot(data2[0], data2[2], 'g', label='Dual Thread')
ax2.plot(data3[0], data3[2], 'b', label='Quad Thread')

# Plot's aesthetics
ax1.set_title(plottitle, pad='35')
ax1.set_ylabel(ylabel1)
ax1.legend(bbox_to_anchor =(0.9, 1.25), ncol = 3)
ax2.set_xlabel(labels[0])
ax2.set_ylabel(ylabel2)
plt.tight_layout()
# Save figure
fig.savefig(outfile, dpi=600)
plt.close("all")